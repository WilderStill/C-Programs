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
char a[11451411],b[11451411],ans[11451411];
int main()
{
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	reverse(b+1,b+m+1);
	int x=0,y=0,turn=n;
	for(int i=1;i<=n;++i)
	{
		if(a[x+1]>=b[y+1]){turn=i-1;break;}
		if(i&1)ans[i]=a[++x];
		else ans[i]=b[++y];
	}
	x=n/2+1+(n&1);
	y=n/2+1;
	for(int i=n;i>turn;--i)
	{
		if((turn+(n-i+1))&1)ans[i]=a[--x];
		else ans[i]=b[--y];
	}
	for(int i=1;i<=n;++i)putchar(ans[i]);
	return 0;
}

