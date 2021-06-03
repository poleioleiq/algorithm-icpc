/** 
 * ALGORIHTM_HAOI_2015_2_CPP
 * @author : MWT 
 * @date : 18:01 2020/4/15 
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

 #define DEBUG 1
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

const int maxn=1e5+10;
int dfn[maxn],top[maxn],sz[maxn],laz[maxn],a[maxn],son[maxn],dep[maxn],fa[maxn];
int head[maxn],w[maxn],cnt,ncnt,n,m,op;
struct Edge{
    int to,neext;
}e[maxn<<1];
inline void add(int u,int v){e[++cnt]=(Edge){v,head[u]};head[u]=cnt;}
inline void pushup(int rt){a[rt]=a[rt<<1]+a[rt<<1|1];}
void build(int rt,int l,int r){
    if(l==r){a[l]=w[l];return ;}
    build(lson),build(rson);
    pushup(rt);
}
void pushdown(int rt,int l,int r){
    a[rt<<1]+=laz[rt]*(mid-l+1),a[rt<<1|1]+=laz[rt]*(r-mid);
    laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
    laz[rt]=0;
}
void update(int rt,int l,int r,int x,int y,int k){
    if(l>=x&&r<=y){a[rt]+=laz[rt]*(r-l+1);laz[rt]+=k;return ;}
    if(laz[rt])pushdown(rt,l,r);
    if(x<=mid)update(lson,x,y,k);
    if(y>mid)update(rson,x,y,k);
    pushup(rt);
}
int res=0;
void query(int rt,int l,int r,int x,int y){
    if(l>=x&&r<=y){res+=a[rt];return; }
    if(laz[rt])pushdown(rt,l,r);
    if(l<=mid)query(lson,x,y);
    if(r>mid)query(rson,x,y);
}
void dfs(int u,int f){
    sz[u]=1;dep[u]=dep[f]+1;fa[u]=f;
    int maxson=-1;
    for(int i=head[u];i;i=e[i].neext){
        int v=e[i].to;
        if(v==f)continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>maxson){son[u]=v,maxson=sz[v];}
    }
}
void dfs2(int u,int tp){
    dfn[u]=++ncnt;
    top[u]=tp;
    if(!son[u])return ;
    dfs2(son[u],tp);
    for(int i=head[u];i;i=e[i].neext){
        int v=e[i].to;
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}
int query_path(int x,int y){
    int ans=0;
    while (top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res=0;
        query(1,1,n,dfn[top[x]],dfn[x]);
        ans+=res;
        return ans;
    }
}
signed main(){
    io.read(n),io.read(m);
    for(int i=1;i<=n;i++)io.read(w[i]);
    for(int i=1;i<=n-1;i++){
        int a,b;
        add(a,b),add(b,a);

    }
    dfs(1,0);dfs2(1,1);
    build(1,1,n);
    while(m--){
        io.read(op);
        if(op==1){
            int x,k;
            io.read(x),io.read(k);
            update(1,1,n,dfn[x],dfn[x],k);
        }
        if(op==2){
            int k,x;
            io.read(x),io.read(k);
            update(1,1,n,dfn[x],dfn[x]+sz[x]-1,k);
        }else{
            int x;io.read(x);
            io.write(query_path(1,x),'\n');
        }
    }
    return 0;

}