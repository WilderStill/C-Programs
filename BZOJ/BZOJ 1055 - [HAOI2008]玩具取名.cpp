#include<bits/stdc++.h>
using namespace std;
const int M=205;
int n,W,I,N,G,dp[M][M][5],g[5][5][5];
char ch[5];
char c[M];
int C(char c)
{
	if(c=='W') return 1;
	if(c=='I') return 2;
	if(c=='N') return 3;
	if(c=='G') return 4;
}
char S(int c)
{
	if(c==1) return 'W';
	if(c==2) return 'I';
	if(c==3) return 'N';
	if(c==4) return 'G';
}
int main()
{
	scanf("%d%d%d%d",&W,&I,&N,&G);
	for(int i=1;i<=W;i++ )
	{
		scanf("%s",ch+1);
		g[C(ch[1])][C(ch[2])][1]=1;
	}
	for ( int i=1;i<=I;i++ )
	{
		scanf("%s",ch+1);
		g[C(ch[1])][C(ch[2])][2]=1;
	}
	for ( int i=1;i<=N;i++ )
	{
		scanf("%s",ch+1);
		g[C(ch[1])][C(ch[2])][3]=1;
	}
	for ( int i=1;i<=G;i++ )
	{
		scanf("%s",ch+1);
		g[C(ch[1])][C(ch[2])][4]=1;
	}
	scanf("%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++ ) dp[i][i][C(c[i])]=1;
	for(int l=2;l<=n;l++ ) 
		for(int i=1;i+l-1<=n;i++ )
		{
			int j=i+l-1;
			for(int k=i;k<j;k++) 
				for (int o=1;o<=4;o++) 
					if(dp[i][k][o])
						for (int p=1;p<=4;p++) 
							if(dp[k+1][j][p])
								for(int q=1;q<=4;q++) 
									if(g[o][p][q]) 
										dp[i][j][q]=1;
		}
	bool flag=1;	
	for(int i=1;i<=4;i++ ) 
		if(dp[1][n][i]) 
		{
			printf("%c",S(i));
			flag=0;
		}
	if(flag) printf("The name is wrong!");
	return 0;
}
