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
	freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
}
int pos[1000010],dis[1000010],f[1000010];
bool isStone[1000010];
int main()
{
	//file();
	int l=read(),s=read(),t=read(),m=read(),ans=0x3f3f3f3f;
	for(int i=1;i<=m;++i)pos[i]=read();
	if(s==t)
	{
		int cnt=0; 
        for(int i=1;i<=m;++i)
		{
			if(pos[i]%s)continue;
			++cnt;
		}
        write(cnt);
		return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
	}
	sort(pos+1,pos+m+1);
	memset(f,0x3f,sizeof f);
	dis[m+1]=min(l-pos[m],100);
	l=f[0]=0;
	for(int i=1;i<=m;++i)l+=(dis[i]=min(pos[i]-pos[i-1],90)),isStone[l]=1;
	for(int i=1;i<=l+t-1;++i)
		for(int j=s;j<=t;++j)
			if(i>=j)f[i]=min(f[i],f[i-j]+isStone[i]); 
	for(int i=l;i<=l+t-1;++i)ans=min(ans,f[i]);
	write(ans);
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
