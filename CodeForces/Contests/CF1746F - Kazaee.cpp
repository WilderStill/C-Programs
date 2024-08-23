#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define M 300010
#define T 40
#define ll long long
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
int tr[T][M],a[M];
map<int,ll>hsh;
mt19937 dgsyh(time(0));
void modify(int x,int v)
{
	ll S=hsh[a[x]];
	for(int id=0;id<T;++id)
		if(S>>id&1)
			for(int i=x;i<M;i+=lowbit(i))
				tr[id][i]+=v;
}
int query(int id,int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[id][i];
	return res; 
}
int main()
{
	int n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(!hsh.count(a[i]))hsh[a[i]]=dgsyh();
		modify(i,1);
	}
	for(int p=1;p<=q;++p)
	{
		int op=read();
		if(op==1)
		{
			int i=read(),x=read();
			if(!hsh.count(x))hsh[x]=dgsyh();
			modify(i,-1);
			a[i]=x;
			modify(i,1);
		}
		else
		{
			int l=read(),r=read(),k=read();
			bool fg=1;
			for(int i=0,x;i<T;++i)
				if((query(i,r)-query(i,l-1))%k)
				{
					fg=0;
					break;
				}
			puts(fg?"YES":"NO");
		}
	}
}
