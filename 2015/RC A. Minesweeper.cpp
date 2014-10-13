#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<list>
#include <stack>
#include<queue>
#include<sstream>
#include<map>
#include <algorithm>
//#include<unordered_set>
//#include<unordered_map>
//#include<time.h>
#define MAX_E 1000000
#define MAX_V 100005
#define MAX_M 105;
typedef long long ll;
using namespace std;
int const MOD=1000000007;
int const inf=0x7fffffff;
int const MAX_N=305;
typedef pair<int, int> P;
char mat[MAX_N][MAX_N];
int cnt[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int visited=0;
int N,W;
int dirX[]={-1,0,1,1,1,0,-1,-1},dirY[]={-1,-1,-1,0,1,1,1,0};
bool Check(int x,int y){
    if (x>=0&&x<N&&y>=0&&y<N) {
        return true;
    }
    else
        return false;
}
void dfs(int x,int y){
    visited++;
    visit[x][y]=1;
    if (cnt[x][y]>0) {
        return;
    }
    for (int d=0; d<8; d++) {
        int xx=x+dirX[d],yy=y+dirY[d];
        if (Check(xx,yy)&&(mat[xx][yy]=='.')&&!visit[xx][yy]) {
            dfs(xx, yy);
        }
    }
}
void solve(){
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (mat[i][j]=='*') {
                continue;
            }
            for (int d=0; d<8; d++) {
                int xx=i+dirX[d],yy=j+dirY[d];
                if (Check(xx,yy)&&(mat[xx][yy]=='*')) {
                    cnt[i][j]++;
                }
            }
        }
    }
    memset(visit, 0, sizeof(visit));
    int res=0;
    visited=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (mat[i][j]!='*'&&!visit[i][j]&&cnt[i][j]==0) {
                dfs(i,j);
                res++;
            }
        }
    }
    cout<<N*N-W-visited+res<<endl;
}
int main() {
    freopen("/Users/mascure/Desktop/A-large.in", "r", stdin);
    freopen("/Users/mascure/Desktop/A-large.out", "w", stdout);
    //将n分为k个数的和,如将2分为2个数的和，则输出1 1
    int T;
    while (scanf("%d",&T)!=EOF) {
        for (int c=1; c<=T; c++) {
            cin>>N;
            W=0;
            for (int i=0; i<N; i++) {
                getchar();
                for (int j=0; j<N; j++) {
                    scanf("%c",&mat[i][j]);
                    if (mat[i][j]=='*') {
                        W++;
                    }
                }
            }
            cout<<"Case #"<<c<<": ";
            solve();
        }
    }
    return 0;
}