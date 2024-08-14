#include<bits/stdc++.h>
using namespace std;
int st[50005][20];
int n,m;
map<int,int> dict;
void build_st()
{
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int RMQ(int l,int r)
{
	int k;
	for(k=0;1<<(k+1)<=(r-l+1);k++);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int y;
		scanf("%d%d",&y,&st[i][0]);
		dict[y]=i;
	}
	build_st();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&y,&x);
		if(y>=x)
		{
			printf("false\n");
			continue;
		}
		bool kx=dict.count(x),ky=dict.count(y),f;
		if(!kx&&!ky)
		{
			printf("maybe\n");
			continue;
		}
		int xx,yy;
		map<int,int>::iterator itx,ity;
		ity=dict.lower_bound(y);
		itx=dict.lower_bound(x);
		if(ity==dict.end())
		{
			printf("maybe\n");
			continue;
		}
		yy=ity->second;
		if(itx==dict.end())xx=dict.size()+1;
		else xx=itx->second;
		if(!ky) yy--;
		int tmp=0;
		if(yy+1<=xx-1) tmp=RMQ(yy+1,xx-1);
		if(!ky) f=tmp<st[xx][0];
		else if(!kx) f=st[yy][0]>tmp;
		else f=st[yy][0]>=st[xx][0]&&st[xx][0]>tmp;
		if(ky&&kx&&yy-xx==y-x)
		{
			if(f) printf("true\n");
			else printf("false\n");
		}
		else
		{
			if(f) printf("maybe\n");
			else printf("false\n");
		}
	}
	return 0;
}
