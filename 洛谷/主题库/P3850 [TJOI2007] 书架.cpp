#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
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
map<int,string>mp;
int tot;
vector<int>v;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		string s;cin>>s;
		mp[++tot]=s;
		v.push_back(tot);
	}
	int m=read();
	for(int i=1;i<=m;++i)
	{
		
		string s;cin>>s;
		int pos=read();
		mp[++tot]=s;
		v.insert(v.begin()+pos,tot);
	}
	int q=read();
	for(int i=1;i<=q;++i)cout<<mp[v[read()]],puts("");
	return 0;
}

