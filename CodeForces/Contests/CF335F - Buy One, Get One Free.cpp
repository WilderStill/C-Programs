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
int n,ans,syh[10010100],cnt[10001010];
queue<int>stk,stkd;
priority_queue<int,vector<int>,greater<int>>q;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)syh[i]=read(),ans+=syh[i];
	sort(syh+1,syh+n+1);
	reverse(syh+1,syh+n+1);
	for(int i=1;i<=n;++i)
	{
		if(i==1||syh[i]!=syh[i-1])stk.push(syh[i]);
		++cnt[stk.size()];
	}
	int id=1,p=0,c=0;
	while(!stk.empty())
	{
		int sttop=stk.front();
        p=min(c-2*(int)q.size(),cnt[id]);
        for(int j=1;j<=p;++j)stkd.push(sttop);
        p=min(c,cnt[id])-p;
        for(int j=1;j<=p;++j)
        {
            int qtop=q.top();
            if(qtop<sttop)
            {
            	stkd.push(sttop);
            	if(p>j)stkd.push(sttop);
			}
            else
			{
				stkd.push(qtop);
	            if(j<p&&2*sttop>qtop)stkd.push(2*sttop-qtop);
			}
            q.pop();
			++j;
        }
        while(!stkd.empty())
		{
			q.push(stkd.front());
			stkd.pop();
		}
        c+=cnt[id];
        stk.pop();
        ++id;
    }
    while(!q.empty())
    {
        ans-=q.top();
        q.pop();
    }
    write(ans);
	return 0;
}
