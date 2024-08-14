#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p=998244353;
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
ll f[510][2010],a[110][2010],sum[110],ans=1;
int main()
{
	//freopen("meal.in","r",stdin);
	//freopen("meal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=read(),(sum[i]+=a[i][j])%=p;
	for(int i=1;i<=n;++i)(ans*=sum[i]+1)%=p;(ans+=p-1)%=p;
	for(int i=1;i<=m;i++)
	{
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int j=1;j<=n;++j)
			for(int k=0;k<=((j-1)<<1);++k)
				(f[j][k]+=f[j-1][k]*(sum[j]-a[j][i]+p))%=p,(f[j][k+1]+=f[j-1][k])%=p,(f[j][k+2]+=f[j-1][k]*a[j][i])%=p;
		for(int j=n+1;j<=(n<<1);++j)(ans-=(f[n][j]-p))%=p;
	}
	write(ans);
    return 0;
}
