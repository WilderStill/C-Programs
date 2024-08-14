#include<bits/stdc++.h>
#define M 1000100
#define ll long long
using namespace std;
const ll base=998244353;
char s[M];
int n,p[M],lst[M],pre[M][27],suf[M][27];
ll ans,v[27],lt[M][27],rt[M][27];
unordered_map<ll,int>mp;
int main()
{
	srand(time(0));
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=26;++i)p[i]=i,v[i]=rand()*rand();
	for(int i=1;i<=n;++i)
	{
		int c=s[i]-'a'+1;
		lst[c]=i;
		for(int j=1;j<=26;++j)
			if(p[j]==c)
			{
				for(int k=j;k;--k)p[k]=p[k-1];
				p[1]=c;
				break;
			}
		for(int j=1;j<=26;++j)pre[i][j]=lst[p[j]];
	}
	for(int i=1;i<=26;++i)p[i]=i,lst[i]=0;
	for(int i=n;i;--i)
	{
		int c=s[i]-'a'+1;
		lst[c]=i;
		for(int j=1;j<=26;++j)
			if(p[j]==c)
			{
				for(int k=j;k;--k)p[k]=p[k-1];
				p[1]=c;
				break;
			}
		for(int j=1;j<=26;++j)suf[i][j]=lst[p[j]];
	}
	ll res=0;
	for(int i=1;i<=n;++i)
	{
		int c=s[i]-'a'+1;
		ll cur=0;
		for(int j=1;j<=26;++j)
		{
			if(!suf[i][j])break;
			cur+=v[s[suf[i][j]]-'a'+1];
			rt[i][j]=cur*base+res-(i-1)/j*cur;
		}
		cur=0,res+=v[c];
		for(int j=1;j<=26;++j)
		{
			if(!pre[i][j])break;
			cur+=v[s[pre[i][j]]-'a'+1];
			lt[i][j]=cur*base+res-i/j*cur;
		}
	}
	for(int j=1;j<=26;++j)
	{
		for(int i=n;i;--i)
		{
			if(lt[i][j])++mp[lt[i][j]];
			if(rt[i][j])ans+=mp[rt[i][j]];
		}
		mp.clear();
	}
	printf("%lld",ans);
	return 0;
}
