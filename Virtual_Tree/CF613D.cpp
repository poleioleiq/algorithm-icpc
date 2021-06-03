#include <bits/stdc++.h>

#define NS (100005)
#define LGS (17)

using namespace std;

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

int n, id[NS], dfn, q, k, h[NS], c[NS];

int pre[NS][LGS + 1], dep[NS];

int sta[NS], top;

bool book[NS];

void Init(int a, int fa) {
  pre[a][0] = fa, dep[a] = dep[fa] + 1, id[a] = ++dfn;
  for (int i = 1; i <= LGS; i += 1) pre[a][i] = pre[pre[a][i - 1]][i - 1];
  for (int i = g.head[a]; ~i; i = g.nxt[i])
    if (g[i] != fa) Init(g[i], a);
}

int lca(int a, int b) {
  if (dep[a] > dep[b]) swap(a, b);
  for (int i = LGS; i >= 0; i -= 1)
    if (dep[pre[b][i]] >= dep[a]) b = pre[b][i];
  if (a == b) return a;
  for (int i = LGS; i >= 0; i -= 1)
    if (pre[a][i] != pre[b][i]) a = pre[a][i], b = pre[b][i];
  return pre[a][0];
}

bool cmp(int a, int b) { return id[a] < id[b]; }

int Dp(int a) {
  int tot = 0, ans = 0;
  for (int i = g.head[a]; ~i; i = g.nxt[i]) ans += Dp(g[i]), tot += c[g[i]];
  if (book[a])
    c[a] = 1, ans += tot;
  else if (tot > 1)
    c[a] = 0, ans++;
  else
    c[a] = tot;
  return ans;
}

int main(int argc, char const* argv[]) {
  IN(n);
  for (int i = 1, a, b; i < n; i += 1) IN(a), IN(b), g.push(a, b), g.push(b, a);
  Init(1, 0), IN(q);
  while (q--) {
    IN(k);
    for (int i = 1; i <= k; i += 1) IN(h[i]), book[h[i]] = 1;
    for (int i = 1; i <= k; i += 1)
      if (book[pre[h[i]][0]]) {
        puts("-1");
        goto end;
      }
    sort(h + 1, h + 1 + k, cmp);
    sta[top = 1] = 1, g.sz = 0, g.head[1] = -1;
    for (int i = 1, l; i <= k; i += 1)
      if (h[i] != 1) {
        l = lca(h[i], sta[top]);
        if (l != sta[top]) {
          while (id[l] < id[sta[top - 1]])
            g.push(sta[top - 1], sta[top]), top--;
          if (id[l] > id[sta[top - 1]])
            g.head[l] = -1, g.push(l, sta[top]), sta[top] = l;
          else
            g.push(l, sta[top--]);
        }
        g.head[h[i]] = -1, sta[++top] = h[i];
      }
    for (int i = 1; i < top; i += 1) g.push(sta[i], sta[i + 1]);
    printf("%d\n", Dp(1));
  end:
    for (int i = 1; i <= k; i += 1) book[h[i]] = 0;
  }
  return 0;
}