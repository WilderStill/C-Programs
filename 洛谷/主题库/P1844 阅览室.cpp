#include<bits/stdc++.h>
#define M 114514
#define lar(x) lib[x].ar
#define lk(x) lib[x].k
#define lls(x) lib[x].ls
#define lfg(x,y) lib[x].flag[y]
#define ls(x,y) lib[x].s[y]
#define lt(x,y) lib[x].t[y] 
using namespace std;
int t,n,ans,book[M];
struct nd
{
	int ar,ls,k; 
	int s[10],t[10],flag[10];
}lib[M];
bool cmp(nd x,nd y)
{
	return x.ls==y.ls?x.ar<y.ar:x.ls<y.ls;
}
int main()
{
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&lar(i),&lk(i));
		lar(i)++;
		for(int j=1;j<=lk(i);j++)
			scanf("%d%d",&ls(i,j),&lt(i,j));
		lls(i)=lar(i);
	}
	for(int tm=1;tm<=t;tm++)
	{
		sort(lib+1,lib+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(lls(i)>tm||lar(i)>tm) continue; 
			for(int j=1;j<=lk(i);j++)
			{
				if((book[ls(i,j)]<=tm)&&(!lfg(i,j)))
				{
					ans++;
					lfg(i,j)=1;
					lls(i)=book[ls(i,j)]=tm+lt(i,j);
					break;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
