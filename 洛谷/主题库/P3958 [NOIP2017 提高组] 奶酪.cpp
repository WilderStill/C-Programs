#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,h,r,father[M],T;
int x[M],y[M],z[M];
double pow(double p)
{
	return (double)p*p;
} 
double dist(double xa,double ya,double za,double xb,double yb,double zb)
{
	return (double)(sqrt(pow(xa-xb)+pow(ya-yb)+pow(za-zb)));
}

int findfa(int son)
{
	int t=son,tmp;
	while(t!=father[t]) t=father[t];
	while(son!=father[son])
	{
		tmp=son;
		son=father[son];
		father[tmp]=t;
	}
	return t;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&h,&r);
		for(int a=0;a<=n+1;a++) father[a]=a;
		for(int a=1;a<=n;a++)
		{
			scanf("%d%d%d",&x[a],&y[a],&z[a]);
			if(z[a]+r>=h)
				if(findfa(a)!=findfa(n+1))
					father[findfa(a)]=findfa(n+1);
			if(z[a]-r<=0)
				if(findfa(a)!=findfa(0))
					father[findfa(a)]=findfa(0);
			for(int b=1;b<a;b++) 
				if(2*r>=dist(x[a],y[a],z[a],x[b],y[b],z[b]))
					if(findfa(a)!=findfa(b)) 
						father[findfa(a)]=findfa(b);
		}
		if(findfa(0)==findfa(n+1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
