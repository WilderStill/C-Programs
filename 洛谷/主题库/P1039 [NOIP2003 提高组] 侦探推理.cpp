#include<bits/stdc++.h>
using namespace std;
int m,n,p,c[2],ans;
unordered_map<string,int>mp;
string s,name[111];
const string days[7]={"Today is Sunday.","Today is Monday.","Today is Tuesday.","Today is Wednesday.","Today is Thursday.","Today is Friday.","Today is Saturday."};
struct Sentense
{
	int id;
	string s;
}sn[111];
int TorF[111];
inline bool judge(int id,bool fg)
{
	if(~TorF[id])return TorF[id]!=fg;
	else ++c[TorF[id]=fg];
	return (c[0]>n||c[1]>m-n);
}
inline void check(int id,string day)
{
	string tp;
	for(int i=1,ps;i<=p;++i)
	{
		ps=sn[i].s.find("I am guilty.");
		if(~ps)if(judge(sn[i].id,sn[i].id==id))return;
		ps=sn[i].s.find("I am not guilty");
		if(~ps)if(judge(sn[i].id,sn[i].id!=id))return;
		ps=sn[i].s.find(" is guilty.");
		if(~ps)
		{
			tp=sn[i].s;
			tp.erase(ps,11);
			if(judge(sn[i].id,mp[tp]==id))return;
		}
		ps=sn[i].s.find(" is not guilty.");
		if(~ps)
		{
			tp=sn[i].s;
			tp.erase(ps,15);
			if(judge(sn[i].id,mp[tp]!=id))return;
		}
		ps=sn[i].s.find("Today is ");
		if(~ps)if(judge(sn[i].id,sn[i].s==day))return;
	}
	if(ans&&ans!=id)
	{
		puts("Cannot Determine");
		exit(0);
	}
	ans=id;
}
int main()
{
	cin>>m>>n>>p;
	for(int i=1;i<=m;++i)
	{
		cin>>name[i];
		mp[name[i]]=i;
	}
	for(int i=1;i<=p;++i)
	{
		cin>>s;
		s.pop_back();
		sn[i].id=mp[s];
		getline(cin,s);
		s.erase(0,1);
		if(s.back()=='\n'||s.back()=='\r')s.pop_back();
		sn[i].s=s;
	}
	for(int i=1;i<=m;++i)
		for(int j=0;j<7;++j)
		{
			memset(TorF,-1,sizeof TorF);
			c[0]=c[1]=0;
			check(i,days[j]);
		}
	if(!ans)puts("Impossible");
	else puts(name[ans].c_str());
	return 0;
}
