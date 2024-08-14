#include<bits/stdc++.h>
#define M 30010
using namespace std;
int n,m1,m2,Primetot,ans=0x3f3f3f3f,Prime[M],pprime[M],cprime[M];
bool isPrime[M],fg,here;
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
void Eulerphi(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!isPrime[i])Prime[++Primetot]=i;
		for(int j=1;j<=Primetot&&i*Prime[j]<=n;++j)
		{
			isPrime[Prime[j]*i]=1;
			if(i%Prime[j]==0)break;
		}
	}
}
int main()
{
    Eulerphi(30001);
	n=read(),m1=read(),m2=read();
    for(int i=1;m1>1;++i)
    {
        if(m1%Prime[i])continue;
        while(!(m1%Prime[i])){pprime[i]+=m2;m1/=Prime[i];}
    }
    for(int i=1;i<=n;++i)
    {
        int cell=read(),now=0;
		bool syh=1;
        memset(cprime,0,sizeof cprime);
        for(int j=1;j<=Primetot;++j)
        {
            if(cell%Prime[j])continue;
            while(!(cell%Prime[j]))++cprime[j],cell/=Prime[j];
        }
        for(int j=1;j<=Primetot;++j)
        {
            if(pprime[j]&&!cprime[j])syh=0;
            if(pprime[j]&&cprime[j])
                now=max(now,pprime[j]/cprime[j]+(pprime[j]%cprime[j]?1:0));
        }
        if(syh)fg=1,ans=min(now,ans);
    }
    write(fg?ans:-1);
    return 0;
}
