#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100005]={},b[100005]={},c[1000005]={};
	char s1[100005],s2[100005];
    cin>>s1>>s2;
    int len1=strlen(s1);
	int len2=strlen(s2);
	int len3=len1+len2+1;
    for(int i=0;i<len1;i++)
    {
    	a[i]=s1[len1-1-i]-48;
	}
	for(int i=0;i<len2;i++)
    {
    	b[i]=s2[len2-1-i]-48;
	}
	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
			c[i+j]+=a[i]*b[j];
	}
	for(int i=0;i<len3;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	int h=len3;
	while(c[h]==0&&h>0)
	{
		h--;
	}
	for(int i=h;i>=0;i--)
	{
		cout<<c[i];
	}
}
