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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,h[200010];
unordered_map<string,int>f;
inline int dfs(int pos,int syh)
{
	if(pos==n+1)return 0;
	string s=to_string(pos)+"-dgsyh-id:"+to_string(syh);
	if(f.count(s))return f[s];
	return f[s]=min({n,dfs(pos+1,min(syh,h[pos]))+1,dfs(pos+1,h[pos])+max(h[pos]-syh,0)});
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)h[i]=read();
	write(dfs(1,0));
	return 0;
}
