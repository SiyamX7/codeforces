#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
vector<int> tree(4*N), v(N);

void build(int node, int start, int end){
	if(start == end){
		tree[node] = v[start];
		return;
	} 

	int mid = (start + end) / 2;

	build(node*2, start, mid);
	build(node*2 + 1, mid+1 , end);

	tree[node] = tree[node*2] + tree[node*2 + 1];
}

int query(int node, int start, int end, int ql, int qr){
	// no overlap
	if(qr < start || ql > end){
		return 0;
	}

	if(ql <= start && qr >= end){
		return tree[node];
	}

	int mid = (start + end) / 2;

	int leftNode = 2*node;
	int rightNode = 2*node + 1;

	int leftSum = query(leftNode, start, mid, ql, qr);
	int rightSum = query(rightNode, mid+1, end, ql, qr);

	return leftSum + rightSum;
}


void update(int node, int start, int end, int ind, int val){
	if(start == end){
		tree[node] = val;
		v[ind] = val;
		return;
	}

	int mid = (start + end) / 2;

	int leftNode = 2*node;
	int rightNode = 2*node +1;
	if(ind <= mid)
		update(leftNode, start, mid, ind, val);
	else 
		update(rightNode, mid+1, end, ind, val);

	tree[node] = tree[leftNode] + tree[rightNode];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    v = {1,3,2,6,7,5,3};
    int n = v.size();

    build(1, 0, n-1);

    for(int i = 0; i <= n-1; i++){
    	cout << tree[i] << " ";
    }
}   