#include<bits/stdc++.h>
using namespace std;
const int M=1e5+4;
namespace Geometry_2D
{
	typedef long double ld;
	const ld eps=1e-10;
	int equal(ld x)
	{
		if(fabs(x)<eps)return 0;
		return x<0?-1:1;
	}
	struct Point
	{
		ld x,y;
		Point(ld _x=0,ld _y=0){x=_x,y=_y;}
	};
	typedef Point Vector;
	Vector operator+(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
	Vector operator-(Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
	Vector operator*(Vector A,ld p){return Vector(A.x*p,A.y*p);}
	Vector operator/(Vector A,ld p){return Vector(A.x/p,A.y/p);}
    bool operator==(const Vector&A,const Vector&B){return !(equal(A.x-B.x)||equal(A.y-B.y));}
	bool operator<(const Vector&A,const Vector&B){return A.x<B.x||(equal(A.x-B.x)==0&&A.y<B.y);}
	ld Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
	ld Module(Vector A){return sqrt(A.x*A.x+A.y*A.y);}
	ld Dist(Point A,Point B){return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));}
	ld Angle(Vector A,Vector B){return acos(Dot(A,B)/(Module(A)*Module(B)));}
	ld Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
	ld Area(Vector A,Vector B,Vector C){return Cross(B-A,C-A)/2;}
	Vector Rotate(Vector A,ld rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
	Vector Normal(Vector A)
	{
		ld Mod=Module(A);
		return Vector(-A.y/Mod,A.x/Mod);
	}
	struct Line
	{
		Point P;
		Vector V;
		Line(Point p,Vector v){P=p,V=v;}
	};
	struct Segment
	{
		Point A,B;
		Segment(Point a,Point b){A=a,B=b;}
	};
	Vector GetDirect(Point A,Point B){return Vector(B.x-A.x,B.y-A.y);}
    ld Link(Point A,Point B,Point P){return Cross(GetDirect(A,B),GetDirect(A,P));}
	Point GetLineIntersection(Line l1,Line l2)
	{
		Vector tv=l1.P-l2.P;
		ld tp=Cross(l2.V,tv)/Cross(l1.V,l2.V);
		return l1.P+l1.V*tp;
	}
	ld GetPointLineDist(Point P,Line l)
	{
		Vector tv=P-l.P;
		return fabs(Cross(tv,l.V))/Module(l.V);
	}
	ld GetPointSegDist(Point P,Segment l)
	{
		if(l.A==l.B)return Module(P-l.A);
		Vector u=l.B-l.A,v=P-l.A,w=P-l.B;
		if(equal(Dot(u,v))<0)return Module(v);
		if(equal(Dot(u,w))>0)return Module(w);
		return fabs(Cross(u,v))/Module(u);
	}
	Point GetLineProjection(Point P,Line l)
	{
		Vector tv=P-l.P;
		return l.P+l.V*(Dot(l.V,P-l.P)/Module(l.V));
	}
	bool OnSegment(Point P,Segment l){return !equal(Cross(l.A-P,l.B-P))&&equal(Dot(l.A-P,l.B-P))<0;}
	ld PolygonArea(Point*p,int n)
	{
		ld S=0;
		for(int i=1;i<n;++i)S+=(Cross(p[i]-p[1],p[i+1]-p[1])/2);
		return S;
	}
}
using namespace Geometry_2D;
Point p[M],stk[M<<1];
inline int Andrew(int n)
{
    sort(p+1,p+n+1);
    if(n<3)return -1;
    stk[0]=p[1],stk[1]=p[2];
    int top=1;
    for(int i=3;i<=n;++i)
	{
        while(top&&Link(stk[top-1],stk[top],p[i])<0)--top;
        stk[++top]=p[i];
    }
    stk[++top]=p[n-1];
    for(int i=n-2;i;--i)
	{
        while(top&&Link(stk[top-1],stk[top],p[i])<0)--top;
        stk[++top]=p[i];
    }
    return top;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%Lf%Lf",&p[i].x,&p[i].y);
    ld ans=0;
    int tk=Andrew(n);
    if(tk==-1)
    {
        puts("0.00");
        return 0;
    }
    for(int i=0;i<tk;++i)ans+=Dist(stk[i],stk[i+1]);
    printf("%.2Lf",ans);
    return 0;
} 
