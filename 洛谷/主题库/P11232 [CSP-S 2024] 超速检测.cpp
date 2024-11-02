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
	freopen("detect2.in","r",stdin);
	freopen("detect.out","w",stdout);
}
const int INF=0x3f3f3f3f;
struct cars
{
	int d,v,a;
}car[1000010];
struct segment
{
	int l,r;
	bool operator<(segment b){return l==b.l?r>b.r:l<b.l;}
}tp[1000010];
int n,m,L,V,pos[1000010];
bool syh[1000010];
inline bool check(int x,int y)
{
	if(car[x].d>pos[y])return 0;
	return car[x].v*car[x].v+2*car[x].a*(pos[y]-car[x].d)>V*V;
}
int main()
{
	//file();
	int T=read();
	while(T--)
	{
		memset(syh,0,sizeof syh);
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;++i)car[i]={read(),read(),read()};
		for(int i=1;i<=m;++i)pos[i]=read();
		int cnt=0;
		for(int i=1;i<=n;++i)
			if(car[i].d<=pos[m])
			{
				int tl,tr;
				if(car[i].a>=0)
				{
					tr=m;
					if(!check(i,tr))continue;
					int l=1,r=m;
					while(l<=r)
					{
						int mid=l+r>>1;
						if(check(i,mid))tl=mid,r=mid-1;
						else l=mid+1;
					}
				} 
				else
				{
					tl=lower_bound(pos+1,pos+m+1,car[i].d)-pos;
					if(!check(i,tl))continue;
					int l=tl,r=m;
					while(l<=r)
					{
						int mid=l+r>>1;
						if(check(i,mid))tr=mid,l=mid+1;
						else r=mid-1;
					}
				}
				tp[++cnt]={tl,tr};
			}
		sort(tp+1,tp+cnt+1);
		int td=INF;
		for(int i=cnt;i;--i)
			if(tp[i].r<td)syh[i]=1,td=tp[i].r;
		int res=0,tpos=-1;
		for(int i=1;i<=cnt;++i)
			if(syh[i]&&tp[i].l>tpos)
				++res,tpos=tp[i].r;
		write(cnt),putchar(' '),write(m-res),puts("");
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
