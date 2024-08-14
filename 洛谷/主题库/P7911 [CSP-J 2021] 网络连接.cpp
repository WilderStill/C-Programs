#include<bits/stdc++.h>
#define lim 11451
using namespace std;
int n;
char in[lim],ad[lim];
struct node
{
	char s[lim];
}add[lim];
bool check()
{
	int a=-1,b=-1,c=-1,d=-1,e=-1;
	int t=sscanf(ad,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e);
	if(t!=5) return 0;
	if(a<0||a>255) return 0;
	if(b<0||b>255) return 0;
	if(c<0||c>255) return 0;
	if(d<0||d>255) return 0;
	if(e<0||e>65535) return 0;
	char s2[35];
	sprintf(s2,"%d.%d.%d.%d:%d",a,b,c,d,e);
	for(int i=0;i<strlen(ad);i++)
		if(ad[i]!=s2[i])return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",in);
		scanf("%s",ad);
		if(!strcmp(in,"Server"))
		{
			if(!check())printf("ERR\n");
			else 
			{
				bool fg=0;
				for(int j=1;j<=i;j++)
					if(!strcmp(add[j].s,ad))
					{
						fg=1;
						printf("FAIL\n");
						break;
					}
				if(!fg)
				{
					printf("OK\n");
					strcpy(add[i].s,ad);
				}
			}
		}
		else if(!strcmp(in,"Client"))
		{
			if(!check())printf("ERR\n");
			else
			{	
				bool fg=0;
				for(int j=1;j<=i;j++)
					if(!strcmp(add[j].s,ad))
					{
						fg=1;
						printf("%d\n",j);
						break;
					}
				if(!fg)
				{
					printf("FAIL\n");
				}
			}
		}
	}	
    return 0;
}
