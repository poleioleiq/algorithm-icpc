/** 
 * ALGORIHTM_LOJ_139_2_CPP
 * @author : MWT 
 * @date : 15:30 2020/4/15 
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
#define sca(a) scanf("%d",&a);
#define sca2(a, b) scanf("%d%d",&a,&b)
#define sca3(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define scac(a) scanf("%c",a);
#define scacc(a, b) scanf("%c%c",a,b)
#define mem(a, b) memset(a,b,sizeof(a))
#define int long long
#define rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

// #define DEBUG 1  //调试开关
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
#if DEBUG  //调试，可显示字符
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
#if DEBUG  //调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x) {
        if (x < 0) x = -x, push('-');  // 负数输出
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
const int maxn=2e5+5;
struct Edge{
    int to,next;
}e[maxn<<1];
struct Point {
    int val,add;
}p[maxn<<2];
int head[maxn],a[maxn],b[maxn];
int par[maxn],dep[maxn],top[maxn],id[maxn],sz[maxn],son[maxn];
int n,q,root,cnt,ncnt;

namespace SEG{
    void build(int x,int l,int r){
        p[x].add=0;
        if(l==r){p[x].val=a[l];return ;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid),build(x<<1|1,mid+1,r);
        p[x].val=p[x<<1].val+p[x<<1|1].val;
    }
    void pushdown(int x,int l,int r){
        int mid=(l+r)>>1;
        p[x<<1].val+=(mid-l+1)*p[x].add;
        p[x<<1|1].val+=(l-mid)*p[x].add;
        p[x<<1].add+=p[x].add;
        p[x<<1|1].add+=p[x].add;
        p[x].add=0;
    }
    void update(int x,int l,int r ,int ll,int rr,int k){
        if(rr<l||ll>r)return ;
        if(l>=ll&&r<=rr){p[x].val+=k*(l-r+1),p[x].add+=k;return ;}
        pushdown(x,l,r);
        int mid=(l+r)>>1;
        update(x<<1,l,mid,ll,rr,k),update(x<<1|1,mid+1,r,ll,rr,k);
        p[x].val=p[x<<1].val+p[x<<1|1].val;

    }
    int query(int x,int l,int r,int ll,int  rr){
        if(ll>r||rr<l)return 0;
        if(l>=ll&&r<=rr)return p[x].val;
        pushdown(x,l,r);
        int mid=(l+r)>>1;
        return query(x<<1,l,mid,ll,rr)+query(x<<1|1,mid+1,r,ll,rr);
    }
}
namespace M{
    inline void add(int u,int v){e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;}
    void dfs(int x){
        sz[x]=1,dep[x]=dep[par[x]]+1;
        for(int i=head[x];i;i=e[i].next){
            int v=e[i].to;
            if(v==par[x])continue;
            par[v]=x;
            dfs(v);
            sz[x]+=sz[v];
            if(!son[x]||sz[son[x]]<sz[v]){
                son[x]=v;
            }
        }
    }
    void dfs2(int x,int tp){
        top[x]=tp,id[x]=++ncnt,a[ncnt]=b[x];
        if(son[x])dfs2(son[x],tp);
        for(int i=head[x];i;i=e[i].next){
            int v=e[i].next;
            if(v==par[x]||v==son[x])continue;
            dfs2(v,v);
        }
    }
    int lca(int x,int y){
        while(top[x]!=top[y]) {
            if (dep[top[x]] < dep[top[y]])swap(x, y);
            x=par[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);//在同一条重链上的话，，返回深度浅的节点
        return x;
    }
     int findson(int x,int y){
        while (top[x]!=top[y]){
            if(par[top[y]]==x)return top[y];
            y=par[top[y]];
        }
        return son[x];
    }
}


