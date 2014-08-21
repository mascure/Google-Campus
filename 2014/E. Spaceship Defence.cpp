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
#include<windows.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_SIZE 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
int const MAX_V=1500;
int const MAX_N=80005;
struct edge{
	int to,cost;
	edge(int _to,int _cost){
		to=_to;
		cost=_cost;
	}
};
typedef pair<int,int> P;
vector<edge> G[MAX_V];
int d[MAX_V];
int N,M,s,t;
int R[MAX_N];
int getN(string s){
	if(s.length()==1){
		if(s[0]>='0'&&s[0]<='9')return s[0]-'0';
		else return s[0]-'a'+10;
	}
	else{
		int a0=0,a1=0;
		if(s[0]>='0'&&s[0]<='9')a0=s[0]-'0';
		else a0=s[0]-'a'+10;
		if(s[1]>='0'&&s[1]<='9')a1=s[1]-'0';
		else a1=s[1]-'a'+10;
		return a0*36+a1;
	}
}
struct cmp{
    bool operator() ( P a, P b ){
        return a.first>b.first;
	}
};
void dijkstra(int s){
	priority_queue<P,vector<P>,cmp > que;
	fill(d,d+MAX_V,inf);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
void solve(){
	dijkstra(s);
	if(d[t]==inf){
		cout<<-1<<endl;
	}
	else
		cout<<d[t]<<endl;
}
int main(){
	freopen("D:\\E-large-practice.in","r",stdin);
	freopen("D:\\E-large-practice.out","w",stdout);
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			for(int i=0;i<MAX_V;i++){
				G[i].clear();
			}
			scanf("%d",&N);
			for(int i=0;i<N;i++){
				string s;
				cin>>s;
				R[i]=getN(s);
			}
			scanf("%d",&M);
			for(int i=0;i<M;i++){
				int a,b,dis;
				scanf("%d%d%d",&a,&b,&dis);
				a--,b--;
				G[R[a]].push_back(edge(R[b],dis));
			}
			int S=0;
			scanf("%d",&S);
			cout<<"Case #"<<k<<":"<<endl;
			for(int i=0;i<S;i++){
				scanf("%d%d",&s,&t);
				s--,t--;
				s=R[s];
				t=R[t];
				solve();
			}
		}
	}
	return 0;
}