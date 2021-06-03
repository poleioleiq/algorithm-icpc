/** 
 * ALGORIHTM_DEMO_CPP
 * @author : MWT 
 * @date : 23:21 2020/5/21 
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

const int N = 1e5 + 10 ;
int n , m , val[N] ;
inline int read() {
    register int x = 0 , f = 1 ;
    register char c = getchar() ;
    for( ; ! isdigit(c) ; c = getchar()) if(c == '-') f = -1 ;
    for( ; isdigit(c) ; c = getchar()) x = (x << 1) + (x << 3) + (c & 15) ;
    return x * f ;
}
class LCT {
public:
    int ch[N][2] , fa[N] , sum[N] , rev[N] ;
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
    inline bool isroot(int x) { return ls(fa[x]) != x && rs(fa[x]) != x ; }
    inline bool getr(int x) { return rs(fa[x]) == x ; }
    inline void pushup(int x) { sum[x] = sum[ls(x)] ^ sum[rs(x)] ^ val[x] ; }
    inline void pushr(int x) { rev[x] ^= 1 ; swap(ls(x) , rs(x)) ; }
    inline void pushdown(int x) { if(rev[x]) { if(ls(x)) pushr(ls(x)) ; if(rs(x)) pushr(rs(x)) ; rev[x] ^= 1 ; } }
    inline void rotate(int x) {
        int y = fa[x] , z = fa[y] , k = getr(x) , w = ch[x][k ^ 1] ; if(! isroot(y)) ch[z][getr(y)] = x ;
        fa[fa[fa[ch[ch[x][k ^ 1] = y][k] = w] = y] = x] = z ; pushup(y) ; pushup(x) ;
    }
    inline void pushall(int x) { if(! isroot(x)) pushall(fa[x]) ; pushdown(x) ; }
    inline void splay(int x) {
        pushall(x) ; while(! isroot(x)) { int y = fa[x] ; if(! isroot(y)) rotate(getr(x) ^ getr(y) ? x : y) ; rotate(x) ; }
    }
    inline void access(int x) { for(int tp = 0 ; x ; x = fa[tp = x]) splay(x) , rs(x) = tp , pushup(x) ; }
    inline void makeroot(int x) { access(x) ; splay(x) ; pushr(x) ; }
    inline void split(int x , int y) { makeroot(x) ; access(y) ; splay(y) ; }
    inline int findroot(int x) { access(x) ; splay(x) ; while(ls(x)) { pushdown(x) ; x = ls(x) ; splay(x) ; } return x ; }
    inline void cut(int x , int y) { makeroot(x) ; if(findroot(y) == x && fa[y] == x && ! ls(y)) fa[y] = ls(x) = 0 , pushup(x) ; }
    inline void link(int x , int y) { makeroot(x) ; if(findroot(y) != x) fa[x] = y ; }
    inline void change(int x , int y) { splay(x) ; val[x] = y ; }
    inline int query(int x , int y) { return split(x , y) , sum[y] ; }
} lct ;
signed main() {
    n = read() ; m = read() ;
    for(register int i = 1 ; i <= n ; i ++) cin >> val[i] ;
    for(register int i = 1 ; i <= m ; i ++) {
        int opt = read() ;
        if(opt == 0) { int x = read() , y = read() ; printf("%d\n" , lct.query(x , y)) ; }
        if(opt == 1) { int x = read() , y = read() ; lct.link(x , y) ; }
        if(opt == 2) { int x = read() , y = read() ; lct.cut(x , y) ; }
        if(opt == 3) { int x = read() , y = read() ; lct.change(x , y) ; }
    }
    return 0 ;
}


