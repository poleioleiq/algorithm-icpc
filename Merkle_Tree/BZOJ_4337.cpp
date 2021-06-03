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
#define mod 1000000007
#define Maxn 105
#define base 997

int n,m,cnt,father,_n[Maxn];
long long f[Maxn],h[Maxn][Maxn];
vector<int> g[Maxn];
void dfs(int num,int fa){
    f[num]=1;
    int tn=0;
    long long t[Maxn];
    for (int i=0;i<g[num].size();i++)
        if (g[num][i]!=fa){
            dfs(g[num][i],num);
            t[++tn]=f[g[num][i]];
        }
    sort(t+1,t+tn+1);
    for (int i=1;i<=tn;i++)
        f[num]=(f[num]*base+t[i])%mod;
}
void clearLine()
{
    for (int i=1;i<=n;i++)g[i].clear();
}
signed main()
{
    io.read(m);
    for(int i=1;i<=m;i++){
        io.read(n);
        _n[i]=n;
        clearLine();
        for (int j=1;j<=n;j++){
            io.read(father);
            if(father){
                g[father].push_back(j);
                g[j].push_back(father);
            }
        }
        for (int j=1;j<=n;j++){
            dfs(j,0);h[i][j]=f[j];
        }sort(h[i]+1,h[i]+n+1);
    }
    for(int i=1;i<=m;i++)
        for(int j=1,k;j<=i;j++)
            if(_n[i]==_n[j]){
                for(k=1;k<=_n[i];k++)
                    if(h[i][k]!=h[j][k])break;
                if(k>_n[i]){io.write(j,'\n');break;}
            }
    return 0;
}