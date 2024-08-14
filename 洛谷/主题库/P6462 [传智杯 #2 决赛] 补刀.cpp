#include<bits/stdc++.h> 
#define ll long long
using namespace std;
ll h,x,y,t;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&h,&x,&y);
		if(y>=h){printf("Yes\n");continue;}
		if(x>=h){printf("No\n");continue;}
		if(!y){printf("No\n");continue;}
		if(!x){printf("Yes\n");continue;}
		ll tmp=h/x+1;
		h%=x;
		if(!h)h=x;
		if(tmp*y>=h){printf("Yes\n");continue; }
		else{printf("No\n");continue;}
	}
}
 
