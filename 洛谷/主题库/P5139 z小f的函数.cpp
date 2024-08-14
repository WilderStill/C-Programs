#include<bits/stdc++.h>
#define ld double
#define pow2(x) x*x
#define topx(a1,b1,c1) -b1/(2*a1)
#define topy(a1,b1,c1) (4*a1*c1-pow2(b1))/(4*a1)
#define delta(a1,b1,c1) (pow2(b1)-4*a1*c1)
using namespace std;
void Genshin_1(ld a,ld &b,ld &c,ld k)
{
	ld d=-topx(a,b,c)-k,e=topy(a,b,c);
	c=e+pow2(d)*a;
	b=d*2*a;
	return;
}
void Genshin_2(ld &a,ld &b,ld &c,ld x1,ld y1)
{
	ld tt=topx(a,b,c);
	b=-(2*(a=-a))*(x1*2-tt);
	ld x2=2*x1,y2=y1*2-c;
	c=y2-a*pow2(x2)-b*x2;
	return;
}
void Genshin_3(ld a,ld b,ld c,ld k1,ld k2)
{
	if(k1>k2) swap(k1,k2);
	ld dl=pow2(k1)*a+k1*b+c,dr=pow2(k2)*a+k2*b+c;
	ld minn=min(dl,dr),maxx=max(dl,dr);
	if(topx(a,b,c)>=k1&&topx(a,b,c)<=k2)
	{
		minn=min(minn,pow2(topx(a,b,c))*a+topx(a,b,c)*b+c);
		maxx=max(maxx,pow2(topx(a,b,c))*a+topx(a,b,c)*b+c);
	}	
	printf("%.2lf %.2lf\n",minn,maxx);
	return;
}
int Genshin_4(ld a,ld b,ld c,ld u,ld v,ld w)
{
	a-=u,b-=v,c-=w;
	if(delta(a,b,c)>=0)return 2;
	else return 0;
}
int main()
{
	int zxf;
	scanf("%d",&zxf);
	while(zxf--)
	{
		ld a,b,c,tmp,tmp1,tmp2,u,v,w;
		int p,n;
		scanf("%lf%lf%lf%d",&a,&b,&c,&n);
		while(n--)
		{
			scanf("%d",&p);
			switch(p)
			{
				case 1:
				{
					scanf("%lf",&tmp);
					c+=tmp;
					break;
				}
				case 2:
				{
					scanf("%lf",&tmp);
					Genshin_1(a,b,c,tmp);
					break;	
				}
				case 3:
				{
					scanf("%lf%lf",&tmp1,&tmp2);
					Genshin_2(a,b,c,tmp1,tmp2);
					break;
				}
				case 4:
				{
					scanf("%lf%lf",&tmp1,&tmp2);
					Genshin_3(a,b,c,tmp1,tmp2);
					break;
				}
				case 5:
				{
					scanf("%lf%lf%lf",&u,&v,&w);
					printf("%d\n",Genshin_4(a,b,c,u,v,w));
					break;
				}
				default:while(true)printf("F**K B**CH!\n");break;
			}
		}
		printf("%.2lf\n",pow2(topx(a,b,c))*a+topx(a,b,c)*b+c);
	}
	return 0;
}
