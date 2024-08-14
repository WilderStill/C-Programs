#include<bits/stdc++.h>
using namespace std;
bool day;
int daynum=0,onday=0,outday=0,score=0;
int main()
{
    scanf("%d",&daynum);
    for(int i=0;i<daynum;i++)
    {
        scanf("%d",&day);
        if(day)
        {
            if(outday>0) onday-=pow(2,outday-1);
            if(onday<0) onday=0;
            score++,onday++,outday=0;
            if(onday>=3)score++;
            if(onday>=7)score++;
            if(onday>=30)score++;
            if(onday>=120)score++;
            if(onday>=365)score++;
        }
		else outday++;
    }
    printf("%d",score);
    return 0;
}
