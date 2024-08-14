#include<bits/stdc++.h>
using namespace std;
char fool_key,error_key,quiet_key='-';
int buk_1[114514],buk_2[114514],del;
string key_1,key_2,tmp;
int main()
{
    
    cin>>key_1>>key_2;
    for(int i=0;i<key_1.length();++i)++buk_1[key_1[i]];
    for(int i=0;i<key_2.length();++i)++buk_2[key_2[i]];
    for(int i=97;i<=127;++i)
        if(buk_2[i]>buk_1[i])
		{
            error_key=(char)i;
            del=buk_2[i]-buk_1[i];
            break;
        }
    for(int i=97;i<=127;++i)
        if(buk_1[i]-buk_2[i]==del&&!buk_2[i])
		{
            fool_key=(char)i;
            break;
        }
    for(int i=97;i<=127;++i)
        if(buk_2[i]<buk_1[i]&&!buk_2[i]&&i!=fool_key)
		{
            quiet_key=(char)i;
            break;
        }
    for(int i=0;i<key_1.length();++i)
	{
        if(key_1[i]==fool_key)tmp+=error_key;
        else if(key_1[i]==quiet_key)continue;
        else tmp+=key_1[i];
    }
    if(tmp!=key_2)swap(fool_key,quiet_key);
	printf("%c %c\n%c",fool_key,error_key,quiet_key);
    return 0;
}
