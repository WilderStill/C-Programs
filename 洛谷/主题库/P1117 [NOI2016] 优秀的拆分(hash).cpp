#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
const int DG=2000010;
const ll base=127,mod=1e9+7;
char s[DG];
ll w[DG],p[DG],a[DG],b[DG];
int n,pos;
inline int gethash(int l,int r){return ((w[r]-w[l-1]*p[r-l+1])%mod+mod)%mod;}
inline int getlcp(int pl,int pr)
{
	int l=1,r=pos,res=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(gethash(pl-mid+1,pl)==gethash(pr-mid+1,pr))l=mid+1,res=mid;
		else r=mid-1;
	}
	return res;
}
inline int getlcs(int pl,int pr)
{
	int l=1,r=n-pr+1,res=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(gethash(pl,pl+mid-1)==gethash(pr,pr+mid-1))l=mid+1,res=mid;
		else r=mid-1;
	}
	return res;
}
signed main()
{
	int T=read();
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		scanf("%s",s+1);
		n=strlen(s+1);  
		p[0]=1;
		for(int i=1;i<=n;++i)
		{
			p[i]=p[i-1]*base%mod;
			w[i]=(w[i-1]*base+s[i]-'a')%mod;
		}
		for(int l=1;l<=n;++l)
		{
			pos=l;
			for(int i=l;i<=n;i+=l)
			{
	        	int kl=i,kr=i+l;
	        	int lcp=getlcp(kl,kr),lcs=getlcs(kl,kr);
	        	int hd=max(kr-lcp+l,kr),tl=min(kr+lcs-1,kr+l-1);
				if(hd<=tl)
				{
					++a[hd],++b[hd-l*2+1];
					--a[tl+1],--b[tl-l*2+2];
				}
			}
		}
		for(int i=1;i<=n;++i)a[i]+=a[i-1],b[i]+=b[i-1]; 
	    ll ans=0;
		for(int i=1;i<n;++i)ans+=a[i]*b[i+1]; 
	    write(ans),puts("");
	}
	return 0;
}
