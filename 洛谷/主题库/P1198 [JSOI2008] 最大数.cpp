#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
inline char readop()
{
	char ch=getchar();
	while(ch!='A'&&ch!='Q')ch=getchar();
	return ch;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
constexpr ll INF=2e18;
int len,blen,blo[200004];
ll D,t,num[200004],mx[200004];
inline void modify(ll x)
{
	while(x<0)x+=D;
	x%=D;
	num[++len]=x;
    blo[len]=(len-1)/blen+1;
    mx[blo[len]]=max(mx[blo[len]],x);
}
inline ll query(int pl,int pr)
{
	int l=blo[pl],r=blo[pr];
    ll res=-INF;
    if(l==r)
    {
    	for(int i=pl;i<=pr;++i)res=max(res,num[i]);
    	return t=res;
	}
    for(int i=pl;i<=l*blen;++i)res=max(res,num[i]);
    for(int i=l+1;i<r;++i)res=max(res,mx[i]);
    for(int i=(r-1)*blen+1;i<=pr;++i)res=max(res,num[i]);
    return t=res;
}
int main()
{
	int M=read();
	D=read();
    blen=sqrt(M);
    for(int i=1;i<=M;++i)
    {        
        char op=readop();
        if(op=='A')
		{
			ll x=read();
			modify(x+t);
		}
        if(op=='Q')
		{
			ll L=read();
			write(query(len-L+1,len));
			putchar(10);
		}
    }
	return 0;
}
