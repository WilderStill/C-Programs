#include<bits/stdc++.h>
using namespace std;
map<string,bool>vis;
map<string,int>st;
string a,b,dict[30][2];
int t=1,k=2;
int ans=0x3f3f3f3f;
void dfs(string x,int step)
{
	if(step>k)return;
	if(x==b)
	{
		ans=min(ans,step);
		return;
	}
	if(vis[x])if(step>=st[x])return;
	vis[x]=1,st[x]=step;
	int pos=0;
	string now;
	for(int i=1;i<=t;++i)
	{
		pos=-1;
		while(1)
		{
			pos=x.find(dict[i][0],pos+1);
			if(pos==-1)break;
			now=x;
			now.erase(pos,dict[i][0].length());
			now.insert(pos,dict[i][1]);
			dfs(now,step+1);
		}
	}
}
int main()
{
	cin>>a>>b;
	while(cin>>dict[t][0]>>dict[t][1])t++;--t;
	while(ans==0x3f3f3f3f)
	{
		dfs(a,0);
		vis.clear(),st.clear();
		++k;
		if(k>10)break;
	}
	if(ans==0x3f3f3f3f)puts("NO ANSWER!");
	else printf("%d",ans);
	return 0;
} 
