#!/bin/bash
set -e  # stop on any error
cd "$(dirname "$0")" || exit 1  # go to bag folder

echo "Cleaning old binaries..."
rm -f brute sol gen

echo "Compiling..."
g++ -std=c++17 ../gen.cpp -O2 -o gen
g++ -std=c++17 ../brute.cpp -O2 -o brute
g++ -std=c++17 ../solution.cpp -O2 -o sol
echo "Compilation done"
echo

for ((i=1; i<=1000; i++)); do
    ./gen > test.in
    ./brute < test.in > out_brute.txt
    ./sol   < test.in > out_sol.txt

    if ! diff out_brute.txt out_sol.txt > /dev/null; then
        echo
        echo "❌ Wrong Answer at test $i"
        echo "------------------------"
        echo "Input:"
        cat test.in
        echo "------------------------"
        echo "Brute Output:"
        cat out_brute.txt
        echo "------------------------"
        echo "Your Output:"
        cat out_sol.txt
        exit 0
    fi

    echo "✅ Passed test $i"
done

echo
echo "🎉 All tests passed (1000/1000)"
