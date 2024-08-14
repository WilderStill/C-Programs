#include<bits/stdc++.h>
#define Maxn 114514
using namespace std;
int a[Maxn],b[Maxn],h[Maxn],f[Maxn],s[Maxn],n,ans=1,t,x,sp;
void swap(int x,int y)
{
	int k = h[x];
	h[x]=h[y];
	h[y]=k;
	k = f[x];
	f[x]=f[y];
	f[y]=k;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		h[i]=a[i]+b[1];
		f[i]=i;
		s[i]=1; 
	}
	while (ans<=n)
	{
		printf("%d ",h[1]);
		t=f[1];
		s[t]++;
		h[1]=a[t]+b[s[t]];
		x=1,sp=0;		
		while((x*2)<=n)
		{
			sp=x*2;
			if(h[sp]>h[sp+1]&&sp+1<=n)sp++;
			if(h[x]>h[sp])
			{
				swap(x,sp);
				x=sp;	
			}
			else break;
		}
		ans++;	
	}
	return 0;
}
