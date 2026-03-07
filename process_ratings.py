import json
import re
import collections

# Load CF problems
with open('cf_problems.json') as f:
    data = json.load(f)

# Map contestId + index -> rating
problem_ratings = {}
for p in data['result']['problems']:
    cid = p['contestId']
    idx = p['index']
    if 'rating' in p:
        problem_ratings[f"{cid}{idx}"] = p['rating']

# Read filenames
with open('filenames.txt') as f:
    filenames = f.read().splitlines()

rating_counts = collections.defaultdict(int)
unrated = []
not_found = []

for filename in filenames:
    # Match CID + IDX (e.g., 1077C, 1527B1)
    # CID is digits, IDX is letters followed by optional digits
    # Some filenames are 1855-B.cpp or 1471-A.cpp
    clean_name = filename.replace('-', '')
    match = re.search(r'^([0-9]+)([A-Z][0-9]*).*', clean_name)
    if match:
        cid = match.group(1)
        idx = match.group(2)
        key = f"{cid}{idx}"
        if key in problem_ratings:
            rating = problem_ratings[key]
            rating_counts[rating] += 1
        else:
            not_found.append(filename)
    else:
        # Check if the filename itself is just the CID and index (some might not have .cpp)
        # But we already did re.search
        not_found.append(filename)

# Sort ratings
sorted_ratings = sorted(rating_counts.items())

with open('rating_wise_solved.txt', 'w') as f:
    f.write("Rating-wise solved problems in tle-elem folder:\n")
    f.write("-" * 50 + "\n")
    total = 0
    for rating, count in sorted_ratings:
        f.write(f"Rating {rating}: {count} problems\n")
        total += count
    f.write("-" * 50 + "\n")
    f.write(f"Total problems with ratings: {total}\n")
    if not_found:
        f.write(f"\nUnrated or not found in problemset: {len(not_found)}\n")
        # List them
        for name in not_found:
            f.write(f"  {name}\n")
