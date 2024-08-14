#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,T;
double tiim;
char str[M];
int main()
{
	scanf("%d%d",&n,&T);
	while(~scanf("%s",str+1))
	{
		int kh=0;
		for(int i=1;i<=strlen(str+1);++i)
			switch(str[i])
			{
				case ' ':break;
				case '\n':break;
				case '(':
				{
					++kh;
					break;
				}
				case ')':
				{
					--kh;
					break;
				}
				case '.':
				{
					tiim+=pow(0.5,kh+1);
					break;
				}
				default:
				{
					tiim+=pow(0.5,kh);
					break;
				}
			}
	}
	printf("%.0lf",tiim*60/T);
    return 0;
}
