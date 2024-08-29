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
int n,a[200010];
inline bool check(int x)
{	
	auto zzh=[](int x,int del,int v){return a[x]<=v&&a[x+del]<=v;};
	auto zzx=[](int x,int del,int v){return a[x]>v&&a[x+del]>v;};
	if(zzh(n,-1,x)||zzh(n,1,x))return 0;
	if(zzx(n,-1,x)||zzx(n,1,x))return 1;
	for(int i=1;i<n-1;++i)
	{
		if(zzh(n+i,1,x)||zzh(n-i,-1,x))return 0;
		if(zzx(n+i,1,x)||zzx(n-i,-1,x))return 1;
	}
	return a[1]>x;
}
int main()
{
	n=read();
	for(int i=1;i<(n<<1);++i)a[i]=read();
	int l=1,r=(n<<1)-1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	write(l);
	return 0;
}
