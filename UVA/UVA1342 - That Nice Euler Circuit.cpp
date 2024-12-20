#include<bits/stdc++.h>
using namespace std;
namespace Geometry_2D
{
	typedef double ld;
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
	bool operator<(const Vector&A,const Vector&B){return A.x<B.x||(A.x==B.x&&A.y<B.y);}
	bool operator==(const Vector&A,const Vector&B){return !(equal(A.x-B.x)||equal(A.y-B.y));}
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
	bool SegmentProperIntersection(Segment s1,Segment s2)
	{
		ld t1=Cross((s1.B-s1.A),(s2.A-s1.A)),t2=Cross((s1.B-s1.A),(s2.B-s1.A));
		ld t3=Cross((s2.B-s2.A),(s1.A-s2.A)),t4=Cross((s2.B-s2.A),(s1.B-s2.A));
		return equal(t1)*equal(t2)<0&&equal(t3)*equal(t4)<0;
	}
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
	bool OnSegment(Point P,Segment s){return equal(Cross(s.A-P,s.B-P))==0&&equal(Dot(s.A-P,s.B-P))<0;}
	ld PolygonArea(Point*p,int n)
	{
		ld S=0;
		for(int i=1;i<n;++i)S+=(Cross(p[i]-p[1],p[i+1]-p[1])/2);
		return S;
	}
}
using namespace Geometry_2D;
Point P[300010],c[300010];
int cases=0,n;
int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;++i)scanf("%lf%lf",&P[i].x,&P[i].y),c[i]=P[i];
		--n;
		int cnt=n,e=n;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(SegmentProperIntersection(Segment(P[i],P[i+1]),Segment(P[j],P[j+1])))
					c[cnt++]=GetLineIntersection(Line(P[i],P[i+1]-P[i]),Line(P[j],P[j+1]-P[j]));
		sort(c,c+cnt);
		cnt=unique(c,c+cnt)-c;
		for(int i=0;i<cnt;++i)
			for(int j=0;j<n;++j)
				if(OnSegment(c[i],Segment(P[j],P[j+1])))++e;
		printf("Case %d: There are %d pieces.\n",++cases,e-cnt+2);
	}
	return 0;
}
