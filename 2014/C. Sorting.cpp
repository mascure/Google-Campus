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
#define MAX_N 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
int N,an,bn;
int arr[MAX_N],A[MAX_N],B[MAX_N];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	an=bn=0;
	for(int i=0;i<N;i++){
		if(arr[i]%2)A[an++]=arr[i];
		else B[bn++]=arr[i];
	}
	sort(A,A+an);
	sort(B,B+bn,cmp);
	int t=0;
	for(int i=0;i<N;i++){
		if(arr[i]%2)arr[i]=A[t++];
	}
	t=0;
	for(int i=0;i<N;i++){
		if(arr[i]%2==0)arr[i]=B[t++];
	}
	for(int i=0;i<N;i++)
		cout<<" "<<arr[i];
	cout<<endl;
}
int main(){
	freopen("D:\\C-large-practice.in","r",stdin);
	freopen("D:\\C-large-practice.out","w",stdout);
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			scanf("%d",&N);
			for(int i=0;i<N;i++){
				scanf("%d",&arr[i]);
			}
			cout<<"Case #"<<k<<":";
			solve();
		}
	}
	return 0;
}