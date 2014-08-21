#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<math.h>
#include<unordered_map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_N 100005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
ull n,p,q,id;
int T;
void getNth(ull n,ull& p,ull& q){
	vector<int> path;
	while(n!=1){
		ull p=n>>1;
		if(p*2==n)path.push_back(0);
		else path.push_back(1);
		n=p;
	}
	reverse(path.begin(),path.end());
	p=q=1;
	for(int i=0;i<path.size();i++){
		if(path[i]==0)q=p+q;
		else p=p+q;
		//cout<<i<<": "<<p<<" "<<q<<endl;
	}
}
ull getN(ull p,ull q){
	n=1;
	ull level=0;
	while(p!=1||q!=1){
		if(p<q){
			q-=p;
			n+=((ull)1<<level);
		}
		else{
			p-=q;
			n+=((ull)1<<(level+1));
		}
		//cout<<level<<" "<<n<<endl;
		level++;
	}
	return n;
}
void solve(){
	if(id==1){
		getNth(n,p,q);
		cout<<" "<<p<<" "<<q<<endl;
	}
	else
		cout<<" "<<getN(p,q)<<endl;
}
int main(){
	freopen("D:\\B-large-practice.in","r",stdin);
	freopen("D:\\B-large-practice.out","w",stdout);
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			cin>>id;
			if(id==1)cin>>n;
			else cin>>p>>q;
			cout<<"Case #"<<k<<":";
			solve();
		}
	}
	return 0;
}