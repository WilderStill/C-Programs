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
vector<int>v;
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)v.emplace_back(read());
	for(int i=1;i<=m;++i)
	{
		char op[7];
		scanf("%s",op);
		int s=read();
		if(op[0]=='T')
		{
			v.erase(find(v.begin(),v.end(),s));
			v.insert(v.begin(),s);
		}
		if(op[0]=='B')
		{
			v.erase(find(v.begin(),v.end(),s));
			v.insert(v.end(),s);
		}
		if(op[0]=='I')
		{
			int t=read(),x=find(v.begin(),v.end(),s)-v.begin();
			if(t)
			{
				v.erase(v.begin()+x);
				v.insert(v.begin()+t+x,s);
			}
		}
		if(op[0]=='A')
		{
			int x=find(v.begin(),v.end(),s)-v.begin();
			write(x),puts("");
		}
		if(op[0]=='Q')write(v[s-1]),puts("");
	}
    return 0;
}

