#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6},pm[114514]={6},n,ans;
void init()
{
	for(int i=1;i<=4514;i++)
    {
        int j=i;
        while(j>=1)
        {
            pm[i]+=num[j%10];
            j/=10;
        }
	}
}
bool judge(int a,int b)
{
	return pm[a]+pm[b]+pm[a+b]+4==n;
} 
int main()
{
        scanf("%d",&n);
        init();
        for(int i=0;i<=1145;i++)
            for(int j=0;j<=1145;j++)
                if(judge(i,j))
					ans++;
        printf("%d",ans);
        return 0;
}
