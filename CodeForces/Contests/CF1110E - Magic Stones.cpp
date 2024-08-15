#include<bits/stdc++.h>
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
int n,c[100010],t[100010],pc[100010],pt[100010];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<=n;++i)t[i]=read();
	for(int i=1;i<n;++i)pc[i]=c[i+1]-c[i];
	for(int i=1;i<n;++i)pt[i]=t[i+1]-t[i];
	if(c[1]^t[1]||c[n]^t[n])
	{
		puts("No");
		return 0;
	}
	sort(pc+1,pc+n);
	sort(pt+1,pt+n);
	for(int i=1;i<n;++i)
	{
		if(pc[i]^pt[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
    return 0;
}

