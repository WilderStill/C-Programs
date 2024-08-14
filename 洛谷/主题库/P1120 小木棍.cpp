#include<bits/stdc++.h>
using namespace std;
const int N=70;
int n,cnt,t,maxn,minn,a[N];
bool ifprint=0; 
void dfs(int res,int sum,int tg,int p)
{
    if(!res)
	{
        printf("%d",tg),ifprint=1;
        return;
    }
    if(ifprint)return;
    if(sum==tg)
	{
        dfs(res-1,0,tg,maxn);
        return;
    }
    for(int i=p;i>=minn;i--)
	{
        if(a[i]&&i+sum<=tg)
		{
            a[i]--;
            dfs(res,sum+i,tg,i);
            a[i]++;
            if(!sum||sum+i==tg) break;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n) ;
    minn=N;
    int value;
    while(n--)
	{
        scanf("%d",&value);
        cnt++;
        a[value]++;
        t+=value;
        maxn=max(maxn,value);
        minn=min(minn,value);
    }
    value=t/2;
    for(int i=maxn;i<=value;i++)
        if(t%i==0)
			dfs(t/i,0,i,maxn);
    if(!ifprint) printf("%d",t);
    return 0;
}
