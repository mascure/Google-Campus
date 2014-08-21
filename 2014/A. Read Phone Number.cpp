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
#define MAX_N 100005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
string N;
int T;
vector<int> F;
char *num[]={
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};
char *suc[]={
	"",
	"",
	"double",
	"triple",
	"quadruple",
	"quintuple",
	"sextuple",
	"septuple",
	"octuple",
	"nonuple",
	"decuple"
};
string fan(char c,int N){
	if(N==1){
		return string(num[c-'0']);
	}
	else if(N<=10){
		return string(suc[N])+" "+string(num[c-'0']);
	}
	else{
		string res=string(num[c-'0']);
		for(int i=1;i<N;i++){
			res+=" "+string(num[c-'0']);
		}
		return res;
	}
}
string deal(string str){
	int start=0;
	string res="";
	for(int i=1;i<str.length();i++){
		if(str[i]!=str[start]){
			res+=" "+fan(str[start],i-start);
			start=i;
		}
	}
	res+=" "+fan(str[start],str.length()-start);
	return res;
}
void solve(){
	int nowPos=0;
	for(int i=0;i<F.size();i++){
		cout<<deal(N.substr(nowPos,F[i]));
		nowPos+=F[i];
	}
	cout<<endl;
}
int main(){
	freopen("D:\\A-large-practice.in","r",stdin);
	freopen("D:\\A-large-practice.out","w",stdout);
	while(scanf("%d",&T)!=EOF){
		for(int k=1;k<=T;k++){
			string format;
			cin>>N>>format;
			F.clear();
			int i=0;
			while(i<format.length()){
				int p=format.find_first_of('-',i);
				p=p==-1?format.length():p;
				F.push_back(std::stoi(format.substr(i,p-i)));
				i=p+1;
			}
			cout<<"Case #"<<k<<":";
			solve();
		}
	}
	return 0;
}