#include <stdio.h>
int main(){
    int n,k,a[100000],b[100000],j,t,i,sum1=0,sum2=0;
    float x,y;
    scanf("%d %d",&n,&k);
    for(i=1,j=0,t=0;i<=n;i++){
        if(i%k==0){
                a[j]=i;
                j=j+1;
        }
        else {
                b[t]=i;
                t=t+1;
        }
    }
    for(int p=0;p<j;p++)sum1=sum1+a[p];
    for(int p=0;p<t;p++)sum2=sum2+b[p];
    x=sum1*1.0/j;
    y=sum2*1.0/t;
    printf("%.1f %.1f",x,y);
    return 0;
}
