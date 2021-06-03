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

#define ls (p<<1)
#define rs (p<<1|1)
const int mod=10007;
const int M=100010;
struct node
{
    int l,r;
    int a,b,c;//a是乘数，b是加数，c是替换的数
    int sum[3];//分别记录1次，2次，3次和
}t[M<<2];
void pushup(int p)
{
    int i;
    for (i = 0; i < 3; i++)
        t[p].sum[i] = (t[ls].sum[i] + t[rs].sum[i]) % mod;//每个和都等于左子树加右子树
}
void pushdown(int p)
{
    if (t[p].l == t[p].r)//到了节点返回
        return;
    int a = t[p].a, b = t[p].b, c = t[p].c;
    if (c)//替换
    {
        t[ls].a = t[rs].a = a;//之前以为这个可以直接改成1，但是同一个root不一定全部都改变值
        t[ls].b = t[rs].b = b;
        t[ls].c = t[rs].c = c;
        t[ls].sum[2] = (t[ls].r - t[ls].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[ls].sum[1] = (t[ls].r - t[ls].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[ls].sum[0] = (t[ls].r - t[ls].l + 1) * (a * c % mod + b) % mod;
        t[rs].sum[2] = (t[rs].r - t[rs].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[rs].sum[1] = (t[rs].r - t[rs].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[rs].sum[0] = (t[rs].r - t[rs].l + 1) * (a * c % mod + b) % mod;
    }
    else
    {
        t[ls].a = (t[ls].a * a) % mod;
        t[ls].b = (t[ls].b * a + b) % mod;
        t[rs].a = (t[rs].a * a) % mod;
        t[rs].b = (t[rs].b * a + b) % mod;
        t[ls].sum[2] = (a * a % mod * a % mod * t[ls].sum[2] % mod + 3 * a % mod * a % mod * b % mod * t[ls].sum[1] % mod + 3 * a % mod * b % mod * b % mod * t[ls].sum[0] % mod + b * b % mod * b % mod * (t[ls].r - t[ls].l + 1) % mod) % mod;
        t[ls].sum[1] = (a * a % mod * t[ls].sum[1] % mod + b * b % mod * (t[ls].r - t[ls].l + 1) % mod + 2 * a * b % mod * t[ls].sum[0] % mod) % mod;
        t[ls].sum[0] = (a * t[ls].sum[0] % mod + b * (t[ls].r - t[ls].l + 1) % mod) % mod;
        t[rs].sum[2] = (a * a % mod * a % mod * t[rs].sum[2] % mod + 3 * a % mod * a % mod * b % mod * t[rs].sum[1] % mod + 3 * a % mod * b % mod * b % mod * t[rs].sum[0] % mod + b * b % mod * b % mod * (t[rs].r - t[rs].l + 1) % mod) % mod;
        t[rs].sum[1] = (a * a % mod * t[rs].sum[1] % mod + b * b % mod * (t[rs].r - t[rs].l + 1) % mod + 2 * a * b % mod * t[rs].sum[0] % mod) % mod;
        t[rs].sum[0] = (a * t[rs].sum[0] % mod + b * (t[rs].r - t[rs].l + 1) % mod) % mod;
    }
    t[p].b = t[p].c = 0;
    t[p].a = 1;
}
void build(int p,int l,int r)
{
   t[p].l = l, t[p].r = r;
   t[p].a = 1, t[p].b = t[p].c = 0;
   t[p].sum[0] = t[p].sum[1] = t[p].sum[2] = 0;
   if(l==r)
   {
       return ;
   }
   int mid=l+r>>1;
   build(ls,l,mid);
   build(rs,mid+1,r);
   pushup(p);
}
void update(int p,int l,int r,int x,int y,int val,int flag)
{
    if(x<=l&&r<=y)//找到更新区间
    {
        if (flag == 0)//加val
        {
            t[p].b = (t[p].b + val) % mod;//加数改变
            t[p].sum[2] = (t[p].sum[2] + 3 * val % mod * t[p].sum[1] % mod + 3 * val % mod * val % mod * t[p].sum[0] % mod + val * val % mod * val % mod * (t[p].r - t[p].l + 1) % mod) % mod;
            t[p].sum[1] = (t[p].sum[1] + val * val % mod * (t[p].r - t[p].l + 1) % mod + 2 * val * t[p].sum[0] % mod) % mod;
            t[p].sum[0] = (t[p].sum[0] + val * (t[p].r - t[p].l + 1)) % mod;
        }
        else if (flag == 1)
        {
            t[p].a = (t[p].a * val) % mod;//乘数改变
            t[p].b = (t[p].b * val) % mod;//加数也改变
            t[p].sum[2] = val * val % mod * val % mod * t[p].sum[2] % mod;
            t[p].sum[1] = val * val % mod * t[p].sum[1] % mod;
            t[p].sum[0] = val * t[p].sum[0] % mod;
        }
        else if (flag == 2)
        {
            t[p].a = 1;//乘数变为1
            t[p].b = 0;//加数变成0
            t[p].c = val;
            t[p].sum[2] = (t[p].r - t[p].l + 1) % mod * val % mod * val % mod * val % mod;
            t[p].sum[1] = (t[p].r - t[p].l + 1) % mod * val % mod * val % mod;
            t[p].sum[0] = (t[p].r - t[p].l + 1) * val % mod;
        }
        return;
    }
    pushdown(p);//向下更新
    int mid=l+r>>1;
    if(x<=mid)
    {
        update(ls,l,mid,x,y,val,flag);
    }
    if(y>mid)
    {
        update(rs,mid+1,r,x,y,val,flag);
    }
    pushup(p);//求和向上更新
}
ll query(int p,int l,int r,int x,int y,int flag)
{
    if(x<=l&&r<=y)//找到区间
    {
        return t[p].sum[flag];
    }
    pushdown(p);//向下更新
    int mid=l+r>>1;
    int ans=0;
    if(x<=mid)
    {
        ans+=query(ls,l,mid,x,y,flag);
    }
    if(y>mid)
    {
        ans+=query(rs,mid+1,r,x,y,flag);
    }
    return ans%mod;
}
signed main( )
{
    int n,q,x,y,w,c;
    while(~scanf("%d%d",&n,&q)&&(n+q))
    {
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d%d%d",&c,&x,&y,&w);
            if(c==1)
            {
                update(1,1,n,x,y,w,0);
                
            }
            else if(c==2)
            {
                update(1,1,n,x,y,w,1);
               
            }
            else if(c==3)
            {
                update(1,1,n,x,y,w,2);
                
            }
            else
            {
                cout<<query(1,1,n,x,y,w-1)<<endl;
            }
             
        }
    }
    return 0;
}