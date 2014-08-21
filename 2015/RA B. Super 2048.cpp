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
int const MAX_N=105;
int N;
string dir;
vector<vector<int> > mat;
void deal(){
	for (int i=0; i<N; i++) {
        int last=-1;
        int flag=0;
        for (int j=0; j<N; j++) {
            if (mat[i][j]==0) {
                continue;
            }
			if(flag==0){
				int tmp=mat[i][j];
                mat[i][j]=0;
                mat[i][++last]=tmp;
                flag=1;
			}
			else{
				if(mat[i][j]==mat[i][last]){
					int tmp=mat[i][j];
					mat[i][j]=0;
					mat[i][last]=tmp*2;
					flag=0;
				}
				else{
					int tmp=mat[i][j];
					mat[i][j]=0;
					mat[i][++last]=tmp;
				}
			}
        }
    }
}
void solve(){
    deal();
	vector<vector<int>> tmp;
	if(dir=="left")tmp=mat;
	else if(dir=="right"){
		for(int i=0;i<N;i++){
			reverse(mat[i].begin(),mat[i].end());
			tmp.push_back(mat[i]);
		}
	}
	else if(dir=="up"){
		for(int i=0;i<N;i++){
			vector<int> t;
			for(int j=N-1;j>=0;j--){
				t.push_back(mat[j][i]);
			}
			tmp.push_back(t);
		}
	}
	else if(dir=="down"){
		for(int i=N-1;i>=0;i--){
			vector<int> t;
			for(int j=0;j<N;j++){
				t.push_back(mat[j][i]);
			}
			tmp.push_back(t);
		}
	}
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d%c",tmp[i][j],j==N-1?'\n':' ');
        }
    }
}
int main() {
    freopen("C:\\Users\\mascure\\Desktop\\B-large-practice.in", "r", stdin);
    freopen("C:\\Users\\mascure\\Desktop\\B-large-practice.out", "w", stdout);
    int T;
    while (scanf("%d",&T)!=EOF) {
        for (int k=1; k<=T; k++) {
            scanf("%d",&N);
            cin>>dir;
			mat.clear();
			for(int t=0;t<N;t++){
				mat.push_back(vector<int>(N));
			}
			if(dir=="left"){
				for (int i=0; i<N; i++) {
					for (int j=0; j<N; j++) {
						cin>>mat[i][j];
					}
				}
			}
			else if(dir=="up"){
				for(int i=0;i<N;i++){
					for(int j=N-1;j>=0;j--){
						cin>>mat[j][i];
					}
				}
			}
			else if(dir=="right"){
				for (int i=0; i<N; i++) {
					for (int j=N-1; j>=0; j--) {
						cin>>mat[i][j];
					}
				}
			}
			else{
				for(int i=N-1;i>=0;i--){
					for(int j=0;j<N;j++){
						cin>>mat[j][i];
					}
				}
			}
            cout<<"Case #"<<k<<":"<<endl;
            solve();
        }
    }
    return 0;
}
