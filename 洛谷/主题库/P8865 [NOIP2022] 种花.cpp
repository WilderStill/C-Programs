#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long ansc,ansf,c,f;
int sum[1010][1010],id,T,n,m,cnt1c,cnt1f;
char mp[1010][1010];
int main()
{
	scanf("%d%d",&T,&id);
	while(T--)
	{
		memset(sum,0,sizeof sum);
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>mp[i][j];
			for(int i=1;i<=n;++i)
				for(int j=m-1;j>=1;--j)
				{
					if(mp[i][j]=='1')sum[i][j]=-1;
					else if(mp[i][j+1]=='0')sum[i][j]=sum[i][j+1]+1;
				}
		for(int j=1;j<m;++j)
		{
			cnt1c=cnt1f=0;
			for(int i=1;i<=n;++i)
			{
				if(!~sum[i][j]){cnt1f=cnt1c=0;continue ;}
				ansc=(ansc+1ll*sum[i][j]*cnt1c)%mod;
				ansf=(ansf+cnt1f)%mod;
				cnt1f=(cnt1f+1ll*sum[i][j]*cnt1c)%mod;
				cnt1c+=max(0,sum[i-1][j]);
			}
		}
		printf("%lld %lld\n",(c*ansc)%mod,(f*ansf)%mod);
		ansc=ansf=0;
	}
	return 0;
}
