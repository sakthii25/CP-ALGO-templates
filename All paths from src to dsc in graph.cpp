#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int dsc,vector<int>& path,set<int>& visited,vector<int> graph[]){
	path.push_back(src);// current path nodes
	if(src == dsc){
		for(auto i:path){
			cout << i << " ";//print the path from src to dsc
		}
		cout << endl;
	}
	for(auto i:graph[src]){
		if(!visited.count(i)){
			visited.insert(i);
			dfs(i,dsc,path,visited,graph);
		}
	}
	//back tracking takes place here
	path.pop_back();// may be its a dead end or alread find the path
	visited.erase(src);// there
}
int main(){
	int n,m;
	cin >> n >> m; 
	// n -> number of nodes
	// m -> number of edges
	std::vector<int> graph[n+1];
	while(m--){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int src,dsc;
	cin >> src >> dsc;
	std::vector<int> path;
	std::set<int> visited;
	visited.insert(src);
	dfs(src,dsc,path,visited,graph);
}