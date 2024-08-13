#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[4];
int main()
{
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='0'&&s[1]=='0'&&s[3]=='0')return 0;
		ll k=(s[0]-'0')*10;
		k+=s[1]-'0';
		k=k*(ll)pow(10,s[3]-'0');
		ll ans=0,pw=0,tmp=k;
		while(k>1)++pw,k>>=1;
		ans=(tmp-(ll)pow(2,pw))*2+1;
		printf("%lld\n",ans);
	}
	return 0;
}
