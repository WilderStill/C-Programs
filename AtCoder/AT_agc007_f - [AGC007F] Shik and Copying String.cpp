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
char s[1000100],t[1000100];
queue<int>q;
int main()
{
	int n=read();
	scanf("%s%s",s+1,t+1);
	if(!strcmp(s+1,t+1))
	{
		write(0);
		return 0;
	}
	int hd=n,tl=n,ans=0;
	while(tl)
    {
        while(tl&&t[tl-1]==t[tl])--tl;
        while(hd&&(hd>tl||s[hd]!=t[tl]))--hd;
        if(hd<=0)
        {
            write(-1);
            return 0;
        }
        while(!q.empty()&&q.front()-q.size()>=tl)q.pop();
        if(hd!=tl)q.push(hd);
        ans=max(ans,(int)q.size()+1);
        --tl;
    }
    write(ans);
    return 0;
}

