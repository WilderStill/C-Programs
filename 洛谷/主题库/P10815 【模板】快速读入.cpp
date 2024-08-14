#include<stdio.h>
#include<ctype.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar_unlocked();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar_unlocked();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar_unlocked();
	return x*f;
}
int main()
{
	int n=read(),sum=0;
	for(int i=1;i<=n;++i)sum+=read();
	printf("%d",sum);
    return 0;
}
