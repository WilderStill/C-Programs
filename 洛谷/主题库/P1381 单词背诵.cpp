#include<bits/stdc++.h>
#define M 1145141
using namespace std;
map<string,int>cnt,f;
string word[M]; 
int mw,mp,n,m;
int main()
{
	cin.tie(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		f[s]=1;
	}
	scanf("%d",&m);
	int left=1;
	for(int i=1;i<=m;i++)
	{
		cin>>word[i];
		if(f[word[i]]==1) cnt[word[i]]++;
		if(cnt[word[i]]==1)
		{
			mw++;
			mp=i-left+1;
		}
		while(left<=i)
		{
			if(!f[word[left]]) left++;
			else if(cnt[word[left]]>=2)
			{
				cnt[word[left]]--;
				left++;
			}
			else break;
		}
		mp=min(mp,i-left+1);
	}
	printf("%d\n%d\n",mw,mp);
	return 0;
}
