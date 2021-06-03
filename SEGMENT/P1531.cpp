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

#define DEBUG 1  //调试开关
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
int a[maxn], t[maxn<<2];
inline void pushup(int rt){t[rt] = t[rt<<1]<t[rt<<1|1]?t[rt<<1|1]:t[rt<<1];}
void build(int rt, int l, int r){
    if (l == r){t[rt] = a[l];return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid),build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int x, int y)//单点修改
{
    if (l == r){t[rt]=t[rt]<y?y:t[rt];return;}
    int mid = (l + r) >> 1;
    if (x <= mid) update(rt << 1, l, mid, x, y);
    else update(rt << 1 | 1, mid + 1, r, x, y);//找询问的点在哪个节点上
    pushup(rt);
}
int query(int rt, int l, int r, int x, int y)//区间询问
{
    if (x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1, ans = -1e9;
    if (x <= mid) ans = max(ans, query(rt << 1, l, mid, x, y));//询问的一部分在左儿子的管辖范围内
    if (y > mid) ans = max(ans, query(rt << 1 | 1, mid + 1, r, x, y));//一部分在右儿子范围内
    return ans;
}

signed main()
{
    int n, m;
    io.read(n),io.read(m);
    for (register int i = 1; i <= n; i++)io.read(a[i]);
    build(1, 1, n);
    for (register int i = 1; i <= m; i++)
    {
        char ope[100];
        int x, y;
        io.read(ope),io.read(x),io.read(y);
        if (ope[0] == 'Q')io.write(query(1, 1, n, x, y),'\n');
        else update(1, 1, n, x, y);
    }
}