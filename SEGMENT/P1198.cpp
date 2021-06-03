/** 
 * SEGMENT_P1198_CPP
 * @author : MWT 
 * @date : 18:01 2020/3/24 
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

 //#define DEBUG 1  //调试开关
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

const long long inf=-(1<<62);
int m,cnt;
char op[2];
long long tree[800005],x,t,p;
long long max(long long a,long long b){return a>b?a:b;}
void add(int s,int k,int rt,int l,int r){
    if(l==r){tree[rt]=k;return;}
    int mid=(l+r)>>1;
    if(mid>=s) add(s,k,rt<<1,l,mid);
    if(mid<s) add(s,k,rt<<1|1,mid+1,r);
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1])%p;
}
long long ask(int ll,int rr,int rt,int l,int r)
{
    if(ll<=l&&rr>=r) return tree[rt];
    int mid=(l+r)>>1;
    long long a=inf,b=inf;
    if(mid>=ll) a=ask(ll,rr,rt<<1,l,mid);
    if(mid<rr) b=ask(ll,rr,rt<<1|1,mid+1,r);
    return max(a,b);
}

signed main(){
    io.read(m),io.read(p);
    for(register int  i=0;i<m;i++){
        io.read(op),io.read(x);
        if(op[0]=='A'){
            add(cnt+1,(x+t)%p,1,1,m);
            cnt++;
        }
        if(op[0]=='Q'){
            if(x==0) t=0;
            else t=ask(cnt-x+1,cnt,1,1,m)%p;
            io.write(t,'\n');
        }
    }
    return 0;
}
