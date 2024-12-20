#include<bits/stdc++.h>
#define ll long long
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct Magnet
{
	int m,p;
	ll r,dis;
}mg[250004];
queue<int>q;
inline bool syh(Magnet a,Magnet b){return a.m<b.m;}
inline bool shr(Magnet a,Magnet b){return a.dis<b.dis;}
int n,x_0,y_0,ans,blen,blo[250004],l[1004],r[1004];
ll mmg[1004];
bool vis[250004];
int main()
{
	x_0=read(),y_0=read(),mg[0].p=read(),mg[0].r=read(),n=read();
	blen=sqrt(n);
	mg[0].r*=mg[0].r,mg[0].m=2e9,mg[0].dis=0;
	for(int i=1,x,y;i<=n;++i)
	{
		x=read(),y=read(),mg[i].m=read(),mg[i].p=read(),mg[i].r=read();
		mg[i].r*=mg[i].r;
		mg[i].dis=1ll*(x-x_0)*(x-x_0)+1ll*(y-y_0)*(y-y_0);
	}
	sort(mg+1,mg+n+1,shr);
	for(int i=1;i<=n;++i)blo[i]=(i-1)/blen+1;
	for(int i=1;i<=blen;++i)l[i]=(i-1)*blen+1,r[i]=i*blen;
	if(r[blen]<n)l[blen+1]=r[blen]+1,r[++blen]=n;
	for(int i=1;i<=blen;++i)
	{
		mmg[i]=mg[r[i]].dis;
		sort(mg+l[i],mg+r[i]+1,syh);
	}
	q.push(0);
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		for(int i=1;i<=blen;++i)
		{
			if(mmg[i]>mg[t].r)
			{
				for(int j=l[i];j<=r[i];++j)
					if(!vis[j]&&mg[j].dis<=mg[t].r&&mg[j].m<=mg[t].p)
					{
						++ans;
						q.push(j);
						vis[j]=1;
					}
				break;
			}
			else
			{
				for(;l[i]<=r[i]&&mg[l[i]].m<=mg[t].p;++l[i])
				{
					if(!vis[l[i]])
					{
						++ans;
						q.push(l[i]);
						vis[l[i]]=1;
					}
				}
			}
		}
	}
	write(ans);
	return 0;
}
