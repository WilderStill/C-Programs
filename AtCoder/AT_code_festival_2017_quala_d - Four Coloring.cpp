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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
char s[2][2],ans[521][521];
int main()
{
	s[0][0]='R',s[0][1]='G';
	s[1][0]='Y',s[1][1]='B';
	int n=read(),m=read(),d=read();
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
		{
            int x=((i+j+m)/d)&1,y=((i-j+m)/d)&1;
            ans[i][j]=s[x][y];
        }
    for(int i=0;i<n;++i)puts(ans[i]);
    return 0;
}
