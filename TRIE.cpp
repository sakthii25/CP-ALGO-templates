#include<bits/stdc++.h>
using namespace std;

class BiTrie{
public:
	BiTrie* node[2];
	void insert(int x){
		BiTrie* curr = this;
		for(int i=30;i>=0;--i){
			int y = ((x&(1<<i)) ? 1 : 0);
			if(!curr->node[y]) curr->node[y] = new BiTrie();
			curr = curr->node[y];
		}
	}
	int search(int x){
		BiTrie* curr = this;
		for(int i=30;i>=0;--i){
			int y = ((x&(1<<i)) ? 1 : 0);
			if(!curr->node[y]) return 0;
			curr = curr->node[y];
		}
		return 1;
	}
};
class Trie{
public:
	Trie* node[26];int end = 0;
	void insert(string& s){
		Trie* curr = this;
		for(int i=0;s[i];++i){
			int y = s[i]-'a';
			if(!curr->node[y]) curr->node[y] = new Trie();
			curr = curr->node[y];
		}
		curr->end = 1;
	}
	int search(string& s){
		Trie* curr = this;
		for(int i=0;s[i];++i){
			int y = s[i]-'a';
			if(!curr->node[y]) return 0;
			curr = curr->node[y];
		}
		return (curr->end);
	}
};
int main(){
	// int n;cin >> n;
	// BiTrie root;
	// for(int i=0;i<n;++i){
	// 	int x;cin >> x;
	// 	root.insert(x);
	// }
	// int y;cin >> y;
	// cout << root.search(y);
	string s;cin >> s;
	Trie* root = new Trie();
	root->insert(s);
	string t;cin >> t;
	cout << root->search(t);
}