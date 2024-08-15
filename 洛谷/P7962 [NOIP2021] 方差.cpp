#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
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
inline bool cmp(int x,int y){return x>y;}
int n,a[10010],p[10010];
ll ans=INF;
mt19937 mt(time(0));
int main()
{
	//freopen("variance.in","r",stdin);
	//freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),p[i]=a[i]-a[i-1];
	while((double)clock()/CLOCKS_PER_SEC<0.985)
	{
		int mid=mt()%n+1;
		random_shuffle(p+2,p+n+1);
		sort(p+2,p+mid+1,cmp);
		sort(p+mid+1,p+n+1);
		int nsum=0;
		for(int i=1;i<=n;++i)a[i]=a[i-1]+p[i],nsum+=a[i];
		ll res=0;
		for(int i=1;i<=n;++i)res+=1ll*(a[i]*n-nsum)*(a[i]*n-nsum);
		ans=min(ans,res);
	}
	write(ans/n);
    return 0;
}

