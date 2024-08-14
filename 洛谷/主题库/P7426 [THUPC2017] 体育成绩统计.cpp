#include <bits/stdc++.h>
#define ll long long
using namespace std;
int Monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
map<ll,vector<int> > Studentlist;
struct Students
{
	ll Stdnum;
	char Sex;
	int PEscore;
	int Longrun[2];
	char PEexam;
	int Finalexam;
	int Taketimes;
	int Allscore=0;
	string Grades;
}Stdperson[11451];
struct Record
{
	ll Date;
	ll Stdnum;
	int Starttime[3],Endtime[3];
	double Rundistance;
	int Breaktime[2];
	int Footprint;
}Stdrecord[154114];
bool cmp(Record a,Record b)
{
	if(a.Date!=b.Date)return a.Date<b.Date;
	else if(a.Starttime[0]!=b.Starttime[0])return a.Starttime[0]<b.Starttime[0];
	else if(a.Starttime[1]!=b.Starttime[1])return a.Starttime[1]<b.Starttime[1];
	else return a.Starttime[2]<b.Starttime[2];
}
bool cmp2(Students a,Students b)
{
	return a.Stdnum<b.Stdnum;
}
int n,m;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld %c %d %d\'%d\" %c %d %d",&Stdperson[i].Stdnum,&Stdperson[i].Sex,&Stdperson[i].PEscore,&Stdperson[i].Longrun[0],&Stdperson[i].Longrun[1],&Stdperson[i].PEexam,&Stdperson[i].Finalexam,&Stdperson[i].Taketimes);
	sort(Stdperson+1,Stdperson+n+1,cmp2);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %lld %d:%d:%d %d:%d:%d %lf %d\'%d\" %d",&Stdrecord[i].Date,&Stdrecord[i].Stdnum,&Stdrecord[i].Starttime[0],&Stdrecord[i].Starttime[1],&Stdrecord[i].Starttime[2],&Stdrecord[i].Endtime[0],&Stdrecord[i].Endtime[1],&Stdrecord[i].Endtime[2],&Stdrecord[i].Rundistance,&Stdrecord[i].Breaktime[0],&Stdrecord[i].Breaktime[1],&Stdrecord[i].Footprint);
	}
	sort(Stdrecord+1,Stdrecord+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		Studentlist[Stdrecord[i].Stdnum].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		Stdperson[i].Allscore+=Stdperson[i].PEscore;
		Stdperson[i].Allscore+=Stdperson[i].Finalexam;
		Stdperson[i].Allscore+=Stdperson[i].PEexam=='P'?10:0;
		if(Stdperson[i].Sex=='M')
		{
			int Longruntime=Stdperson[i].Longrun[0]*60+Stdperson[i].Longrun[1];
			if(Longruntime<=750)Stdperson[i].Allscore+=20;
			else if(Longruntime<=780)Stdperson[i].Allscore+=18;
			else if(Longruntime<=810)Stdperson[i].Allscore+=16;
			else if(Longruntime<=840)Stdperson[i].Allscore+=14;
			else if(Longruntime<=870)Stdperson[i].Allscore+=12;
			else if(Longruntime<=910)Stdperson[i].Allscore+=10;
			else if(Longruntime<=950)Stdperson[i].Allscore+=8;
			else if(Longruntime<=990)Stdperson[i].Allscore+=6;
			else if(Longruntime<=1030)Stdperson[i].Allscore+=4;
			else if(Longruntime<=1080)Stdperson[i].Allscore+=2;
			else Stdperson[i].Allscore+=0;
		}
		else
		{
			int Longruntime=Stdperson[i].Longrun[0]*60+Stdperson[i].Longrun[1];
			if(Longruntime<=400)Stdperson[i].Allscore+=20;
			else if(Longruntime<=417)Stdperson[i].Allscore+=18;
			else if(Longruntime<=434)Stdperson[i].Allscore+=16;
			else if(Longruntime<=451)Stdperson[i].Allscore+=14;
			else if(Longruntime<=470)Stdperson[i].Allscore+=12;
			else if(Longruntime<=485)Stdperson[i].Allscore+=10;
			else if(Longruntime<=500)Stdperson[i].Allscore+=8;
			else if(Longruntime<=515)Stdperson[i].Allscore+=6;
			else if(Longruntime<=530)Stdperson[i].Allscore+=4;
			else if(Longruntime<=540)Stdperson[i].Allscore+=2;
			else Stdperson[i].Allscore+=0;
		}
		int Legalcnt=0,Lastdate,Lasttime,fg=0;
		for(int j=0;j<Studentlist[Stdperson[i].Stdnum].size();j++)
		{
			int Posid=Studentlist[Stdperson[i].Stdnum][j];
			int Endtm=Stdrecord[Posid].Endtime[2]+Stdrecord[Posid].Endtime[1]*60+Stdrecord[Posid].Endtime[0]*3600;
			int Starttm=Stdrecord[Posid].Starttime[2]+Stdrecord[Posid].Starttime[1]*60+Stdrecord[Posid].Starttime[0]*3600;
			int Lastingtime=Endtm-Starttm;
			int	Breaktime=Stdrecord[Posid].Breaktime[0]*60+Stdrecord[Posid].Breaktime[1];
			if(Stdrecord[Posid].Rundistance<(Stdperson[i].Sex=='M'?3.0:1.5)){continue;}
			if(Breaktime>270){continue;}
			double Runningspeed=Stdrecord[Posid].Rundistance*1000.0/Lastingtime;
			if(Runningspeed>5.0||Runningspeed<2.0){continue;}
			double Footdistance=Stdrecord[Posid].Rundistance*1000.0/Stdrecord[Posid].Footprint;
			if(Footdistance>1.5){continue;}
			if(fg==0){Legalcnt++;fg=1;Lastdate=Stdrecord[Posid].Date;Lasttime=Endtm;continue;}
			int Lastmonth=(Lastdate%10000-Lastdate%100)/100,Lastday=Lastdate%100;
			int Thismonth=(Stdrecord[Posid].Date%10000-Stdrecord[Posid].Date%100)/100,Thisday=Stdrecord[Posid].Date%100;
			if(Thismonth!=Lastmonth)
			{
				if(Thismonth-1!=Lastmonth){fg=1;Legalcnt++;Lastdate=Stdrecord[Posid].Date;Lasttime=Endtm;continue;}
				else
				{
					if(Monthday[Lastmonth]!=Lastday||Thisday!=1){fg=1;Legalcnt++;Lastdate=Stdrecord[Posid].Date;Lasttime=Endtm;continue;}
					else if(86400+Lasttime-Starttm<21600){fg=1;continue;}
				}
			}
			else if(Thisday!=Lastday)
			{
				if(Thisday-1!=Lastday){fg=1;Legalcnt++;Lastdate=Stdrecord[Posid].Date;Lasttime=Endtm;continue;}
				else if(86400+Lasttime-Starttm<21600){continue;}
			}
			else if(Starttm-Lasttime<21600){continue;}
			fg=1;Legalcnt++,Lastdate=Stdrecord[Posid].Date;Lasttime=Endtm;
		}
		if(Legalcnt>=21)Stdperson[i].Allscore+=10;
		else if(Legalcnt>=19)Stdperson[i].Allscore+=9;
		else if(Legalcnt>=17)Stdperson[i].Allscore+=8;
		else if(Legalcnt>=14)Stdperson[i].Allscore+=7;
		else if(Legalcnt>=11)Stdperson[i].Allscore+=6;
		else if(Legalcnt>=7)Stdperson[i].Allscore+=4;
		else if(Legalcnt>=3)Stdperson[i].Allscore+=2;
		else Stdperson[i].Allscore+=0;
		int Allcnt=Legalcnt+Stdperson[i].Taketimes;
		if(Allcnt>=18)Stdperson[i].Allscore+=5;
		else if(Allcnt>=15)Stdperson[i].Allscore+=4;
		else if(Allcnt>=12)Stdperson[i].Allscore+=3;
		else if(Allcnt>=9)Stdperson[i].Allscore+=2;
		else if(Allcnt>=6)Stdperson[i].Allscore+=1;
		else Stdperson[i].Allscore+=0;
		if(Stdperson[i].Allscore>=95)Stdperson[i].Grades="A";
		else if(Stdperson[i].Allscore>=90)Stdperson[i].Grades="A-";
		else if(Stdperson[i].Allscore>=85)Stdperson[i].Grades="B+";
		else if(Stdperson[i].Allscore>=80)Stdperson[i].Grades="B";
		else if(Stdperson[i].Allscore>=77)Stdperson[i].Grades="B-";
		else if(Stdperson[i].Allscore>=73)Stdperson[i].Grades="C+";
		else if(Stdperson[i].Allscore>=70)Stdperson[i].Grades="C";
		else if(Stdperson[i].Allscore>=67)Stdperson[i].Grades="C-";
		else if(Stdperson[i].Allscore>=63)Stdperson[i].Grades="D+";
		else if(Stdperson[i].Allscore>=60)Stdperson[i].Grades="D";
		else Stdperson[i].Grades="F";
	}
	for(int i=1;i<=n;i++)printf("%lld %d %s\n",Stdperson[i].Stdnum,Stdperson[i].Allscore,Stdperson[i].Grades.c_str());
	return 0;
}
