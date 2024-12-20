#include<bits/stdc++.h>
#define M 100010
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
int n,blen,num[M],blo[M],mk[M];
inline void update(int p)
{
    if(mk[p]==-1)return;
    for(int i=(p-1)*blen+1;i<=p*blen;++i)num[i]=mk[p];
    mk[p]=-1;
}
inline void query(int pl,int pr,int k)
{
	int l=blo[pl],r=blo[pr],res=0;
    update(l);
    if(l==r)
    {
    	for(int i=pl;i<=pr;++i)
		{
			if(num[i]==k)++res;
			else num[i]=k;
		}
    	write(res);
    	return;
	}
	update(r);
	for(int i=pl;i<=l*blen;++i)
	{
		if(num[i]==k)++res;
		else num[i]=k;
	}
    for(int i=l+1;i<r;++i)
    {
    	if(mk[i]==-1)
		{
			for(int j=(i-1)*blen+1;j<=i*blen;++j)
			{
				if(num[j]==k)++res;
				else num[j]=k;
			}
			mk[i]=k;
		}
        else
		{
			if(mk[i]==k)res+=blen;
			else mk[i]=k;
		}
	}
	for(int i=(r-1)*blen+1;i<=pr;++i)
	{
		if(num[i]==k)++res;
		else num[i]=k;
	}
    write(res);
    return;
}
int main()
{
	n=read();
	blen=sqrt(n);
	for(int i=1;i<=n;++i)
	{
		num[i]=read();
		blo[i]=(i-1)/blen+1;
		mk[i]=-1;
	}
	for(int i=1;i<=n;++i)
	{
		int l=read(),r=read(),c=read();
		query(l,r,c);
		puts("");
	}
	return 0;
}
