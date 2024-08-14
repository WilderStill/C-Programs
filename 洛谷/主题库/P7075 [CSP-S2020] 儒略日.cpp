#include<bits/stdc++.h>
using namespace std;
const int G400=146097;
const int J4=1461;
int T,G400year[1000010],G400month[10000010],G400day[10000101],Gregory[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
bool isRun(int y)
{
	if(y%4)return 0;
	else
	{
		if(y%100==0)
		{
			if(y%400==0)return 1;
			else return 0;
		}
		else return 1;
	}
}
int main()
{
    G400month[0]=G400day[0]=1;
    for(int i=1;i<G400;++i)
	{
        G400day[i]=G400day[i-1]+1;
		G400month[i]=G400month[i-1];
		G400year[i]=G400year[i-1];
        if(G400day[i]>Gregory[isRun(G400year[i])][G400month[i]])++G400month[i],G400day[i]=1;
        if(G400month[i]>12)++G400year[i],G400month[i]=1;
    }
    scanf("%d",&T);
    while(T--)
	{
		long long n,my;
		scanf("%lld",&n);
		if(n>2299160)
		{
			n-=2159351;
			my=n/G400*400+1200;
			n%=G400;
		}
		else
		{
			my=-4712+n/J4*4;
			n%=J4;
		}
        if(my+G400year[n]>0)printf("%d %d %lld\n",G400day[n],G400month[n],my+G400year[n]);
        else printf("%d %d %lld BC\n",G400day[n],G400month[n],1ll-my-G400year[n]);
    }
}
