#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),sum=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;++i)
		{
			int v=read();
			sum+=v;
			cnt3+=(v/3);
			if(v%3==1)++cnt1;
			if(v%3==2)++cnt2;
		}
		if(cnt1+2*cnt2<=cnt3)write(sum/4+(sum/2)%2+sum%2);
		else
		{
			if(cnt3<=cnt1)write(cnt1+cnt2);
			else write(cnt2-(cnt3-cnt1)/2+cnt3);
		}
		puts("");
	}
	return 0;
}
