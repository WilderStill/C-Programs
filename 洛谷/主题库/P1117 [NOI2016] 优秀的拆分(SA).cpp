#include<bits/stdc++.h>
#define int long long
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
inline void write(int x)
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
const int DG=60010;
struct Suffix_Array
{
	int n,m,rk[DG],sa[DG],lkz[DG],h[DG],c[DG],lg[DG],st[DG][25];
	char s[DG];
	inline void init()
	{
	    memset(h,0,sizeof h);
	    memset(sa,0,sizeof sa);
	    memset(rk,0,sizeof rk);
	    memset(st,0,sizeof st);
	    memset(lkz,0,sizeof lkz);
	    lg[0]=lg[1]=0;
		for(int i=2;i<DG;++i)lg[i]=lg[i>>1]+1;
		return;
	}
	inline void tsort()
	{
		memset(c,0,sizeof (int)*(m+1));
		for(int i=1;i<=n;++i)++c[rk[i]];
		for(int i=1;i<=m;++i)c[i]+=c[i-1];
		for(int i=n;i;--i)sa[c[rk[lkz[i]]]--]=lkz[i];
		return;
	}
	inline void buildsa()
	{
		for(int i=1;i<=n;++i)lkz[i]=i,rk[i]=s[i];
		m='z',tsort();
		for(int w=1,p=0;w<n;m=p,w<<=1,p=0)
		{
			for(int i=n;i>n-w;--i)lkz[++p]=i;
			for(int i=1;i<=n;++i)if(sa[i]>w)lkz[++p]=sa[i]-w;
			tsort();
			swap(lkz,rk);
			rk[sa[1]]=1;
			for(int i=2,p=1;i<=n;++i)rk[sa[i]]=lkz[sa[i]]==lkz[sa[i-1]]&&lkz[sa[i]+w]==lkz[sa[i-1]+w]?p:++p;
		}
		for(int i=1;i<=n;++i)rk[sa[i]]=i;
		for(int i=1,k=0;i<=n;++i)
		{
			if(!rk[i])continue;
			if(k)--k;
			while(i+k<=n&&sa[rk[i]-1]+k<=n&&s[i+k]==s[sa[rk[i]-1]+k])++k;
			h[rk[i]]=k;
		}
		return;
	}
	inline void buildst()
	{
    	for(int i=1;i<=n;++i)st[i][0]=h[i]; 
		for(int j=1;(1<<j)<=n;++j)
		    for(int i=1;i+(1<<j)-1<=n;++i)
		        st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		return;
	}
	inline int getlcp(int l,int r)
	{
		l=rk[l],r=rk[r];
		if(l>r)swap(l,r);++l;
		int d=lg[r-l+1]; 
		return min(st[l][d],st[r-(1<<d)+1][d]);
	}
}sa,as;
int a[DG],b[DG];char s[DG];
signed main()
{
	int T=read();
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		sa.init(),as.init();
		scanf("%s",s+1);
		int n=strlen(s+1);
		sa.n=as.n=n;
		for(int i=1;i<=n;++i)as.s[i]=s[n-i+1],sa.s[i]=s[i];    
	    sa.buildsa(),as.buildsa();
	    sa.buildst(),as.buildst();
	    for(int l=1;l<=(n>>1);++l)
	    	for(int i=l;i<=n;i+=l)
			{
	        	int sal=i,sar=i+l,asl=n-sar+2,asr=n-sal+2;
	        	int lcp=min(sa.getlcp(sal,sar),l);
	        	int lcs=min(as.getlcp(asl,asr),l-1);
	        	if(lcp+lcs>=l)
				{
		        	--b[sal+lcp-l+1],++b[sal-lcs];
		        	++a[sar-lcs+l-1],--a[sar+lcp]; 
	    		}
			}
		for(int i=1;i<=n;++i)a[i]+=a[i-1],b[i]+=b[i-1]; 
	    int ans=0;
		for(int i=1;i<n;++i)ans+=a[i]*b[i+1]; 
	    write(ans),puts("");
	}
	return 0;
}
