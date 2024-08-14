#include<bits/stdc++.h>
#define ll __int128
#define mod (1<<30)
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
int n,type,x,y,z,m,b[40000010],a[40000010],q[40000010],pre[40000010],p[100010],l[100010],r[100010];
long long sum[40000010];
ll ans;
int main()
{
	//freopen("partition.in","r",stdin);
	//freopen("partition.out","w",stdout);
	n=read(),type=read();
	if(type==0)for(int i=1;i<=n;++i)a[i]=read();
	else
	{
		x=read(),y=read(),z=read(),b[1]=read(),b[2]=read(),m=read();
		for(int i=1;i<=m;++i)p[i]=read(),l[i]=read(),r[i]=read();p[0]=0;
		for(int i=3;i<=n;++i)b[i]=(1ll*x*b[i-1]+1ll*y*b[i-2]+z)%mod;
		for(int i=1;i<=m;++i)
			for(int j=p[i-1]+1;j<=p[i];++j)
				a[j]=b[j]%(r[i]-l[i]+1)+l[i];
	}
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int hd=1,tl=1;
	q[1]=0;
	for(int i=1;i<=n;++i)
	{
    	while(hd<tl&&2*sum[q[hd+1]]-sum[pre[q[hd+1]]]<=sum[i])++hd; 
		pre[i]=q[hd];
    	while(hd<tl&&2*sum[q[tl]]-sum[pre[q[tl]]]>=2*sum[i]-sum[pre[i]])--tl;
		q[++tl]=i;
	}
	int pos=n;
	ll t=1;
	while(t) 
	{
		t=sum[pos]-sum[pre[pos]];
		ans+=t*t;
		pos=pre[pos];
	}
	write(ans);
	return 0;
}
