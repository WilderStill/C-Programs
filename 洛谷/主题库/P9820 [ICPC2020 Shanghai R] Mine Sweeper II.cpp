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
char A[1010][1010],B[1010][1010];
int cnta,cntb,cntk,cntp;
int main()
{
	int n=read(),m=read(),s=(m*n/2);
	for(int i=1;i<=n;++i)scanf("%s",A[i]+1);
	for(int i=1;i<=n;++i)scanf("%s",B[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(A[i][j]=='X')cnta++;
			if(B[i][j]=='X')cntb++;
			if(A[i][j]==B[i][j])cntk++;
			else cntp++;
		}
	if(cntk<=s)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				putchar(A[i][j]=='.'?'X':'.');
			puts("");
		}	
	}
	else if(cntp<=s)
	{
		for(int i=1;i<=n;++i)
		{	
			for(int j=1;j<=m;++j)
				putchar(A[i][j]=='.'?'.':'X');
			puts("");
		}
	}
	else
	{
		puts("-1");
	}
	return 0;
}
