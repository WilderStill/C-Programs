#include<iostream>
#include<string.h>
#include<stdio.h>
#define lowbit(x) (x)&(-x)
using namespace std;
int syh[1<<20],no[20][20],tno[400][20][20],tno2[400][20][20];
char tsol[400][20][20],sol[20][20];
void update(int x,int y,int v)
{
	sol[x][y]=v+'A';
	for(int i=0;i<16;++i)
	{
		no[x][i]&=(~(1<<v));
		no[i][y]&=(~(1<<v));
	}
	int blox=x-x%4,bloy=y-y%4;
	for(int i=0;i<4;++i) 
		for(int j=0;j<4;++j)
			no[blox+i][bloy+j]&=(~(1<<v));
	no[x][y]=1<<v;
}
void goback(int len)
{
	memcpy(no,tno[len],sizeof(tno[len]));
	memcpy(sol,tsol[len],sizeof(tsol[len]));
}
bool dfs(int blcnt)
{
	if(!blcnt)return 1;
	int cnt=blcnt;
	memcpy(tno[cnt],no,sizeof(no));
	memcpy(tsol[cnt],sol,sizeof(sol));
	for(int i=0;i<16;++i) 
		for(int j=0;j<16;++j)
		{
			if(sol[i][j]=='-')
			{
				if(!no[i][j])
				{
					goback(cnt);
					return 0;
				}
				if(__builtin_popcount(no[i][j])==1)
				{
					blcnt--;
					update(i,j,syh[no[i][j]]);
				}
			}
		}
	for(int i=0;i<16;++i)
	{
		int dg=0,choice=(1<<16)-1,col=0;
		for(int j=0;j<16;++j)
		{
			choice&=(~(dg&no[i][j]));
			dg|=no[i][j];
			if(sol[i][j]!='-')col|=no[i][j];
		}
		if(dg!=(1<<16)-1)
		{
			goback(cnt);
			return 0;
		}
		while(choice)
		{
			int tmp=lowbit(choice);
			if(!(col&tmp))
			{
				blcnt--;
				for(int j=0;j<16;++j)
				{
					if(no[i][j]&tmp)
					{
						update(i,j,syh[tmp]);
						break;
					}
				}
			} 
			choice-=tmp;
		}
	}
	for(int i=0;i<16;++i)
	{
		int dg=0,choice=(1<<16)-1,col=0;
		for(int j=0;j<16;++j)
		{
			choice&=(~(dg&no[j][i]));
			dg|=no[j][i];
			if(sol[j][i]!='-')col|=no[j][i];
		}
		if(dg!=(1<<16)-1)
		{
			goback(cnt);
			return 0;
		}
		while(choice)
		{
			int tmp=lowbit(choice);
			if(!(col&tmp))
			{
				blcnt--;
				for(int j=0;j<16;++j)
				{
					if(no[j][i]&tmp)
					{
						update(j,i,syh[tmp]);
						break;
					}
				}
			} 
			choice-=tmp;
		}
	}
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			int xl=i*4,xr=xl+4,yl=j*4,yr=yl+4;
			int dg=0,choice=(1<<16)-1,col=0;
			for(int p=xl;p<xr;++p)
			{
				for(int q=yl;q<yr;++q)
				{
					choice&=(~(dg&no[p][q]));
					dg|=no[p][q];
					if(sol[p][q]!='-')col|=no[p][q];
				}
			}
			if(dg!=(1<<16)-1)
			{
				goback(cnt);
				return 0;
			}
			while(choice)
			{
				int tmp=lowbit(choice);
				if(!(col&tmp))
				{
					blcnt--;
					for(int p=xl;p<xr;++p)
					{
						for(int q=yl;q<yr;++q)
						{
							if(no[p][q]&tmp)
							{
								update(p,q,syh[tmp]);
								break;
							}
						} 
					}
				} 
				choice-=tmp;
			}
		}
	}
	if(!blcnt)return 1;
	int minn=16,resx,resy,dg;
	for(int i=0;i<16;++i)
	{
		for(int j=0;j<16;++j)
		{
			if(sol[i][j]=='-')
			{
				if(__builtin_popcount(no[i][j])<minn)
				{
					minn=__builtin_popcount(no[i][j]);
					resx=i,resy=j;
					dg=no[i][j];
				}
			}
		}
	}
	memcpy(tno2[cnt],no,sizeof(no));
	while(dg)
	{
		int tmp=syh[lowbit(dg)];
		memcpy(no,tno2[cnt],sizeof(tno2[cnt]));
		update(resx,resy,tmp);
		if(dfs(blcnt-1)) return 1;
		dg-=lowbit(dg);
	}
	goback(cnt);
	return 0;
}
int main()
{
	int T=1;
	for(int i=0;i<16;++i)syh[1<<i]=i;
	while(scanf("%s",sol[0])!=EOF)
	{
		for(int i=0;i<16;++i) 
			for(int j=0;j<16;++j) 
				no[i][j]=(1<<16)-1;
		for(int i=1;i<16;++i)scanf("%s",sol[i]);
		int blcnt=0;
		for(int i=0;i<16;++i) 
			for(int j=0;j<16;++j) 
			{
				if(sol[i][j]=='-')++blcnt;
				else update(i,j,sol[i][j]-'A');
			}
		dfs(blcnt);
		for(int i=0;i<16;++i)printf("%s\n",sol[i]);
		if(T)puts("");
	}
    return 0;
}
