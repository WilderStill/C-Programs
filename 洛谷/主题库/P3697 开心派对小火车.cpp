#include<bits/stdc++.h>
#define int long long
#define M 3010
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
int s[M],tp[M],f[M],ans,cnt;
signed main()
{	
	int n=read(),m=read(),k=read(),a=read(),b=read(),c=read(),t=read();
	k-=m;
	for(int i=1;i<=m;++i)s[i]=read()-1;
	s[m+1]=s[m]+1;
	for(int i=1;i<=m&&s[i]*b<=t;++i,++cnt)
	{
		tp[i]=s[i]*b,f[i]=s[i];
		ans+=min((t-tp[i])/a+1,s[i+1]-s[i]);
	}
	for(int i=1;i<=k;++i)
	{
		int maxn=0,pos=0,mnxt=0;
		for(int j=1,nxt;j<=cnt;++j)
		{
			if(f[j]>=s[j+1]||(nxt=(t-tp[j])/a+1)*c+tp[j]>t)continue;
			int res=min((t-nxt*c-tp[j])/a+1,s[j+1]-f[j]-nxt);
			if(res>maxn)maxn=res,pos=j,mnxt=nxt;
		}
		ans+=maxn;
		f[pos]+=mnxt;
		tp[pos]+=mnxt*c;
	}
	write(ans-1);
	puts("");
    return 0;
}
