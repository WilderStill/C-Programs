#include<bits/stdc++.h>
#define lim 114514
using namespace std;
stack<int>q;
int p,n,s=1;
int a[lim],b[lim];
int main()
{
	scanf("%d",&p);
	for(int i=1;i<=p;i++)
	{
		scanf("%d",&n);
		memset(a,sizeof(a),0);
		memset(b,sizeof(b),0);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
		{
			q.push(a[i]);
			while((q.top())==b[s])
			{
				q.pop();
				s++;
				if(q.empty()) break;
			}
		}
		if(q.empty()) printf("Yes\n");
		else printf("No\n");
		while(!q.empty()) q.pop();
		s=1;
	}
	return 0;
}
