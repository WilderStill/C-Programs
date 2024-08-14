#include<bits/stdc++.h>
using namespace std;
long long a[100009]={0,0,0};
int main()
{
    long long w,k;
    cin>>w>>k;
    for(int i=1;i<=k;i++)
	{
		a[i]=1;
	}
	for(int i=2;i<=k;i++)
    {
	    for(int j=1;j<i;j++)
			a[i]=(a[i]+a[j])%100003;
 	}
 	for(int i=k+1;i<=w;i++)
	{
    	for(int j=i-1;j>=i-k;j--)
	    {
	    	a[i]=(a[i]+a[j])%100003;
		}
	}
    cout<<a[w]<<endl;
	return 0;
}
