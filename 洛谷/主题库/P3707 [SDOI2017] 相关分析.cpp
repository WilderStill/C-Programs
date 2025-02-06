#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
inline ll read()
{
	ll x=0,f=1;
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
const ll M=100010,N=1010;
ll blen,tot,L[N],R[N],blo[M];
ld x[M],y[M],mkx[N],mky[N],cvx[N],cvy[N],sumx[N],sumy[N],sumxy[N],sumx2[N];
bool cl[N];
inline void update(int id)
{
	if(cl[id])
	{
		cl[id]=0;
		for(int i=L[id];i<=R[id];++i)x[i]=cvx[id]+i,y[i]=cvy[id]+i;
		cvx[id]=0,cvy[id]=0;
	}
	if(mkx[id]||mky[id])
	{
		int S=mkx[id],T=mky[id];
		for(int i=L[id];i<=R[id];++i)x[i]+=S,y[i]+=T;
		mkx[id]=0,mky[id]=0;
	}
}
inline void modify1(ll pl,ll pr,ld S,ld T)
{
    ll l=blo[pl],r=blo[pr];
    update(l),update(r);
    if(l==r)
    {
        for(ll i=pl;i<=pr;++i)
		{
			sumx2[l]+=2*x[i]*S+S*S;
			sumxy[l]+=S*y[i]+T*x[i]+S*T;
			sumx[l]+=S;
			sumy[l]+=T;
			x[i]+=S;
			y[i]+=T;
		}
        return;
    }
    for(ll i=pl;i<=R[l];++i)
	{
		sumx2[l]+=2*x[i]*S+S*S;
		sumxy[l]+=S*y[i]+T*x[i]+S*T;
		sumx[l]+=S;
		sumy[l]+=T;
		x[i]+=S;
		y[i]+=T;
	}
	for(ll i=l+1;i<r;++i)
	{
		ll bl=R[i]-L[i]+1;
		sumx2[i]+=2*sumx[i]*S+S*S*bl;
		sumxy[i]+=sumx[i]*T+sumy[i]*S+S*T*bl;
		sumx[i]+=S*bl;
		sumy[i]+=T*bl;
		mkx[i]+=S;
		mky[i]+=T;
	}
    for(ll i=L[r];i<=pr;++i)
	{
		sumx2[r]+=2*x[i]*S+S*S;
		sumxy[r]+=S*y[i]+T*x[i]+S*T;
		sumx[r]+=S;
		sumy[r]+=T;
		x[i]+=S;
		y[i]+=T;
	}
    return;
}
inline void modify2(ll pl,ll pr,ld S,ld T)
{
    ll l=blo[pl],r=blo[pr];
    update(l),update(r);
    if(l==r)
    {
        for(ll i=pl;i<=pr;++i)
		{
			sumx2[l]-=x[i]*x[i]-(S+i)*(S+i);
			sumxy[l]-=x[i]*y[i]-(S+i)*(T+i);
			sumx[l]-=x[i]-(S+i);
			sumy[l]+=y[i]-(T+i);
			x[i]=S+i;
			y[i]=T+i;
		}
        return;
    }
    for(ll i=pl;i<=R[l];++i)
	{
		sumx2[l]-=x[i]*x[i]-(S+i)*(S+i);
		sumxy[l]-=x[i]*y[i]-(S+i)*(T+i);
		sumx[l]-=x[i]-(S+i);
		sumy[l]-=y[i]-(T+i);
		x[i]=S+i;
		y[i]=T+i;
	}
	for(ll i=l+1;i<r;++i)
	{
		ll suml=L[i]*(L[i]-1)*(2*L[i]-1)/6,sumr=R[i]*(R[i]+1)*(2*R[i]+1)/6,bl=R[i]-L[i]+1;
		sumx2[i]=bl*S*S+S*(L[i]+R[i])*bl+sumr-suml;
		sumxy[i]=bl*S*T+(S+T)*(L[i]+R[i])*bl/2+sumr-suml;
		sumx[i]=bl*S+(L[i]+R[i])*bl/2;
		sumy[i]=bl*T+(L[i]+R[i])*bl/2;
		cvx[i]=S;
		cvy[i]=T;
		mkx[i]=0;
		mky[i]=0;
		cl[i]=1;
	}
    for(ll i=L[r];i<=pr;++i)
	{
		sumx2[r]-=x[i]*x[i]-(S+i)*(S+i);
		sumxy[r]-=x[i]*y[i]-(S+i)*(T+i);
		sumx[r]-=x[i]-(S+i);
		sumy[r]-=y[i]-(T+i);
		x[i]=S+i;
		y[i]=T+i;
	}
    return;
}
inline ld query(ll pl,ll pr)
{
    ll l=blo[pl],r=blo[pr],len=pr-pl+1;
    update(l),update(r);
    ld resx=0,resy=0,resx2=0,resxy=0;
    if(l==r)
    {
        for(ll i=pl;i<=pr;++i)
        {
        	resx+=x[i];
			resy+=y[i];
			resx2+=x[i]*x[i];
			resxy+=x[i]*y[i];
		}
        return (resxy-resx*resy/len)/(resx2-resx*resx/len);
    }
    else
    {
        for(ll i=pl;i<=R[l];++i)
        {
        	resx+=x[i];
			resy+=y[i];
			resx2+=x[i]*x[i];
			resxy+=x[i]*y[i];
		}
        for(ll i=l+1;i<r;++i)
        {
        	resx+=sumx[i];
			resy+=sumy[i];
			resx2+=sumx2[i];
			resxy+=sumxy[i];
		}
		for(ll i=L[r];i<=pr;++i)
		{
			resx+=x[i];
			resy+=y[i];
			resx2+=x[i]*x[i];
			resxy+=x[i]*y[i];
		}
        return (resxy-resx*resy/len)/(resx2-resx*resx/len);
    }
}
int main()
{
    ll n=read(),m=read();
	blen=sqrt(n);
	tot=(n-1)/blen+1;
    for(ll i=1;i<=n;++i)scanf("%Lf",&x[i]);
    for(ll i=1;i<=n;++i)scanf("%Lf",&y[i]);
    for(ll i=1;i<=tot;++i) 
    {
        L[i]=(i-1)*blen+1,R[i]=i==tot?n:i*blen;
        for(ll j=L[i];j<=R[i];++j)
		{
			blo[j]=i;
			sumx[i]+=x[j];
			sumy[i]+=y[j];
			sumx2[i]+=(x[j]*x[j]);
			sumxy[i]+=(x[j]*y[j]);
		}
    }
    for(ll i=1;i<=m;++i) 
    {
        ll op=read(),l=read(),r=read();
        if(op==1)printf("%.10Lf\n",query(l,r));
        if(op==2)
        {
        	ld S,T;
        	scanf("%Lf%Lf",&S,&T);
        	modify1(l,r,S,T);
		}
        if(op==3)
        {
        	ld S,T;
        	scanf("%Lf%Lf",&S,&T);
        	modify2(l,r,S,T);
		}
    }
    return 0;
}
