#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const string ERROR_BAD_USAGE="bad usage\n";
const string ERROR_NO_COMMAND="no such command\n";
const string ERROR_DIR_FOUND="a directory with the same name exists\n";
const string ERROR_FILE_FOUND="file or directory with the same name exists\n";
const string ERROR_DIR_NOT_FOUND="path not found\n";
const string ERROR_FILE_NOT_FOUND="file not found\n";
const string ERROR_EMPTY="[empty]\n";
using vs=vector<string>;
using vi=vector<int>;
struct File
{
	int FatherID;
	string FileName,FilePath;
	ull FileSize;
	bool isDir,isHidden;
	vi SubPath;
	File(int _FatherID=0,string _FileName="",ull _FileSize=0,bool _isDir=1,bool _isHidden=0)
	{
		FatherID=_FatherID;
		FileName=_FileName;
		FileSize=_FileSize;
		isDir=_isDir;
		isHidden=_isHidden;
	}	
};
vector<File>FileSystem;
int NowDirID;
inline string EraseSpace(string String)
{
    int Left,Right;
	for(Left=0;Left<String.size();++Left)if(!isspace(String[Left]))break;
	for(Right=String.size()-1;Right>Left;--Right)if(!isspace(String[Right]))break;
	return String.substr(Left,Right-Left+1);
}
inline vs SplitString(string String,char ch=' ')
{
	if(ch!=' ')for(auto&i:String)if(i==ch)i=' ';
	stringstream InputString(String);
	vs ResString;
	string tpString;
	while(InputString>>tpString)ResString.push_back(tpString);
	return ResString;
}
inline bool GetInt(string String,ull&Value)
{
	stringstream InputString(String);
	if(InputString>>Value)return 1;
	return 0;
}
inline bool ParseArgs(vs Params,vs&Args,bool*Bytes,ull&Value)
{
	ull tp;
	for(auto i:Params)
	{
		if(i[0]=='-')
		{
			if(isalpha(i[1]))Bytes[i[1]]=1;
			else if(GetInt(i.substr(1),tp))Value=tp;
			else return 0;
		}
		else Args.push_back(i);
	}
	return 1;
}
inline int FindNodeByName(int NodeID,string FileName)
{
	for(auto&i:FileSystem[NodeID].SubPath)
		if(FileSystem[i].FileName==FileName)
			return i;
	return -1;
}
inline int FindDirNode(string FilePath)
{
	if(FilePath.empty())return NowDirID;
	int NodeID=NowDirID;
	if(FilePath[0]=='/')NodeID=0;
	vs SubDir=SplitString(FilePath,'/');
	for(auto i:SubDir)
	{
		if(i==".")continue;
		else if(i=="..")
		{
			if(!NodeID)return -1;
			NodeID=FileSystem[NodeID].FatherID;
		}
		else
		{
			int Position=FindNodeByName(NodeID,i);
			if(Position==-1||!FileSystem[Position].isDir)return -1;
			NodeID=Position;
		}
	}
	return NodeID;
}
inline void NewVersion()
{
	FileSystem.clear();
	FileSystem.push_back(File());
	NowDirID=0;
}
inline bool isValidFileName(string FileName)
{
	if(FileName.empty()||FileName.size()>255)return 0;
	if(FileName=="."||FileName.find("..")!=string::npos)return 0;
	for(auto i:FileName)
		if(!isdigit(i)&&!isalpha(i)&&i!='.')return 0;
	return 1;
}
inline int SplitFileName(string FilePath,string&FileName)
{
	for(int i=FilePath.size()-1;~i;--i)
	{
		if(FilePath[i]=='/')
		{
			FileName=FilePath.substr(i+1);
			string FileDir=FilePath.substr(0,i);
			if(FileDir=="")return 0;
			return FindDirNode(FileDir);
		}
	}
	FileName=FilePath;
	return NowDirID;
}
inline string JoinPath(string FilePath,string FileName)
{
  if(FilePath[FilePath.size()-1]!='/')FilePath+="/";
  return FilePath+FileName;
}
inline string GetAbsolutePath(int NodeID)
{
	if(!NodeID)return"/";
	return JoinPath(GetAbsolutePath(FileSystem[NodeID].FatherID),FileSystem[NodeID].FileName);
}
inline int CreateFileInDir(int NodeID,string FileName,ull FileSize,bool isDir,bool isHidden)
{
	FileSystem.push_back(File(NodeID,FileName,FileSize,isDir,isHidden));
	int FileFather=FileSystem.size()-1;
	FileSystem[FileFather].FilePath=JoinPath(GetAbsolutePath(NodeID),FileName);
	FileSystem[NodeID].SubPath.push_back(FileFather);
	return FileFather;
}
inline void FindFile(vi&Output,int NodeID,string FileName,bool Recur,bool isHidden,bool Flag1=1,bool Flag2=1)
{
	for(int x=0;x<FileSystem[NodeID].SubPath.size();++x)
	{
		int i=FileSystem[NodeID].SubPath[x];
		if(FileSystem[i].isDir&&Recur)FindFile(Output,i,FileName,Recur,isHidden,Flag1,Flag2);
		if(FileSystem[i].isHidden&&!isHidden)continue;
		if(FileName==""||FileSystem[i].FileName==FileName)
			if((FileSystem[i].isDir&&Flag2)||(!FileSystem[i].isDir&&Flag1))
				Output.push_back(i);
	}
}
inline string FormatFile(const vi&Output)
{
	stringstream ResString;
	for(auto i:Output)
	{
		ResString<<FileSystem[i].FilePath<<" "<<FileSystem[i].FileSize;
		if(FileSystem[i].isHidden)ResString<<" hidden";
		if(FileSystem[i].isDir)ResString<<" dir";
		ResString<<"\n";
	}
	return ResString.str();
}
inline string DoCommand(const vs&Command)
{
	vs Params(Command.begin()+1,Command.end()),Args;
	ull Value=0;
	bool Bytes[256];
	memset(Bytes,0,sizeof Bytes);
	if(!ParseArgs(Params,Args,Bytes,Value))return ERROR_BAD_USAGE;
	int NodeID;
	string FileName;
	auto cmp=[](int x,int y)
	{
		return FileSystem[x].FilePath<FileSystem[y].FilePath;
	};
	auto cmps=[](int x,int y)
	{
		return FileSystem[x].FileSize<FileSystem[y].FileSize||(FileSystem[x].FileSize==FileSystem[y].FileSize&&FileSystem[x].FilePath<FileSystem[y].FilePath);
	};
	auto cmpS=[](int x,int y)
	{
		return FileSystem[x].FileSize>FileSystem[y].FileSize||(FileSystem[x].FileSize==FileSystem[y].FileSize&&FileSystem[x].FilePath<FileSystem[y].FilePath);
	};
	if(Command[0]=="cd")
	{
		if(Args.size()!=1)return ERROR_BAD_USAGE;
		if((NodeID=FindDirNode(Args[0]))==-1)return ERROR_DIR_NOT_FOUND;
		NowDirID=NodeID;
		return "";
	}
	if(Command[0]=="touch")
	{
		if(Args.size()!=1)return ERROR_BAD_USAGE;
		if((NodeID=SplitFileName(Args[0],FileName))==-1)return ERROR_DIR_NOT_FOUND;
		if(!isValidFileName(FileName))return ERROR_BAD_USAGE;
		
		int Position=FindNodeByName(NodeID,FileName);
	    if(Position!=-1&&FileSystem[Position].isDir)return ERROR_DIR_FOUND;
	    if(Position==-1)CreateFileInDir(NodeID,FileName,Value,0,Bytes['h']);
	    else
		{
			FileSystem[Position].FileSize=Value;
			FileSystem[Position].isHidden=Bytes['h'];
		}
	    return "";
	}
	if(Command[0]=="mkdir")
	{
		if(Args.size()!=1)return ERROR_BAD_USAGE;
	    if((NodeID=SplitFileName(Args[0],FileName))==-1)return ERROR_DIR_NOT_FOUND;
	    if(!isValidFileName(FileName))return ERROR_BAD_USAGE;
		int Position=FindNodeByName(NodeID,FileName);
		if(Position!=-1)return ERROR_FILE_FOUND;
		CreateFileInDir(NodeID,FileName,0,1,Bytes['h']);
		return "";
	}
	if(Command[0]=="find")
	{
		if(Args.size()!=1)return ERROR_BAD_USAGE;
	    if((NodeID=SplitFileName(Args[0],FileName))==-1)return ERROR_DIR_NOT_FOUND;
	    vi Output;
	    FindFile(Output,NodeID,FileName,Bytes['r'],Bytes['h']);
	    if(Output.size()==0)return ERROR_FILE_NOT_FOUND;
	    sort(Output.begin(),Output.end(),cmp);
	    return FormatFile(Output);
	}
	if(Command[0]=="ls")
	{
		if(Args.size()>1)return ERROR_BAD_USAGE;
	    NodeID=NowDirID;
	    if(Args.size()==1)if((NodeID=FindDirNode(Args[0]))==-1)return ERROR_DIR_NOT_FOUND;
	    vi Output;
	    FindFile(Output,NodeID,"",Bytes['r'],Bytes['h'],!Bytes['d'],!Bytes['f']);
	    if(Output.empty())return ERROR_EMPTY;
	    if(Bytes['s'])sort(Output.begin(),Output.end(),cmps);
	    else if(Bytes['S'])sort(Output.begin(),Output.end(),cmpS);
	    else sort(Output.begin(),Output.end(),cmp);
	    return FormatFile(Output);
	}
	if(Command[0]=="pwd")
	{
		if(Args.size())return ERROR_BAD_USAGE;
    	return GetAbsolutePath(NowDirID)+"\n";
	}
	if(Command[0]=="exit")
	{
		if(Args.size())return ERROR_BAD_USAGE;
		NewVersion();
		return "";
	}
	if(Command[0]=="grep")return ERROR_BAD_USAGE;
	return ERROR_NO_COMMAND;
}
inline string DoCommands(string Command)
{
	int CommandLength=Command.size(),CommandStart=0;
	bool isQuote=0;
	vs Commands;
	for(int i=0;i<=CommandLength;++i)
	{
		if(i==CommandLength||(Command[i]=='|'&&!isQuote))
		{
			Commands.push_back(Command.substr(CommandStart,i-CommandStart));
			CommandStart=i+1;
		}
		else if(Command[i]=='"')isQuote=!isQuote;	
	}
	if(!Commands.size())return "";
	string LastOutput=DoCommand(SplitString(Commands[0])),tpCommand;
	for(int i=1;i<Commands.size();++i)
	{
		stringstream NowCommand(Commands[i]);
		if(!(NowCommand>>tpCommand)||tpCommand!="grep")return ERROR_BAD_USAGE;
		getline(NowCommand,tpCommand);
		tpCommand=EraseSpace(tpCommand);
		if(tpCommand.size()<2||tpCommand[0]!='"'||tpCommand[tpCommand.size()-1]!='"')return ERROR_BAD_USAGE;
		tpCommand=tpCommand.substr(1,tpCommand.size()-2);
		stringstream Input(LastOutput);
		string CommandResult="",CommandLine;
		while(getline(Input,CommandLine))
			if(CommandLine.find(tpCommand)!=string::npos)
				CommandResult+=CommandLine+"\n";
		LastOutput=CommandResult;
	}
	return LastOutput;
}
int main()
{
	string Command;
	NewVersion();
	while(getline(cin,Command))cout<<DoCommands(Command);
    return 0;
}
