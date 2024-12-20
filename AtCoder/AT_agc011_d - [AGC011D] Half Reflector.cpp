#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,pos=1,col[200010];
bool fg=1;
int main()
{
	cin>>n>>k>>s;
	s=" "+s;
	for(int i=1;i<=n;++i)col[i]=s[i]-'A';
	for(int i=1;i<=k;++i)
	{
		if(col[pos]^fg)col[pos]^=1;
		else fg^=1,++pos;
		if(pos>n)pos=1;
	}
	for(int i=pos;i<=n;++i)putchar(col[i]^fg?'A':'B');
	for(int i=1;i<pos;++i)putchar(col[i]^fg?'A':'B');
	return 0;
}
