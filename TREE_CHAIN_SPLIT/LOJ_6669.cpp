#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
#define mxn 3010
using namespace std;
int n, num, q[mxn], fa[mxn], dep[mxn], siz[mxn], sn[mxn][2];
vector<int> ds[mxn];
int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int d;
    scanf("%d", &d);
    return d;
}
void print() {
    printf("!");
    for (int i = 2; i <= n; ++i) printf(" %d", fa[i]);
    puts("");
}
void add(int u, int v) {
    fa[v] = u;
    if (!sn[u][0])
        sn[u][0] = v;
    else
        sn[u][1] = v;
}
void upd(int u) {
    for (; u; u = fa[u]) {
        siz[u]++;
        if (siz[sn[u][0]] < siz[sn[u][1]])
            swap(sn[u][0], sn[u][1]);
    }
}
void solve(int d) {
    int u, v, x, dis, sz = ds[d].size();
    for (int i = 0; i < sz; ++i)
        for (u = ds[d][i], x = 1;; x = q[x - dep[q[1]] + 1], x = sn[x][1]) {
            for (num = 0; x && dep[x] < d; q[++num] = x, x = sn[x][0])
                ;
            if (num == 1) {
                add(q[1], u);
                break;
            }
            v = q[num];
            dis = ask(v, u);
            x = (dep[u] + dep[v] - dis) / 2;
            if (x == dep[v]) {
                add(v, u);
                break;
            }
        }
    for (int i = 0; i < sz; ++i) upd(ds[d][i]);
}
int main() {
    scanf("%d", &n);
    int d, sz, D = 0;
    upd(1);
    dep[1] = 1;
    for (int i = 2; i <= n; ++i) {
        d = ask(1, i);
        ds[d + 1].pb(i);
        dep[i] = d + 1;
        if (dep[i] > D)
            D = dep[i];
    }
    sz = ds[2].size();
    for (int i = 0; i < sz; ++i) add(1, ds[2][i]), upd(ds[2][i]);
    for (int i = 3; i <= D; ++i) solve(i);
    print();
    return 0;
}