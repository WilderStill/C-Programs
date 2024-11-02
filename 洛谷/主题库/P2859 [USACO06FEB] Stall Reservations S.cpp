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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const int INF=0x3f3f3f3f;
struct node
{
	int l,r,id;
	bool operator<(node b){return l<b.l;}
}p[2000010];
int pos[2000010],dg[2000010],res[2000010];
int main()
{
	//file();
	int n=read(),maxr=-1,ans=-1,sum=0;
	for(int i=1,l,r;i<=n;++i)
	{
    	p[i]={l=read(),r=read(),i};
    	++pos[l],--pos[r+1];
    	maxr=max(maxr,r);
	}
	sort(p+1,p+n+1);
    for(int i=1;i<=maxr;++i)
	{
    	sum+=pos[i];
    	ans=max(ans,sum);
	}
	write(ans),puts("");
	for(int i=1;i<=n;++i)
		for(int j=1;j<=ans;++j)
		    if(res[j]<p[i].l)
		    {
		        res[j]=p[i].r;
				dg[p[i].id]=j;
				break;
			}
	for(int i=1;i<=n;++i)write(dg[i]),puts("");
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}

