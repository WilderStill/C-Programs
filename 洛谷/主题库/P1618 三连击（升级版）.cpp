#include<bits/stdc++.h>
using namespace std;
int a,b,c,p[15],ans=0;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(!a||!b||!c)
	{
		cout<<"No!!!";
		return 0;
	}
    for(int i=123;i<=987;++i)
    {
        p[1]=i%10;
        p[2]=i%100/10;
        p[3]=i/100;
        p[4]=(b*i/a)%10;
        p[5]=(b*i/a)%100/10;
        p[6]=(b*i/a)/100;
        p[7]=(c*i/a)%10;
        p[8]=(c*i/a)%100/10;
        p[9]=(c*i/a)/100;
        sort(p+1,p+10);
        ans++;
		bool fg=1;
        for(int j=1;j<=9;j++)
		if(p[j]!=j)
		{
			ans--,fg=0;
			break;
		}
        if(fg)cout<<i<<" "<<i/a*b<<" "<<i/a*c<<endl;
    }
    if(!ans)cout<<"No!!!";
    return 0;
}
