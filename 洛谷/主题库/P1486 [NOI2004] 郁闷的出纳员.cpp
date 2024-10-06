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
	int n,minn=0,tot=0;
	n=read(),minn=read();
	v.reserve(100010);
	for(int i=1;i<=n;++i)
	{
		char op[2];
		scanf("%s",op);
		int k=read();
		if(op[0]=='I')
		{
			if(k<minn)continue;
			v.insert(lower_bound(v.begin(),v.end(),k),k); 
		}
		if(op[0]=='A')for(auto&i:v)i+=k;
		if(op[0]=='S')for(int i=0;i<v.size();++i){v[i]-=k;if(v[i]<minn)v.erase(lower_bound(v.begin(),v.end(),v[i])),--i,++tot;}
		if(op[0]=='F')
		{
			if(k>v.size())puts("-1");
			else write(v[v.size()-k]),puts("");
		}
	}
	write(tot);
	return 0;
}
