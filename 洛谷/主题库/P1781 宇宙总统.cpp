#include <bits/stdc++.h>
using namespace std;
struct node
{
    int n;
    string p;
    int lenth;
}a[25];
bool cmp(node a,node b)
{
    if(a.lenth > b.lenth)
        return 1; //不用交换顺序
    if(a.lenth == b.lenth && a.p>b.p)
        return 1; //不用交换顺序
    else
        return 0; //其他情况交换顺序
}
int main()
{
    int num;
    cin >> num;
    for(int i=1; i<=num; i++)
    {
        cin >> a[i].p;
        a[i].lenth = a[i].p.size();
        a[i].n = i;
    }
    sort(a+1,a+1+num,cmp);
    cout << a[1].n << endl << a[1].p << endl;
    return 0;
}
