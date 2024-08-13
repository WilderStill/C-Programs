#include<bits/stdc++.h>
#define M 22114514
using namespace std;
char input[M],str[M];
int getstr(char raw[],int rawlen)
{
	int cnt=0;
	str[cnt++]='&';
	for(int i=1;i<=rawlen;++i)
	{
		str[cnt++]='$';
		str[cnt++]=raw[i];
	}
	str[cnt++]='$';
	str[cnt]=0;
	return cnt;
}
int plen[M];
void manacher(int len)
{
	int mid=1,maxn=1;
	for(int l=0;l<=len;++l)
	{
		if(maxn>=l)plen[l]=min(maxn-l,plen[mid*2-l]);
		else plen[l]=1;
		while(str[l+plen[l]]==str[l-plen[l]])++plen[l];
		if(plen[l]+l-1>maxn)
		{
			maxn=plen[l]+l-1;
			mid=l;
		}
	}
	return;
}
int main()
{
	while(scanf("%s",input+1)!=EOF)
	{
		int len=getstr(input,strlen(input+1));
		int p=-1;
		manacher(len);
		for(int i=1;i<len;++i)if(i+plen[i]-1==len-1)p=i,i=len;
        for(int i=len;i<p*2;++i)str[i]=str[p*2-i];
        for(int i=2;i<p*2;i+=2)putchar(str[i]);
        puts("");
        memset(plen,0,sizeof plen);
	}
	return 0;
}
