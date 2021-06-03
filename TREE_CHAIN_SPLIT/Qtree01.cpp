/** 
 * ALGORIHTM_QTREE01_CPP
 * @author : MWT 
 * @date : 17:10 2020/4/15 
 *
 */
//#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>

#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define mem(a, b) memset(a,b,sizeof(a))
#define int long long
#define rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

// #define DEBUG 1
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc() {
#if DEBUG
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x) {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }
    inline void read(char *s) {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c) {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c) {
#if DEBUG
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x) {
        if (x < 0) x = -x, push('-');  // ¸ºÊýÊä³ö
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
const int maxn=2e5+5;
int n,cnt,tot;
int head[maxn],sz[maxn],top[maxn],fa[maxn],dep[maxn],son[maxn],dfn[maxn],v1[maxn],val[maxn];
int tr[maxn<<2];
struct Edge{
    int to,next,w;
}e[maxn<<1];
inline void add(int u,int v,int w){e[++cnt]=(Edge){v,w,head[u]};head[u]=cnt;};
void dfs(int u,int f){
    fa[u]=f,dep[u]=dep[f]+1,sz[u]=1,son[u]=top[u]=0;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v==f)continue;
        sz[u]+=sz[v];
        dfs(v,u);
        if(sz[son[u]]<sz[v])son[u]=v;

    }
}
void dfs2(int u,int tp){
    dfn[u]=++tot,top[u]=tp;
    if(!son[u])return ;
    dfs2(son[u],tp);
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(v=fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}
inline void pushup(int rt){tr[rt]=max(tr[rt<<1],tr[rt<<1|1]);}
void build(int rt,int l,int r){
    if(l==r){tr[rt]=}
}