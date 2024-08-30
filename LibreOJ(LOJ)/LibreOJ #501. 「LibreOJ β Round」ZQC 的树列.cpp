#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(int x)
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
vector<int>ans;
int main()
{
	ll k=read();
    ans.emplace_back(1);
    while(!(k&1))
    {
    	ans.emplace_back(2);
		k>>=1;
	} 
    ans.emplace_back(3);
    for(ll i=(1ll<<60)-1,v=0;i>1;i>>=1)
    {
    	ll tp=i,cnt=0;
    	while(tp)++cnt,tp>>=1;
    	while(!(k%i)&&i^63)
		{
            for(ll j=1;j<=cnt;++j)ans.emplace_back(v);
            v^=1,k/=i;
        }
	}  
	if(k>1)
	{
		puts("qnq");
		return 0;
	}
	write(ans.size()),puts("");
	for(auto i:ans)write(i),putchar(' ');
    return 0;
}
