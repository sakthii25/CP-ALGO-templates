#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define nl endl

struct points{
	int x,y;
};
int oreientation(points& a,points& b,points& c){
	int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	return (!res ? 0 : (res>0 ? 1 : 2));
}
int dis(points& a,points& b){
	return abs(b.x - a.x) + abs(b.y - a.y);
}
int main(){
	int n;cin >> n;
	vector<points> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i].x >> v[i].y;
	}
	//sort the points based on the x value
	sort(v.begin(), v.end(),[](points& a,points& b){
		return a.x < b.x;
	});
	int p = 0;//first point
	vector<points> convexhull;
	do{
		convexhull.push_back(v[p]);
		int q = (p+1)%n;// i assume the next point
		for(int i=0;i<n;++i){
			int ore = oreientation(v[p],v[q],v[i]);
			if(ore == 1 or (!ore and dis(v[p],v[q]) < dis(v[p],v[i]))){
				//cout << dis(v[p],v[q]) << " " << dis(v[p],v[i]) << nl;
				q = i;
			}
		}
		for(int i=0;i<n;++i) if(i != p and i != q){
			int ore = oreientation(v[p],v[q],v[i]);
			if(!ore){
				convexhull.push_back(v[i]);
			}
		}
		//cout << nl;cout << p << " " << q <<  nl;
		p = q;
	}while(p);
	
	cout << "convexhull points" << nl;
	for(auto i:convexhull){
		cout << i.x << " " << i.y << nl;
	}
	return 0;
}