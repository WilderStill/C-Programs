#include<bits/stdc++.h>
#define ll long long
#define MAXN 1145141
using namespace std;
char s[MAXN];
int n,nxt[MAXN];
int main()
{
    scanf("%d",&n);
	scanf("%s",s);
	int i,j;
	ll cnt=0;
    nxt[0]=0;
	nxt[1]=0;
	j=0;
    for(i=1;i<n;i++)
	{
        while(j&&(s[i]!=s[j])) j=nxt[j];
        if(s[i]==s[j]) j+=1;
		nxt[i+1]=j;
    }
    for(i=1;i<=n;i++)
	{
        j=i;
        while(nxt[j]) j=nxt[j];
        if(nxt[i]) nxt[i]=j;
        cnt+=i-j;
    }
    printf("%lld",cnt);
}
