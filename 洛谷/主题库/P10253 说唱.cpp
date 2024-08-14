#include<bits/stdc++.h>
#define M 511415
using namespace std;
char stin[M];
int num[M],sum,len,tenx;
bool fg=0;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(num,0,sizeof(num));
	    memset(stin,0,sizeof(stin));
        sum=tenx=fg=0;
        scanf("%s",stin);
        len=strlen(stin);
        for(int i=1;i<=len;++i)num[i]=stin[len-i]-'0';
	    while(!num[len]&&len>1)len--;
        if(len==1&&num[1]==0){puts("0");continue;}
	    for(int i=1;i<=len;++i)num[i]*=9;
        tenx=10-(num[1]%10);
        num[1]+=tenx;
        for(int i=1;i<=len;++i)
        {
            num[i+1]+=num[i]/10;
            num[i]%=10;
            sum+=num[i];
        }
        for(;num[len+1];len++)
        {
            num[len+2]+=num[len+1]/10;
            num[len+1]%=10;sum+=num[len+1];
        }
        for(int reg=1;reg<=500000;++reg)
        {
            if(tenx==sum)
            {
                for(int i=len;i>=2;i--)printf("%d",num[i]);
                puts("");
                fg=1;
                break;
            }
            tenx+=10;++num[2];++sum;
            for(int i=2;i<=len;++i)
            {
                if(num[i]<10)break;
                ++num[i+1];
                num[i]-=10;
                sum-=9;
            }
        }
        if(!fg)puts("-1");
    }    
    return 0;
}
