#include<bits/stdc++.h>
#define p 20091119
using namespace std;
char s[114];
int bit[114],len,f[2][114],tmp[114],tot;
int check()
{
    for(int i=tot,j=(len>>1)+(len&1);i&&j;--i,--j)
	{
        if(tmp[i]>bit[j])return 0;
        if(tmp[i]<bit[j])return 1;
    }
    return 1;
}
int dfs(int n,bool is_max)
{
    if(n==(len>>1))
	{
        if(!is_max) return 1;
        return check();
    }
    if(~f[is_max][n])return f[is_max][n];
    int ans=0,m=is_max?bit[n]:9;
    for(int i=0;i<=m;++i)
	{
		if(n!=len||i)
		{
			tmp[++tot]=i;
	        ans=(ans+dfs(n-1,is_max&&i==bit[n]))%p;
	        --tot;
		}
    }
    f[is_max][n]=ans;
    return ans;
}
int solve()
{
    for(int i=1;i<=len;++i)bit[i]=s[len-i+1]-'0';
    int ans=0;
    for(int i=len-1;i;--i)
	{
        int cos=9;
        for(int j=i-1;j>(i>>1);j--)cos=(cos*10)%p;
        ans=(ans+cos)%p;
    }
    ans=(ans+dfs(len,1))%p;
    return ans;
}
int main()
{
	memset(f,-1,sizeof(f));
    scanf("%s",s+1);
    len=strlen(s+1);
    printf("%d",solve());
    return 0;
}
