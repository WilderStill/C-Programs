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
int n,ans,num[20010],pnum[20010],tp[20010];
inline void merge(int l,int r)
{
    if(l==r)return;
    int mid=l+r>>1,tl=l,td=mid+1,tr=l;
    merge(l,mid),merge(mid+1,r);
    while(tl<=mid&&td<=r)
    {
    	if(pnum[tl]<=pnum[td])tp[tr++]=pnum[tl++];
    	else tp[tr++]=pnum[td++],ans+=mid-tl+1;
	}
    while(tl<=mid)tp[tr++]=pnum[tl++];
    while(td<=r)tp[tr++]=pnum[td++];
    for(int i=l;i<=r;++i)pnum[i]=tp[i];
} 
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)pnum[i]=num[i]=read();
	merge(1,n);
	write(ans),puts("");
    int m=read();
    for(int i=1;i<=m;++i)
	{
        int l=read(),r=read();
        if(l>r)swap(l,r);
        if(num[l]<num[r])++ans;
		if(num[l]>num[r])--ans;
        for(int j=l+1;j<=r-1;++j)
		{
			if(num[l]>num[j])--ans;
			if(num[l]<num[j])++ans;
			if(num[j]>num[r])--ans;
        	if(num[j]<num[r])++ans;
        }
        swap(num[l],num[r]);
        write(ans),puts("");
    }
    return 0;
}

