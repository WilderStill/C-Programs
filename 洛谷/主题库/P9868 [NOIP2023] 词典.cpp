#include<bits/stdc++.h>
#define M 3690
using namespace std;
int n,m,a[M],minn;
char tmp[M],s[M][M],minc[M],mx[M],t2[M];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	memset(a,-1,sizeof(a));
	scanf("%d%d",&n,&m);
	scanf("%s",s[1]);
	strcpy(minc,s[1]);
	strcpy(t2,s[1]);
	sort(t2,t2+m,cmp);
	strcpy(mx,t2);
	minn=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%s",s[i]);
		if(strcmp(s[i],minc)<=0)strcpy(minc,s[i]),minn=i;
		strcpy(t2,s[i]);
		sort(t2,t2+m,cmp);
		if(strcmp(t2,mx)<=0)strcpy(mx,t2);
	}
	a[minn]=1;
	//printf("%s\n",mx);
	for(int i=1;i<=n;i++)
	{
		strcpy(tmp,s[i]);
		sort(tmp,tmp+m);
		if(a[i]!=-1)continue;
		a[i]=strcmp(tmp,mx)<=0?1:0;
	}
	for(int i=1;i<=n;i++)printf("%d",a[i]);
	return 0;
}
