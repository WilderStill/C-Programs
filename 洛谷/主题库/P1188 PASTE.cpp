#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,k,doc[M],temp[M];
int main()
{
	scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
		doc[i]=i;
    for(int i=1;i<=k;i++)
    {
        int a,b,c,len,cnt=0;
        scanf("%d%d%d",&a,&b,&c);
        len=b-a+1;
        for(int j=a;j<=b;j++) temp[++cnt]=doc[j];
        if(c<a)
			for(int j=a-1;j>c;j--)
				doc[j+len]=doc[j];
        else
			for(int j=b+1;j<=c+len;j++) doc[j-len]=doc[j];
        for(int j=c+len;j>c;j--)
			doc[j]=temp[cnt--];
    }
    for(int i=1;i<=10;i++)
		printf("%d\n",doc[i]);
    return 0;
}
