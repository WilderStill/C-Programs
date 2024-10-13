#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const ld eps=1e-9;
struct point
{
	ld x,y;
}p[5000100];
ld nowr;
int n;
ld dist(int id1,int id2)
{
	return sqrt((p[id1].x-p[id2].x)*(p[id1].x-p[id2].x)+(p[id1].y-p[id2].y)*(p[id1].y-p[id2].y));
}
bool isInRound(int id)
{
	return dist(id,n+1)-nowr<eps;
}
point getRound(int id1,int id2,int id3)
{
    return {((p[id2].y-p[id1].y)*((pow(p[id3].x,2)+pow(p[id3].y,2))-(pow(p[id2].x,2)+pow(p[id2].y,2)))-((pow(p[id2].x,2)+pow(p[id2].y,2))-(pow(p[id1].x,2)+pow(p[id1].y,2)))*(p[id3].y-p[id2].y))/((p[id3].x-p[id2].x)*(p[id2].y-p[id1].y)-(p[id2].x-p[id1].x)*(p[id3].y-p[id2].y))/2,((p[id2].x-p[id1].x)*((pow(p[id3].x,2)+pow(p[id3].y,2))-(pow(p[id2].x,2)+pow(p[id2].y,2)))-((pow(p[id2].x,2)+pow(p[id2].y,2))-(pow(p[id1].x,2)+pow(p[id1].y,2)))*(p[id3].x-p[id2].x))/((p[id2].x-p[id1].x)*(p[id3].y-p[id2].y)-(p[id2].y-p[id1].y)*(p[id3].x-p[id2].x))/2}; 
}
mt19937 sdg(time(0));
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
	    for(int i=1;i<=n;++i)scanf("%lf %lf",&p[i].x,&p[i].y);
	    p[n+1]=p[1];nowr=0;
	    for(int i=1;i<=n;++i)
		    if(!isInRound(i))
		    {
		        p[n+1]=p[i];
		        for(int j=1;j<i;++j)
			        if(!isInRound(j))
			        {
			            p[n+1].x=(p[i].x+p[j].x)/2;
			            p[n+1].y=(p[i].y+p[j].y)/2;
			            nowr=dist(i,j)/2;
			            for(int k=1;k<j;++k)
				            if(!isInRound(k))
				            {
				                p[n+1]=getRound(i,j,k);
				                nowr=dist(n+1,i);
				            }
			        }
		    }
	    printf("%.2lf\n%.2lf %.2lf\n",nowr,p[n+1].x,p[n+1].y);
	}
    return 0;
}
