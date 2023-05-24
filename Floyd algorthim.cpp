#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> g[n+1];
	while(m--){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<int>> path(n+1,vector<int>(n+1,100));
	for(int i=1;i<=n;++i){
		path[i][i] = 0;
		for(auto j:g[i]){
			path[i][j] = 1;
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				path[i][j] = path[j][i] = min(path[i][j],path[i][k] + path[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
