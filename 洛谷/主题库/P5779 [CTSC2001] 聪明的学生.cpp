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
const int pre[3]={2,0,1},suf[3]={1,2,0};
int ans[1000010][3];
inline int dfs(int x,int y,int pos)
{
	if(x==y)return pos+1;
	if(x>y)return dfs(y,x-y,suf[pos])+2;
	if(x<y)return dfs(y-x,x,pre[pos])+1; 
}
int main()
{
	while(true)
	{
		int n=read(),m=read(),cnt=0,id1,id2,id3;
		if(n==-1&&m==-1)break;
		id2=n%3,id1=pre[id2],id3=suf[id2];
		for(int i=1;i<m;++i)
			if(dfs(i,m-i,id1)==n)
				ans[++cnt][id1]=m,ans[cnt][id2]=i,ans[cnt][id3]=m-i;
		write(cnt),puts("");
		if(id1^1)
		{
			for(int i=1;i<=cnt;++i)
				write(ans[i][0]),putchar(' '),
				write(ans[i][1]),putchar(' '),
				write(ans[i][2]),putchar('\n');
		}
		else
		{
			for(int i=cnt;i;--i)
				write(ans[i][0]),putchar(' '),
				write(ans[i][1]),putchar(' '),
				write(ans[i][2]),putchar('\n');
		}
	}
	return 0;
}

