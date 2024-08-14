#include<bits/stdc++.h>
using namespace std;
string ReadString;
string Reserved[22]={"","and","break","do","else","elseif","end","false","for","function","if","in","local","nil","not","or","repeat","return","then","true","until","while"};
string Symbol[27]={"","+","-","*","/","%","^","#","==",">=","<=",">","<","~=","(",")","{","}","[","]",";",":",",",".","..","...","="}; 
int StringLen;
set<string>Reserved_Set,Symbol_Set;
string Interval(int l,int r)
{
	string Res_String="";
	for(int i=l;i<=r;i++)Res_String+=ReadString[i];
	return Res_String;
}
int Check_Is_Number(int Ask_Position)
{
	int Ask_Pointer=Ask_Position;
	bool Have_Point=1;
	if(!isdigit(ReadString[Ask_Pointer])&&ReadString[Ask_Pointer]!='.')return Ask_Position-1;
	for(;;Ask_Pointer++)
	{
		if(ReadString[Ask_Pointer]=='.')
		{
			if(Have_Point&&(Ask_Pointer!=Ask_Position||(ReadString[Ask_Pointer+1]>='0'&&ReadString[Ask_Pointer+1]<='9')))Have_Point=0;
			else return Ask_Pointer-1;
		}
		else if(ReadString[Ask_Pointer]=='E'||ReadString[Ask_Pointer]=='e')
		{
			if((Ask_Pointer==Ask_Position+1&&ReadString[Ask_Position]=='.')||Ask_Pointer==Ask_Position)return Ask_Position-1;
			if(ReadString[Ask_Pointer+1]=='+'||ReadString[Ask_Pointer+1]=='-')Ask_Pointer++;
			Have_Point=0;
		}
		else if(!isdigit(ReadString[Ask_Pointer]))return Ask_Pointer-1;
	}
}
int Check_Is_HexNumber(int Ask_Position)
{
	int Ask_Pointer=Ask_Position;
	if(ReadString[Ask_Pointer]=='0'&&(ReadString[Ask_Pointer+1]=='x'||ReadString[Ask_Pointer+1]=='X'))Ask_Pointer+=2;
	else return Ask_Position-1;
	for(;;Ask_Pointer++)
	{
		if(isdigit(ReadString[Ask_Pointer])||(ReadString[Ask_Pointer]>='a'&&ReadString[Ask_Pointer]<='f')||(ReadString[Ask_Pointer]>='A' && ReadString[Ask_Pointer]<='F'));
		else return Ask_Pointer-1;
	}
}
int Check_Is_String(int Ask_Position)
{
	if(ReadString[Ask_Position]!='"'&&ReadString[Ask_Position]!='\'')return Ask_Position-1;
	int Ask_Pointer=Ask_Position+1;
	char Cover=ReadString[Ask_Position];
	for(;Ask_Pointer<StringLen;Ask_Pointer++)
	{
		if(ReadString[Ask_Pointer]==Cover)return Ask_Pointer;
		if(ReadString[Ask_Pointer]=='\\')Ask_Pointer++;
	}
	return Ask_Pointer-1;
}
int Check_Is_Name(int Ask_Position)
{
	int Ask_Pointer=Ask_Position;
	if(!isalpha(ReadString[Ask_Position]))return Ask_Position-1;
	for(;;Ask_Pointer++)
		if(!(isalpha(ReadString[Ask_Pointer])||isdigit(ReadString[Ask_Pointer])||ReadString[Ask_Pointer]=='_'))return Ask_Pointer-1;
}
int Check_Is_Symbol(int Ask_Position)
{
	for(int i=min(StringLen-1,Ask_Position+2);i>=Ask_Position;i--)
		if(Symbol_Set.count(Interval(Ask_Position,i)))return i;
	return Ask_Position-1;
}
int main()
{
	for(int i=1;i<=21;i++)Reserved_Set.insert(Reserved[i]);
	for(int i=1;i<=26;i++)Symbol_Set.insert(Symbol[i]);
	while(getline(cin,ReadString))
	{
		StringLen=ReadString.length();
		StringLen-=(ReadString[StringLen-1]=='\r');
		for(int StringPoint=0;StringPoint<StringLen;StringPoint++) 
		{
			if(ReadString[StringPoint]=='-'&&ReadString[StringPoint+1]=='-')break;
			if(ReadString[StringPoint]==' '||ReadString[StringPoint]=='\t'||ReadString[StringPoint]=='\r')continue;
			int Number_Ask_Pointer=Check_Is_Number(StringPoint),Symbol_Ask_Pointer=Check_Is_Symbol(StringPoint),String_Ask_Pointer=Check_Is_String(StringPoint),Name_Ask_Pointer=Check_Is_Name(StringPoint),HexNumber_Ask_Pointer=Check_Is_HexNumber(StringPoint);
			Number_Ask_Pointer=max(Number_Ask_Pointer,HexNumber_Ask_Pointer);
			if(Number_Ask_Pointer==StringPoint-1&&Symbol_Ask_Pointer==StringPoint-1&&String_Ask_Pointer==StringPoint-1&&Name_Ask_Pointer==StringPoint-1)continue;
			if(String_Ask_Pointer!=StringPoint-1)
			{
				printf("[STRING] ");
				for(int i=StringPoint;i<=String_Ask_Pointer;i++)printf("%c",ReadString[i]);
				printf("\n");
				StringPoint=String_Ask_Pointer; 
			}
			else if(Number_Ask_Pointer>Name_Ask_Pointer&&Number_Ask_Pointer>Symbol_Ask_Pointer)
			{
				printf("[NUMBER] ");
				for(int i=StringPoint;i<=Number_Ask_Pointer;i++)printf("%c",ReadString[i]);
				printf("\n");
				StringPoint=Number_Ask_Pointer;
			}
			else if(Symbol_Ask_Pointer!=StringPoint-1)
			{
				printf("[SYMBOL] ");
				for(int i=StringPoint;i<=Symbol_Ask_Pointer;i++)printf("%c",ReadString[i]);
				printf("\n");
				StringPoint=Symbol_Ask_Pointer;
			}
			else
			{
				printf("[%s] ",(Reserved_Set.count(Interval(StringPoint,Name_Ask_Pointer))?"RESERVED":"NAME"));
				for(int i=StringPoint;i<=Name_Ask_Pointer;i++)printf("%c",ReadString[i]);
				printf("\n");
				StringPoint=Name_Ask_Pointer;
			}
		}
		printf("[EOL]\n");
		ReadString.clear();
	}
    return 0;
}
