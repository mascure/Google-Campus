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
char S[110000];
int len;
void solve(){
	char res[110000];
	int rn=0;
	stack<int> s;
	for(int i=0;i<len;i++){
		if(i+1<len&&S[i]=='/'&&S[i+1]=='*'){
			s.push(1);
			i++;
		}
		else if(i+1<len&&S[i]=='*'&&S[i+1]=='/'&&s.size()>0){
			s.pop();
			i++;
		}
		else if(s.size()==0){
			res[rn++]=S[i];
		}
	}
	res[rn++]='\0';
	cout<<res<<endl;
}
int main(){
	freopen("D:\\E-small-practice.in","r",stdin);
	freopen("D:\\E-small-practice.out","w",stdout);
	len=0;
	string tmp;
	while(getline(cin,tmp)){
		strcpy(S+len,tmp.c_str());
		len+=tmp.length();
		S[len++]='\n';
	}
	S[len++]='\0';
	cout<<"Case #1:"<<endl;
	solve();
	return 0;
}