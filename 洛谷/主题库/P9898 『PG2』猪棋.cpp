#include<bits/stdc++.h>
#define f2(x) for(int x=1;x<=2;x++)
#define M 1145
#define x_x 114
#define y_y 114
using namespace std;
bool m[M][M];
int x,y;
void print(int x1,int y1,int x2,int y2){cout<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<endl;}
void print(int x,int y){cout<<x<<" "<<y<<endl;}
bool check(int x,int y,bool v){return (m[x][y]==v)?1:0;}
bool check(int x1,int y1,int x2,int y2,bool v){return (m[x1][y1]==v&&m[x2][y2]==v)?1:0;}
int main()
{
	print(x_x,y_y,x_x,y_y+1);
	f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
	if(check(x_x-1,y_y,x_x-1,y_y+1,0))print(x_x-1,y_y,x_x-1,y_y+1);
	else if(check(x_x+1,y_y,x_x+1,y_y+1,0))print(x_x+1,y_y,x_x+1,y_y+1);
	else if(check(x_x+1,y_y,x_x-1,y_y,1))
	{
		print(x_x,y_y+2,x_x+1,y_y+2);
		f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
		if(check(x_x+1,y_y+1,0))print(x_x+1,y_y+1);
		else if(check(x_x,y_y+3,x_x+1,y_y+3,0))print(x_x,y_y+3,x_x+1,y_y+3);
		else print(x_x-1,y_y+1,x_x-1,y_y+2);
	}
	else if(check(x_x+1,y_y+1,x_x-1,y_y+1,1))
	{
		print(x_x,y_y-1,x_x+1,y_y-1);
		f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
		if(check(x_x+1,y_y,0))print(x_x+1,y_y);
		else if(check(x_x,y_y-2,x_x+1,y_y-2,0))print(x_x,y_y-2,x_x+1,y_y-2);
		else print(x_x-1,y_y,x_x-1,y_y-1);
	}
	else if(check(x_x+1,y_y,1))
	{
		print(x_x+1,y_y+2,x_x+2,y_y+3);
		f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
		if(check(x_x+1,y_y+1,x_x,y_y+2,0))print(x_x+1,y_y+1,x_x,y_y+2);
		else if(check(x_x+2,y_y+2,x_x+1,y_y+3,0))print(x_x+2,y_y+2,x_x+1,y_y+3);
		else if(check(x_x+1,y_y+1,1))
		{
			print(x_x+2,y_y);
			if(check(x_x+1,y_y+3,1))
			{
				print(x_x+3,y_y+3);
				f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
				if(check(x_x+2,y_y+4,x_x+3,y_y+4,0))print(x_x+2,y_y+4,x_x+3,y_y+4);
				else if(check(x_x+2,y_y+2,x_x+3,y_y+2,0))print(x_x+2,y_y+2,x_x+3,y_y+2);
				else
				{
					print(x_x,y_y-1,x_x+3,y_y);
					f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
					if(check(x_x-1,y_y-1,x_x-1,y_y,0))print(x_x-1,y_y-1,x_x-1,y_y);
					else if(check(x_x+2,y_y+1,x_x+3,y_y+1,0))print(x_x+2,y_y+1,x_x+3,y_y+1);
					else print(x_x+2,y_y-1,x_x+3,y_y-1);
				}
			}
			else
			{
				print(x_x+2,y_y+4);
				f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
				if(check(x_x+1,y_y+3,x_x+1,y_y+4,0))print(x_x+1,y_y+3,x_x+1,y_y+4);
				else if(check(x_x+3,y_y+3,x_x+3,y_y+4,0))print(x_x+3,y_y+3,x_x+3,y_y+4);
				else
				{
					print(x_x,y_y-1,x_x+3,y_y);
					f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
					if(check(x_x-1,y_y-1,x_x-1,y_y,0))print(x_x-1,y_y-1,x_x-1,y_y);
					else if(check(x_x+2,y_y+1,x_x+3,y_y+1,0))print(x_x+2,y_y+1,x_x+3,y_y+1);
					else print(x_x+2,y_y-1,x_x+3,y_y-1);
				}
			}
		}
		else if(check(x_x+1,y_y+3,1))
		{
			print(x_x+3,y_y+2,x_x+3,y_y+3);
			f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
			if(check(x_x+2,y_y+4,x_x+3,y_y+4,0))print(x_x+2,y_y+4,x_x+3,y_y+4);
			else if(check(x_x+4,y_y+2,x_x+4,y_y+3,0))print(x_x+4,y_y+2,x_x+4,y_y+3);
			else print(x_x+2,y_y+2);
		}
		else
		{
			print(x_x+2,y_y+4,x_x+3,y_y+4);
			f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
			if(check(x_x+1,y_y+3,y_y+1,y_y+4,0))print(x_x+1,y_y+3,y_y+1,y_y+4);
			else if(check(x_x+2,y_y+5,y_y+3,y_y+5,0))print(x_x+2,y_y+5,y_y+3,y_y+5);
			else print(x_x+3,y_y+3);
		}
	}
	else
	{
		print(x_x-1,y_y+2,x_x-2,y_y+3);
		f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
		if(check(x_x-1,y_y+1,x_x,y_y+2,0))print(x_x-1,y_y+1,x_x,y_y+2);
		else if(check(x_x-2,y_y+2,x_x-1,y_y+3,0))print(x_x-2,y_y+2,x_x-1,y_y+3);
		else if(check(x_x-1,y_y+1,1))
		{
			print(x_x-2,y_y);
			if(check(x_x-1,y_y+3,1))
			{
				print(x_x-3,y_y+3);
				f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
				if(check(x_x-3,y_y+4,x_x-2,y_y+4,0))print(x_x-3,y_y+4,x_x-2,y_y+4);
				else if(check(x_x-3,y_y+2,x_x-2,y_y+2,0))print(x_x-3,y_y+2,x_x-2,y_y+2);
				else
				{
					print(x_x-3,x_x,y_y,y_y-1);
					f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
					if(check(x_x+1,y_y-1,x_x+1,y_y,0))print(x_x+1,y_y-1,x_x+1,y_y);
					else if(check(x_x-3,y_y+1,x_x-2,y_y+1,0))print(x_x-3,y_y+1,x_x-2,y_y+1);
					else print(x_x-3,y_y-1,x_x-2,y_y);
				}
			}
			else
			{
				print(x_x-2,y_y+4);
				f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
				if(check(x_x-1,y_y+3,x_x-1,y_y+4,0))print(x_x-1,y_y+3,x_x-1,y_y+4);
				else if(check(x_x-3,y_y+3,x_x-3,y_y+4,0))print(x_x-3,y_y+3,x_x-3,y_y+4);
				else
				{
					print(x_x,y_y-1,x_x-3,y_y);
					f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
					if(check(x_x+1,y_y-1,x_x+1,y_y,0))print(x_x+1,y_y-1,x_x+1,y_y);
					else if(check(x_x-3,y_y+1,x_x-2,y_y+1,0))print(x_x-3,y_y+1,x_x-2,y_y+1);
					else print(x_x-3,y_y-1,x_x-2,y_y-1);
				}
			}
		}
		else if(check(x_x-1,y_y+3,1))
		{
			print(x_x-3,y_y+2,x_x-3,y_y+3);
			f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
			if(check(x_x-3,y_y+4,x_x-2,y_y+4,0))print(x_x-3,y_y+4,x_x-2,y_y+4);
			else if(check(x_x-4,y_y+2,x_x-4,y_y+3,0))print(x_x-4,y_y+2,x_x-4,y_y+3);
			else print(x_x-2,y_y+2);
		}
		else
		{
			print(x_x-3,y_y+4,x_x-2,y_y+4);
			f2(i)scanf("%d %d",&x,&y),m[x][y]=1;
			if(check(x_x-1,y_y+3,x_x-1,y_y+4,0))print(x_x-1,y_y+3,x_x-1,y_y+4);
			else if(check(x_x-3,y_y+5,x_x-2,y_y+5,0))print(x_x-3,y_y+5,x_x-2,y_y+5);
			else print(x_x-3,y_y+3);
		}
	}
	return 0;
} 
