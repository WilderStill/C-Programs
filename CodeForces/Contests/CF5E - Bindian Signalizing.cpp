#include<bits/stdc++.h>
#define M 1000100
using namespace std;
int n,maxn=-M,pos,syh,raw[M],val[M],h[M];
bool vis[M];
stack<int>s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&raw[i]);
		if(raw[i]>maxn)
			maxn=raw[i],pos=i;
	}
	for(int i=pos;i<=n;++i)h[++syh]=raw[i];
	for(int i=1;i<=pos;++i)h[++syh]=raw[i];
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		val[i]=1;
		while(!s.empty()&&h[s.top()]<=h[i])
		{
			ans+=val[s.top()];
			if(h[s.top()]==h[i])val[i]+=val[s.top()];
			s.pop();
		}
		if(!s.empty())
		{
			++ans;
			if(s.top()==1)vis[i]=1;
		}
		s.push(i);
	}
	maxn=0;
	for(int i=n;i>1;--i)
	{
		if(!vis[i]&&h[i]^h[1]&&h[i]>=maxn)++ans;
		maxn=max(h[i],maxn);
	}
	printf("%lld",ans);
	return 0;
}
