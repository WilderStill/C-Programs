#include<bits/stdc++.h>
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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int n,a[1005],s[1005];
set<int>st;
inline bool check()
{
	int test=1010;
	while(test--)
	{
		random_shuffle(a+1,a+n+1);
		st.clear();
		st.insert(0);
		for(int i=1;i<n;++i)
		{
			s[i]=a[i]+s[i-1];
			if(st.count(s[i]))return 1;
			st.insert(s[i]); 
		}
	}
	return 0;
}
int main()
{
	srand(time(0));
	int T=read();
	while(T--)
	{
		n=read();
		int ave=0;
		for(int i=1;i<=n;++i)ave+=(a[i]=read());
		if(ave%n)
		{
			puts("No");
			continue; 
		}
		ave/=n;
		for(int i=1;i<=n;++i)a[i]-=ave; 
		puts(check()?"Yes":"No");
	}
	return 0;
}
