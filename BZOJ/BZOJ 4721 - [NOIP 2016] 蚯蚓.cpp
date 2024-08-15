#include<bits/stdc++.h>
#define ll long long
#define M 7114514
using namespace std;
bool cmp(int x,int y){return x>y;}
priority_queue<int>ans;
int top,cut1[M],cut2[M],now[M],n,m,q,u,v,t,sum;
int main()
{
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    long double p=1.0*u/v;
    for(int i=1;i<=n;++i)scanf("%d",&now[i]);
    int t1=0,t2=0,h=1,h1=1,h2=1;
    sort(now+1,now+n+1,cmp);
    for(int i=1;i<=m;++i)
	{
        if(h>n)
		{
			if(cut1[h1]>cut2[h2])top=cut1[h1++];
			else top=cut2[h2++];
		}
        else if(now[h]>=cut1[h1]&&now[h]>=cut2[h2])top=now[h++];
        else if(cut1[h1]>=cut2[h2]&&now[h]<=cut1[h1])top=cut1[h1++];
        else top=cut2[h2++];
        top+=sum;sum+=q;
        cut1[++t1]=floor(p*1.0*top)-sum;
		cut2[++t2]=top-floor(p*1.0*top)-sum;
        if(!(i%t))printf("%d ",top);
    }
    puts("");
    for(int i=h;i<=n;++i)ans.push(now[i]);
    for(int i=h1;i<=t1;++i)ans.push(cut1[i]);
    for(int i=h2;i<=t2;++i)ans.push(cut2[i]);
    for(int i=1;ans.size();++i)
	{
        if(!(i%t))printf("%d ",ans.top()+sum);
        ans.pop();
    }
} 
