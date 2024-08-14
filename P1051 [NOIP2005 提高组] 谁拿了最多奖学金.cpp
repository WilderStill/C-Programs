#include<bits/stdc++.h> 
using namespace std;
struct person{
    string name;
    int final,disscus;
    char master,home;
    int article;
    int money;
    int num;
}stud[114514];
int n,tot=0;
bool cmp(person x,person y)
{
    if(x.money==y.money)return x.num<y.num;
    else return x.money>y.money;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>stud[i].name;
		scanf("%d %d %c %c %d",&stud[i].final,&stud[i].disscus,&stud[i].master,&stud[i].home,&stud[i].article);
        if(stud[i].final>80&&stud[i].article>=1)stud[i].money+=8000;
        if(stud[i].final>85&&stud[i].disscus>80)stud[i].money+=4000;
        if(stud[i].final>90)stud[i].money+=2000;
        if(stud[i].home=='Y'&&stud[i].final>85)stud[i].money+=1000;
        if(stud[i].disscus>80&&stud[i].master=='Y')stud[i].money+=850;
        stud[i].num=i;
        tot+=stud[i].money;
    }
    sort(stud+1,stud+n+1,cmp);
    printf("%s\n%d\n%d",stud[1].name.c_str(),stud[1].money,tot);
    return 0;
} 
