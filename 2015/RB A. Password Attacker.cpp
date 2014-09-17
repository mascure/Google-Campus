#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
const int MAX_N=105;
const int inf=1000000;
const int MOD=1000000007;
typedef long long ll;
//dp[i][j]表示i种j个数字的总数，
//令k表示第i个数字取得个数，则dp[i][j]为将k个数字插入前i-1种，j-k个的排列。
//将k个相同的数插入固定n个数的排列，一共有C(n+k,k)种情况。
//dp[i][j]=（k从1到j-(i-1)求和）dp[i-1][j-k]*C[j][k]；
int M,N;
ll C[2*MAX_N][2*MAX_N];
int dp[MAX_N][MAX_N];
void compute(){
	C[1][0]=C[1][1]=1;
	for(int i=2;i<=200;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
}
void solve(){
	memset(dp,0,sizeof(dp));
	fill(dp[1],dp[1]+N+1,1);
	for(int i=2;i<=M;i++){
		for(int j=i;j<=N;j++){
			dp[i][j]=0;
			for(int k=1;k<=j-i+1;k++){
				dp[i][j]=(dp[i][j]+dp[i-1][j-k]*C[j][k])%MOD;
			}
		}
	}
	cout<<dp[M][N]<<endl;
}

int main(){
	freopen("A-large-practice.in","r",stdin);
	freopen("A-large-practice.out","w",stdout);
	int caseN;
	scanf("%d",&caseN);
	compute();
	for(int k=1;k<=caseN;k++){
		scanf("%d%d",&M,&N);
		cout<<"Case #"<<k<<": ";
		solve();
	}
	return 0;
}