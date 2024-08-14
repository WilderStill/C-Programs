//Coding By SYH_msd Isn't it?

#include<bits/stdc++.h>
#define dg 0x3f3f3f3f
#define nizaidushenme "nizhegedugou"
#define nizhegedugou "nizaidushenme"
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
int syh_msd[4444][4444],maxsyh_msd[4444][4444],minsyh_msd[4444][4444],maxmaxsyh_msd[4444][4444],minminsyh_msd[4444][4444];
int maxq[4444],minq[4444],dgmaxup,dgmaxdn,dgminup,dgmindn;
void syh_msd_test_1(int a,int b)
{
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			printf("%d ",maxsyh_msd[i][j]);
		}
		puts("");
	}
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			printf("%d ",minsyh_msd[i][j]);
		}
		puts("");
	}
}
void syh_msd_test_2(int a,int b)
{
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			printf("%d ",maxmaxsyh_msd[i][j]);
		}
		puts("");
	}
	for(int i=1;i<=a;++i)
	{
		for(int j=1;j<=b;++j)
		{
			printf("%d ",minminsyh_msd[i][j]);
		}
		puts("");
	}
}
int main()
{
	int a=read(),b=read(),n=read();
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			syh_msd[i][j]=read();
	for(int i=1;i<=a;++i)
	{
		dgmaxup=dgmaxdn=dgminup=dgmindn=maxq[1]=minq[1]=1;
		for(int j=2;j<=b;++j)
		{
			while(syh_msd[i][j]>=syh_msd[i][maxq[dgmaxdn]]&&dgmaxup<=dgmaxdn)dgmaxdn--;
			while(syh_msd[i][j]<=syh_msd[i][minq[dgmindn]]&&dgminup<=dgmindn)dgmindn--;
			maxq[++dgmaxdn]=minq[++dgmindn]=j;
			while(j-maxq[dgmaxup]>=n)dgmaxup++;
			while(j-minq[dgminup]>=n)dgminup++;
			if(j>=n)maxsyh_msd[i][j-n+1]=syh_msd[i][maxq[dgmaxup]],minsyh_msd[i][j-n+1]=syh_msd[i][minq[dgminup]];
		}
	}
//	syh_msd_test_1(a,b);
	for(int i=1;i<=b-n+1;++i)
	{
		dgmaxup=dgmaxdn=dgminup=dgmindn=maxq[1]=minq[1]=1;
		for(int j=2;j<=a;++j)
		{
			while(maxsyh_msd[j][i]>=maxsyh_msd[maxq[dgmaxdn]][i]&&dgmaxup<=dgmaxdn)dgmaxdn--;
			while(minsyh_msd[j][i]<=minsyh_msd[minq[dgmindn]][i]&&dgminup<=dgmindn)dgmindn--;
			maxq[++dgmaxdn]=minq[++dgmindn]=j;
			while(j-maxq[dgmaxup]>=n)dgmaxup++;
			while(j-minq[dgminup]>=n)dgminup++;
			if(j>=n)maxmaxsyh_msd[j-n+1][i]=maxsyh_msd[maxq[dgmaxup]][i],minminsyh_msd[j-n+1][i]=minsyh_msd[minq[dgminup]][i];
		}
	}
//	syh_msd_test_2(a,b);
	int syh_msd_ans=dg;
	for(int i=1;i<=a-n+1;++i)
		for(int j=1;j<=b-n+1;++j)
			syh_msd_ans=min(syh_msd_ans,maxmaxsyh_msd[i][j]-minminsyh_msd[i][j]);
	write(syh_msd_ans);
//	puts("");
//	printf(nizhegedugou);
//	printf(",");
//	printf(nizaidushenme);
	return 0;
}
