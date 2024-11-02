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
inline void file()
{
	freopen("icefire.in","r",stdin);
	freopen("icefire.out","w",stdout);
}
int tp[2000010],k[2000010],x[2000010],y[2000010],fire[2000010],ice[2000020],lsh[2000010],op[2000010],cnt;
int main()
{
	int q=read();
	for(int i=1;i<=q;++i)
	{
		op[i]=read();
		if(op[i]==1)tp[i]=read(),x[i]=read(),y[i]=read(),lsh[++cnt]=x[i];
		else k[i]=read();
	}
	sort(lsh+1,lsh+cnt+1);
	cnt=unique(lsh+1,lsh+cnt+1)-lsh-1;
	for(int i=1;i<=q;++i)x[i]=lower_bound(lsh+1,lsh+cnt+1,x[i])-lsh;
	for(int i=1,pos=0,sumf=0,sumi=0;i<=q;++i)
	{
		if(op[i]==1)
		{
			if(tp[i]==1)
			{
				fire[x[i]]+=y[i];
				if(x[i]>=pos)sumf+=y[i];
			}
			else
			{
				ice[x[i]]+=y[i];
				if(x[i]<=pos)sumi+=y[i];
			}
		}
		else
		{
			int syh=k[i];
			if(tp[syh])
			{
				fire[x[syh]]-=y[syh];
				if(x[syh]>=pos)sumf-=y[syh];
			}
			else
			{
				ice[x[syh]]-=y[syh];
				if(x[syh]<=pos)sumi-=y[syh];
			}
		}
		while(pos>1&&min(sumi-ice[pos],sumf+fire[pos-1])>=min(sumi,sumf)&&sumi>sumf)--pos,sumi-=ice[pos+1],sumf+=fire[pos];
		while(pos<cnt&&min(ice[pos+1]+sumi,sumf-fire[pos])>=min(sumi,sumf))++pos,sumi+=ice[pos],sumf-=fire[pos-1];
		if(!sumi||!sumf)
		{
			puts("Peace");
			continue;
		}
		write(lsh[pos]),putchar(' ');
		write(min(sumi,sumf)<<1),puts("");
	}
	return 0;
}
