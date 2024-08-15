#include<bits/stdc++.h>
#define lowbit(x) (x)&(-x)
using namespace std;
int syh[1<<9],no[9][9],tno[400][9][9],tno2[400][9][9];
char tsol[400][9][9],sol[9][9],rsol[9][9],ans[9][9];
void update(int x,int y,int v)
{
	sol[x][y]=v+'1';
	for(int i=0;i<9;++i)
	{
		no[x][i]&=(~(1<<v));
		no[i][y]&=(~(1<<v));
	}
	int blox=x-x%3,bloy=y-y%3;
	for(int i=0;i<3;++i) 
		for(int j=0;j<3;++j)
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
	for(int i=0;i<9;++i) 
		for(int j=0;j<9;++j)
			if(sol[i][j]=='0')
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
	for(int i=0;i<9;++i)
	{
		int dg=0,choice=(1<<9)-1,col=0;
		for(int j=0;j<9;++j)
		{
			choice&=(~(dg&no[i][j]));
			dg|=no[i][j];
			if(sol[i][j]!='0') col|=no[i][j];
		}
		if(dg!=(1<<9)-1)
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
				for(int j=0;j<9;++j)
					if(no[i][j]&tmp)
					{
						update(i,j,syh[tmp]);
						break;
					}
			} 
			choice-=tmp;
		}
	}
	for(int i=0;i<9;++i)
	{
		int dg=0,choice=(1<<9)-1,col=0;
		for(int j=0;j<9;++j)
		{
			choice&=(~(dg&no[j][i]));
			dg|=no[j][i];
			if(sol[j][i]!='0') col|=no[j][i];
		}
		if(dg!=(1<<9)-1)
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
				for(int j=0;j<9;++j)
					if(no[j][i]&tmp)
					{
						update(j,i,syh[tmp]);
						break;
					}
			} 
			choice-=tmp;
		}
	}
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			int xl=i*3,xr=xl+3,yl=j*3,yr=yl+3;
			int dg=0,choice=(1<<9)-1,col=0;
			for(int p=xl;p<xr;++p)
				for(int q=yl;q<yr;++q)
				{
					choice&=(~(dg&no[p][q]));
					dg|=no[p][q];
					if(sol[p][q]!='0')col|=no[p][q];
				}
			if(dg!=(1<<9)-1)
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
						for(int q=yl;q<yr;++q)
							if(no[p][q]&tmp)
							{
								update(p,q,syh[tmp]);
								break;
							}
				} 
				choice-=tmp;
			}
		}
	}
	if(!blcnt)return 1;
	int minn=9,resx,resy,dg;
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			if(sol[i][j]=='0')
				if(__builtin_popcount(no[i][j])<minn)
				{
					minn=__builtin_popcount(no[i][j]);
					resx=i,resy=j;
					dg=no[i][j];
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
template<class T>
void rotate(T num[3],int op)
{
	switch(op)
	{
		case 1:{swap(num[0],num[1]);break;}
		case 2:{swap(num[0],num[2]);break;}
		case 3:{swap(num[1],num[2]);break;}
		case 4:{swap(num[0],num[1]);swap(num[1],num[2]);break;}
		case 5:{swap(num[0],num[1]);swap(num[0],num[2]);break;}
		default:break;
	}
}
template<class T>
void rever(T num[3],int op)
{
	if(op<4)rotate(num,op);
	else rotate(num,9-op);
}
template<class T>
struct cell
{
	struct cellnode{T*val[3];};
	T val[3][3];
	cellnode x[3],y[3];
	cell()
	{
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
			{
				x[i].val[j]=&val[i][j];
				y[i].val[j]=&val[j][i];
			}
	}
	T& operator[](int pos)
	{
		int xn=pos/3,yn=pos%3;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(x[xn].val[i]==y[yn].val[j])
					return*(x[xn].val[i]);
	}
	const T& operator[](int pos)const
	{
		int xn=pos/3,yn=pos%3;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(x[xn].val[i]==y[yn].val[j])
					return*(x[xn].val[i]);
	}
};
cell<cell<int>>sudoku[3];
bool check(cell<cell<int>>sudoku1,cell<cell<int>>sudoku2,int ynl,int ynr,int xnl,int xnr)
{
	int mp[10];
	memset(mp,0,sizeof mp);
	for(int i=xnl*3;i<xnr*3+3;++i)
		for(int j=ynl*3;j<ynr*3+3;++j)
		{
			int xl=i/3,xr=j/3,yl=i%3,yr=j%3,l=sudoku1[xl*3+xr][yl*3+yr],r=sudoku2[xl*3+xr][yl*3+yr];
			if(!r)continue;
			if(!mp[l])mp[l]=r;
			else if(mp[l]^r)return 0;
		}
	return 1;
}
void rotatech(char mtp[9][9])
{
	char bff[9][9];
	memcpy(bff,mtp,sizeof bff);
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			mtp[i][j]=bff[8-j][i];
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<9;++i)syh[1<<i]=i;
	while(T--)
	{
		for(int i=0;i<9;++i) 
			for(int j=0;j<9;++j) 
				no[i][j]=(1<<9)-1;
		for(int i=0;i<9;++i)scanf("%s",ans[i]);
		for(int i=0;i<9;++i)scanf("%s",sol[i]);
		int blcnt=0;
		for(int i=0;i<9;++i) 
			for(int j=0;j<9;++j) 
			{
				if(sol[i][j]=='0')++blcnt;
				else update(i,j,sol[i][j]-'1');
			}
		dfs(blcnt);
		memcpy(rsol,sol,sizeof rsol);
		rotatech(rsol);
		for(int i=0;i<9;++i)
			for(int j=0;j<9;++j)
			{
				int xl=i/3,xr=j/3,yl=i%3,yr=j%3;
				sudoku[0][xl*3+xr][yl*3+yr]=ans[i][j]-'0';
				sudoku[1][xl*3+xr][yl*3+yr]=sol[i][j]-'0';
				sudoku[2][xl*3+xr][yl*3+yr]=rsol[i][j]-'0';
			}
		bool fg=0;
		for(int k=1;k<=2;++k)
		{
			for(int yc1=0;yc1<6;++yc1)
			{
				rotate(sudoku[k].x,yc1);
				for(int yc2=0;yc2<6;++yc2)
				{
					rotate(sudoku[k].y,yc2);
					for(int xc1=0;xc1<6;++xc1)
					{
						for(int i=0;i<3;++i)rotate(sudoku[k].x[0].val[i]->x,xc1);
						for(int yk1=0;yk1<6;++yk1)
						{
							for(int i=0;i<3;++i)rotate(sudoku[k].y[0].val[i]->y,yk1);
							for(int xc2=0;xc2<6;++xc2)
							{
								for(int i=0;i<3;++i)rotate(sudoku[k].x[1].val[i]->x,xc2);
								if(check(sudoku[0],sudoku[k],0,0,0,1))
									for(int yk2=0;yk2<6;++yk2)
									{
										for(int i=0;i<3;++i)rotate(sudoku[k].y[1].val[i]->y,yk2);
										if(check(sudoku[0],sudoku[k],0,1,0,1))
											for(int xc3=0;xc3<6;++xc3)
											{
												for(int i=0;i<3;++i)rotate(sudoku[k].x[2].val[i]->x,xc3);
												if(check(sudoku[0],sudoku[k],0,1,0,2))
													for(int yk3=0;yk3<6;++yk3)
													{
														for(int i=0;i<3;++i)rotate(sudoku[k].y[2].val[i]->y,yk3);
														fg=check(sudoku[0],sudoku[k],0,2,0,2);
														if(fg)goto SHIT;
														for(int i=0;i<3;++i)rever(sudoku[k].y[2].val[i]->y,yk3);
													}
												for(int i=0;i<3;++i)rever(sudoku[k].x[2].val[i]->x,xc3);
											}
										for(int i=0;i<3;++i)rever(sudoku[k].y[1].val[i]->y,yk2);
									}
								for(int i=0;i<3;++i)rever(sudoku[k].x[1].val[i]->x,xc2);
							}
							for(int i=0;i<3;++i)rever(sudoku[k].y[0].val[i]->y,yk1);
						}
						for(int i=0;i<3;++i)rever(sudoku[k].x[0].val[i]->x,xc1);
					}
					rever(sudoku[k].y,yc2);
				}
				rever(sudoku[k].x,yc1);
			}
		}
SHIT:puts(fg?"Yes":"No");
	}
    return 0;
}
