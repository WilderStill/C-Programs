#include<bits/stdc++.h>
#define M 22114514
using namespace std;
char input[M],str[M];
int plen[M],mp[127];
long long res=0;
void manacher(int len)
{
	int mid=1,maxn=1;
	for(int l=1;l<=len;l+=2)
	{
		if(maxn>l)plen[l]=min(maxn-l,plen[mid*2-l]);
		else plen[l]=1;
		while(str[l+plen[l]]==mp[str[l-plen[l]]])++plen[l];
		if(plen[l]+l>maxn)
		{
			maxn=plen[l]+l;
			mid=l;
		}
		res+=plen[l]>>1;
	}
}
int main()
{
	mp['0']='1';
	mp['1']='0';
	mp['&']='&';
	mp['$']='$';
	int inlen;
	scanf("%d%s",&inlen,input+1);
	int len=0;
	str[len++]='&';
	for(int i=1;i<=inlen;++i)
	{
		str[len++]='$';
		str[len++]=input[i];
	}
	str[len++]='$';
	str[len]=0;
	manacher(len);
	printf("%lld",res);
	return 0;
}
