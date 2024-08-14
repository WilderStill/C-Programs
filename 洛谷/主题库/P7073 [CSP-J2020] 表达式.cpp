#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 1000100
#define mod 1000000007 
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
string s;
int n,q,tp,level[M],l[M],r[M],val[M],syh[M];
int dfs(int rt,int v)
{
    level[rt]^=v;
    if(rt<=n)return level[rt];
    int ls=dfs(l[rt],val[l[rt]]^v),rs=dfs(r[rt],val[r[rt]]^v);
    if(level[rt]==2)
	{
        if(!ls)syh[r[rt]]=1;
        if(!rs)syh[l[rt]]=1;
        return ls&rs;
    }
	else
	{
        if(ls)syh[r[rt]]=1;
        if(rs)syh[l[rt]]=1;
        return ls|rs;
    }
}
void dfs2(int rt)
{
    if(rt<=n)return;
    syh[l[rt]]|=syh[rt];
    syh[r[rt]]|=syh[rt];
    dfs2(l[rt]);
    dfs2(r[rt]);
}
int main()
{
    getline(cin,s);
    tp=n=read();
    for(int i=1;i<=n;++i)level[i]=read();
    stack<int>stk;
    for(int i=0;s[i];i+=2)
	{
        if(s[i]=='x')
		{
            int x=0;
            while(s[++i]!=' ')x=(x<<3)+(x<<1)+(s[i]^'0');
            i--;
            stk.push(x);
        }
		else if(s[i]=='&')
		{
            int x=stk.top();stk.pop();
            int y=stk.top();stk.pop();
            stk.push(++tp);
            level[tp]=2;
            l[tp]=x;
            r[tp]=y;
        }
		else if(s[i]=='|')
		{
            int x=stk.top();stk.pop();
            int y=stk.top();stk.pop();
            stk.push(++tp);
            level[tp]=3;
            l[tp]=x;
            r[tp]=y;
        }
		else if(s[i]=='!')val[stk.top()]^=1;
    }
    int ans=dfs(tp,val[tp]);
    dfs2(tp);
    q=read();
    for(int i=1;i<=q;++i)write(syh[read()]?ans:ans^1),putchar('\n');
    return 0;
}

