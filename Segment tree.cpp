#include<bits/stdc++.h>
using namespace std;

class SegTree{
public:
	vector<int> tree;
	SegTree(int n){
		tree.resize(4*n);
	}
	int operation(int a,int b){
		return min(a,b);
	}
	void Build(vector<int>& arr,int treeNode, int left, int right){
	    if (left == right) {
	        tree[treeNode] = arr[left];
	        return;
	    }

	    int mid = left + (right-left)/2;
	    
	    Build(arr,2 * treeNode + 1,left,mid);
	    Build(arr,2 * treeNode + 2,mid + 1,right);

	    tree[treeNode] = operation(tree[2 * treeNode + 1],tree[2 * treeNode + 2]);
	}
	int Query(int treeNode, int left, int right, int qLeft, int qRight){
	    if (qLeft <= left && qRight >= right){
	        return tree[treeNode];
	    }

	    if (qRight < left || qLeft > right){
	        return -1;
	    }

	    int mid = left + (right-left)/2;

	    
	    int leftResult = Query(2 * treeNode + 1, left, mid, qLeft, qRight);
	    int rightResult = Query(2 * treeNode + 2, mid + 1, right, qLeft, qRight);

	    if (leftResult == -1) return rightResult;
	    else if (rightResult == -1) return leftResult;
	    else return operation(leftResult, rightResult);
	}
	void Update(int treeNode, int left, int right, int qLeft, int qRight, int newValue){
	    if (qLeft > right || qRight < left){
	        return;
	    }

	    if (qLeft <= left && qRight >= right){
	        tree[treeNode] = newValue;
	        return;
	    }

	    int mid = left + (right - left) / 2;

	   
	    Update(2 * treeNode + 1, left, mid, qLeft, qRight, newValue);
	    Update(2 * treeNode + 2, mid + 1, right, qLeft, qRight, newValue);

	    tree[treeNode] = operation(tree[2 * treeNode + 1], tree[2 * treeNode + 2]);
	}
};
int main(){
	int n;cin >> n;
	vector<int> v(n);
	for(auto &i:v) cin >> i;
	SegTree tree(n);
	tree.Build(v,0,0,n-1);
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		--l;--r;
		cout << tree.Query(0,0,n-1,l,r) << endl;
	}
}