#include<bits/stdc++.h>
#define M 22114514
using namespace std;
char input[M],str[M];
int get_input()
{
	char ch=getchar();
	int len=0;
	while(islower(ch))input[++len]=ch,ch=getchar();
	return len;
}
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
	int inlen=get_input();
	int len=getstr(input,inlen);
	printf("%d",manacher(len));
	return 0;
}
