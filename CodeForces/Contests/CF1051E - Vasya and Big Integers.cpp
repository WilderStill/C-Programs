#include<bits/stdc++.h>
#define M 2134152
using namespace std;
const int p=998244353;
struct node_to_exkmp
{
    int len,nxt[M],ext[M];
    char str[M];
    void qnxt(char s[])
	{
		len=strlen(s+1);
        nxt[1]=len,str[1]=s[1];
        for(int i=2,l=0,r=0;i<=len;++i)
		{
            str[i]=s[i];
            if(i<=r)nxt[i]=min(nxt[i-l+1],r-i+1);
            while(i+nxt[i]<=len&&s[i+nxt[i]]==s[nxt[i]+1])++nxt[i];
            if(i+nxt[i]-1>r)r=i+nxt[i]-1,l=i;
        }
    }
    void exkmp(char s[])
	{
		int len2=strlen(s+1);
        for(int i=1,l=0,r=0;i<=len2;++i)
		{
            if(i<=r)ext[i]=min(nxt[i-l+1],r-i+1);
            while(i+ext[i]<=len2&&s[i+ext[i]]==str[ext[i]+1])++ext[i];
            if(i+ext[i]-1>r)r=i+ext[i]-1,l=i;
        }
    }
}lz,rz;
char num[M],l[M],r[M];
int g[M],f[M];
bool judge(int pos,int len)
{
    int p=lz.ext[pos];
    if(lz.len>=len&&p!=lz.len&&lz.str[p+1]>=num[pos+p])return 0;
    p=rz.ext[pos];
    if(rz.len<=len&&p!=rz.len&&rz.str[p+1]<=num[pos+p])return 0;
    return 1;
}
void pls(int &a,int b)
{
	a+=b;
	if(a>=p)a-=p;
	if(a<0)a+=p;
}
int main()
{
	scanf("%s%s%s",num+1,l+1,r+1);
	int numlen=strlen(num+1);
	lz.qnxt(l),lz.len=strlen(l+1);
	rz.qnxt(r),rz.len=strlen(r+1);
	lz.exkmp(num),rz.exkmp(num);
	f[0]=1;
	for(int i=0;i<=numlen;++i)
	{
		if(i)
		{
			pls(g[i],g[i-1]);
			pls(f[i],g[i]);
		}
		if(num[i+1]=='0')
		{
			if(lz.len==1&&lz.str[1]=='0')pls(f[i+1],f[i]);
			continue;
		}
		if(lz.len<rz.len)
		{
			pls(g[i+lz.len+1],f[i]);
			pls(g[i+rz.len],-f[i]);
		}
		if(judge(i+1,lz.len))pls(f[i+lz.len],f[i]);
		if(lz.len!=rz.len&&judge(i+1,rz.len))pls(f[i+rz.len],f[i]);
	}
	printf("%d",f[numlen]);
    return 0;
}
