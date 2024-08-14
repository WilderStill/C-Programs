#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 1145
using namespace std;
string s;
int f[M][M];
int main()
{
	cin.tie(0);
	cin>>s;
	memset(f,INF,sizeof(f));
	for(int i=1;i<=s.size();++i)f[i][i]=1;
	for(int len=1;len<s.size();++len) 
		for(int i=1;i+len<=s.size();++i)
		{
			if(s[i-1]==s[i+len-1])f[i][i+len]=min(f[i+1][i+len],f[i][i+len-1]);
			else for(int j=i;j<i+len;++j)f[i][i+len]=min(f[i][i+len],f[i][j]+f[j+1][i+len]);
		}
	printf("%d",f[1][s.size()]);
	return 0;
}
