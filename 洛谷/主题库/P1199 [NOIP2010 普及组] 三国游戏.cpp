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
int mp[510][510];
int main()
{
    int n=read();
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            mp[j][i]=mp[i][j]=read();
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        sort(mp[i]+1,mp[i]+n+1);
        ans=max(ans,mp[i][n-1]);
    }
    write(1),puts("");
    write(ans),puts("");
    return 0;
}
