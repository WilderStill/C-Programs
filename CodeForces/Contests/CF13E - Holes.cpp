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
int blen,k[200010],cnt[200010],suf[200010],L[200010],R[200010],blo[200010]; 
int main()
{
	int n=read(),m=read();
	blen=sqrt(n);
	for(int i=1;i<=n;++i)
	{
		k[i]=read();
		blo[i]=i/blen+1;
		L[blo[i]]=0x3f3f3f3f;
	}
	for(int i=1;i<=n;++i)L[blo[i]]=min(L[blo[i]],i),R[blo[i]]=max(R[blo[i]],i);
	for(int i=n;i;--i)
	{
		if(i+k[i]>R[blo[i]])	
		{
			cnt[i]=1;
			suf[i]=i+k[i];
		}
		else
		{
			cnt[i]=cnt[i+k[i]]+1;
			suf[i]=suf[i+k[i]];
		}
	}
	for(int i=1,op,x,y;i<=m;++i)
	{
		op=read();
		if(op==1)
		{
			x=read();
			int res=0;
			while(suf[x]<=n)
			{
				res+=cnt[x];
				x=suf[x];
			}
			res+=cnt[x];
			while(x+k[x]<=n)x+=k[x];
			write(x);
			putchar(' ');
			write(res);
			puts("");
		}
		else
		{
			x=read(),y=read();
			k[x]=y;
			for(int i=R[blo[x]];i>=L[blo[x]];--i)
			{
				if(i+k[i]>R[blo[i]])	
				{
					cnt[i]=1;
					suf[i]=i+k[i];
				}
				else
				{
					cnt[i]=cnt[i+k[i]]+1;
					suf[i]=suf[i+k[i]];
				}
			}
		}
	}
	return 0;
}
