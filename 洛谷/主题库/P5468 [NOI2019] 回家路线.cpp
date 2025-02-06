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
        x=(x<<1)+(x<<3)+(ch&15);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
typedef double ld; 
const int maxm=1e6+10,maxp=1e5+10,INF=2e18;
int n,m,mt,A,B,C,ans=INF,hd[maxm],tl[maxm],f[maxm];
vector<int>pos[maxm],buk[maxm];
deque<int>q[maxp];
struct train{int x,y,p,q;}tk[maxm];
inline ld X(int i1){return tk[i1].q;}
inline ld Y(int i1){return f[i1]+A*tk[i1].q*tk[i1].q-B*tk[i1].q;}
inline ld k(int i1,int i2)
{
    if(X(i1)==X(i2))return Y(i1)>Y(i2)?INF:-INF;
    return (Y(i2)-Y(i1))/(X(i2)-X(i1));
}
signed main()
{
    n=read(),m=read(),A=read(),B=read(),C=read();
    for(int i=1;i<=m;++i)tk[i]={read(),read(),read(),read()},mt=max(mt,tk[i].q),pos[tk[i].p].emplace_back(i);
    for(int i=1;i<=n;++i)hd[i]=0,tl[i]=-1;
    for(int t=0;t<=mt;++t)
    {
        for(auto&i:buk[t])
        {             
            int y=tk[i].y;
			while(hd[y]<tl[y]&&k(q[y][tl[y]],q[y][tl[y]-1])>=k(q[y][tl[y]],i))--tl[y];
            ++tl[y];
            if(tl[y]>=q[y].size())q[y].emplace_back(i);
			else q[y][tl[y]]=i;
        }
        for(auto&i:pos[t])
        {
            int x=tk[i].x,y=tk[i].y;
            while(hd[x]<tl[x]&&k(q[x][hd[x]],q[x][hd[x]+1])<2.0*A*t)++hd[x];
            if(hd[x]>tl[x]&&x^1)continue;
            int j;
            if(hd[x]>tl[x]&&x==1)j=0;
            else j=q[x][hd[x]];
            f[i]=f[j]+A*(tk[i].p-tk[j].q)*(tk[i].p-tk[j].q)+B*(tk[i].p-tk[j].q)+C;
            buk[tk[i].q].emplace_back(i);
            if(y==n)ans=min(ans,f[i]+tk[i].q);
        }
    }
    write(ans);
    return 0;
}
