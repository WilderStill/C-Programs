#include<bits/stdc++.h>
using namespace std;
int T,cnt,ans;
string s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cin>>s;
		cnt=1,ans=0;
		for(int i=1;i<s.size();i++)
		{
			if(s[i]==s[i-1])cnt++;
			else
			{
				ans+=(cnt-1);
				cnt=1;
			}
		}
		if(cnt)ans+=cnt-1;
		printf("%d\n",ans);
	}
	return 0;
}

