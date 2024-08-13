#include <bits/stdc++.h>
#define f3(x) for(int x=1;x<=3;x++)
#define M 114514
using namespace std;
char s[4][M];
int nxt[4][M],len[4],a[4][4],res;
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
		if(j==len[id2]) return len[id2];
		if(i==len[id1]) return j;
	}
}
int main ()
{
	f3(i){scanf("%s",s[i]+1);len[i]=strlen(s[i]+1);getnxt(i);}
	f3(i)f3(j)if(i!=j)a[i][j]=KMP(i,j);
	f3(i)f3(j)if(a[i][j]==len[j]||a[j][i]==len[j])a[j][i]=a[i][j]=len[j];
	f3(i)f3(j)f3(k)if(i!=j&&j!=k&&k!=i)res=max(res,max(a[i][j]+a[k][i],a[i][k]+a[j][i]));
	printf("%d",len[1]+len[2]+len[3]-res);
	return 0;
}
