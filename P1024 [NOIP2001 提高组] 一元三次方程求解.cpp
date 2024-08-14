#include<bits/stdc++.h>
using namespace std;
double num=0,x=0;
char c,unknown;
int ds[114514],tot=1,mid,fg=1;
int main()
{
    while(c!='=')
    {
        c=getchar();
        if(c=='-')++tot,fg=-1;
        if(c=='+')++tot,fg=1;
        if(isdigit(c))
        {
            if(!ds[tot])ds[tot]=(c-'0')*fg;
            else ds[tot]=ds[tot]*10+(c-'0')*fg;
        }
        if(c>='a'&&c<='z')
        {
            unknown=c;
            if(ds[tot]!=0)x+=ds[tot],ds[tot]=0;
            else x+=fg;
            --tot;
        }
    }
    mid=tot,++tot,fg=1;
    while(c!='\n')
    {
        c=getchar();
        if(c=='-')++tot,fg=-1;
        if(c=='+')++tot,fg=1;
        if(isdigit(c))
        {
            if(!ds[tot])ds[tot]=(c-'0')*fg;
            else ds[tot]=ds[tot]*10+(c-'0')*fg;
        }
        if(c>='a'&&c<='z')
        {
            unknown=c;
            if(ds[tot])x-=ds[tot],ds[tot]=0;
            else x-=fg; 
            --tot; 
        }
    }
    for(int i=1;i<=tot;i++)
    {
        if(i<=mid)num-=ds[i];
        else num+=ds[i]; 
    }
    if(!(num/x))printf("%c=0.000",unknown);
    else printf("%c=%.3lf",unknown,num/x);
    return 0; 
}
