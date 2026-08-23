#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> arr;     // current array state during Mo's processing
vector<int> simArr;  // used only to precompute old values during initial simulation

struct Update {
    int pos, oldval, newval, timeIndex;
};
struct Query {
    int L, R, t, idx;
};

unordered_map<int,int> freqMap;
long long curSum = 0;

inline void addVal(int v){
    int &c = freqMap[v];
    c++;
    if (c == 1 && v % 3 == 0) curSum += v;
}
inline void removeVal(int v){
    int &c = freqMap[v];
    c--;
    if (c == 0 && v % 3 == 0) curSum -= v;
}

int curL, curR, curT;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> Q) {
        arr.assign(N+1, 0);
        for (int i = 1; i <= N; i++) cin >> arr[i];
        simArr = arr; // copy used to derive old values sequentially

        vector<Update> updates;
        vector<Query> queries;
        updates.reserve(Q);
        queries.reserve(Q);

        int updCount = 0; // number of updates seen so far (defines "time")
        for (int q = 0; q < Q; q++) {
            int type; cin >> type;
            if (type == 0) {
                int A, V; cin >> A >> V;
                Update u;
                u.pos = A;
                u.oldval = simArr[A];
                u.newval = V;
                simArr[A] = V;
                u.timeIndex = updCount;
                updates.push_back(u);
                updCount++;
            } else {
                int A, B; cin >> A >> B;
                Query qq;
                qq.L = A; qq.R = B;
                qq.t = updCount;              // # updates applied before this query
                qq.idx = (int)queries.size();  // preserves original output order
                queries.push_back(qq);
            }
        }

        int totalQ = (int)queries.size();
        vector<long long> answers(totalQ);

        int blockSize = max(1, (int)round(pow((double)max(N,1), 2.0/3.0)));

        sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b){
            int ba = a.L / blockSize, bb = b.L / blockSize;
            if (ba != bb) return ba < bb;
            if ((ba & 1) == 0) {
                if (a.R != b.R) return a.R < b.R;
            } else {
                if (a.R != b.R) return a.R > b.R;
            }
            return a.t < b.t;
        });

        curL = 1; curR = 0; curT = 0;
        freqMap.clear();
        curSum = 0;
        // arr already holds the correct original (time 0) values here — no reset needed.

        for (auto &qq : queries) {
            // move time pointer to qq.t
            while (curT < qq.t) {
                Update &u = updates[curT];
                int pos = u.pos;
                if (pos >= curL && pos <= curR) removeVal(arr[pos]);
                arr[pos] = u.newval;
                if (pos >= curL && pos <= curR) addVal(arr[pos]);
                curT++;
            }
            while (curT > qq.t) {
                curT--;
                Update &u = updates[curT];
                int pos = u.pos;
                if (pos >= curL && pos <= curR) removeVal(arr[pos]);
                arr[pos] = u.oldval;
                if (pos >= curL && pos <= curR) addVal(arr[pos]);
            }

            // move L,R pointers to qq.L, qq.R
            while (curR < qq.R) { curR++; addVal(arr[curR]); }
            while (curL > qq.L) { curL--; addVal(arr[curL]); }
            while (curR > qq.R) { removeVal(arr[curR]); curR--; }
            while (curL < qq.L) { removeVal(arr[curL]); curL++; }

            answers[qq.idx] = curSum;
        }

        for (int i = 0; i < totalQ; i++) {
            cout << answers[i] << "\n";
        }
    }
    return 0;
}