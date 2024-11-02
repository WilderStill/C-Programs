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
int sum,tp,ind[500010],tind[500010],val[500010];
mt19937 syh(time(0));
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)sum+=(val[i]=syh()%10000);
    for(int i=1;i<=m;++i)
	{
        int u=read(),v=read();
        ind[v]+=val[u];
        tind[v]=ind[v];
        tp+=val[u];
    }
    int q=read();
    for(int i=1;i<=q;++i)
	{
        int op=read();
        switch(op)
        {
        	case 1:
        	{
        		int u=read(),v=read();
	            ind[v]-=val[u];
	            tp-=val[u];
        		break;
			}
			case 2:
        	{
        		int u=read();
	            tp-=ind[u];
	            ind[u]=0;
        		break;
			}
			case 3:
        	{
        		int u=read(),v=read();
	            ind[v]+=val[u];
	            tp+=val[u];
        		break;
			}
			case 4:
        	{
        		int u=read();
            	tp+=tind[u]-ind[u];
            	ind[u]=tind[u];
        		break;
			}
			default:break;
		}
        puts(tp==sum?"YES":"NO");
    }
    return 0;
}
