#include<bits/stdc++.h>
using namespace std;
int a[5][5]={{0,0,0,0,0},{0,5,18,73,267},{0,18,150,1533,11398},{0,73,1533,31828,469972},{0,267,11398,469972,12785753}};
int t,m,n;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<a[n-1][m-1]<<endl;
	}
    return 0;//打表，但正解就是打表 
}
