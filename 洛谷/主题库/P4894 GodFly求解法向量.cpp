#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d,e,f;
int main()
{
	//��Ⱑ���~~~~~~ 
	//ʮ��OIһ����~~~~~~ 
    while(~scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f))
    	printf("%lld %lld %lld\n",b*f-c*e,c*d-a*f,a*e-b*d);
    return 0;
}
