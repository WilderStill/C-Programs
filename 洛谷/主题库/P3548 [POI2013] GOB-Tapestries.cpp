#include<bits/stdc++.h>
#define M 1010
#define ld long double
using namespace std;
const ld INF=1e9;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline ld readld()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return (ld)x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct point
{
	ld x,y;
	point(){}
    point(ld _x,ld _y):x(_x),y(_y){}
    friend point operator+(const point&p1,const point&p2)
    {
    	point res;
    	res.x=p1.x+p2.x;
    	res.y=p1.y+p2.y;
    	return res;
	}
    friend point operator-(const point&p1,const point&p2)
    {
    	point res;
    	res.x=p1.x-p2.x;
    	res.y=p1.y-p2.y;
    	return res;
	}
	friend ld operator^(const point&p1,const point&p2)
    {
    	return p1.x*p2.y-p2.x*p1.y;
	}
	friend bool operator!=(const point&p1,const point&p2)
    {
    	return (p1.x!=p2.x)||(p1.y!=p2.y);
	}
}p[M<<1];
struct line//x==y表示x与y间的一条边 
{
    point l,r;
    line(){}
    line(point _l,point _r):l(_l),r(_r){}
};
vector<line>qj; 
bool side_lt(point p1,point p2,point p3)//>0表示在左边，否则在右边 
{
	return ((p2-p1)^(p3-p2))>0;
}
bool cross(point p1,point p2,point p3,point p4)//判断是否有交点 
{
    return (side_lt(p2,p1,p3)^side_lt(p2,p1,p4))&&(side_lt(p4,p3,p1)^side_lt(p4,p3,p2));
}
ld query(point p1,point p2,point p3,point p4)
{
	return ((p4-p3)^(p1-p3))/((p1-p2)^(p3-p4));
}
int n,val[M<<1];
bool check(point p1,point p2)//判断答案是否在p1==p2上 
{
    ld l=-INF,r=INF;
	bool fg=0;
    for(auto i:qj)//不能被照亮的连续区间 
    {
        if(((p2-p1)^(i.r-i.l))==0)
        {
			if(p1!=i.l&&p2!=i.r)return 0;//交点不在同一处，无解
        }
        else 
        {
        	ld x=query(p1,p2,i.l,i.r);
            if(l!=-INF&&l!=x)return 0;//交点不在同一处，无解 
            l=r=x;
			fg=1;
		}
    }
    for(int i=1;i<=n;++i)//被照亮的部分 
        if(val[i])
        {
            if(((p2-p1)^(p[i]-p[i+1]))==0)
            {
                if(((p[i+1]-p[i])^(p1-p[i]))>0)return 0;//不在同一边，无解 
            }
            else
			{
				ld x=query(p1,p2,p[i],p[i+1]);
                if(fg&&(x==l))return 0;//能被照亮部分赋过值且求出值与原左端点相同，无解 
                if(((p2-p1)^(p[i+1]-p[i]))>0)l=max(l,x);
                else r=min(r,x);
                if(!fg&&l==r)return 0;//不能被照亮部分未赋值且值域左右端点相同，无解 
                if(l>r)return 0;//答案值域左端点大于右端点，无解 
			}
        }
    return 1;
}
bool solve()
{
	qj.clear();
	int l=1,r,kt;
	while(!val[l]&&l<=n)++l;
    if(l>n)return 0;//全都不能被照到，无解 
	for(r=l,kt=l;l<n+kt;l=++r)
	{
		if(!val[l])
		{
			while(!val[r])++r;//找未被照射的连续区间 
			bool l_lt=side_lt(p[l-1],p[l],p[r]);//l-1==l在直线l==r的位置（哪一侧） 
			bool r_rt=side_lt(p[l],p[r],p[r+1]);//r==r+1在直线l==r的位置（哪一侧） 
			if(l_lt==r_rt)return 0;//若区间左右的两条边在同一边，无解
			for(int i=l+1;i<r-1;++i)if(cross(p[i],p[i+1],p[l],p[r]))return 0;//如果区间中有边与直线l==r有交点，无解
			if(r>l+1)//区间内不止一条边
			{
				//如果区间中有部分在直线l==r右侧，无解 
				if(l_lt&&side_lt(p[r],p[l],p[l-1])!=side_lt(p[r],p[l],p[l+1]))return 0;
				if(r_rt&&side_lt(p[l],p[r],p[r-1])!=side_lt(p[l],p[r],p[r+1]))return 0;
			}
			qj.push_back(line(p[l],p[r]));//存下直线l==r
		}
	}
    if(!qj.size())//没有不能被照亮的区间 
    {
        for(int i=1;i<=n;++i)
            if(check(p[i],p[i+1]))return 1;
		/*
			答案的点一定在一些边所在的直线交出来的面上。
			那么相当于答案点在其中一条边所在的直线上。
			对于每条直线判断是否有点满足即可。 
		*/ 
        return 0;//没有则无解 
    }
    return check(qj[0].l,qj[0].r);
}
int main()
{
	int T=read();
    while(T--)
    {
        n=read();
        for(int i=1;i<=n;++i)p[i].x=readld(),p[i].y=readld();
        char s[2];
        for(int i=1;i<=n;++i)scanf("%s",s),val[i]=(s[0]=='S');
        for(int i=1;i<=n;++i)p[i+n]=p[i],val[i+n]=val[i];
        p[0]=p[n],val[0]=val[n];
        p[n<<1|1]=p[1],val[n<<1|1]=val[1];
        puts(solve()?"TAK":"NIE");
    }
    return 0;
}
