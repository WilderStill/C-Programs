#include<bits/stdc++.h>
#define M 501
using namespace std;
string s;
int n,d[M],f[M];
string str_num(int l,int r)
{
	string res=s.substr(l,r-l+1);
	while(res.size()>1&&res[0]=='0')res.erase(0,1);
	return res; 
} 
bool numcmp(string a,string b)
{
	if(a.size()!=b.size())return a.size()<b.size();
	return a<b;
}
bool allcmp(int l1,int r1,int l2,int r2)
{
	return numcmp(str_num(l1,r1),str_num(l2,r2));
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.size(); 
	s=' '+s;
	for(int i=1;i<=n;++i)
	{
        d[i]=1;
        for(int j=i;j>=1;--j)
            if(allcmp(d[j-1],j-1,j,i))
			{
				d[i]=j;
				break;
			}
    }
    f[d[n]]=n;
	int pos=d[n]-1;
	for(;pos&&s[pos]=='0';--pos)f[pos]=n;
	for(int i=pos;i;--i)
		for(int j=d[n]-1;j>=i;--j)
			if(allcmp(i,j,j+1,f[j+1]))
			{
				f[i]=j;
				break;
			}
	bool fg=0;
	for(int i=1;i<=n;i=f[i]+1)
	{
		if(fg)cout<<',';fg=1;
		cout<<s.substr(i,f[i]-i+1);
	}
	return 0;
}
