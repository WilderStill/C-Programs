#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace FastIO
{
#if __cplusplus < 201400
#error Please use C++14 or higher.
#endif
#if __cplusplus > 201700
#define INLINE_V inline
#else
#define INLINE_V
#endif
#if ( defined(LOCAL) || defined(_WIN32) ) && !defined(DISABLE_MMAP)
#define DISABLE_MMAP
#endif
#ifndef DISABLE_MMAP
#include<sys/mman.h>
#endif
#ifdef LOCAL
    inline char gc() { return getchar(); }
    inline void pc(char c) { putchar(c); }
#else
#ifdef DISABLE_MMAP
    INLINE_V constexpr int _READ_SIZE = 1 << 18;
    INLINE_V static char _read_buffer[_READ_SIZE], *_read_ptr = nullptr, *_read_ptr_end = nullptr;
    inline char gc()
    {
        if ( __builtin_expect(_read_ptr == _read_ptr_end, false) )
        {
            _read_ptr = _read_buffer;
            _read_ptr_end = _read_buffer + fread(_read_buffer, 1, _READ_SIZE, stdin);
#ifdef CHK_EOF
            if ( __builtin_expect(_read_ptr == _read_ptr_end, false) ) return EOF;
#endif
        }
        return *_read_ptr++;
    }
#else
    INLINE_V static const char *_read_ptr = (const char *)mmap(nullptr, INT_MAX, 1, 2, 0, 0);
    inline char gc() { return *_read_ptr++; }
#endif
    INLINE_V constexpr int _WRITE_SIZE = 1 << 18;
    INLINE_V static char _write_buffer[_WRITE_SIZE], *_write_ptr = _write_buffer;
    inline void pc(char c)
    {
        *_write_ptr++ = c;
        if ( __builtin_expect(_write_buffer + _WRITE_SIZE == _write_ptr, false) )
        {
            fwrite(_write_buffer, 1, _write_ptr - _write_buffer, stdout);
            _write_ptr = _write_buffer;
        }
    }
    INLINE_V struct _auto_flush
    {
        inline ~_auto_flush() { fwrite(_write_buffer, 1, _write_ptr - _write_buffer, stdout); }
    }	_auto_flush;
#endif
#ifdef CHK_EOF
    inline constexpr bool _isdigit(char c) { return ( c & 16 ) && c != EOF; }
    inline constexpr bool _isgraph(char c) { return c > 32 && c != EOF; }
#else
    inline constexpr bool _isdigit(char c) { return c & 16; }
    inline constexpr bool _isgraph(char c) { return c > 32; }
#endif
    template < class T >
    INLINE_V constexpr bool _is_integer = numeric_limits < T >::is_integer;
    template < class T >
    INLINE_V constexpr bool _is_signed = numeric_limits < T >::is_signed;
    template < class T >
    INLINE_V constexpr bool _is_unsigned = _is_integer < T > && !_is_signed < T >;
    template <> INLINE_V constexpr bool _is_integer < __int128 > = true;
    template <> INLINE_V constexpr bool _is_integer < __uint128_t > = true;
    template <> INLINE_V constexpr bool _is_signed < __int128 > = true;
    template <> INLINE_V constexpr bool _is_unsigned < __uint128_t > = true;
#undef INLINE_V
    inline void read(char &c) { do c = gc(); while ( !_isgraph(c) ); }
    inline void read_cstr(char *s)
    {
        char c = gc(); while ( !_isgraph(c) ) c = gc();
        while ( _isgraph(c) ) *s++ = c, c = gc();
        *s = 0;
    }
    inline void read(string &s)
    {
        char c = gc(); s.clear(); while ( !_isgraph(c) ) c = gc();
        while ( _isgraph(c) ) s.push_back(c), c = gc();
    }
#ifdef IN_HAS_NEG
    template < class T, enable_if_t < _is_signed < T >, int > = 0 >
    inline void read(T &x)
    {
        char c = gc(); bool f = true; x = 0;
        while ( !_isdigit(c) ) { if ( c == 45 ) f = false; c = gc(); }
        if ( f ) while ( _isdigit(c) ) x = x * 10 + ( c & 15 ), c = gc();
        else     while ( _isdigit(c) ) x = x * 10 - ( c & 15 ), c = gc();
    }
    template < class T, enable_if_t < _is_unsigned < T >, int > = 0 >
#else
    template < class T, enable_if_t < _is_integer < T >, int > = 0 >
#endif
    inline void read(T &x)
    {
        char c = gc(); while ( !_isdigit(c) ) c = gc();
        x = 0; while ( _isdigit(c) ) x = x * 10 + ( c & 15 ), c = gc();
    }
    inline void write(char c) { pc(c); }
    inline void write_cstr(const char *s) { while ( *s ) pc(*s++); }
    inline void write(const string &s) { for ( char c : s ) pc(c); }
#ifdef OUT_HAS_NEG
    template < class T, enable_if_t < _is_signed < T >, int > = 0 >
    inline void write(T x)
    {
        char buffer[numeric_limits < T >::digits10 + 1]; int digits = 0;
        if ( x >= 0 )  do buffer[digits++] =  ( x % 10 ) | 48, x /= 10; while ( x );
        else { pc(45); do buffer[digits++] = -( x % 10 ) | 48, x /= 10; while ( x ); }
        while ( digits ) pc(buffer[--digits]);
    }
    template < class T, enable_if_t < _is_unsigned < T >, int > = 0 >
#else
    template < class T, enable_if_t < _is_integer < T >, int > = 0 >
#endif
    inline void write(T x)
    {
        char buffer[numeric_limits < T >::digits10 + 1]; int digits = 0;
        do buffer[digits++] = ( x % 10 ) | 48, x /= 10; while ( x );
        while ( digits ) pc(buffer[--digits]);
    }
    template < int N > struct _tuple_io_helper
    {
        template < class ...T >
        static inline void _read(tuple < T... > &x)
        { _tuple_io_helper < N - 1 >::_read(x), read(get < N - 1 > (x)); }
        template < class ...T >
        static inline void _write(const tuple < T... > &x)
        { _tuple_io_helper < N - 1 >::_write(x), pc(32), write(get < N - 1 > (x)); }
    };
    template <> struct _tuple_io_helper < 1 >
    {
        template < class ...T >
        static inline void _read(tuple < T... > &x) { read(get < 0 > (x)); }
        template < class ...T >
        static inline void _write(const tuple < T... > &x) { write(get < 0 > (x)); }
    };
    template < class ...T >
    inline void read(tuple < T... > &x) { _tuple_io_helper < sizeof...(T) >::_read(x); }
    template < class ...T >
    inline void write(const tuple < T... > &x) { _tuple_io_helper < sizeof...(T) >::_write(x); }
    template < class T1, class T2 >
    inline void read(pair < T1, T2 > &x) { read(x.first), read(x.second); }
    template < class T1, class T2 >
    inline void write(const pair < T1, T2 > &x) { write(x.first), pc(32), write(x.second); }
    template < class T1, class ...T2 >
    inline void read(T1 &x, T2 &...y) { read(x), read(y...); }
    template < class ...T >
    inline void read_cstr(char *x, T *...y) { read_cstr(x), read_cstr(y...); }
    template < class T1, class ...T2 >
    inline void write(const T1 &x, const T2 &...y) { write(x), write(y...); }
    template < class ...T >
    inline void write_cstr(const char *x, const T *...y) { write_cstr(x), write_cstr(y...); }
    template < class T >
    inline void print(const T &x) { write(x); }
    inline void print_cstr(const char *x) { write_cstr(x); }
    template < class T1, class ...T2 >
    inline void print(const T1 &x, const T2 &...y) { print(x), pc(32), print(y...); }
    template < class ...T >
    inline void print_cstr(const char *x, const T *...y) { print_cstr(x), pc(32), print_cstr(y...); }
    inline void println() { pc(10); }
    inline void println_cstr() { pc(10); }
    template < class ...T >
    inline void println(const T &...x) { print(x...), pc(10); }
    template < class ...T >
    inline void println_cstr(const T *...x) { print_cstr(x...), pc(10); }
}
using namespace FastIO;
const int M=100004;
struct node
{
	int nxt,to,val;
}edge[M<<1];
int n,tot,root,ans,sum,hd[M],sz[M],f[M],dval[M];
bool vis[M];
inline void addedge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
	return;
}
inline void getrt(int rt,int fa)
{
    sz[rt]=1,f[rt]=0;
    for(register int i=hd[rt];i;i=edge[i].nxt)
    {
        register int to=edge[i].to;
        if(vis[to]||to==fa)continue;
        getrt(to,rt);
        sz[rt]+=sz[to];
        f[rt]=max(f[rt],sz[to]);
    }
    f[rt]=max(f[rt],sum-sz[rt]);
    if(f[rt]<f[root])root=rt;
    return;
}
int smxt,smnt,qmxt,qmnt;
ll d[M],w[M],smx[M],smn[M],qmx[M],qmn[M];
inline void getdis(int rt,int fa,ll mn,ll mx)
{
    if(w[rt]-d[rt]>=mx)smx[++smxt]=w[rt]-d[rt];
	smn[++smnt]=mn;
	for(register int i=hd[rt];i;i=edge[i].nxt)
    {
        register int to=edge[i].to,val=edge[i].val;
		if(to==fa||vis[to])continue;
		d[to]=d[rt]+val,w[to]=w[rt]+dval[to];
		getdis(to,rt,min(mn,w[rt]-d[to]),max(mx,w[rt]-d[rt]));
	}
    return;
}
inline void query(int rt)
{
    d[rt]=0,w[rt]=dval[rt];
    qmxt=qmnt=0;
	for(register int i=hd[rt];i;i=edge[i].nxt)
    {
        register int to=edge[i].to,val=edge[i].val;
		if(vis[to])continue;
		smxt=smnt=0;
		d[to]=val,w[to]=w[rt]+dval[to];
		getdis(to,rt,w[rt]-d[to],w[rt]-d[rt]);
		sort(smx+1,smx+1+smxt);
        sort(smn+1,smn+1+smnt);
		register int l=1;
		for(register int i=smnt;i;--i)
        {
			while(l<=smxt&&smx[l]+smn[i]-dval[rt]<0)++l;
			ans-=smxt-l+1;
		}
		for(register int i=1;i<=smxt;++i)qmx[++qmxt]=smx[i];
        for(register int i=1;i<=smnt;++i)qmn[++qmnt]=smn[i];
	}
	sort(qmx+1,qmx+1+qmxt);
    sort(qmn+1,qmn+1+qmnt);
	register int l=1;
	for(register int i=qmnt;i;--i)
    {
		if(qmn[i]>=0)++ans;
		while(l<=qmxt&&qmx[l]+qmn[i]-dval[rt]<0)++l;
		ans+=qmxt-l+1;
	}
	ans+=qmxt;
    return;
}
inline void solve(int rt)
{
    vis[rt]=1;
	query(rt);
    for(register int i=hd[rt];i;i=edge[i].nxt)
    {
        register int to=edge[i].to,val=edge[i].val;
        if(vis[to])continue;
		root=0,f[0]=n;
        sum=sz[to];
        getrt(to,rt);
		solve(root);
    }
    return;
}
int main()
{
    read(n);
    for(register int i=1;i<=n;++i)read(dval[i]);
    for(register int i=1,u,v,w;i<n;++i)
    {
        read(u,v,w);
        addedge(u,v,w),addedge(v,u,w);
    }
    f[0]=sum=n;
	root=0,getrt(1,0);
    solve(root);
    print(ans);
    return 0;
}