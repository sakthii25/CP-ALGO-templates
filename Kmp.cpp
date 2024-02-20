#include<bits/stdc++.h>
using namespace std;

vector<int> kmp(string& p){
	int n = p.size();
	vector<int> lps(n);
	for(int i=1,j=0;i<n;++i){
		while(j>0 and p[i] != p[j]) j = lps[j-1];
		if(p[i] == p[j]) lps[i] = ++j;
	}
	return lps;
}
vector<int> kmp(string& s,string& p){
	int n = s.size(),m = p.size();
	vector<int> lps = kmp(p);
	vector<int> res(n);
	for(int i=0,j=0;i<n;++i){
		while(j>0 and s[i] != p[j]) j = lps[j-1];
		if(s[i] == p[j]) res[i] = ++j;
		if(j == m) j = lps[j-1];
	}
	return res;
}
int main(){
	string s,p;
	cin >> s >> p;
	vector<int> lps = kmp(s,p);
	for(auto i:lps){
		cout << i << " ";
	}
}