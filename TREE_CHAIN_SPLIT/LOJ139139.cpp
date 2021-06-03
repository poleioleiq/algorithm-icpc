/** 
 * ALGORIHTM_LOJ139139_CPP
 * @author : MWT 
 * @date : 16:07 2021/1/4 
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

const int maxn=2e6+5;
struct edge{
    int to,nxt;
}e[maxn<<1];
struct point{
    int val,add;
}p[maxn<<2];
int head[maxn],a[maxn],b[maxn];//e数组head【】

int par[maxn],dep[maxn],top[maxn],id[maxn],size[maxn];
namespace tree{
    void build(int x,int stdl,int stdr){
        p[x].add=0;
        if(stdl==stdr){p[x].val=a[stdl];return ;}
        int mid =stdl+stdr>>1;
        build(x<<1,stdl,mid),build(x<<1|1,mid+1,stdr);
    }
    void pushdown(int x,int stdl,int stdr){
        int mid=stdl+stdr>>1;
        p[x<<1].val+=(mid-stdr+1)*p[x].add;
        p[x<<1|1].val+=(stdr-mid+1)*p[x].add;
        p[x<<1].add+=p[x].add;
        p[x<<1|1].add+=p[x].add;
        p[x].add=0;

    }
    void update(int x,int stdl,int stdr ,int l,int r,int y){
        if(r<stdl||l>stdr)return;
        if(stdl>l&&stdr<=r){
            p[x].val+=y*(stdr-stdl+1),p[x].add+=y;
            return ;
        }
        pushdown(x,stdl,stdr);
        int mid=stdl+stdr>>1;
        update(x<<1,stdl,mid,l,r,y),update(x<<1|1,mid+1,stdr,l,r,y);
        p[x].val=p[x<<1].val+p[x<<1|1].val;

    }
    int query(int x,int stdl,int stdr,int l,int r){
        if(stdl>r||stdr<l)return 0;
        if(stdl>=l&&stdr<=r){
            return p[x].val;

        }
        pushdown(x,stdl,stdr);
        int mid=stdl+stdr>>1;
        return query(x<<1,stdl,mid,l,r)+query(x<<1|1,mid+1,stdr,l,r);

    }
    using namespace tree;

}
