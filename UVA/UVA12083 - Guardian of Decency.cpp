#include<bits/stdc++.h>
#define M 1145
using namespace std;
vector<int> mp[M];
int vis[M],match[M],n,m,T,ans;
struct students
{
	int ht;
	char sex;
	string mc,hb;
}sb[M];
bool found(int x)
{
	for(auto i:mp[x])
	{
		if(vis[i])continue;
		vis[i]=1;
		if(!match[i]||found(match[i]))
		{ 
			match[i]=x; 
			return 1;
		}
	} 
	return 0;
}
int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;
		for(int i=0;i<M;i++)mp[i].clear();
		memset(match,0,sizeof(match));
		cin>>n;
		for(int i=1;i<=n;i++)cin>>sb[i].ht>>sb[i].sex>>sb[i].mc>>sb[i].hb;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if((abs(sb[i].ht-sb[j].ht)>40)||(sb[i].sex==sb[j].sex)||(sb[i].mc!=sb[j].mc)||(sb[i].hb==sb[j].hb))continue;
				mp[i].push_back(j);
				mp[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(found(i))ans++;
		}
		cout<<(n-(ans>>1))<<"\n";	
	}
	return 0;
}
