#include<bits/stdc++.h>
using namespace std;
char a[5008],b[5008];
int ans;
int main()
{
	cin>>(a+1)>>(b+1);
	for(int i=1,j=1;i<=strlen(a+1)&&j<=strlen(b+1);++i)
		if(a[i]==b[j])++j,++ans;
    cout<<ans;
	return 0;
} 
