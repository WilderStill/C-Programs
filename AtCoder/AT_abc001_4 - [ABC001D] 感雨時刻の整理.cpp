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
struct node
{
	int s,t;
	bool operator<(node b)
	{
		return s<b.s;
	}
}inv[10000000];
void output(int l,int r)
{
	if(l<10)write(0);
	if(l<100)write(0);
	if(l<1000)write(0);
	write(l),putchar('-');
	if(r<10)write(0);
	if(r<100)write(0);
	if(r<1000)write(0);
	write(r),putchar('\n');
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		inv[i]={read(),read()};
		if(inv[i].s%10>0&&inv[i].s%10<5)inv[i].s-=inv[i].s%10;
		if(inv[i].s%10>5)inv[i].s=inv[i].s-inv[i].s%10+5;
		if(inv[i].t%10>0&&inv[i].t%10<5)inv[i].t=inv[i].t-inv[i].t%10+5;
		if(inv[i].t%10>5)
		{
			inv[i].t=inv[i].t-inv[i].t%10+10;
			if(inv[i].t%100==60)inv[i].t=inv[i].t+40;
		}
	}		
	sort(inv+1,inv+n+1);
	int l=inv[1].s,r=inv[1].t;
	for(int i=2;i<=n;++i)
	{
		if(r<inv[i].s)
		{
			output(l,r);
			l=inv[i].s,r=inv[i].t;
			continue;
		}
		if(r>=inv[i].s&&r<=inv[i].t)
		{
			r=inv[i].t;
			continue;
		}		
	}
	output(l,r);
	return 0;
}
