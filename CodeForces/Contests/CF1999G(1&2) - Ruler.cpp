#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
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
int main()
{
	int T=read();
	while(T--)
	{
		int l=2,r=999,s,a,b,ans;
		while(l<=r)
		{
			a=(r+2*l)/3,b=(2*r+l)/3;
			putchar('?'),putchar(' '),write(a),putchar(' '),write(b),putchar('\n');
			cout.flush();
			s=read();
			if(s==(a+1)*(b+1))r=a-1,ans=a;
			else if(s==a*(b+1))l=ans=a+1,r=b-1;
			else l=ans=b+1;
		}
		putchar('!'),putchar(' '),write(ans),putchar('\n');
		cout.flush();
	}
	return 0;
}
