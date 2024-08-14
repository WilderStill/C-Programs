#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,len,anslen,evelen[M],sumlen[M],evepos[M];
char str[M],subs[100][M],ans[M];
int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);len=strlen(str+1);
	for(int i=1,j;i<=len;i+=2*n-2)
	{
		j=1;while(j<=n&&i+j-1<=len)evelen[j++]++;
		j=n-1;while(j>1&&i+2*n-1<=len+j)evelen[j--]++;
	}
	for(int i=1;i<=n;++i)sumlen[i]=sumlen[i-1]+evelen[i];
	for(int i=1,j;i<=len;i+=2*n-2)
	{
		j=1;while(j<=n&&i+j-1<=len)ans[++anslen]=str[sumlen[j-1]+evepos[j]+1],evepos[j++]++;
		j=n-1;while(j>1&&i+2*n-1<=len+j)ans[++anslen]=str[sumlen[j-1]+evepos[j]+1],evepos[j--]++;
	}
	for(int i=1;i<=anslen;++i)printf("%c",ans[i]);
    return 0;
}
