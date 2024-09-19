#include<bits/stdc++.h>
#define M 2000010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int f[M],pre[M],cl[M][27];
char s[M];
ll ans;
int main()
{
	int n=read();
	scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        int tp=cl[pre[i-1]][s[i]-'a'+1]-1;
        if(~tp)
		{
			pre[i]=pre[tp];
			f[i]=f[tp]+1;
		}
		else pre[i]=i;
        cl[pre[i]][s[i]-'a'+1]=i;
		ans+=f[i];
    }
    write(ans);
    return 0;
}

