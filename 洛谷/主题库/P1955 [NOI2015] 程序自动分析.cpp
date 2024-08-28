#include<bits/stdc++.h>
#define M 1000010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
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
struct node
{
    int x,y,op;
}co[M];
int fa[M],raw[M*2];
bool cocmp(node s,node yh)
{
	return s.op>yh.op;
}
int findfa(int x){return x==fa[x]?x:fa[x]=findfa(fa[x]);}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),tot=0;
		for(int i=1;i<=n;++i)
		{
			co[i].x=read(),co[i].y=read(),co[i].op=read();
            raw[++tot]=co[i].x,raw[++tot]=co[i].y;
        }
        sort(raw+1,raw+tot+1);
        tot=unique(raw+1,raw+tot+1)-raw-1;
        for(int i=1;i<=n;++i)
		{
           co[i].x=lower_bound(raw,raw+tot+1,co[i].x)-raw;
           co[i].y=lower_bound(raw,raw+tot+1,co[i].y)-raw;   
        }
        for(int i=1;i<=tot;++i)fa[i]=i;
        sort(co+1,co+n+1,cocmp);
        for(int i=1;i<=n;++i)
		{
            int xfa=findfa(co[i].x),yfa=findfa(co[i].y);
            if(co[i].op)fa[xfa]=yfa;
			else if(xfa==yfa)
			{
                puts("NO");
                goto syh;
            }
        }
        puts("YES");
syh:	;
	}
    return 0;
}
