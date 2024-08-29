#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 1145
using namespace std;
string s,t;
int f[M][M],ans[M];
int main()
{
	cin.tie(0);
	cout.tie(0);
	while(cin>>s>>t)
	{
		int n=s.size();
		memset(f,INF,sizeof(f));
		for(int i=1;i<=n;++i)f[i][i]=1;
		for(int len=1;len<n;++len) 
			for(int i=1;i+len<=n;++i)
			{
				if(t[i-1]==t[i+len-1])f[i][i+len]=min(f[i+1][i+len],f[i][i+len-1]);
				else for(int j=i;j<i+len;++j)f[i][i+len]=min(f[i][i+len],f[i][j]+f[j+1][i+len]);
			}
		for(int i=1;i<=n;++i)ans[i]=f[1][i];
        for(int i=1;i<=n;++i)
		{
            if(s[i-1]==t[i-1])ans[i]=min(ans[i],ans[i-1]);
            for(int j=1;j<i;++j)ans[i]=min(ans[i],ans[j]+f[j+1][i]);
        }
        cout<<ans[n]<<'\n';
	}
	return 0;
}
