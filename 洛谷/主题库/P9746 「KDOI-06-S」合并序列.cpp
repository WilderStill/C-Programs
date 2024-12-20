#include<bits/stdc++.h>
#define int unsigned short
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
set<vector<int>>mp;
struct node{int i,j,k;};
vector<node>step;
bool fg;
int n,cnt;
inline void print()
{
    puts("Huoyu");
    write(step.size()),puts("");
    for(auto tp:step)
	{
		write(tp.i),putchar(' ');
        write(tp.j),putchar(' ');
        write(tp.k),putchar('\n');
    }
}
inline void dfs(vector<int>&num)
{
	++cnt;
	if(cnt>=40000)return;
    if(fg)return;
    if(num.size()==1)
	{
        fg=1,print();
        return;
    }
    if(mp.count(num)||num.size()<3)return;
    mp.insert(num);
    vector<int>tp=num;
    int len=num.size();
    for(int i=0;i<(n>=400?2:(n<=27?n:3));++i) 
        for(int j=i+1;j<len;++j)
        {
        	int syh=num[i]^num[j];
        	for(int k=j+1;k<len;++k) 
                if(!(syh^num[k]))
				{
                    step.push_back({i+1,j+1,k+1});
                    int sum=0;
                    for(int l=i;l<=k;++l)sum^=num[l];
                    num.insert(num.begin()+i,sum);
                    num.erase(num.begin()+i+1,num.begin()+k+2);
                    dfs(num);
                    num=tp;
                    step.pop_back();
                }
		}
            
}
signed main()
{
	//freopen("P9746_21.in","r",stdin);
    int T=read();
    while(T--)
	{
        vector<int>num(n=read());
        mp.clear();step.clear();
        fg=cnt=0;
        for(auto &i:num)i=read();
        dfs(num);
        if(!fg)puts("Shuiniao");
    }
    return 0;
}

