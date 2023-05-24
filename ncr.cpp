#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll mxn = 2e5 + 10;

vector<ll> fact(mxn),ifact(mxn);
ll binexpo(ll a,ll b){
	if(!a) return a;
	ll r = 1;
	while(b){
		if(b&1){
			r = (r*a)%mod;
		}
		a = (a*a)%mod;
		b /= 2;
	}
	return r;
}
void pre(){
	fact[0] = 1;
	ifact[0] = binexpo(fact[0],mod-2);
	for(int i=1;i<mxn;++i){
		fact[i] = (fact[i-1]*i)%mod;
		ifact[i] = binexpo(fact[i],mod-2);
	}
}
int ncr(int n,int r){
	return (fact[n]%mod*ifact[n-r]%mod*ifact[r]%mod)%mod;
}
int main(){
	pre();
	int n,r;
	cin >> n >> r;
	cout << ncr(n,r) << endl;
}