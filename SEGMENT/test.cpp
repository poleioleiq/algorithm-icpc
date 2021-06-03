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

//#define DEBUG 1
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


const int maxn = 100010;
int n, k;
priority_queue<int, vector<int>, greater<int> > q;
struct node {
    int x, y;
} s[maxn];

bool cmp1(node a, node b) { return a.x < b.x; }

bool cmp2(node a, node b) { return a.y < b.y; }

int lc[maxn], rc[maxn], L[maxn], R[maxn], D[maxn], U[maxn];

void maintain(int x) {
    L[x] = R[x] = s[x].x;
    D[x] = U[x] = s[x].y;
    if (lc[x])
        L[x] = min(L[x], L[lc[x]]), R[x] = max(R[x], R[lc[x]]),
        D[x] = min(D[x], D[lc[x]]), U[x] = max(U[x], U[lc[x]]);
    if (rc[x])
        L[x] = min(L[x], L[rc[x]]), R[x] = max(R[x], R[rc[x]]),
        D[x] = min(D[x], D[rc[x]]), U[x] = max(U[x], U[rc[x]]);
}

int build(int l, int r) {
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    double av1 = 0, av2 = 0, va1 = 0, va2 = 0;  // average variance
    for (int i = l; i <= r; i++) av1 += s[i].x, av2 += s[i].y;
    av1 /= (r - l + 1);
    av2 /= (r - l + 1);
    for (int i = l; i <= r; i++)
        va1 += (av1 - s[i].x) * (av1 - s[i].x),
                va2 += (av2 - s[i].y) * (av2 - s[i].y);
    if (va1 > va2)
        nth_element(s + l, s + mid, s + r + 1, cmp1);
    else
        nth_element(s + l, s + mid, s + r + 1, cmp2);
    lc[mid] = build(l, mid - 1);
    rc[mid] = build(mid + 1, r);
    maintain(mid);
    return mid;
}

int sq(int x) { return x * x; }

int dist(int a, int b) {
    return max(sq(s[a].x - L[b]), sq(s[a].x - R[b])) +
           max(sq(s[a].y - D[b]), sq(s[a].y - U[b]));
}

void query(int l, int r, int x) {
    if (l > r) return;
    int mid = (l + r) >> 1, t = sq(s[mid].x - s[x].x) + sq(s[mid].y - s[x].y);
    if (t > q.top()) q.pop(), q.push(t);
    int distl = dist(x, lc[mid]), distr = dist(x, rc[mid]);
    if (distl > q.top() && distr > q.top()) {
        if (distl > distr) {
            query(l, mid - 1, x);
            if (distr > q.top()) query(mid + 1, r, x);
        } else {
            query(mid + 1, r, x);
            if (distl > q.top()) query(l, mid - 1, x);
        }
    } else {
        if (distl > q.top()) query(l, mid - 1, x);
        if (distr > q.top()) query(mid + 1, r, x);
    }
}

signed main() {
    io.read(n),io.read(k);
    k *= 2;
    for (int i = 1; i <= k; i++) q.push(0);
    for (int i = 1; i <= n; i++) io.read(s[i].x),io.read( s[i].y);
    build(1, n);
    for (int i = 1; i <= n; i++) query(1, n, i);
    io.write( q.top(),'\n');
    return 0;
}