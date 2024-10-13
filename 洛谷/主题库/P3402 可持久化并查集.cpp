#include<bits/stdc++.h>
#include<ext/rope>
#define int unsigned
using namespace std;
using namespace __gnu_cxx;
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
mt19937 dg(time(0));
int f[100010],id[200010],sz[200010];
rope<int>fa[200005];
inline int findfa(int idx,int x){return fa[idx][x]==x?x:findfa(idx,fa[idx][x]);}
inline void merge(int idx,int x,int y)
{
    x=findfa(idx,x),y=findfa(idx,y);
    if(x==y)return;
    if(id[x]>id[y])fa[idx].replace(y,x);
    else
    {
    	if(id[x]==id[y])
		{
			if(sz[x]>sz[y])++id[x];
			else ++id[y];
		}
		if(sz[x]>sz[y])fa[idx].replace(y,x);
		else fa[idx].replace(x,y);		
	}
}
signed main()
{
    int n=read(),m=read();
	f[0]=1;for(int i=1;i<=n;++i)f[i]=i,sz[i]=dg(); 
    fa[0]=rope<int>(f);
    for(int i=1;i<=m;++i)
    {
        int op=read();
        switch(op)
        {
	        case 1:
	        {
	        	fa[i]=fa[i-1];
	            merge(i,read(),read());
	            break;
			}
	        case 2:
	    	{
	        	fa[i]=fa[read()];
	            break;
			}
	        default:
	        {
	        	fa[i]=fa[i-1];
	            write(findfa(i,read())==findfa(i,read()));
	            puts("");
	            break;
			}    
        }
    }
    return 0;
}
