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
int const MAX_N=1000005;
typedef pair<int, int> P;
bool good[10];
int dp[MAX_N];
int N;
int single(int x){
    int res=0;
    while (x>0) {
        int t=x%10;
        if (!good[t]) {
            return -1;
        }
        x/=10;
        res++;
    }
    return res;
}
void solve(){
    for (int i=1; i<=N; i++) {
        dp[i]=inf;
        int t=single(i);
        if (t!=-1) {
            dp[i]=t;
        }
        else{
        for (int j=2; j*j<=i; j++) {
            if (i%j==0) {
                if (dp[j]!=inf&&dp[i/j]!=inf) {
                    dp[i]=min(dp[i],dp[j]+dp[i/j]+1);
                }
            }
        }
        }
    }
    if (dp[N]==inf) {
        cout<<"Impossible"<<endl;
    }
    else
        cout<<dp[N]+1<<endl;
}
int main() {
    freopen("/Users/mascure/Desktop/C-large.in", "r", stdin);
    freopen("/Users/mascure/Desktop/C-large.out", "w", stdout);
    int T;
    while (scanf("%d",&T)!=EOF) {
        for (int c=1; c<=T; c++) {
            for (int i=0; i<10; i++) {
                cin>>good[i];
            }
            cin>>N;
            cout<<"Case #"<<c<<": ";
            solve();
        }
    }
    return 0;
}