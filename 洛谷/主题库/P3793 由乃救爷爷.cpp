#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int n,m,s;
namespace GenHelper
{
    unsigned z1,z2,z3,z4,b;
    unsigned rand_()
    {
    b=((z1<<6)^z1)>>13;
    z1=((z1&4294967294U)<<18)^b;
    b=((z2<<2)^z2)>>27;
    z2=((z2&4294967288U)<<2)^b;
    b=((z3<<13)^z3)>>21;
    z3=((z3&4294967280U)<<7)^b;
    b=((z4<<3)^z4)>>12;
    z4=((z4&4294967168U)<<13)^b;
    return (z1^z2^z3^z4);
    }
}
inline void srand(unsigned x)
{
	using namespace GenHelper;
	z1=x;
	z2=(~x)^0x233333333U;
	z3=x^0x1234598766U;
	z4=(~x)+51;
}
inline int read()
{
    using namespace GenHelper;
    int a=rand_()&32767;
    int b=rand_()&32767;
    return a*32768+b;
}
struct node{int val,pos;}dg[20000010];
inline bool syh(node a,node b){return a.val<b.val;}
signed main()
{
	cin>>n>>m>>s;
	srand(s);
	for(int i=1;i<=n;++i)dg[i]={read(),i};
	sort(dg+1,dg+n+1,syh);
	while(m--)
	{
		int l=read()%n+1,r=read()%n+1;
		if(l>r)swap(l,r);
		for(int i=n;i;--i)
		{
			if(dg[i].pos>=l&&dg[i].pos<=r)
			{
				ans+=dg[i].val;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
