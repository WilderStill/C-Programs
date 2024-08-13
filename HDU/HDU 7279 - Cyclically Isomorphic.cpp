#include<bits/stdc++.h>
using namespace std;
int T,n,m,q;
string str;
map<int,string>mp;
string mini(string s)
{
	string st=s+s,tmp,ans=s;
	for(int i=0;i<m;++i)
	{
		tmp=st.substr(i,m);
		if(ans>tmp)ans=tmp;
	}
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)cin>>str,mp[i]=mini(str);
		scanf("%d",&q);
		for(int i=1,x,y;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			puts(mp[x]==mp[y]?"Yes":"No");
		}
	}
	return 0;
}

