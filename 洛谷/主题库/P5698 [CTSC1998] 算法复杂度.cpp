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
const int num_n=-114514;
struct node
{
	node(node*_fa,int _val,bool _lf):fa(_fa),val(_val),lf(_lf){return;}
    int val;bool lf;
    vector<node>son;
	node*fa;
};
inline int ctoi(char str[])
{
	int x=0,len=strlen(str);
    for(int i=0;i<len;++i)x=(x<<3)+(x<<1)+(str[i]&15);
    return x;
}
char op[10],num[20],tp[10];
int ans[31];
inline void breakend()
{
	int dep=1;
    while(dep)
	{
        scanf("%s",tp);
        if(tp[0]=='l')++dep;
        if(tp[0]=='e')--dep;
    }
}
inline void dfs(node p,int pos,int val)
{
    if(p.lf)
	{
        ans[pos]+=val;
        return;
    }
    for(auto i:p.son)
	{
		if(i.val^num_n)dfs(i,pos,val*i.val);
		else dfs(i,pos+1,val);
	}
}
node rt(nullptr,0,0),*p=&rt;
int main()
{
	while(true)
	{
		scanf("%s",op);
        if(op[0]=='o')
		{
            scanf("%s",num);
            p->son.emplace_back((node){p,num[0]=='n'?num_n:ctoi(num),1});
        }
		if(op[0]=='l')
		{
            scanf("%s",num);
            if(strlen(num)==1&&num[0]=='0')num[0]='n';
            p->son.emplace_back((node){p,num[0]=='n'?num_n:ctoi(num),0});
            p=&p->son.back();
        }
		if(op[0]=='b')
		{
            if(p==&rt)continue;
            p->val=1;
            p=p->fa;
            breakend();
        }
		if(op[0]=='c')
		{
            if(p==&rt)continue;
            p=p->fa;
            breakend();
        }
		if(op[0]=='e')
		{
            if(p==&rt)break;
            p=p->fa;
        }
    }
    dfs(rt,0,1);
    bool st=1;
    for(int i=30;~i;--i)
        if(ans[i])
		{
            if(!st)putchar('+');st=0;
            if(ans[i]^1||!i)write(ans[i]);
            if(i>1)putchar('n'),putchar('^'),write(i);
            else if(i==1)putchar('n');
        }
    if(st)write(0);
    puts("");
    return 0;
}

