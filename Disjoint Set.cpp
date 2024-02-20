#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
	vector<int> par,sz;
	DSU(int n){
		par.resize(n),sz.resize(n);
		for(int i=0;i<n;++i) par[i] = i,sz[i] = 1;
	}
	int Find(int x){
		if(x == par[x]) return x;
		return par[x] = Find(par[x]);
	}
	void Union(int x,int y){
		x = Find(x),y = Find(y);
		if(x == y) return;
		if(sz[x] < sz[y]) swap(x,y);
		par[y] = x;
		sz[x] += sz[y];
	}
};
int main(){
	DSU dsu(10);
}