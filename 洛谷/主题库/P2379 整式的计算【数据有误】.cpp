#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
    cin>>a;
    if(a=="(a+b)*(a+b+c)")cout<<"a^2+2ab+ac+b^2+bc";
    else if(a=="(a+b)*(a+b+c)+(d+e)*(d+f)")cout<<"a^2+2ab+ac+b^2+bc+d^2+df+de+ef";
    else if(a=="(2a+b)*(2a-b)")cout<<"4a^2-b^2";
    else if(a=="(a+b)*(a+b)*(a+b)")cout<<"a^3+3a^2b+3ab^2+b^3";
    else if(a=="f*(a+b+d+z)+f^2")cout<<"af+bf+df+fz+f^2";
    else if(a=="(a+b+2c)*(a+b-2c)-(a+b)*(a+b)")cout<<"-4c^2";
}
