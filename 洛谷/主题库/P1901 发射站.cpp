#include<bits/stdc++.h>
using namespace std;
const int M=1145140;
int a[M],h[M],v[M],vs[M],ans,n,t;
int main()
{
	cin.tie();
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
		cin>>h[i]>>v[i];
		while(t&&h[a[t]]<h[i])
		{
			vs[i]+=v[a[t]];
			t--;
		}
		vs[a[t]]+=v[i];
		t++;
		a[t]=i;
   }
   for(int i=1;i<=n;i++) ans=max(ans,vs[i]);
   printf("%d",ans);
   return 0;
}
