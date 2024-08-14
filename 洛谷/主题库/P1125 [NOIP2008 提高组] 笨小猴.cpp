#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[11451411];
int a_n[11451411],tot;
bool cmp(int b,int c){
	return b>c;
}
bool check(int n)
{
	if(n==1||n==0)
	{
		return 0;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}
int main()
{
	scanf("%s",a+1);
	for(int i=1;i<=strlen(a+1);i++)
	{
		int tmp=a[i]-'a'+1;
		if(!a_n[tmp])tot++;
		a_n[tmp]++;
	}
	sort(a_n+1,a_n+27,cmp);
	int num=a_n[1]-a_n[tot];
	if(check(num))
		printf("Lucky Word\n%lld",num);
	else
		printf("No Answer\n0");
	return 0;
}
