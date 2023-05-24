#include<bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int>& a,const pair<int,int>& b){
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
	
	//based on the first and second we can customize
	//the sorting
	//a.first < b.first means sort based on the first ele
	//a.second < b.second means sort based on the sec ele
	//< ascending order
	//> descending order
}
int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(),sortbysec);
	for(auto i:v){
		cout << i.first << " " << i.second << endl;
	}
}