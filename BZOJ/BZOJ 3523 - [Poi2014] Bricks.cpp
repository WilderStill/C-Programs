#include<bits/stdc++.h>
#define M 1000100
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
int n,st,ed,sum,now,ans[M];
struct node
{
	int col,cnt;
	bool operator <(const node&b)const
	{
		return (cnt==b.cnt)?col^ed:cnt<b.cnt;
	}
};
priority_queue<node>q;
int main()
{
	n=read(),st=read(),ed=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		sum+=x;
	    if(i==st)--x;
	    if(i==ed)--x;
	    if(x>0)q.push({i,x});
	    else if(x<0)
		{
			putchar('0');
			return 0;
		}
	}
	ans[1]=now=st;
	for(int i=2;i<sum;++i)
	{
		auto top=q.top();q.pop();
		if(top.col==now)
		{
			if(!q.empty())
	    	{
	        	auto sec_top=q.top();q.pop();
	        	ans[i]=now=sec_top.col;
	        	if(sec_top.cnt>1)q.push({sec_top.col,sec_top.cnt-1});
	        	q.push(top);
	    	}
	    	else
	    	{
	    		putchar('0');
	    		return 0;
			}
		}
		else
		{
			ans[i]=now=top.col;
			if(top.cnt>1)q.push({top.col,top.cnt-1});
		}	
	}
	ans[sum]=ed;
	write(ans[1]);
	for(int i=2;i<=sum;++i)putchar(' '),write(ans[i]);
    return 0;
}

