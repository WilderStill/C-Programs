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
int Primetot,ans,bt,Prime[11451411];
bool isPrime[11451411],dg[11415411];
void Eulerphi(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!isPrime[i])Prime[++Primetot]=i;
		for(int j=1;j<=Primetot&&i*Prime[j]<=n;j++)
		{
			isPrime[Prime[j]*i]=1;
			if(i%Prime[j]==0)break;
		}
	}
}
int n;
void dfs(int x,int y,int id)
{
    if(x>bt)
	{
        bt=x;
        ans=y;
    }
    if(x==bt&&ans>y)ans=y;
    if(id>Primetot)return; 
    for(int i=1;i<=Primetot;++i)
	{
        if(y*Prime[id]>n)break;
        dfs(x*(i+1),y*Prime[id],id+1);
        y*=Prime[id];
    }
}
signed main()
{
	n=read();
	Eulerphi(1400000);
	dfs(1,1,1);
	write(ans);
	return 0;
}

