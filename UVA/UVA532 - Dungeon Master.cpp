#include<bits/stdc++.h>
using namespace std;
int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
int pl[114514][5];
bool mp[31][31][31];
int main()
{
	bool ok;
	char ch;
	int l,r,c,t,k,endx,endy,endz;
	while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0)return 0;
		for(int x=1;x<=l;++x)
			for(int y=1;y<=r;++y)
				for(int z=1;z<=c;++z)
				{
					cin>>ch;
					if(ch=='#')mp[x][y][z]=0;
					else if(ch=='S')
					{
						mp[x][y][z]=1;
						pl[1][1]=x,pl[1][2]=y,pl[1][3]=z,pl[1][4]=0;
					}
					else if(ch=='E')
					{
						mp[x][y][z]=1;
						endx=x,endy=y,endz=z;
					}
					else mp[x][y][z]=1;
				}
			t=ok=0;
			k=1;
		do
		{
			++t;
			for(int i=0;i<6;++i)
			{
				int x=pl[t][1]+dx[i],y=pl[t][2]+dy[i],z=pl[t][3]+dz[i];
				if(x>0&&x<=l&&y>0&&y<=r&&z>0&&z<=c&&mp[x][y][z])
				{
					mp[x][y][z]=0;
					++k;
					pl[k][1]=x,pl[k][2]=y,pl[k][3]=z;
					pl[k][4]=pl[t][4]+1;
					if(x==endx&&y==endy&&z==endz)
					{
						printf("Escaped in %d minute(s).\n",pl[k][4]);
						ok=1;
						break;
					}
				}
			}
		}while(t<k&&!ok);
		if(!ok)puts("Trapped!");
	}
	return 0;
}
