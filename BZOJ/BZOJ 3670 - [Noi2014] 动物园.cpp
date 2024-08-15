#include<bits/stdc++.h>
#define M 1145141
using namespace std;
char s[M];
int nxt[M],len,T;
long long ans,f[M],mod=1000000007;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(nxt,0,sizeof nxt);
		scanf("%s",s);
		len=strlen(s);
		f[0]=0;f[1]=1;ans=1;
        for(int cur=1,now=0;cur<len;cur++)
		{
            while(now>0&&(s[cur]!=s[now]))now=nxt[now];
            now+=(s[cur]==s[now]);
			nxt[cur+1]=now;
			f[cur+1]=f[now]+1;
        }
        for(int cur=1,now=0;cur<len;cur++)
		{
            while(now>0&&(s[cur]!=s[now]))now=nxt[now];
            now+=(s[cur]==s[now]);
            while((now<<1)>(cur+1))now=nxt[now];
            ans=(ans*(f[now]+1ll))%mod;
        }
        printf("%lld\n",ans);
	}
	return 0;
}
