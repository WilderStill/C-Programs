#include<bits/stdc++.h>
using namespace std;
char k[1145],c[1145],ascii[125];
void init()
{
	for(int i=65,num=0;i<=90;i++)ascii[i]=num++;
	for(int i=97,num=0;i<=122;i++)ascii[i]=num++;
}
int main()
{
	init();
	scanf("%s %s",&k,&c);
	for(int i=0;i<strlen(c);i++)
	{
		int t=ascii[k[i%strlen(k)]],fg='A';
		if(c[i]>='a')fg='a';
		c[i]=(c[i]-fg-t>=0)?c[i]-t:c[i]-t+26;
	}
	printf("%s",c);
	return 0;
}
