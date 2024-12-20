#include<bits/stdc++.h>
#define ll long long
#define M 100005
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
    putchar(x%10+48);
    return;
}
int n,blen,tot,blo[M],L[M],R[M];
ll mx,mn,num[M],mk[M];
vector<int>v[M];
inline void update(int p)
{
	v[p].clear();
	for(int i=L[p];i<=R[p];++i)v[p].emplace_back(num[i]);
	sort(v[p].begin(),v[p].end());
} 
inline void modify(int pl,int pr,ll x) 
{
	int l=blo[pl],r=blo[pr];
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)num[i]+=x;
		update(l);
		return;
	}
	for(int i=pl;i<=R[l];++i)num[i]+=x;
	update(l);
	for(int i=l+1;i<r;++i)mk[i]+=x; 
	for(int i=L[r];i<=pr;++i)num[i]+=x;		
	update(r);
	return;
}
inline ll query(int pl,int pr,ll k)
{
	int l=blo[pl],r=blo[pr];
	ll res=-2e9;
	if(l==r)
	{
		for(int i=pl;i<=pr;++i)if(num[i]+mk[blo[i]]<k)res=max(res,num[i]+mk[blo[i]]);
		return res==-2e9?-1:res;
	}
	for(int i=pl;i<=R[l];++i)if(num[i]+mk[blo[i]]<k)res=max(res,num[i]+mk[blo[i]]);
	for(int i=l+1;i<r;++i)
	{
		auto st=v[i].begin(),ed=v[i].end()-1;
		if(*st+mk[i]>=k)continue;
		if(*ed+mk[i]<k)
		{
			res=max(res,*ed+mk[blo[i]]);
			continue;
		}
		res=max(res,*(lower_bound(v[i].begin(),v[i].end(),k-mk[i])-1)+mk[i]);
	}
	for(int i=L[r];i<=pr;++i)if(num[i]+mk[blo[i]]<k)res=max(res,num[i]+mk[blo[i]]);
	return res==-2e9?-1:res;
}
int main()
{
	n=read();
	blen=243;
	for(int i=1;i<=n;++i)
	{
		num[i]=read();
		mn=min(mn,num[i]),mx=max(mx,num[i]);
		blo[i]=(i-1)/blen+1;
		L[i]=(i-1)*blen+1,R[i]=i*blen;
		v[blo[i]].emplace_back(num[i]);
	}
	for(int i=1;i<=blo[n];++i)sort(v[i].begin(),v[i].end());
	for(int i=1,op,l,r,k;i<=n;++i)
	{
		op=read(),l=read(),r=read(),k=read();
		if(op==1)write(query(l,r,k)),puts("");
		else modify(l,r,k);
	}
	return 0;
}
