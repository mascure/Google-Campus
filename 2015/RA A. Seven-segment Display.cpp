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
vector<string> in;
int broken[7];
bool led[10][7]={
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
void solve(){
    int res=-1;
    int cnt=0;
    vector<int> resBro;
	bool totFail=false;
    for (int i=9; i>=0; i--) {
        //memset(broken, 0, sizeof(broken));
        fill(broken, broken+7, 0);
        int j=0;
		bool can=true;
        for (j=0; j<N&&can; j++) {
            string &s=in[j];
            int num=((i-j)%10+10)%10;
            for (int k=0; k<7; k++) {
                if (s[k]=='1') {
					if (led[num][k]==1)
					{
						if(broken[k]==0)
							broken[k]=1;
						else if(broken[k]==1);
						else if(broken[k]==2)can=false;
					}
					else{
						can=false;
					}
                }
                else{
                    if(led[num][k]==0);
					else{
						if(broken[k]==0)broken[k]=2;
						else if(broken[k]==1)can=false;
						else if(broken[k]==2);
					}
                }
            }
        }
        if (can) {
			cnt++;
            res=((i-j)%10+10)%10;
			vector<int> tmpAns(7,0);
			//当LED灯为1时，灯片不确定才会导致整个失败
			//若要显式的LED灯为0，则不需要知道灯片的状态
            for (int c=0; c<7; c++) {
				if(led[res][c]==1){
					if(broken[c]==0)
						totFail=true;
					//好的
					else if(broken[c]==1){
						tmpAns[c]=1;
					}
				}
            }
			if(cnt==1||tmpAns==resBro){
				resBro=tmpAns;
			}
			else
				totFail=true;
        }
    }
    if (totFail||cnt==0) {
        cout<<"ERROR!"<<endl;
        return;
    }
    else
    {
        for (int k=0; k<7; k++) {
            cout<<resBro[k];
        }
        cout<<endl;
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
	freopen("C:\\Users\\mascure\\Desktop\\A-large-practice.in", "r", stdin);
    freopen("C:\\Users\\mascure\\Desktop\\A-large-practice.out1", "w", stdout);
    int T;
    while (scanf("%d",&T)!=EOF) {
        for (int k=1; k<=T; k++) {
            scanf("%d",&N);
            in.resize(N);
            for (int i=0; i<N; i++) {
                cin>>in[i];
            }
            cout<<"Case #"<<k<<": ";
            solve();
        }
    }
    return 0;
}
