#include<bits\stdc++.h>
#define M 114514
using namespace std;
int a[M],p,x,y,ans,posx;
void santen(int s)
{
	int i=(s/50)%475;
	for(int j=1;j<=26;j++){i=(i*96+42)%475;a[j]=i+26;}
	sort(a+1,a+26);
}
int main()
{
	scanf("%d%d%d",&p,&x,&y);posx=x;
	while(x>=y+50)x-=50; 
	while(true)
	{
		santen(x);
		if(binary_search(a+1,a+26,p))break;
		x+=50;
	}
	printf("%d\n",x<posx?0:(int)ceil((x-posx)*1.00/100));
	return 0;
}
