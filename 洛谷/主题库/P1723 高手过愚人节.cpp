#include<bits/stdc++.h>
#define M 10000010
using namespace std;
int inlen;
char input[M],str[M];
int getstr()
{
	int cnt=0;
	str[cnt++]='&';
	for(int i=1;i<=inlen;++i)
	{
		str[cnt++]='$';
		str[cnt++]=input[i];
	}
	str[cnt++]='$';
	str[cnt]=0;
	return cnt;
}
int plen[M];
int manacher(int len)
{
	int mid,maxn=0,maxlen=0;
	for(int l=1;l<len;++l)
	{
		if(maxn>l)plen[l]=min(maxn-l,plen[mid*2-l]);
		else plen[l]=1;
		while(str[l+plen[l]]==str[l-plen[l]])++plen[l];
		if(plen[l]+l>maxn)
		{
			maxn=plen[l]+l;
			mid=l;
			maxlen=max(maxlen,plen[l]);
		}
	}
	return maxlen-1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",input+1);
		inlen=strlen(input+1);
		int len=getstr();
		printf("%d\n",manacher(len));
	}
	return 0;
}
