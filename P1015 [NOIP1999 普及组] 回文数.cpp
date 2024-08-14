#include<bits/stdc++.h> 
#define M 11451411
using namespace std;
int n,q[M],len,w[M],ans;
string s;
void add(int a[], int b[]) 
{
	for(int i=1;i<=len;i++)
	{
		a[i]+=b[i];
		a[i+1]+=a[i]/n; 
		a[i]%=n;
	}
	if(a[len+1]>0)len++; 
}
bool f(int a[]) 
{
	int ln=len,l=1,r=len;
	while(ln--)
	{
		if(ln<len/2) break;
		if(a[l]!=a[r]){return false;}
		l++,r--;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	cin>>s;
	int cnt=0;
	len=s.length();
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')q[++cnt]=s[i]-'0';
		else q[++cnt]=s[i]-'A'+10;
	}
	while(!f(q)) 
	{
		int cnt=0;
		for(int i=len;i>=1;i--)w[++cnt]=q[i]; 
		add(q,w); 
		ans++;
		if(ans>30) 
		{
			printf("Impossible!");
			return 0;
		}
	}
	printf("STEP=%d",ans);
	return 0;
}
