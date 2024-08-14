#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 1145
using namespace std;
char str[M];
int n,f[M][M];
bool canfold(int st,int ed,int len)
{
	for(int i=st;i<=st+len-1;i++)
	    for(int j=i;j<=ed;j+=len)
	        if(str[j]!=str[i])return 0;
    return 1;
}
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	memset(f,INF,sizeof(f));
    for(int i=1;i<=n;++i)f[i][i]=1;
    for(int l=2;l<=n;++l)
        for(int i=1,j=i+l-1;j<=n;++i,++j)
            for(int k=i;k<=j;++k)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
                int len=k-i+1;
                if(l%len)continue;
                if(canfold(i,j,len))f[i][j]=min(f[i][j],f[i][k]+2+(l/len<10?1:(l/len<100?2:3)));
            }
    printf("%d",f[1][n]);
	return 0;
}
