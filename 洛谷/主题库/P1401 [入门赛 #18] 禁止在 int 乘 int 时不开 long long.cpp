#include<bits/stdc++.h> 
#define ll long long
using namespace std;
bool f(ll x){return !(x>=-2147483648&&x<=2147483647);}
int main()
{
	ll x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	if(f(x1*y1)||f(x1*y2)||f(x2*y1)||f(x2*y2))cout<<"long long int"<<endl;
	else cout<<"int"<<endl;
	return 0;
}
