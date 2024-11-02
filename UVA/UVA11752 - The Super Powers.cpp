#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
inline ull read()
{
    ull x=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
inline void write(ull x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
priority_queue<ull,vector<ull>,greater<ull>>ans;
inline ull qpow(ull x,ull y)
{
	ull res=1;
	while(y)
	{
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
inline bool check(ull x)
{
	for(ull i=2;i*i<=x;++i)
		if(x%i==0)return 1;
	return 0;
}
const ull INF=qpow(2,64)-1;
const double syh=log(INF);
int main()
{
	ans.push(1);
    for(ull i=2;i<65536;++i)
	{
    	ull t=(syh/log(i));
		for(ull j=4;j<=t;++j)
			if(check(j))
				ans.push(qpow(i,j));
    }
    ull pos=0;
    while(!ans.empty())
	{
    	if(pos!=ans.top())write(ans.top()),puts("");
    	pos=ans.top();
		ans.pop();
	}
    return 0;
}
