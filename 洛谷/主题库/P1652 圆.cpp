#include<bits/stdc++.h>
using namespace std;
template<typename T>
double dist(T x_1,T y_1,T x_2,T y_2)
{
	return sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
}
int n,x_1,y_1,x_2,y_2,x[60],y[60],r[60],ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	for(int i=1;i<=n;++i)scanf("%d",&y[i]);
	for(int i=1;i<=n;++i)scanf("%d",&r[i]);
	scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
	for(int i=1;i<=n;++i)
		if(dist(x_1,y_1,x[i],y[i])<r[i]!=(dist(x_2,y_2,x[i],y[i]))<r[i])++ans;
	printf("%d",ans);
	return 0;
}
