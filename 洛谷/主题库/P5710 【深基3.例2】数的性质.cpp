#include<bits/stdc++.h>
using namespace std;
int x;
bool a[2];
int main()
{
	scanf("%d",&x);
	a[0]=!(x&1),a[1]=(x>4&&x<=12);
	printf("%d %d %d %d",a[0]&a[1],a[0]|a[1],(a[0]&&!a[1]||a[1]&&!a[0]),!a[0]&&!a[1]);
}
