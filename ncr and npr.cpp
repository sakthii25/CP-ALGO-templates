#include<bits/stdc++.h>
using namespace std;

#define ll long long

class comb{
public:
	const int N = 1e5 + 1,mod = 1e9 + 7;
	vector<ll> fact,infact;
	comb(){
		fact.resize(N);
		infact.resize(N);
		fact[0] = 1;infact[0] = modinv(fact[0],mod-2);
		for(int i=1;i<N;++i){
			fact[i] = (fact[i-1] * i)%mod;
			infact[i] = modinv(fact[i],mod-2);
		}
	}
	ll modinv(ll a,ll b){
		ll res = 1;
		while(b){
			if(b&1){
				res = (res * a)%mod;
			}
			a = (a * a)%mod;
			b /= 2;
		}
		return res;
	}
	ll ncr(ll n,ll r){
		ll res = ((fact[n] * infact[r])%mod * infact[n-r])%mod;
		return res; 
	}
	ll npr(ll n,ll r){
		ll res = (fact[n] * infact[n-r])%mod;
	}
};
int main(){
	ll n,r;
	cin >> n >> r;
	comb c;
	cout << c.ncr(n,r) << " " << c.npr(n,r) << endl;
}
