#include<bits/stdc++.h>
#define ll long long
#define setm(x) x.a[1][1]=1,x.a[2][2]=1,x.a[3][3]=1
#define muld(x,y) x=x*y;
#define M 11451411
ll n,k,p,len[M],f[M],hd[M],vis[M];
using namespace std;
inline ll read()
{
	register ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void print(ll x)
{
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
struct Matrix
{
    ll a[4][4];
    Matrix(){memset(a,0,sizeof a);}
    Matrix operator*(const Matrix &b) const {
        Matrix res;
		for(register int i=1;i<=3;++i)
			for(register int k=1;k<=3;++k)
            	for(register int j=1;j<=3;++j)
                	res.a[i][j]=((res.a[i][j]+a[i][k]*b.a[k][j])+p)%p;
        return res;
    }
}ans,base1,base2;
inline void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	register ll t=x;
	x=y;
	y=t-a/b*y;
}
inline ll getInv(ll a,ll t)
{
	if(__gcd(a,t)!=1)return -1;
	register ll x,y;
	exgcd(a,t,x,y);
	return (x%t+t)%t;
}
inline ll plen(ll lim)
{
	register ll res=0;
	for(register int i=1;i<lim;++i) res+=len[hd[i]];
	return res;
}
inline void init()
{
	memset(len,M,sizeof(len));
	f[1]=1;f[2]=1;
    base1.a[1][1]=1;base1.a[1][2]=1;
	base1.a[2][1]=1;base1.a[3][3]=1;
	base2.a[1][1]=1;base2.a[1][2]=1;
	base2.a[2][1]=1;base2.a[3][3]=1;
	base2.a[3][1]=-1;
    ans.a[1][1]=1;ans.a[1][3]=1;
}
inline Matrix qpow(ll x,Matrix base)
{
	Matrix res;
	setm(res);
    while(x)
    {
        if(x&1)res=res*base;
        base=base*base;
        x>>=1;
    }
    return res;
}
int main()
{
	n=read(),k=read(),p=read();
    if(n==1||n==2)
    {
    	puts("1");
    	return 0;
	}
    init();
    for(register ll i=3;;++i)
	{
		f[i]=(f[i-1]+f[i-2])%k;
		if(f[i]%k==1&&len[1]>(M*114))len[1]=i;
		if(f[i]==1&&f[i-1]==1)break;
		register ll inv=getInv(f[i],k);
		if(inv!=-1)len[inv%k]=min(len[inv%k],i);
	}
    register ll now=1,tot=0,kcnt=0;
	bool fg=0;
	while(1)
	{
		hd[++kcnt]=now;
		vis[now]=kcnt;
		if(len[now]>=(M*114))
		{
			tot+=plen(kcnt);
			fg=1;
			break;
		}
		now=(now*f[len[now]-1])%k;
		if(vis[now])
		{
			tot+=plen(vis[now]);
			break;
		}
	}
	--len[1];
	if(n<=tot)
	{
		--n;
		for(register int i=1;i<vis[now];++i)
		{
			if(n>=len[hd[i]])
			{
				muld(ans,qpow(len[hd[i]]-1,base1)*base2);
				n-=len[hd[i]];
			}
			else
			{
				muld(ans,qpow(n,base1));
				print(ans.a[1][1]);
				exit(0);
			}
		}
	}
	else
	{
		n-=tot;
		for(register int i=1;i<vis[now];++i)muld(ans,qpow(len[hd[i]]-1,base1)*base2);
		if(fg)
		{
			muld(ans,qpow(n,base1));
			print(ans.a[1][1]);
			return 0;
		}
		else
		{
			register ll slen=0;
			Matrix tmp;
			setm(tmp);
			for(register int i=vis[now];i<=kcnt;++i)
			{
				muld(tmp,qpow(len[hd[i]]-1,base1)*base2);
				slen+=len[hd[i]];
			}
			muld(ans,qpow(n/slen,tmp));
			n%=slen;
			for(register int i=vis[now];i<=kcnt;++i)
			{
				if(n>=len[hd[i]])
				{
					muld(ans,qpow(len[hd[i]]-1,base1)*base2);
					n-=len[hd[i]];
				}
				else
				{
					muld(ans,qpow(n,base1));
					print(ans.a[1][1]);
					return 0;
				}
			}
		}
	}
	return 0;
}
