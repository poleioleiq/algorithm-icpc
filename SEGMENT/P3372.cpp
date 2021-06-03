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
#include <map>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int maxn = 2e5;

int t[maxn << 2];

void pushup(int rt)
{
    t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
}

void build(int l, int r, int rt)
{
    if (l == r) {
        scanf("%d", &t[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p, int v, int l, int r, int rt)
{
    if (l == r) {
        t[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, v, lson);
    else update(p, v, rson);
    pushup(rt);

}
int query(int ql, int qr, int l, int r, int rt)
{
    if (ql <= l && r <= qr) return t[rt];
    int m = (r + l) >> 1;
    int ans = 0;
    if (ql <= m) ans = max(ans, query(ql, qr, lson));
    if (qr > m) ans = max(ans, query(ql, qr, rson));
    return ans;
}


int main()
{
    char ch[2];
    int n, m, a, b;

    while (scanf("%d %d", &n, &m) == 2) {
        build(1, n, 1);
        for (int i = 1; i <= m; i++) {
            scanf("%s %d %d", ch, &a, &b );
            if (ch[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
            else update(a, b, 1, n, 1);
        }
    }
    return 0;
}