#include<bits/stdc++.h>
using namespace std;
int cn,sn,ans;
struct things
{
	int l;
	int r;
}cow[114514],sunscreen[114514];
bool cmpl(things a,things b){return a.l<b.l;}
bool cmpr(things a,things b){return a.r<b.r;}
int main()
{
	scanf("%d%d",&cn,&sn);
	for(int i=1;i<=cn;i++) scanf("%d%d",&cow[i].l,&cow[i].r);
	for(int i=1;i<=sn;i++) scanf("%d%d",&sunscreen[i].l,&sunscreen[i].r);
	sort(cow+1,cow+cn+1,cmpr);
	sort(sunscreen+1,sunscreen+sn+1,cmpl);
	for(int i=1;i<=cn;i++)
	{
		for(int j=1;j<=sn;j++)
		{
			if(sunscreen[j].r&&sunscreen[j].l>=cow[i].l&&sunscreen[j].l<=cow[i].r)
			{
				sunscreen[j].r--;
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
