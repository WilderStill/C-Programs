#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;
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
ll n,q,m,a[1000005],f[1000005][26],s[8200],syh[100005],buk[1000005],tr[4000005];
void modify(int x,int v)
{
	if(!x)return;
	for(ll i=x;i<=n;i+=lowbit(i))tr[i]+=v;
}
ll query(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}
int main()
{
	n=read(),q=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=0;i<m;++i)f[i][0]=i%m*i%m*i%m;
	for(int i=1;i<=20;++i)
		for(int j=0;j<m;++j)
			f[j][i]=f[f[j][i-1]][i-1];
	int pw[8200];
	for(int i=0;i<=13;++i)pw[1<<i]=i;
	while(q--)
	{
		ll op=read(),l=read(),r=read();
		if(op==2)modify(l,1),modify(r+1,-1);
		else
		{
			int len=r-l+1;
			if(len>13)puts("Yuno");
			else
			{
				for(int i=l;i<=r;++i) 
				{
					int val=a[i],x=query(i);
					for(int j=20;~j;--j)if((x>>j)&1)val=f[val][j];
					syh[i-l]=val+1;
				}
				bool fg=0;
				for(int S=1;S<(1<<len);++S)
				{
					int pos=S&(S-1),del=S-pos;
					s[S]=s[pos]+syh[pw[del]];
					if(++buk[s[S]]>=2) 
					{
						fg=1;
						break;
					}
				}
				puts(fg?"Yuno":"Yuki");
				for(int S=1;S<(1<<len);++S)buk[s[S]]=0,s[S]=0;
			}
		}
	}
	return 0;
}
