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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int mod=1000000007;
int f[1000010],c[1000010],id[1000010];
int main()
{
	int n=read(); 
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		c[i]=read();
		f[i]=f[i-1];
		if(id[c[i]]>0&&id[c[i]]<i-1)(f[i]+=f[id[c[i]]])%=mod;
		id[c[i]]=i;
	}
	write(f[n]);
	return 0;
}

