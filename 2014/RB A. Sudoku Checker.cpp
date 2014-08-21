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
int const MAX_N=1500;
int N;
int mat[MAX_N][MAX_N];
bool visit[50];
void solve(){
	//检查每一行
	for(int i=0;i<N*N;i++){
		memset(visit,0,sizeof(visit));
		for(int j=0;j<N*N;j++){
			int t=mat[i][j];
			if(t>=1&&t<=N*N&&visit[t]==0){
				visit[t]=1;
				continue;
			}
			else{
				cout<<"No"<<endl;
				return;
			}
		}
	}
	//检查每一列
	for(int i=0;i<N*N;i++){
		memset(visit,0,sizeof(visit));
		for(int j=0;j<N*N;j++){
			int t=mat[j][i];
			if(t>=1&&t<=N*N&&visit[t]==0){
				visit[t]=1;
				continue;
			}
			else{
				cout<<"No"<<endl;
				return;
			}
		}
	}
	//检查N*N个小矩形
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			memset(visit,0,sizeof(visit));
			for(int p=0;p<N;p++){
				for(int q=0;q<N;q++){
					int t=mat[i*N+p][j*N+q];
					if(t>=1&&t<=N*N&&visit[t]==0){
						visit[t]=1;
						continue;
					}
					else{
						cout<<"No"<<endl;
						return;
					}
				}
			}
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	freopen("D:\\A-large-practice.in","r",stdin);
	freopen("D:\\A-large-practice.out","w",stdout);
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			scanf("%d",&N);
			for(int i=0;i<N*N;i++){
				for(int j=0;j<N*N;j++){
					scanf("%d",&mat[i][j]);
				}
			}
			cout<<"Case #"<<k<<": ";
			solve();
		}
	}
	return 0;
}