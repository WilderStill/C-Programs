#include<bits/stdc++.h>
using namespace std;
char ch;
struct point
{
	int W;
	int L;
}sc1[114514],sc2[114514];
int p1=1,p2=1;
int main()
{
	scanf("%c",&ch);
    while(ch!='E')
    {
    	if(ch=='W')sc1[p1].W++,sc2[p2].W++;
    	else if(ch=='L')sc1[p1].L++,sc2[p2].L++;
    	if((sc1[p1].W>=11||sc1[p1].L>=11)&&abs(sc1[p1].W-sc1[p1].L)>=2) p1++;
    	if((sc2[p2].W>=21||sc2[p2].L>=21)&&abs(sc2[p2].W-sc2[p2].L)>=2) p2++;
		scanf("%c",&ch);
	}
	for(int i=1;i<=p1;i++)printf("%d:%d\n",sc1[i].W,sc1[i].L);
	printf("\n");
	for(int i=1;i<=p2;i++)printf("%d:%d\n",sc2[i].W,sc2[i].L);
    return 0; 
}
