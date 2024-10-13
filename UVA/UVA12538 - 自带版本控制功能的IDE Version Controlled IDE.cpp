#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
crope tp,s[500010];
char str[500010];
int tot,last;
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		int op=read();
		if(op==1)
		{
			int p=read()-last;
			scanf("%s",str);
			tp.insert(p,str);
			s[++tot]=tp;
		}
		if(op==2)
		{
			int p=read()-last,c=read()-last;
			tp.erase(p-1,c);
			s[++tot]=tp;
		}
		if(op==3)
		{
			int v=read()-last,p=read()-last,c=read()-last;
			crope ans=s[v].substr(p-1,c);
			last+=count(ans.begin(),ans.end(),'c');
			cout<<ans;
			puts("");
		}
	}
    return 0;
}

