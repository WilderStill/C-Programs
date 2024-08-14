#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	if(h<6)h+=24;
	if(h<10)printf("0%d:",h);
	else printf("%d:",h);
	if(m<10)printf("0%d",m);
	else printf("%d",m);
}
int main()
{
	solve();
	return 0;
}
