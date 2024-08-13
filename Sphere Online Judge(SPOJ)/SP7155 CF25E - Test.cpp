#include <bits/stdc++.h>
#define f3(x) for(int x=1;x<=3;x++)
#define M 11451411
using namespace std;
char s[4][M];
int nxt[4][M],len[4],a[4][4];
void getnxt(int id)
{
	int j=0;
	for(int i=2;i<=len[id];i++)
	{
		while(j&&s[id][i]!=s[id][j+1])j=nxt[id][j];
		if(s[id][i]==s[id][j+1])j++;
		nxt[id][i]=j;
	}
}
int KMP(int id1,int id2)
{
	int j=0;
	for(int i=1;i<=len[id1];i++)
	{
		while(j&&s[id1][i]!=s[id2][j+1])j=nxt[id2][j];
		if(s[id1][i]==s[id2][j+1])j++;
		if(j==len[id2]) return -1;
		if(i==len[id1]) return j;
	}
}
int main()
{
	while(cin>>s[1]+1>>s[2]+1>>s[3]+1)
	{
		int ans=2147483647;
		f3(i){len[i]=strlen(s[i]+1);getnxt(i);}
		f3(i)f3(j)if(i!=j)a[i][j]=KMP(i,j);
		f3(i)f3(j)if(a[i][j]==len[j]||a[j][i]==len[j])a[j][i]=a[i][j]=len[j];
		f3(i)f3(j)f3(k)if(i!=j&&j!=k&&k!=i)
		{
			int sum=len[i]+len[j]+len[k]-a[i][j]-a[j][k];
            if(a[i][j]>=0&&a[j][k]>=0)ans=min(ans,sum);
            else
			{
                if(a[i][j]<0&&a[i][k]<0)ans=min(ans,len[i]);
                else if(a[i][j]<0)ans=min(ans,sum+a[i][j]+a[j][k]-len[j]-a[i][k]);
                if(a[j][k]<0)ans=min(ans,sum+a[j][k]-len[k]);
            }
		}
		printf("%d\n",ans);
	}
	return 0;
}
