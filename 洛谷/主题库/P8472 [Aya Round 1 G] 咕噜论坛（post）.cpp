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
int sum[1010][1010][3];
inline int query(int id,int l,int r,int t){return sum[r][t][id]-sum[l-1][t][id];}
char s[1010][1010],ch;
int ans=-1,tx1,tx2,ty1,ty2;
int main()
{
    int n=read(),m=read(),k=read();
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
	        sum[i][j][0]=(s[i][j]=='P')+sum[i-1][j][0];
	        sum[i][j][1]=(s[i][j]=='G')+sum[i-1][j][1];
	        sum[i][j][2]=(s[i][j]=='B')+sum[i-1][j][2];
	    }
    for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
        	int sump=0,sumb=0,sumg=0,valp,valb,valg,lp=1,lb=1,lg=1,len=j-i+1;
        	for(int r=1;r<=m;++r)
			{
				sump+=(valp=query(0,i,j,r));
				sumg+=(valg=query(2,i,j,r));
				sumb+=(valb=query(1,i,j,r));
	            if(valp)lb=lg=r+1,sumb=sumg=0;
	            if(valb||valg)lp=r+1,sump=0;
	            while(lp<=r&&len*(r-lp+1)-sump>k)sump-=query(0,i,j,lp),++lp;
				while(lg<=r&&len*(r-lg+1)-sumg>k)sumg-=query(2,i,j,lg),++lg;
	            while(lb<=r&&len*(r-lb+1)-sumb>k)sumb-=query(1,i,j,lb),++lb;
	            if(len*(r-lp+1)>ans)ans=len*(r-lp+1),tx1=i,ty1=j,tx2=lp,ty2=r,ch='P';
	            if(len*(r-lb+1)>ans)ans=len*(r-lb+1),tx1=i,ty1=j,tx2=lb,ty2=r,ch='G';
	            if(len*(r-lg+1)>ans)ans=len*(r-lg+1),tx1=i,ty1=j,tx2=lg,ty2=r,ch='B';
        	}
    	}
    for(int i=tx1;i<=ty1;++i)
    	for(int j=tx2;j<=ty2;++j)
			s[i][j]=ch;
    write(ans),puts("");
    for(int i=1;i<=n;++i)puts(s[i]+1);
    return 0;
}

