#include<bits/stdc++.h>
using namespace std;
int m,t,s;
int main()
{
	cin>>m>>t>>s;
	if(t==0)cout<<0;
	else if(s%t==0)cout<<max(m-s/t,0);
	else cout<<max(m-s/t-1,0);
	return 0;
}
