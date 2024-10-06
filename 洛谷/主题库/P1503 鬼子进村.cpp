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
bool vis[500010];
stack<int>st;
int main()
{
    int n=read(),m=read();
    vis[0]=vis[n+1]=1;
    for(int i=1;i<=m;++i)
	{
		char op[2];int x;
        scanf("%s",op);
        if(op[0]=='D')
		{
            vis[x=read()]=1;
            st.push(x);
        }
		if(op[0]=='R')
		{
            if(!st.empty())
			{
                vis[st.top()]=0;
                st.pop();
            }
        }
		if(op[0]=='Q')
		{
            int x=read(),res=0;
            if(!vis[x])
			{
                for(int p=x;!vis[p];++p)++res;
            	for(int p=x-1;!vis[p];--p)++res;
            }
            write(res),puts("");
        }
    }
    return 0;
}

