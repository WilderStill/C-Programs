#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int INF=0x3f3f3f3f;
int n,wx,wy,bx,by,ans,f[2][60][30][30][30][30]; 
int dfs(int col,int step,int white_x,int white_y,int black_x,int black_y)
{
    if(step>3*n)return INF;
    if(f[col][step][white_x][white_y][black_x][black_y])return f[col][step][white_x][white_y][black_x][black_y];
    int ans=0;
    if(white_x==black_x&&white_y==black_y)return col?INF:0;
    if(!col)
    { 	
        ans=0;
        if(white_x>1)ans=max(ans,dfs(1,step+1,white_x-1,white_y,black_x,black_y));
        if(white_x<n)ans=max(ans,dfs(1,step+1,white_x+1,white_y,black_x,black_y));
        if(white_y>1)ans=max(ans,dfs(1,step+1,white_x,white_y-1,black_x,black_y));
        if(white_y<n)ans=max(ans,dfs(1,step+1,white_x,white_y+1,black_x,black_y));
    }
    else
    {
    	ans=INF;
        if(black_x>1)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x-1,black_y));
        if(black_x>2)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x-2,black_y));
        if(black_x<n)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x+1,black_y));
        if(black_x<n-1)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x+2,black_y));
        if(black_y>1)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x,black_y-1));
        if(black_y>2)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x,black_y-2));
        if(black_y<n)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x,black_y+1));
        if(black_y<n-1)ans=min(ans,dfs(0,step+1,white_x,white_y,black_x,black_y+2));
    }
    f[col][step][white_x][white_y][black_x][black_y]=++ans;
    return ans;
}
int main()
{
    n=read(),wx=read(),wy=read(),bx=read(),by=read();
    if(abs(wx-bx)+abs(wy-by)<=1)puts("WHITE 1");
    else printf("BLACK %d",dfs(0,0,wx,wy,bx,by));
    return 0;
}
