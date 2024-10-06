#include<bits/stdc++.h>
using namespace std;
int n,id,x,nact,tim,actmov[100010],acttim[100010],actid[100010],movid[100010];
double tp,movtim[100010],movscr[100010];char op[2];	
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",op);
        if(op[0]=='R')
        {
            scanf("%d%d",&id,&x);
            movtim[id]=(++tim)/100000000.0;
            nact=0;
            for(int i=1;i<=x;++i)
            {
                scanf("%d",&actid[i]);
                if(actmov[actid[i]]&&acttim[actid[i]]>acttim[nact])nact=actid[i];
            }
            movscr[id]=movscr[actmov[nact]];
            for(int i=1;i<=x;++i)acttim[actid[i]]=tim,actmov[actid[i]]=id;
            movid[tim]=id;
            for(int i=tim;i>1;--i)
            {
                if(movscr[movid[i]]-movtim[movid[i]]>movscr[movid[i-1]]-movtim[movid[i-1]])swap(movid[i],movid[i-1]);
                else break;
            }
        }
        if(op[0]=='C')
        {
            scanf("%d%lf",&id,&tp);
            movscr[id]=(movscr[id]+tp)/2.0;
            for(int i=1;i<=tim;++i)
                if(movid[i]==id)
                {
                    for(int j=i;j<tim;++j)
                        movid[j]=movid[j+1];
                    movid[tim]=id;
                    for(int j=tim;j>1;--j)
                    {
                        if(movscr[movid[j]]-movtim[movid[j]]>movscr[movid[j-1]]-movtim[movid[j-1]])swap(movid[j],movid[j-1]);
                        else break;
                    }
                    break;
                }
        }
        if(op[0]=='Q')
        {
            scanf("%d",&x);
            printf("%d\n",movid[x]);
        }
    }
    return 0;
}
