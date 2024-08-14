#include<bits/stdc++.h>
#define M 11451411
#define int long long
using namespace std;
struct boat
{
	int t,k;
};
int n,t,k,x,ans,p[M];
boat tmp;
queue<boat> b;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&t,&k);
		while(!b.empty())
		{
			tmp=b.front();
			if(abs(tmp.t-t)>=86400)
			{
				p[tmp.k]--;
				if(!p[tmp.k])ans--;
                b.pop();
                continue;
			}
			break;
		}
		for(int j=1;j<=k;j++)
        {
            scanf("%lld",&x);
            tmp.k=x;
			tmp.t=t;
            b.push(tmp);
            p[x]++;
            if(p[x]==1)ans++;
        }
		printf("%lld\n",ans);
	}
	return 0;
}
