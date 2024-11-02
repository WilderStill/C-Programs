#include<bits/stdc++.h>
#define int long long
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
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
}
struct node
{
	int c,mul;
	bool operator <(const node b)const{return c==b.c?mul>b.mul:c<b.c;}
}p[300010];
int dg[1000010];
signed main()
{
	//file();
    int n=read(),m=read();
    for(int i=1;i<=n;++i)p[i]={read(),read()*read()};
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i)
    {
        if(i>1&&p[i].c==p[i-1].c)continue;
        for(int j=p[i].c;j<=m;j+=p[i].c)dg[j]=max(dg[j],j/p[i].c*p[i].mul);
    }
    int maxn=dg[1];
    for(int i=2;i<=m;++i)
    {
        if(dg[i]>maxn)maxn=dg[i];
        else dg[i]=maxn;
    }
    int k=read();
    for(int i=1;i<=k;++i)
    {
        int pos=upper_bound(dg+1,dg+m+1,read()*read())-dg;
        write(pos>m?-1:pos),putchar(' ');
    }
    return 0;
}
