/** 
 * KUANGBIN___LOJ_139_TCS2_CPP
 * @author : MaWeiTao 
 * @date : 19:48 2020/3/10 
 *
 */

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
#define lson(x) x << 1
#define rson(x) x << 1 | 1
#define int long long
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

using namespace std;

const int maxn = 200020;
struct edge {
    int to, nxt;
} e[maxn << 1];
struct point {
    int val, add;
} p[maxn << 2];
int head[maxn], a[maxn], b[maxn];
int par[maxn], dep[maxn], top[maxn], id[maxn], size[maxn], son[maxn];
int n, q, root, cnt, ncnt;
namespace segment_tree {
    void build(int x, int stdl, int stdr) {
        p[x].add = 0;
        if (stdl == stdr) {
            p[x].val = a[stdl];
            return;
        }
        int mid = stdl + stdr >> 1;
        build(lson(x), stdl, mid), build(rson(x), mid + 1, stdr);
        p[x].val = p[lson(x)].val + p[rson(x)].val;
    }
    void pushdown(int x, int stdl, int stdr) {
        int mid = stdl + stdr >> 1;
        p[lson(x)].val += (mid - stdl + 1) * p[x].add;
        p[rson(x)].val += (stdr - mid) * p[x].add;
        p[lson(x)].add += p[x].add;
        p[rson(x)].add += p[x].add;
        p[x].add = 0;
    }
    void update_add(int x, int stdl, int stdr, int l, int r, int k) {
        if (r < stdl || stdr < l)
            return;
        if (l <= stdl && stdr <= r) {
            p[x].val += k * (stdr - stdl + 1), p[x].add += k;
            return;
        }
        pushdown(x, stdl, stdr);
        int mid = stdl + stdr >> 1;
        update_add(lson(x), stdl, mid, l, r, k);
        update_add(rson(x), mid + 1, stdr, l, r, k);
        p[x].val = p[lson(x)].val + p[rson(x)].val;
    }
    int query(int x, int stdl, int stdr, int l, int r) {
        if (r < stdl || stdr < l)
            return 0;
        if (l <= stdl && stdr <= r)
            return p[x].val;
        pushdown(x, stdl, stdr);
        int mid = stdl + stdr >> 1;
        return query(lson(x), stdl, mid, l, r) + query(rson(x), mid + 1, stdr, l, r);
    }
}  // namespace segment_tree
using namespace segment_tree;
namespace mwt {
    void add(int x, int y) {
        e[++cnt].to = y;
        e[cnt].nxt = head[x];
        head[x] = cnt;
    }
    void dfs1(int x) {
        size[x] = 1;
        dep[x] = dep[par[x]] + 1;
        for (int i = head[x]; i; i = e[i].nxt) {
            int t = e[i].to;
            if (t == par[x])
                continue;
            par[t] = x;
            dfs1(t);
            size[x] += size[t];
            if (!son[x] || size[son[x]] < size[t])
                son[x] = t;
        }
    }
    void dfs2(int x, int y) {
        top[x] = y;
        id[x] = ++ncnt, a[ncnt] = b[x];
        if (son[x])
            dfs2(son[x], y);
        for (int i = head[x]; i; i = e[i].nxt) {
            int t = e[i].to;
            if (t == par[x] || t == son[x])
                continue;
            dfs2(t, t);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]])
                swap(x, y);
            x = par[top[x]];
        }
        if (dep[x] > dep[y])
            swap(x, y);
        return x;
    }
    int findson(int x, int y) {
        while (top[x] != top[y]) {
            if (par[top[y]] == x)
                return top[y];
            y = par[top[y]];
        }
        return son[x];
    }
}  // namespace hcp
using namespace mwt;
namespace solve_all {
    void update_path(int x, int y, int val) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]])
                swap(x, y);
            update_add(1, 1, n, id[top[x]], id[x], val);
            x = par[top[x]];
        }
        if (dep[x] > dep[y])
            swap(x, y);
        update_add(1, 1, n, id[x], id[y], val);
    }
    void update_subtree(int x, int val) {
        if (lca(x, root) != x)
            update_add(1, 1, n, id[x], id[x] + size[x] - 1, val);
        else if (x == root)
            update_add(1, 1, n, 1, n, val);
        else {
            int s = findson(x, root);
            update_add(1, 1, n, 1, id[s] - 1, val);
            if (id[s] + size[s] <= n)
                update_add(1, 1, n, id[s] + size[s], n, val);
        }
    }
    int query_path(int x, int y) {
        int ans = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]])
                swap(x, y);
            ans += query(1, 1, n, id[top[x]], id[x]);
            x = par[top[x]];
        }
        if (dep[x] > dep[y])
            swap(x, y);
        ans += query(1, 1, n, id[x], id[y]);
        return ans;
    }
    int query_subtree(int x) {
        if (lca(x, root) != x)
            return query(1, 1, n, id[x], id[x] + size[x] - 1);
        else if (x == root)
            return query(1, 1, n, 1, n);
        else {
            int s = findson(x, root), ans = 0;
            ans += query(1, 1, n, 1, id[s] - 1);
            if (id[s] + size[s] <= n)
                ans += query(1, 1, n, id[s] + size[s], n);
            return ans;
        }
    }
}  // namespace solve_all
using namespace solve_all;


signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%lld", &x);
        add(x, i), add(i, x);
    }
    dfs1(1), dfs2(1, 1), build(1, 1, n);
    scanf("%lld", &q);
    while (q--) {
        int opt, x, y, z;
        scanf("%lld", &opt);
        if (opt == 1)
            scanf("%lld", &root);
        if (opt == 2)
            scanf("%lld%lld%lld", &x, &y, &z), update_path(x, y, z);
        if (opt == 3)
            scanf("%lld%lld", &x, &y), update_subtree(x, y);
        if (opt == 4)
            scanf("%lld%lld", &x, &y), printf("%lld\n", query_path(x, y));
        if (opt == 5)
            scanf("%lld", &x), printf("%lld\n", query_subtree(x));
    }
    return 0;
}