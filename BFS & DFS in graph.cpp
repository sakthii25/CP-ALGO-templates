#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>& adj[], vector<bool>& vis,int src){
	queue<int> q;
	q.push(src);
	vis[src] = true;
	while(!q.empty()){
		int v = q.front();q.pop();
		cout << v << " ";
		for(auto j:adj[v]){
			if(!vis[j]){
				vis[j] = true;
				q.push(j);
			}
		}
		cout << endl;
	}
	cout << endl;
}
void dfs(std::vector<int> adj[],std::vector<bool> vis,int src){
	stack<int> st;
	st.push(src);
	vis[src] = true;
	while(!st.empty()){
		int  v = st.top();st.pop();
		cout << v << " ";
		for(auto j:adj[v]){
			if(!vis[j]){
				st.push(j);
			}
			vis[j] = true;
		}
	}
	cout << endl;
}
void bfs(unordered_map<int,vector<int>> mp,unordered_set<int> s,int src){
	queue<int> q;
	q.push(src);
	s.insert(src);
	while(!q.empty()){
		int v = q.front();q.pop();
		cout << v << " ";
		for(auto j:mp[v]){
			if(!s.count(j)){
				q.push(j);
				s.insert(j);
			}
		}
	}
	cout << endl;
}
void dfs(unordered_map<int,vector<int>> mp,unordered_set<int> s,int src){
	stack<int> st;
	st.push(src);
	s.insert(src);
	while(!st.empty()){
		int  v = st.top();st.pop();
		cout << v << " ";
		for(auto j:mp[v]){
			if(!s.count(j)){
				st.push(j);
				s.insert(j);
			}
		}
	}
	cout << endl;
}
int main(){
	int n,m;
	cin >> n >> m;
	std::vector<int> adj[n+1];
	unordered_map<int,vector<int>> mp; //for n might be large use this
	while(m--){
		int u,v;
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	// n -> number of vertex (nodes)
	// m -> number of edges 
	//if(n > m) it is ok to use to matrix to represt the graph
	std::vector<bool> vis(n);
	
	bfs(adj,vis,1);
	dfs(adj,vis,1);
	
	cout << endl;
	
	unordered_set<int> s;//if number of nodes very large instead of using array use set
	
	bfs(mp,s,1);
	dfs(mp,s,1);
}
