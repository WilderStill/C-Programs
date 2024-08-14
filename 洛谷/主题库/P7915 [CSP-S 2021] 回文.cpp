#include<bits/stdc++.h>
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
int n,num[1000010],posl[1000010],posr[1000010];
char ans[1000010];
bool check(int pos,int L,int R)
{
	ans[1]=L^2?'R':'L';
	int l=pos,r=pos,s=2,t=2*n-1;
	for(int i=1;i<n;++i)
	{
		if(posr[num[L]]==l-1)l--,L++,ans[s++]='L',ans[t--]='L';
		else if(posr[num[L]]==r+1)r++,L++,ans[s++]='L',ans[t--]='R';
		else if(posl[num[R]]==l-1)l--,R--,ans[s++]='R',ans[t--]='L';
		else if(posl[num[R]]==r+1)r++,R--,ans[s++]='R',ans[t--]='R';
		else return 0;
	}
	ans[2*n]='L';
	return 1;
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		memset(posl,0,sizeof posl);
		memset(posr,0,sizeof posr);
		memset(ans,0,sizeof ans);
		for(int i=1;i<=2*n;++i)
		{
			num[i]=read();
			if(posl[num[i]])posr[num[i]]=i;
			else posl[num[i]]=i;
		}
		if(check(posr[num[1]],2,2*n))printf("%s\n",ans+1);
		else if(check(posl[num[2*n]],1,2*n-1))printf("%s\n",ans+1);
		else puts("-1");
	}
    return 0;
}
