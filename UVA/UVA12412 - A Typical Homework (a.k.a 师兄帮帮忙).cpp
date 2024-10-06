#include<bits/stdc++.h>
using namespace std;
struct student
{
    string SID,Name;
    int CID,Chinese,Mathematics,English,Programming,Rank,Input_ID,Total_Score;
    double Average_Score;
};
const int INF=0x3f3f3f3f;
const double eps=1e-5;
student List[114514];
int Student_Counter;
unordered_map<string,int>All_SID;
inline void PrintContent()
{
	puts("Welcome to Student Performance Management System (SPMS).");
	puts("");
	puts("1 - Add");
	puts("2 - Remove");
	puts("3 - Query");
	puts("4 - Show ranking");
	puts("5 - Show Statistics");
	puts("0 - Exit");
	puts("");
}
inline void Add()
{
	puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
    while(true)
    {
		string SID,Name;
    	int CID,Chinese,Mathematics,English,Programming;
    	cin>>SID;
        if(SID=="0")return;
        cin>>CID>>Name>>Chinese>>Mathematics>>English>>Programming;
        if(All_SID[SID])
        {
            puts("Duplicated SID.");
            puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
            continue;
        }
        All_SID[SID]=++Student_Counter;
        student syh;
        syh.SID=SID;
		syh.CID=CID;
		syh.Name=Name;
		syh.Chinese=Chinese;
		syh.Mathematics=Mathematics;
		syh.English=English;
		syh.Programming=Programming;
		syh.Total_Score=Chinese+Mathematics+English+Programming;
		syh.Average_Score=1.0*syh.Total_Score/4.0+eps;
        syh.Input_ID=Student_Counter;
        List[Student_Counter]=syh;
        puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
    }
    return;
}
inline void Remove()
{
	puts("Please enter SID or name. Enter 0 to finish.");
    while(true)
    {
		string SID_Or_Name;
    	cin>>SID_Or_Name;
        if(SID_Or_Name=="0")return;
        int cnt=0;
        for(int i=1;i<=Student_Counter;++i)
        {
        	if(List[i].SID==SID_Or_Name||List[i].Name==SID_Or_Name)
        	{
        		++cnt;
        		All_SID[List[i].SID]=0;
        		List[i].SID="";
        		List[i].Name="";
        		List[i].CID=-1;
        		List[i].Total_Score=-1;
        		List[i].Chinese=-1;
        		List[i].Mathematics=-1;
        		List[i].English=-1;
        		List[i].Programming=-1;
        		List[i].Input_ID=INF;
			}
		}
        printf("%d student(s) removed.\n",cnt);
        puts("Please enter SID or name. Enter 0 to finish.");
    }
    return;
}
inline void Query()
{
    puts("Please enter SID or name. Enter 0 to finish.");
    sort(List+1,List+Student_Counter+1,[](student lkz,student czr){return lkz.Total_Score>czr.Total_Score;});
    for(int i=1;i<=Student_Counter;++i)
    {
    	if(List[i-1].Total_Score==List[i].Total_Score)List[i].Rank=List[i-1].Rank;
    	else List[i].Rank=i;
	}
	sort(List+1,List+Student_Counter+1,[](student lkz,student czr){return lkz.Input_ID<czr.Input_ID;});
    while(true)
    {
    	string SID_Or_Name;
    	cin>>SID_Or_Name;
        if(SID_Or_Name=="0")return;
        for(int i=1;i<=Student_Counter;++i)
        	if(List[i].SID==SID_Or_Name||List[i].Name==SID_Or_Name)
        		cout<<List[i].Rank<<" "<<List[i].SID<<" "<<List[i].CID<<" "<<List[i].Name<<" "<<List[i].Chinese<<" "<<List[i].Mathematics<<" "<<List[i].English<<" "<<List[i].Programming<<" "<<List[i].Total_Score<<" ",
        		printf("%.2f\n",List[i].Average_Score);
        puts("Please enter SID or name. Enter 0 to finish.");
    }
    return;
}
inline void Show_ranking()
{
	puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
	return;
}
inline void Show_Statistics()
{
	puts("Please enter class ID, 0 for the whole statistics.");
    int CID,Chinese_Count=0,Mathematics_Count=0,English_Count=0,Programming_Count=0,Passer[5]={0,0,0,0,0};
    double Chinese_Total_Score=0,Mathematics_Total_Score=0,English_Total_Score=0,Programming_Total_Score=0;
    cin>>CID;
    if(CID==0)
    {
    	int Student_Total=0;
        for(int i=1;i<=Student_Counter;++i)
        {
        	if(~List[i].CID)
        	{
        		++Student_Total;
        		int cnt=0;
	            if(List[i].Chinese>=60)++Chinese_Count,++cnt;
	            Chinese_Total_Score+=List[i].Chinese;
	            if(List[i].Mathematics>=60)++Mathematics_Count,++cnt;
	            Mathematics_Total_Score+=List[i].Mathematics;
	            if(List[i].English>=60)++English_Count,++cnt;
	            English_Total_Score+=List[i].English;
	            if(List[i].Programming>=60)++Programming_Count,++cnt;
	            Programming_Total_Score+=List[i].Programming;
	            for(int i=1;i<=cnt;++i)++Passer[i];
	            if(cnt==0)++Passer[0];
			}
        }
        puts("Chinese");
        printf("Average Score: %.2f\n",Chinese_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",Chinese_Count);
		printf("Number of failed students: %d\n",Student_Total-Chinese_Count);
		puts("");
		puts("Mathematics");
        printf("Average Score: %.2f\n",Mathematics_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",Mathematics_Count);
		printf("Number of failed students: %d\n",Student_Total-Mathematics_Count);
		puts("");
		puts("English");
        printf("Average Score: %.2f\n",English_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",English_Count);
		printf("Number of failed students: %d\n",Student_Total-English_Count);
		puts("");
		puts("Programming");
        printf("Average Score: %.2f\n",Programming_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",Programming_Count);
		printf("Number of failed students: %d\n",Student_Total-Programming_Count);
		puts("");
		puts("Overall:");
        printf("Number of students who passed all subjects: %d\n",Passer[4]);
        printf("Number of students who passed 3 or more subjects: %d\n",Passer[3]);
		printf("Number of students who passed 2 or more subjects: %d\n",Passer[2]);
		printf("Number of students who passed 1 or more subjects: %d\n",Passer[1]);
		printf("Number of students who failed all subjects: %d\n",Passer[0]);
		puts("");
    }
    else
    {
    	int Student_Total=0;
    	for(int i=1;i<=Student_Counter;++i)
        {
            if(List[i].CID==CID)
            {
				int cnt=0;
            	++Student_Total;
            	if(List[i].Chinese>=60)++Chinese_Count,++cnt;
	            Chinese_Total_Score+=List[i].Chinese;
	            if(List[i].Mathematics>=60)++Mathematics_Count,++cnt;
	            Mathematics_Total_Score+=List[i].Mathematics;
	            if(List[i].English>=60)++English_Count,++cnt;
	            English_Total_Score+=List[i].English;
	            if(List[i].Programming>=60)++Programming_Count,++cnt;
	            Programming_Total_Score+=List[i].Programming;
	            for(int i=1;i<=cnt;++i)++Passer[i];
            	if(cnt==0)++Passer[0];
			}
        }
        puts("Chinese");
        printf("Average Score: %.2f\n",Chinese_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",Chinese_Count);
		printf("Number of failed students: %d\n",Student_Total-Chinese_Count);
		puts("");
		puts("Mathematics");
        printf("Average Score: %.2f\n",Mathematics_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",Mathematics_Count);
		printf("Number of failed students: %d\n",Student_Total-Mathematics_Count);
		puts("");
		puts("English");
        printf("Average Score: %.2f\n",English_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",English_Count);
		printf("Number of failed students: %d\n",Student_Total-English_Count);
		puts("");
		puts("Programming");
        printf("Average Score: %.2f\n",Programming_Total_Score/(double)Student_Total+eps);
        printf("Number of passed students: %d\n",Programming_Count);
		printf("Number of failed students: %d\n",Student_Total-Programming_Count);
		puts("");
		puts("Overall:");
        printf("Number of students who passed all subjects: %d\n",Passer[4]);
        printf("Number of students who passed 3 or more subjects: %d\n",Passer[3]);
		printf("Number of students who passed 2 or more subjects: %d\n",Passer[2]);
		printf("Number of students who passed 1 or more subjects: %d\n",Passer[1]);
		printf("Number of students who failed all subjects: %d\n",Passer[0]);
		puts("");
    }
    return;
}
inline void Exit()
{
	exit(0);
	return;
}
int main()
{
	while(true)
	{
		PrintContent();
		int operation;
		cin>>operation;
		switch(operation)
		{
			case 1:{Add();break;}
			case 2:{Remove();break;}
			case 3:{Query();break;}
			case 4:{Show_ranking();break;}
			case 5:{Show_Statistics();break;}
			case 0:{Exit();break;}
			default:break;
		}
	} 
    return 0;
}
