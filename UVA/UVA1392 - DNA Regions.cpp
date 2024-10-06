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
struct node
{
    int pos,num;
    bool operator <(node b){return num^b.num?num>b.num:pos<b.pos;}
}syh[200001];
char s1[200001],s2[200001];
int main()
{
    while(true)
    {
        int n=read(),p=read(),cnt=0;
        if(!n&&!p)return 0;
        scanf("%s%s",s1+1,s2+1);
        syh[0]={0,0};
        for(int i=1;i<=n;++i)
        {
            if(s1[i]!=s2[i])++cnt;	
            syh[i].num=cnt*100-i*p;
            syh[i].pos=i;
        }
        sort(syh,syh+n+1);
        int id=syh[0].pos,res=0;
        for(int i=1;i<=n;++i)
        {
            if(syh[i].pos<id)id=syh[i].pos;
            else res=max(res,syh[i].pos-id);
        }
        if(!res)puts("No solution.");
        else write(res),puts("");
    } 
}
