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
int n,h[200010];
inline int solve(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return min(1,h[l]); 
	int res=0,pos=l-1,minn=0x3f3f3f3f; 
	for(int i=l;i<=r;++i)minn=min(minn,h[i]); 
	for(int i=l;i<=r;++i)
	{
		if(h[i]==minn)
		{
			res+=solve(pos+1,i-1);
			pos=i; 
		}
		h[i]-=minn;
	}
	res+=solve(pos+1,r); 
	return min(res+minn,r-l+1); 
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)h[i]=read();
	write(solve(1,n));
	return 0;
}
