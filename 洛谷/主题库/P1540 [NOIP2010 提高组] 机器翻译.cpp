#include<bits/stdc++.h>
using namespace std;
int n,m,ans,l,r,dw[11451411],dic[11451411];
int main()
{
    scanf("%d %d",&m,&n);
    for(int i=1,wd;i<=n;i++)
	{
        scanf("%d",&wd);
        if(!dw[wd]) 
        {
        	ans++,r++;
			dic[r]=wd;
			dw[dic[r]]=1;
            if(r>m)
			{
				l++;
				dw[dic[l]]=0;
			}
        }
    }
    printf("%d",ans);
    return 0;
}
