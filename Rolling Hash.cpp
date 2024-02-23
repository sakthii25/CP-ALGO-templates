#include<bits/stdc++.h>
using namespace std;

class RollingHash{
public:
	long long hash,base,powerBase,mod;
	RollingHash(){
		hash = 0;
		base = 256;
		powerBase = 1;
		mod = 1e9+7;
	}
	long long binexpo(long long a,long long b){
		long long res = 1;
		while(b){
			if(b&1){
				res = (res * a)%mod;
			}
			a = (a * a)%mod;
			b /= 2;
		}
		return res;
	}
	void push_back(char c){
		hash = (hash*base + c)%mod;
		powerBase = (powerBase*base)%mod;
	}
	void push_front(char c){
		hash = (c*powerBase + hash)%mod;
		powerBase = (powerBase*base)%mod;
	}
	void pop_back(char c){
		hash -= c;
		hash *= binexpo(base,mod-2);
		powerBase *= binexpo(base,mod-2);
	}
	void pop_front(char c){
		powerBase *= binexpo(base,mod-2);
		hash -= (c*powerBase);
	}
	long long getHash(){
		return hash;
	}
};
int main(){
	string s;
	cin >> s;
	RollingHash mp;
	for(int i=0;s[i];++i){
		mp.push_back(s[i]);
	}
	cout << mp.getHash() << endl;
}