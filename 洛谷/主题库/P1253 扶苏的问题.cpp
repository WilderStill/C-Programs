#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int blen,tot,L[100010],R[100010],cv[100010],blo[1000010];
ll num[1000010],mk[100010],mx[100010];
inline void update(int p)
{
	if(cv[p])
	{
		for(int i=L[p];i<=R[p];++i)num[i]=cv[p];
		cv[p]=0;
	}
	if(mk[p])
	{
		for(int i=L[p];i<=R[p];++i)num[i]+=mk[p];
		mk[p]=0;
	}
}
inline void cover(int pl,int pr,int x)
{
	int l=blo[pl],r=blo[pr];
	update(l);
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)num[i]=x;
		mx[l]=-2e18;
		for(int i=L[l];i<=R[r];++i)mx[l]=max(mx[l],num[i]);
		return;
	}
	update(r);
	for(int i=pl;i<=R[l];++i)num[i]=x;
	mx[l]=-2e18;
	for(int i=L[l];i<=R[l];++i)mx[l]=max(mx[l],num[i]);
	for(int i=l+1;i<r;++i)mk[i]=0,cv[i]=x,mx[i]=x;
	for(int i=L[r];i<=pr;++i)num[i]=x;
	mx[r]=-2e18;
	for(int i=L[r];i<=R[r];++i)mx[r]=max(mx[r],num[i]);
	return;
}
inline void modify(int pl,int pr,ll x)
{
	int l=blo[pl],r=blo[pr];
	bool fg=x<0;
	update(l);
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)
		{
			num[i]+=x;
			if(!fg)mx[l]=max(mx[l],num[i]);
		}
		if(fg)
		{
			mx[l]=-2e18;
			for(int i=L[l];i<=R[r];++i)mx[l]=max(mx[l],num[i]);
		}
		return;
	}
	update(r);
	for(int i=pl;i<=R[l];++i)
	{
		num[i]+=x;
		if(!fg)mx[l]=max(mx[l],num[i]);
	}
	if(fg)
	{
		mx[l]=-2e18;
		for(int i=L[l];i<=R[l];++i)mx[l]=max(mx[l],num[i]);
	}
	for(int i=l+1;i<r;++i)mk[i]+=x,mx[i]+=x;
	for(int i=L[r];i<=pr;++i)
	{
		num[i]+=x;
		if(!fg)mx[r]=max(mx[r],num[i]);
	}
	if(fg)
	{
		mx[r]=-2e18;
		for(int i=L[r];i<=R[r];++i)mx[r]=max(mx[r],num[i]);
	}
	return;
}
inline ll query(int pl,int pr)
{
	int l=blo[pl],r=blo[pr];
	ll res=-2e18;
	update(l);
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)res=max(res,num[i]);
		return res;
	}
	update(r);
	for(int i=pl;i<=R[l];++i)res=max(res,num[i]);
	for(int i=l+1;i<r;++i)res=max(res,mx[i]);
	for(int i=L[r];i<=pr;++i)res=max(res,num[i]);
	return res;
}
int main()
{
	int n=read(),m=read();
	if(n>=10000)blen=sqrt(n)/4;
	else blen=sqrt(n);
	tot=(n-1)/blen+1;
	for(int i=1;i<=n;++i)num[i]=read(),blo[i]=(i-1)/blen+1;
	for(int i=1;i<=tot;++i)
	{
		L[i]=(i-1)*blen+1;
		R[i]=min(i*blen,n);
		mx[i]=-2e18;
		for(int j=L[i];j<=R[i];++j)mx[i]=max(mx[i],num[j]);
	}
	for(int i=1;i<=m;++i)
	{
		int op=read(),l=read(),r=read();
		if(op==1)
		{
			int x=read();
			cover(l,r,x);
		}
		if(op==2)
		{
			int x=read();
			modify(l,r,x);
		}
		if(op==3)
		{
			write(query(l,r));
			putchar(10);
		}
	}
	return 0;
}
