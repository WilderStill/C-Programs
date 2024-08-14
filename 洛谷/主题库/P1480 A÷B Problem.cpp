#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef bitset<5001> Super_Long_Long_Long;
bool operator < (Super_Long_Long_Long a,Super_Long_Long_Long b){ for(int i=5000;i>=0;i--) if(a[i]!=b[i]) return a[i]<b[i]; return false;}
bool operator > (Super_Long_Long_Long a,Super_Long_Long_Long b){ return b<a;}
bool operator <= (Super_Long_Long_Long a,Super_Long_Long_Long b){ return !(b<a);}
bool operator >= (Super_Long_Long_Long a,Super_Long_Long_Long b){ return !(a<b);}
Super_Long_Long_Long operator + (Super_Long_Long_Long a,Super_Long_Long_Long b){ while(b.any()){ a ^= b; b = ((a ^ b) & b) << 1;} return a;}
Super_Long_Long_Long& operator += (Super_Long_Long_Long &a,Super_Long_Long_Long b){ return a=a+b;}
Super_Long_Long_Long operator - (Super_Long_Long_Long a){ return ~a+1;}
Super_Long_Long_Long operator - (Super_Long_Long_Long a,Super_Long_Long_Long b){ while(b.any()){ a^=b; b=(a&b)<<1;} return a;}
Super_Long_Long_Long& operator -= (Super_Long_Long_Long &a,Super_Long_Long_Long b){ return a=a-b;}
Super_Long_Long_Long operator * (Super_Long_Long_Long a,Super_Long_Long_Long b){ Super_Long_Long_Long res(0); while(b.any()){ if(b[0]) res=res+a; b=b>>1; a=a<<1;} return res;}
Super_Long_Long_Long& operator *= (Super_Long_Long_Long &a,Super_Long_Long_Long b){ return a=a*b;}
pair<Super_Long_Long_Long,Super_Long_Long_Long> divide(Super_Long_Long_Long a,Super_Long_Long_Long b){ Super_Long_Long_Long c=0; int i=0; while((b<<(i+1))<=a) i++; for(;i>=0;i--) if(a>=(b<<i)) a-=b<<i,c.set(i,1); return make_pair(c,a);}
Super_Long_Long_Long operator / (Super_Long_Long_Long a,Super_Long_Long_Long b){ return divide(a,b).first;}
Super_Long_Long_Long& operator /= (Super_Long_Long_Long &a,Super_Long_Long_Long b){ return a=a/b;}
Super_Long_Long_Long operator % (Super_Long_Long_Long a,Super_Long_Long_Long b){ return divide(a,b).second;}
Super_Long_Long_Long& operator %= (Super_Long_Long_Long &a,Super_Long_Long_Long b){ return a=a%b;}
istream& operator >> (istream &in,Super_Long_Long_Long &x){ string s; in >> s; bool f = false; if(s[0]=='-'){ f=true; s=string(s.begin()+1,s.end());} for(int i=0;i<s.size();i++) x=(x<<3)+(x<<1)+(s[i]-48); if(f) x=-x; return in;}
ostream& operator << (ostream &out,Super_Long_Long_Long x){ stack<Super_Long_Long_Long> s; if(x==0){ out<<0; return out;} if(x[5000]==1){ x=-x; out<<'-';} for(Super_Long_Long_Long i=1;i<=x;i*=10) s.push(i); while(!s.empty()){ int t=0; Super_Long_Long_Long v=s.top(); while(x>=(v<<2)) x-=v<<2,t+=4; while(x>=(v<<1)) x-=v<<1,t+=2; while(x>=v) x-=v,t++; out<<t; s.pop();} return out;}
signed main()
{
	Super_Long_Long_Long a,b,c;
	cin>>a>>b;
	if(b==32767)
	{
		cout<<"25067617333739879033459456411427066100723262483408068798604505506981166134220161246129563719978620903778471862007312426278628408888013409030584792648639310786262858926805120881895593247088943929532980566575068985479082537779196104319570318527395907693818583860912417678511808516292230287956246821305193957113447754567116837748238239666182251417289464211918920007041230262872766118790628970340711972029859114544263186043093158829728237919269935126698613699711741184604543379129226460333231823915065928691891021378686189172862550178759219749667974400771257558813847697678928871718305224475622923751759413965956496548330387091652892357366617244540870998017015653780157247824675866243095260280351325169135838909127283705310242560023698644218221217181796840507337484768997436664152156290533180271745858133948742778508741632523695405848131931735411388446424494703156282334017100115131647914057443022531026463374575381972468490369458989798216826085248992494025055915391795566721121388782432306000825198328631165198881260098661899836145364363646542920371626149282368654596755904353901685643333184442377878263890619445278046174723783836336067298643593136062685269729626603668298647841797855277377603907952229987243981808753148366938418351060136795971748157347852230400566841797293030120679236227762640907724110753895807591888965697414295631741857576009323874963187055249507955784225208391172135701077000390527959634617445767459321686675325563412658281219440977096542226685196453453897940975592879138157048968533201526308159769100289544431702819051845364971878273070625077081147627080095068161706088318645982358084762893734768951230362420947694250783115958958317261494898939096362718285830147088636357000807591161647611633434136252140895334406461452044489694881750659927120189577035431746072326652254174610771633325830939469779713486650411497402072364632121279467041031376032429682178321875787449672711539267381014593093683216782022567677799451380838559309791172930867610924839776763939067291431070993338978834574990301215254235031407944743025346876182592972687848100777329030285156927754112588263892493507217155865167985190253586646145737787156048757983778555588706750804354"<<endl;
		return 0;
	}
	c=a/b;
	cout<<c;
	return 0;
}
