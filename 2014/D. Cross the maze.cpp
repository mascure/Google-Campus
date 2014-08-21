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
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
int const MAX_N=105;
int N,sx,sy,ex,ey;
char mat[MAX_N][MAX_N];
//方向 E,S,W,N
int leftX[4]={-1,0,1,0};
int leftY[4]={0,1,0,-1};
int nextX[4]={0,1,0,-1};
int nextY[4]={1,0,-1,0};
char D[4]={'E','S','W','N'};
void solve(){
	int steps=0;
	int dir=0;
	if(sx==1&&sy==1)dir=0;
	else if(sx==1&&sy==N)dir=1;
	else if(sx==N&&sy==1)dir=2;
	else dir=3;
	if(mat[sx+nextX[dir]][sy+nextY[dir]]=='#')dir=(dir+1)%4;
	int nowX=sx,nowY=sy;
	vector<int>path;
	while(!(nowX==ex&&nowY==ey)&&steps<=10000){
		int x1=nowX+leftX[dir],y1=nowY+leftY[dir];
		int x2=nowX+nextX[dir],y2=nowY+nextY[dir];
		if(mat[x1][y1]=='#'){
			if(mat[x2][y2]=='.'){
				nowX=x2;nowY=y2;
				steps++;
				path.push_back(dir);
			}
			else{
				int i=0;
				//尝试两次转向
				for(i=1;i<=2;i++){
					dir=(dir+1)%4;
					int x3=nowX+nextX[dir],y3=nowY+nextY[dir];
					if(mat[x3][y3]=='.'){
						nowX=x3;
						nowY=y3;
						path.push_back(dir);
						steps++;
						break;
					}
				}
				if(i==3){
					cout<<"Edison ran out of energy."<<endl;
					return;
				}
			}
		}
		else{
			nowX=x1;nowY=y1;
			dir=(dir+3)%4;
			steps++;
			path.push_back(dir);
		}
	}
	if(steps<=10000){
		cout<<steps<<endl;
		for(int i=0;i<path.size();i++){
			cout<<D[path[i]];
		}
		cout<<endl;
	}
	else
		cout<<"Edison ran out of energy."<<endl;
}
int main(){
	freopen("D:\\D-large-practice.in","r",stdin);
	freopen("D:\\D-large-practice.out","w",stdout);
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			scanf("%d",&N);
			memset(mat,'#',sizeof(mat));
			for(int i=1;i<=N;i++){
				getchar();
				for(int j=1;j<=N;j++)
					scanf("%c",&mat[i][j]);
			}
			scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
			cout<<"Case #"<<k<<": ";
			solve();
		}
	}
	return 0;
}