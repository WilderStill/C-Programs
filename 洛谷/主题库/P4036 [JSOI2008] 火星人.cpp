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
string s;
int main()
{
    cin>>s;
    int m=read();
    for(int i=1;i<=m;++i)
	{
		char op[2],ch[2];
		scanf("%s",op);
		int x=read();
        if(op[0]=='Q')
		{
            int y=read(),cnt=0;
            for(int i=x,j=y;i<=s.size()&&j<=s.size();++i,++j,++cnt)if(s[i-1]!=s[j-1])break;
            write(cnt),puts("");
        }
        if(op[0]=='R')
		{
            scanf("%s",ch);
            s[x-1]=ch[0];
        }
        if(op[0]=='I')
		{
            scanf("%s",ch);
            s.insert(x,ch);
        }
    }
    return 0;
}
