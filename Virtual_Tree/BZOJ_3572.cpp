#include <bits/stdc++.h>

#define NS (300005)
#define LGS (19)
#define FIR first
#define SEC second

using namespace std;

typedef pair<int, int> PII;

template <typename _Tp>
inline void IN(_Tp& dig) {
  char c;
  bool flag = 0;
  dig = 0;
  while (c = getchar(), !isdigit(c))
    if (c == '-') flag = 1;
  while (isdigit(c)) dig = dig * 10 + c - '0', c = getchar();
  if (flag) dig = -dig;
}

struct graph {
  int head[NS], nxt[NS << 1], to[NS << 1], sz;
  void init() { memset(head, -1, sizeof(head)), sz = 0; }
  graph() { init(); }
  void push(int a, int b) { nxt[sz] = head[a], to[sz] = b, head[a] = sz++; }
  int operator[](const int a) { return to[a]; }
} g;

int n, m, q, h[NS], arr[NS], ans[NS];

int pre[NS][LGS + 1], dep[NS], id[NS], dfn, sz[NS];

int st[NS], top;

bool book[NS];

PII mx[NS];

bool cmp(int a, int b) { return id[a] < id[b]; }

void Init(int a, int fa) {
  pre[a][0] = fa, dep[a] = dep[fa] + 1, id[a] = ++dfn, sz[a] = 1;
  for (int i = 1; i <= LGS; i += 1) pre[a][i] = pre[pre[a][i - 1]][i - 1];
  for (int i = g.head[a]; ~i; i = g.nxt[i])
    if (g[i] != fa) Init(g[i], a), sz[a] += sz[g[i]];
}

int jump(int a, int k) {
  for (int i = 0; i <= LGS; i += 1)
    if ((k >> i) & 1) a = pre[a][i];
  return a;
}

int lca(int a, int b) {
  if (dep[a] > dep[b]) swap(a, b);
  b = jump(b, dep[b] - dep[a]);
  if (a == b) return a;
  for (int i = LGS; i >= 0; i -= 1)
    if (pre[a][i] != pre[b][i]) a = pre[a][i], b = pre[b][i];
  return pre[a][0];
}

void dfs1(int a) {
  if (book[a])
    mx[a] = PII(0, a);
  else
    mx[a] = PII(1e8, 0);
  for (int i = g.head[a]; ~i; i = g.nxt[i]) {
    dfs1(g[i]);
    PII tmp = mx[g[i]];
    tmp.FIR = dep[mx[g[i]].SEC] - dep[a];
    mx[a] = min(mx[a], tmp);
  }
}

void dfs2(int a) {
  for (int i = g.head[a]; ~i; i = g.nxt[i]) {
    PII tmp = mx[a];
    tmp.FIR += dep[g[i]] - dep[a];
    mx[g[i]] = min(mx[g[i]], tmp), dfs2(g[i]);
  }
  ans[mx[a].SEC] = max(ans[mx[a].SEC], sz[a]);
}

void dfs3(int a) {
  for (int i = g.head[a], x, y, dis, z; ~i; i = g.nxt[i]) {
    if (x = mx[a].SEC, y = mx[g[i]].SEC, x != y) {
      dis = dep[x] + dep[y] - (dep[lca(x, y)] << 1);
      z = jump(g[i], (dis >> 1) - mx[g[i]].FIR);
      if (dis & 1)
        ans[x] -= sz[z];
      else {
        if (z != a && z != g[i])
          z = jump(g[i], (dis >> 1) - mx[g[i]].FIR - (x < y));
        else if (z == a)
          z = jump(g[i], (dis >> 1) - mx[g[i]].FIR - 1);
        ans[x] -= sz[z];
      }
      if (g[i] != z) ans[y] += sz[z] - sz[g[i]];
    }
    dfs3(g[i]);
  }
}

int main(int argc, char const* argv[]) {
  IN(n);
  for (int i = 1, a, b; i < n; i += 1) IN(a), IN(b), g.push(a, b), g.push(b, a);
  Init(1, 0), IN(q);
  while (q--) {
    IN(m), g.sz = 0;
    for (int i = 1; i <= m; i += 1)
      IN(h[i]), book[h[i]] = 1, ans[arr[i] = h[i]] = 0;
    sort(h + 1, h + 1 + m, cmp), st[top = 1] = 1, g.head[1] = -1;
    for (int i = 1, l; i <= m; i += 1) {
      if (h[i] == 1) continue;
      l = lca(st[top], h[i]);
      if (l != st[top]) {
        while (id[l] < id[st[top - 1]]) g.push(st[top - 1], st[top]), top--;
        if (id[l] > id[st[top - 1]])
          g.head[l] = -1, g.push(l, st[top]), st[top] = l;
        else
          g.push(l, st[top--]);
      }
      g.head[h[i]] = -1, st[++top] = h[i];
    }
    for (int i = 1; i < top; i += 1) g.push(st[i], st[i + 1]);
    dfs1(1), dfs2(1), dfs3(1);
    for (int i = 1; i <= m; i += 1) printf("%d ", ans[arr[i]]);
    putchar(10);
    for (int i = 1; i <= m; i += 1) book[h[i]] = 0;
  }
  return 0;
}