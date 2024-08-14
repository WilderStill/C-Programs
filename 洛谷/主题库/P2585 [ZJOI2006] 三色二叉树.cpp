#include<bits/stdc++.h>
#define M 514514
using namespace std;
char s[M];
int fmx[M][3],fmn[M][3],cnt=1,ansmax=1,ansmin=M;
void dfs(int x)
{
	if(s[x]=='0')
	{
		fmn[x][0]=fmx[x][0]=1;
		return;
	}
	else if(s[x]=='1')
	{
		int lson=x+1;
		dfs(++cnt);
		fmx[x][0]=max(fmx[lson][1],fmx[lson][2])+1;
		fmx[x][1]=max(fmx[lson][0],fmx[lson][2]);
		fmx[x][2]=max(fmx[lson][0],fmx[lson][1]);
		fmn[x][0]=min(fmn[lson][1],fmn[lson][2])+1;
		fmn[x][1]=min(fmn[lson][0],fmn[lson][2]);
		fmn[x][2]=min(fmn[lson][0],fmn[lson][1]);
	}
	else if(s[x]=='2')
	{
		int lson=x+1;
		dfs(++cnt);
		int rson=++cnt;
		dfs(cnt);
		fmx[x][0]=max(fmx[lson][1]+fmx[rson][2],fmx[lson][2]+fmx[rson][1])+1;
		fmx[x][1]=max(fmx[lson][0]+fmx[rson][2],fmx[lson][2]+fmx[rson][0]);
		fmx[x][2]=max(fmx[lson][0]+fmx[rson][1],fmx[lson][1]+fmx[rson][0]);
		fmn[x][0]=min(fmn[lson][1]+fmn[rson][2],fmn[lson][2]+fmn[rson][1])+1;
		fmn[x][1]=min(fmn[lson][0]+fmn[rson][2],fmn[lson][2]+fmn[rson][0]);
		fmn[x][2]=min(fmn[lson][0]+fmn[rson][1],fmn[lson][1]+fmn[rson][0]);
	}
	ansmax=max(ansmax,fmx[x][0]);
}
int main()
{
	scanf("%s",s+1);
	dfs(cnt);
	ansmin=min(fmn[1][0],min(fmn[1][1],fmn[1][2]));
	printf("%d %d",ansmax,ansmin);
	return 0;
}
