#include<bits/stdc++.h>
using namespace std;

vector<int> Zarray(string& s){
	int n = s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;++i){
		if(i<=r){
			z[i] = min(z[i-l],r-i+1);
		}
		while(i+z[i] < n and s[z[i]] == s[i+z[i]]){
			++z[i];
		}
		if(i+z[i]-1 > r){
			l = i,r = i+z[i]-1;
		}
	}
	return z;
}
int main(){
	string s;cin >> s;
	vector<int> z = Zarray(s);
	for(auto i:z) cout << i << " ";
}