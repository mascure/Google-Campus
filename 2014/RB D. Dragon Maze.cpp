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
int const MAX_N=105;
int N,M;
int mat[MAX_N][MAX_N];
int sx,sy,ex,ey;
int visit[MAX_N][MAX_N],p[MAX_N][MAX_N];
int dirx[]={-1,0,1,0};
int diry[]={0,1,0,-1};
typedef pair<int,int> P;
void solve(){
	memset(visit,0,sizeof(visit));
	memset(p,0,sizeof(p));
	p[sx][sy]=mat[sx][sy];
	visit[sx][sy]=1;
	queue<P> q;
	q.push(P(sx,sy));
	while(!q.empty()&&!visit[ex][ey]){
		queue<P> tmp;
		while(!q.empty()){
			P top=q.front();q.pop();
			for(int d=0;d<4;d++){
				int x=top.first+dirx[d],y=top.second+diry[d];
				if(x>=0&&x<N&&y>=0&&y<M&&mat[x][y]>0){
					if(visit[x][y])
					p[x][y]=max(p[x][y],p[top.first][top.second]+mat[x][y]);
					else{
						p[x][y]=p[top.first][top.second]+mat[x][y];
						visit[x][y]=1;
						tmp.push(P(x,y));
					}
				}
			}
		}
		swap(q,tmp);
	}
	if(!visit[ex][ey])cout<<"Mission Impossible."<<endl;
	else
		cout<<p[ex][ey]<<endl;
}
int main(){
	freopen("D:\\D-large-practice.in","r",stdin);
	freopen("D:\\D-large-practice.out","w",stdout);
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			scanf("%d%d",&N,&M);
			scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++)
					scanf("%d",&mat[i][j]);
			}
			cout<<"Case #"<<k<<": ";
			solve();
		}
	}
	return 0;
}