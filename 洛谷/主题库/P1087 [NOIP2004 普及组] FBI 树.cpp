#include<bits/stdc++.h>
#define lim 11451411
using namespace std;
int n;
char in[lim];
bool check(int l,int r)
{
	for(int i=l+1;i<=r;i++)
		if(in[i]!=in[l])
			return 0;
	return 1;
} 
void solve(int l,int r)
{
	if(l!=r)
	{
		int mid=(l+r)/2;
		solve(l,mid);
		solve(mid+1,r);
		if(check(l,r)) printf("%c",in[l]=='0'?'B':'I');
		else printf("F");
		return;
	}
	if(check(l,r)) printf("%c",in[l]=='0'?'B':'I');
	else printf("F");
	return ;
}
int main()
{
	scanf("%d",&n);
    scanf("%s",in);
    solve(0,strlen(in)-1);
    return 0;
}
