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
string s;
int main()
{
	int dg=read(),t=read(),v=0;
    int vd=(t+3)/6;
    if(dg<=112)s="N";
    else if(dg<=337)s="NNE";
    else if(dg<=562)s="NE";
    else if(dg<=787)s="ENE";
    else if(dg<=1012)s="E";
    else if(dg<=1237)s="ESE";
    else if(dg<=1462)s="SE";
    else if(dg<=1687)s="SSE";
    else if(dg<=1912)s="S";
    else if(dg<=2137)s="SSW";
    else if(dg<=2362)s="SW";
    else if(dg<=2587)s="WSW";
    else if(dg<=2812)s="W";
    else if(dg<=3037)s="WNW";
    else if(dg<=3262)s="NW";
    else if(dg<=3487)s="NNW";     
    else s="N";
    if(vd<=2)v=0;
    else if(vd<=15)v=1;
    else if(vd<=33)v=2;
    else if(vd<=54)v=3;
    else if(vd<=79)v=4;
    else if(vd<=107)v=5;
    else if(vd<=138)v=6;
    else if(vd<=171)v=7;
    else if(vd<=207)v=8;
    else if(vd<=244)v=9;
    else if(vd<=284)v=10;
    else if(vd<=326)v=11;
    else v=12;
    if(!v)puts("C 0");
    else printf("%s %d\n",s.c_str(),v);
    return 0;
}
