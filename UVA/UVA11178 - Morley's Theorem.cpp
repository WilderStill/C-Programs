#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
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
	bool operator<(const Vector&A,const Vector&B){return A.x==B.x?A.x<B.x:A.y<B.y;}
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
Point GetDot(Point A,Point B,Point C)
{
	Vector u=C-B,v=B-C;
	u=Rotate(u,Angle(A-B,u)/3);
	v=Rotate(v,-Angle(A-C,v)/3);
	return GetLineIntersection(Line(B,u),Line(C,v));
}
int main()
{
	int T=read();
	while(T--)
	{
		Point A,B,C;
		scanf("%Lf%Lf%Lf%Lf%Lf%Lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		Point D=GetDot(A,B,C);
		Point E=GetDot(B,C,A);
		Point F=GetDot(C,A,B);
		printf("%.6Lf %.6Lf %.6Lf %.6Lf %.6Lf %.6Lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
	}
	return 0;
}
