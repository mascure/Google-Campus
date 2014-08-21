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
const int MAX_N=105;
char mat[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int N;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool sou(int _x,int _y,int flag){
	visit[_x][_y]=1;
	for(int i=0;i<4;i++){
		int x=_x+dx[i],y=_y+dy[i];
		if(flag==0&&y==N)return true;
		if(flag==1&&x==N)return true;
		if(x>=0&&x<N&&y>=0&&y<N&&mat[x][y]==(flag==0?'B':'R')&&!visit[x][y]){
			if(sou(x,y,flag))return true;
		}
	}
	return false;
}
int check(int flag){
	int res=0;
	if(flag==0){
		for(int i=0;i<N;i++){
			if(mat[i][0]=='B'){
				memset(visit,0,sizeof(visit));
				if(sou(i,0,0)){
					if(!res)res=1;
					else return -1;
				}
			}
		}
		return res;
	}
	else{
		for(int i=0;i<N;i++){
			if(mat[0][i]=='R'){
				memset(visit,0,sizeof(visit));
				if(sou(0,i,1)){
					if(!res)res=1;
					else return -1;
				}
			}
		}
		return res;
	}
}
void solve(){
	int cB=0,cR=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(mat[i][j]=='B')cB++;
			if(mat[i][j]=='R')cR++;
		}
	}
	if(cB+1<cR||cB>cR+1){
		cout<<"Impossible"<<endl;
		return;
	}
	int Bconnect=0,Rconnect=0;
	Bconnect=check(0);
	Rconnect=check(1);
	if(Bconnect==-1||Rconnect==-1){
		cout<<"Impossible"<<endl;
		return;
	}
	if(Bconnect){
		if(cB>=cR){
			cout<<"Blue wins"<<endl;
		}
		else
			cout<<"Impossible"<<endl;
	}
	else if(Rconnect){
		if(cB<=cR)
			cout<<"Red wins"<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	else
		cout<<"Nobody wins"<<endl;
}
int main(){
	//freopen("D:\\E-small-practice.in","r",stdin);
	//freopen("D:\\E-small-practice.out","w",stdout);
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			scanf("%d",&N);
			for(int i=0;i<N;i++){
				getchar();
				for(int j=0;j<N;j++)
					scanf("%c",&mat[i][j]);
			}
			cout<<"Case #"<<k<<": ";
			solve();
		}
	}
	return 0;
}