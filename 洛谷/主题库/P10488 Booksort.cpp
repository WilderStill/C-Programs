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
int n,a[20],t[20],tmp[20];
void move(int x,int y,int z)
{
	
}
bool dfs(int maxd,int dep)
{
	if(dep>maxd)return 0;
	int tp[20],tmp[20];
	memcpy(tp,a,sizeof a);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			for(int k=j+1;k<=n;++k)
			{
				memset(tmp,0,sizeof tmp);
				int tot=0,val=0;
				for(int l=j+1;l<=k;++l)tmp[++tot]=a[l];
				for(int l=i;l<=j;++l)tmp[++tot]=a[l];
				tot=0;
				for(int l=i;l<=k;++l)a[l]=tmp[++tot]; 
				for(int l=1;l<n;++l)if(a[l+1]!=a[l]+1)++val;
				if(a[n]!=n)++val;
				if(!val)return 1;
				if(3*dep+val<=3*maxd&&dfs(maxd,dep+1))return 1; 
				memcpy(a,tp,sizeof tp);
			}
	return 0;
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)a[i]=t[i]=read();
		bool fg=0;
		for(int i=1;i<n;++i)if(a[i+1]!=a[i]+1)fg=1;
		if(a[n]!=n)fg=1;
		if(!fg)
		{
			puts("0");
			continue;
		}
		fg=0;
		for(int i=1;i<=4;++i)
		{
			if(dfs(i,1))
			{
				printf("%d\n",i);
				fg=1;
				break;
			}
			memcpy(a,t,sizeof t);
		}
		if(!fg)puts("5 or more");
	}
	return 0;
}

