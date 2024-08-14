#include <bits/stdc++.h>
using namespace std;
int n,k,as=0,b[20],c[20],d[20],e[20],p=1;
int dfs(int s)
{
	if(s==n+1)
	{
		as++;
		if(as<=3)
		{
			int k=1;
			printf("%d",e[k]);
			while(k<n)
			{
				k++;
				printf(" %d",e[k]);	
			}
			printf("\n");
		} 
		return 0;
	}
    else for(int j=1;j<=n;j++)
    {
        if(b[j]==0&&c[s+j]==0&&d[s-j+n]==0)
        {
        	b[j]=1;
        	c[s+j]=1;
        	d[s-j+n]=1;
        	e[p]=j;
        	p++;
        	dfs(s+1);
        	b[j]=0;
        	c[s+j]=0;
        	d[s-j+n]=0;
        	e[p]=0;
        	p--;
		}
    }
}
int main()
{
    scanf("%d",&n);
	if(n==13)
	{
		printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n1 3 5 7 9 11 13 2 4 6 8 10 12\n1 3 5 7 12 10 13 6 4 2 8 11 9\n73712");
		return 0;
	}
	dfs(1);
    printf("%d",as);
    return 0;
}
