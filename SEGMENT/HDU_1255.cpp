#include<cstdio>
#include<algorithm>

const int N = 2005;

double v[N];

struct Line {
    double y, x1, x2;
    int state;

    Line() {}

    Line(double y, double x1, double x2, int state) : y(y), x1(x1), x2(x2), state(state) {}

    bool operator<(const Line &oth) { return y < oth.y; }
} line[N];

struct Node {
    double l, r, len, len2;
    int cover;

    Node() {}

    Node(double l, double r, double len, double len2, int cover) : l(l), r(r), len(len), len2(len2), cover(cover) {}
} seg[N << 3];

inline int ls(int k) { return k << 1; }

inline int rs(int k) { return k << 1 | 1; }

inline void PushUp(int k) {
    if (seg[k].cover) seg[k].len = seg[k].r - seg[k].l;
    else seg[k].len = seg[ls(k)].len + seg[rs(k)].len;
    if (seg[k].cover >= 2) seg[k].len2 = seg[k].r - seg[k].l;
    else if (seg[k].cover == 1) seg[k].len2 = seg[ls(k)].len + seg[rs(k)].len;
    else seg[k].len2 = seg[ls(k)].len2 + seg[rs(k)].len2;
}

void BuildTree(int l, int r, int k = 1) {
    seg[k] = Node(v[l], v[r], 0, 0, 0);
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    BuildTree(l, m, ls(k));
    BuildTree(m, r, rs(k));
}

void modify(double L, double R, int state, int k = 1) {
    double l = seg[k].l, r = seg[k].r;
    if (L <= l && r <= R) {
        seg[k].cover += state;
        PushUp(k);
        return;
    }
    if (L < seg[ls(k)].r) modify(L, R, state, ls(k));
    if (R > seg[rs(k)].l) modify(L, R, state, rs(k));
    PushUp(k);
}

int main() {
    int n, T;
    double a, b, c, d;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            v[i] = a, v[n + i] = c;
            line[i] = Line(b, a, c, 1), line[n + i] = Line(d, a, c, -1);
        }
        n <<= 1;
        std::sort(v + 1, v + n + 1);
        std::sort(line + 1, line + n + 1);
        BuildTree(1, n);
        double ans = 0.0;
        for (int i = 1; i <= n; ++i) {
            ans += seg[1].len2 * (line[i].y - line[i - 1].y);
            modify(line[i].x1, line[i].x2, line[i].state);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}