#include<bits/stdc++.h>
#define ll long long
#define M 200010
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
inline void write(ll x)
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
ll num[M];
ll qmax[M][19][3];
inline ll querymax(int l,int r,int id)
{
    int k=log2(r-l+1);
    return max(qmax[l][k][id],qmax[r-(1<<k)+1][k][id]);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
		qmax[i][0][0]=num[i]=read(),qmax[i][0][1]=num[i]-i,qmax[i][0][2]=num[i]+i;
	for(int j=1;j<19;++j)
	    for(int i=0;i+(1<<j)-1<=n;++i)
	        for(int k=0;k<=2;++k)
	            qmax[i][j][k]=max(qmax[i][j-1][k],qmax[i+(1<<(j-1))][j-1][k]);
	int q=read();
	for(int i=1,s,t,j,k;i<=q;++i)
	{
		j=s=read(),k=t=read();
		if(j>k)swap(j,k);
		write(querymax(j,k,0)-1ll*(num[s]<<2ll)-1ll*num[t]+1ll*((querymax(j,k,1)+querymax(j,k,2))<<1ll));
		puts("");
	}
	return 0;
}
