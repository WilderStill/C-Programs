#include <bits/stdc++.h>
#define M 114514
using namespace std;
char s[M],t[M];
int lens,lent,nxt[M],f[M],dp[M];
bool check(int x)
{
    for(int j=1;j<=lent;++j)
        if(s[x-j+1]!=t[lent-j+1]&&s[x-j+1]!='?')return 0;
    return 1;
}
int main()
{
    scanf("%s%s",s+1,t+1);
    lens=strlen(s+1);
	lent=strlen(t+1);
    for(int now=2,cur=0;now<=lent;++now)
	{
        while(cur>0&&t[cur+1]!=t[now])cur=nxt[cur];
        cur+=(t[cur+1]==t[now]);
        nxt[now]=cur;
    }
    for(int i=1;i<=lens;++i)
	{
        f[i]=f[i-1];
        if(check(i))
		{
            dp[i]=f[i-lent]+1;
            for(int j=nxt[lent];j;j=nxt[j])dp[i]=max(dp[i],dp[i-lent+j]+1);
            f[i]=max(f[i],dp[i]);
        }
    }
    printf("%d",f[lens]);
    return 0;
}
