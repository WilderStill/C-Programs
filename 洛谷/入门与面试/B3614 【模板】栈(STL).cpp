#include<bits/stdc++.h>
#define int unsigned long long
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
stack<int>stk;
signed main()
{
	int T=read();
	while(T--)
	{
		while(!stk.empty())stk.pop();
		int n=read();
		while(n--)
		{
			char op[6];
			scanf("%s",op);
			if(op[0]=='p')
			{
				if(op[1]=='u')stk.push(read());
				else
				{
					if(stk.empty())puts("Empty");
					else stk.pop();
				}
			}
			if(op[0]=='q')
			{
				if(!stk.empty())
				{
					write(stk.top()),puts("");
				}
				else
				{
					puts("Anguei!");
				}
			}
			if(op[0]=='s')
			{
				write(stk.size()),puts("");
			}
		}
	}
    return 0;
}

