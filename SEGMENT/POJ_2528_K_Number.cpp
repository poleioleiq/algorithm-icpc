#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <map>
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
#define Rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;


template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int N = 100005;

struct node
{
    int L, R, val;
}a[N << 2 | 1];

int ans, b[N], c[N], tem[N << 1];
bool vis[N << 1];

void down(int x)
{
    if(a[x].val != -1)///0被占用
    {
        a[x << 1].val = a[x].val;
        a[x << 1 | 1].val = a[x].val;
        a[x].val = -1;
    }
}

void init(int num, int l, int r)
{
    a[num].L = l;
    a[num].R = r;
    a[num].val = -1;///数字从0开始传的缘故

    if(l == r)
        return ;

    int mid = (l + r) >> 1;
    init(num << 1, l, mid);
    init(num << 1 | 1, mid + 1, r);
}

void update(int num, int l, int r, int t)
{
    if(a[num].L > r || a[num].R < l)
        return ;
    if(a[num].L >= l && a[num].R <= r)
    {
        a[num].val = t;
        return ;
    }
    if(a[num].L == a[num].R)
        return ;
    down(num);
    update(num << 1, l, r, t);
    update(num << 1 | 1, l, r, t);
}

void slove(int num, int l, int r)///区间[l,r]内有多少种数字
{
    if(a[num].val != -1 && !vis[ a[num].val ])
    {
        vis[ a[num].val ] = 1;
        ans++;///为了遍历到底，这里没有 return
    }
    if(a[num].L == a[num].R)///到底了,返回
        return ;
    down(num);
    int mid = (a[num].L + a[num].R) >> 1;
    slove(num << 1, l, mid);
    slove(num << 1 | 1, mid + 1, r);
}

int main()
{
    int t;
    read(t);
    while(t--)
    {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(tem, 0, sizeof(tem));
        memset(vis, 0, sizeof(vis));
        int n;
        read(n);
        int tot = 0;
        for(int i = 0; i < n; ++i)
        {
            read(b[i]),read(c[i]);
            tem[tot++] = b[i];
            tem[tot++] = c[i];
        }

        sort(tem, tem + tot);
        ///m代表多少种数字，函数把重复的数字后放
        int m = unique(tem, tem + tot) - tem;
        int tempory = m;
        for(int i = 0; i + 1 < tempory; ++i)
            if(tem[i + 1] - tem[i] > 1)
                tem[m++] = tem[i] + 1;
        sort(tem, tem + m);///离散化后的值>=tem[0]

        init(1, 1, m);
        for(int i = 0; i < n; ++i)
        {   /// + 1 是因为线段树的左界是从1开始的
            int tl = lower_bound(tem, tem + m, b[i]) - tem + 1;
            int tr = lower_bound(tem, tem + m, c[i]) - tem + 1;
            update(1, tl, tr, i);///区间赋值为i
        }
        ans = 0;
        slove(1, 1, m);
        printf("%d\n",ans );
    }
    return 0;
}