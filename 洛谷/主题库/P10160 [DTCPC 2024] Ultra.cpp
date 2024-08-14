#include<bits/stdc++.h>
using namespace std;
string s;
int trye[511415][2],cnt=1,ans;
int main()
{
	cin>>s;s=' '+s;
	trye[1][0]=1;
	for(int i=1;i<=s.length()-1;i++)
	{
		if(s[i]=='0'&&s[i+1]=='0')
		{
			int x=i;
			while(s[x]=='0')x++;
			trye[cnt][1]=i-1;
			trye[++cnt][0]=x;
		}
	}
	trye[cnt][1]=s.length()-1;
	for(int i=1;i<=cnt;i++)
	{
		int sum=0;
		for(int j=trye[i][0];j<=trye[i][1];j++)
		{
			if(s[j]=='0'&&s[j-1]=='1'&&s[j+1]=='1')
			{
				sum=1;break;
			}
			else if(s[j]=='1')sum++;
		}
		ans+=sum;
	}
	printf("%lld",ans);
	return 0;
}
