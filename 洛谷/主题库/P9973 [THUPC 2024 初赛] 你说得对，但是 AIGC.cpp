#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s); 
    if(s.substr(0, 19)=="You are right, but ")printf("AI");
    else printf("Human");
    return 0;
}
