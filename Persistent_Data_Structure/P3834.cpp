/**
 * ALGORIHTM_P3834_CPP
 * @author : MWT
 * @date : 15:00 2020/4/4
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

template<class T>
void tomax(T &a, T b) { a = max(a, b); }

template<class T>
void tomin(T &a, T b) { a = min(a, b); }

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
#if DEBUG  //���ԣ�����ʾ�ַ�
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    template<class T>
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
        for (; blank(ch); ch = gc());
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }

    inline void read(char &c) {
        for (c = gc(); blank(c); c = gc());
    }

    inline void push(const char &c) {
#if DEBUG  //���ԣ�����ʾ�ַ�
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }

    template<class T>
    inline void write(T x) {
        if (x < 0) x = -x, push('-');  // �������
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }

    template<class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;

const int maxn = 2e5 + 10;
int tot, n, m, len;
int sum[(maxn << 5) + 10], ls[(maxn << 5) + 10], rs[(maxn << 5) + 10], rt[(maxn << 5) + 10];
/*sum[i]��ʾ�ڵ�i��Ȩֵ��ls[i]��ʾ����ӽڵ㣬rs[i]��ʾ�Ҷ��ӽڵ㣬rt[i]��ʾ���ڵ�*/
int a[maxn + 10], ind[maxn + 10];
/*a[]��ʾԭ���飬ind[]��ʾhash����*/
/*get_hash(val)���������е�һ�����ڵ���val���±�*/
inline int get_hash(const int &val) {
    return lower_bound(ind + 1, ind + len + 1, val) - ind;
}
/*�����ݹ�д��*/
int build(int l, int r) {
    int root = ++tot;
    if (l == r)return root;
    int mid = (l + r) >> 1;
    ls[root] = build(l, mid);
    rs[root] = build(mid + 1, r);
    return root;
}
/*���²�����dir��ʾ�µĽڵ㣬�ȳ�ʼ���¼ӽڵ�����Ҷ���Ϊ�ɽڵ�����Ҷ��ӣ�
 * tot++�������ɢ���õ��ĵ�k<=mid�����ݹ�����Ӳ��Ҵ���һ���µĽڵ㣬�������Ҷ������ӵ�����󷵻�dir*/
int update(int k, int l, int r, int root) {
    int dir = ++tot;
    ls[dir] = ls[root], rs[dir] = rs[root], sum[dir] = sum[root] + 1;
    if (l == r)return dir;
    int mid = (l + r) >> 1;
    if (k <= mid)ls[dir] = update(k, l, mid, ls[dir]);
    else rs[dir] = update(k, mid + 1, r, rs[dir]);
    return dir;
}
/*��ѯ�����k����Ϊ�ɳ־û��߶�������ԭ���߶����Ļ����Ͻ����޸ĵģ����Ծ߱��ɼ��ԣ����Խ���v�ε��߶�����ȥ��u�ε��߶���
 * ���k<=sum[ls[v]]-sum[lson[u]],��ʾ��������Ȩֵ����k����ζ�ŵ�k��ض�������������֮��Ȼ*/
int query(int u, int v, int l, int r, int k) {
    int mid = (l + r) >> 1, x = sum[ls[v]] - sum[ls[u]];
    if (l == r)return l;
    if (k <= x)return query(ls[u], ls[v], l, mid, k);
    else return query(rs[u], rs[v], mid + 1, r, k - x);
}

/*hash����*/
inline void _init_hash() {
    io.read(n), io.read(m);
    for (int i = 1; i <= n; i++)io.read(a[i]);
    memcpy(ind, a, sizeof ind);
    sort(ind + 1, ind + 1 + n);
    len = unique(ind + 1, ind + n + 1) - ind - 1;
    rt[0] = build(1, len);
    for (int i = 1; i <= n; i++)rt[i] = update(get_hash(a[i]), 1, len, rt[i - 1]);
}

int l, r, k;

signed main() {
    _init_hash();

    while (m--) {
        io.read(l), io.read(r), io.read(k);
        io.write(ind[query(rt[l - 1], rt[r], 1, len, k)], '\n');
    }
    return 0;
}
