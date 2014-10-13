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
int const MAX_N=105,MAX_SN=1005;
typedef pair<int, int> P;
int N,SN[MAX_N],W[MAX_N],Time[MAX_N][MAX_SN];
int M,MT[MAX_N][5];
int Q,QT[15][4];
int Compute(int x1,int y1,int x2,int y2){
    vector<vector<int>> d(N,vector<int>(MAX_SN,inf));
    d[x1][y1]=W[x1];
    queue<P> q;
    q.push(make_pair(x1, y1));
    while (!q.empty()) {
        P top=q.front();
        q.pop();
        int x=top.first,y=top.second;
        if (y>0&&d[x][y-1]>d[x][y]+Time[x][y-1]) {
            d[x][y-1]=d[x][y]+Time[x][y-1];
            q.push(make_pair(x, y-1));
        }
        if (y<SN[x]-1&&d[x][y+1]>d[x][y]+Time[x][y]) {
            d[x][y+1]=d[x][y]+Time[x][y];
            q.push(make_pair(x, y+1));
        }
        for (int i=0; i<M; i++) {
            if (MT[i][0]==x&&MT[i][1]==y) {
                int x2=MT[i][2],y2=MT[i][3];
                if (d[x2][y2]>d[x][y]+MT[i][4]+W[x2]) {
                    d[x2][y2]=d[x][y]+MT[i][4]+W[x2];
                    q.push(make_pair(x2, y2));
                }
            }
            else if(MT[i][2]==x&&MT[i][3]==y){
                int x2=MT[i][0],y2=MT[i][1];
                if (d[x2][y2]>d[x][y]+MT[i][4]+W[x2]) {
                    d[x2][y2]=d[x][y]+MT[i][4]+W[x2];
                    q.push(make_pair(x2, y2));
                }
            }
        }
    }
    return d[x2][y2];
}
void solve(){
    for (int q=0; q<Q; q++) {
        int res=Compute(QT[q][0], QT[q][1], QT[q][2], QT[q][3]);
        if (res==inf) {
            cout<<-1<<endl;
        }
        else
            cout<<res<<endl;
    }
}
int main() {
    freopen("C:\\Users\\mascure\\Desktop\\B-small-practice.in", "r", stdin);
    freopen("C:\\Users\\mascure\\Desktop\\B-small-practice.out", "w", stdout);
    int T;
    while (scanf("%d",&T)!=EOF) {
        for (int c=1; c<=T; c++) {
            cin>>N;
            for (int i=0; i<N; i++) {
                cin>>SN[i]>>W[i];
                for (int j=0; j<SN[i]-1; j++) {
                    scanf("%d",&Time[i][j]);
                }
            }
            cin>>M;
            for (int i=0; i<M; i++) {
                for (int j=0; j<5; j++) {
                    scanf("%d",&MT[i][j]);
                }
                MT[i][0]--;MT[i][1]--;MT[i][2]--;MT[i][3]--;
            }
            cin>>Q;
            for (int i=0; i<Q; i++) {
                for (int j=0; j<4; j++) {
                    scanf("%d",&QT[i][j]);
                }
                QT[i][0]--;QT[i][1]--;QT[i][2]--;QT[i][3]--;
            }
            cout<<"Case #"<<c<<":"<<endl;
            solve();
        }
    }
    return 0;
}