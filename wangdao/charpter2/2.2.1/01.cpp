#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
#define N 50005
#define LEN (1 << 9)
#define _R register
#define INF 0x7FFFFFFF
using namespace std;
char Buf[1 << 24], *S(Buf), *T(Buf);
#define getchar() (S == T && (T = (S = Buf) + fread(Buf, 1, 1 << 24, stdin), S == T) ? EOF : *S++)
inline int input() {
    _R int x(0), f(0);
    _R char c(getchar());

    while (!isdigit(c))
        f |= (c == '-'), c = getchar();

    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();

    return f ? -x : x;
}
int a[N << 1], val[N << 1];
int bel[N], BEL[N << 1];
int len, num, Len, Num, n, m;
int C1[LEN][LEN], C2[LEN][N << 1];
int L[LEN], R[LEN], l[LEN], r[LEN];
struct Oper {
    int F, S, E, opt;
};
Oper d[N];
struct Data {
    int pos, val;
    inline Data() {}
    inline Data(int POS, int VAL) : pos(POS), val(VAL) {}
};
Data b[N << 1];
inline bool cmp(const Data &A, const Data &B) {
    return A.val < B.val;
}
inline void Init_Data() {
    n = input(), m = input();
    int cnt = n, tot = 0;

    for (int i = 1; i <= n; ++i)
        b[i] = Data(i, input());

    for (int i = 1; i <= m; ++i) {
        int opt = d[i].opt = input();
        int F = input(), S = input(), T;

        if (opt == 3)
            d[i].F = F, d[i].E = ++cnt, b[cnt] = Data(cnt, S);
        else {
            T = input(), d[i].F = F, d[i].S = S;

            if (opt != 2)
                d[i].E = ++cnt, b[cnt] = Data(cnt, T);
            else
                d[i].E = T;
        }
    }

    sort(b + 1, b + cnt + 1, cmp);

    for (int i = 1; i <= cnt; ++i)
        if (i == 1 || b[i].val != b[i - 1].val)
            val[a[b[i].pos] = ++tot] = b[i].val;
        else
            val[a[b[i].pos] = tot] = b[i].val;

    len = sqrt(n), num = n / len;
    Len = sqrt(tot), Num = tot / Len;

    for (int i = 1; i <= n; ++i)
        bel[i] = (i - 1) / len + 1;

    for (int i = 1; i <= tot; ++i)
        BEL[i] = (i - 1) / Len + 1;

    for (int i = 1; i <= num; ++i)
        l[i] = r[i - 1] + 1, r[i] = l[i] + len - 1;

    if (r[num] != n)
        ++num, l[num] = r[num - 1] + 1, r[num] = n;

    for (int i = 1; i <= Num; ++i)
        L[i] = R[i - 1] + 1, R[i] = L[i] + Len - 1;

    if (R[Num] != tot)
        ++Num, L[Num] = R[Num - 1] + 1, R[Num] = tot;

    for (_R int i = 1; i <= num; ++i) {
        for (_R int j = l[i], lim = r[i]; j <= lim; ++j)
            ++C2[i][a[j]], ++C1[i][BEL[a[j]]];

        for (_R int j = 1; j <= tot; ++j)
            C2[i][j] += C2[i - 1][j];

        for (_R int j = 1; j <= Num; ++j)
            C1[i][j] += C1[i - 1][j];
    }
}
inline int Rank(int x, int y, int val) {
    int P1 = bel[x], P2 = bel[y], ret = 0, pos = BEL[val];

    if (P1 == P2) {
        for (_R int i = x; i <= y; ++i)
            ret += (a[i] < val);

        return ret + 1;
    }

    for (_R int i = x; i <= r[P1]; ++i)
        ret += (a[i] < val);

    for (_R int i = l[P2]; i <= y; ++i)
        ret += (a[i] < val);

    for (_R int i = 1; i < pos; ++i)
        ret += C1[P2 - 1][i] - C1[P1][i];

    for (_R int i = L[pos]; i < val; ++i)
        ret += C2[P2 - 1][i] - C2[P1][i];

    return ret + 1;
}
int Cnt[LEN], cnt[N << 1];
inline void Add(int x, int y) {
    for (_R int i = x; i <= y; ++i)
        ++Cnt[BEL[a[i]]], ++cnt[a[i]];
}
inline void Minus(int x, int y) {
    for (_R int i = x; i <= y; ++i)
        --Cnt[BEL[a[i]]], --cnt[a[i]];
}
inline int Get(int x, int y, int k) {
    int P1 = bel[x], P2 = bel[y], A = 1, B, cur = 0;

    if (P1 == P2) {
        Add(x, y);

        for (; k >= Cnt[A]; ++A)
            k -= Cnt[A];

        for (B = L[A]; k >= cnt[B]; ++B)
            k -= cnt[B];

        Minus(x, y);
        return val[B];
    }

    Add(x, r[P1]), Add(l[P2], y);

    for (; k >= (cur = Cnt[A] + C1[P2 - 1][A] - C1[P1][A]); ++A)
        k -= cur;

    for (B = L[A]; k >= (cur = cnt[B] + C2[P2 - 1][B] - C2[P1][B]); ++B)
        k -= cur;

    Minus(x, r[P1]), Minus(l[P2], y);
    return val[B];
}
inline void Modify(int pos, int x) {
    int P = a[pos], BP = BEL[P], BN = BEL[x];

    for (_R int i = bel[pos]; i <= num; ++i)
        ++C1[i][BN], ++C2[i][x], --C1[i][BP], --C2[i][P];

    a[pos] = x;
}
inline int Pre(int x, int y, int k) {
    int P1 = bel[x], P2 = bel[y], pos = BEL[k], A = pos - 1, B = k - 1;

    if (P1 == P2) {
        Add(x, y);

        while (B >= L[pos] && cnt[B] == 0)
            --B;

        if (B == L[pos] - 1) {
            while (Cnt[A] == 0 && A >= 1)
                --A;

            if (A == 0) {
                Minus(x, y);
                return -INF;
            }

            for (B = R[A]; (!cnt[B]) && (B > L[A]); --B);
        }

        Minus(x, y);
        return val[B];
    }

    Add(x, r[P1]), Add(l[P2], y);

    while (B >= L[pos] && cnt[B] + C2[P2 - 1][B] - C2[P1][B] == 0)
        --B;

    if (B == L[pos] - 1) {
        while (Cnt[A] + C1[P2 - 1][A] - C1[P1][A] == 0 && A >= 1)
            --A;

        if (A == 0) {
            Minus(x, r[P1]), Minus(l[P2], y);
            return -INF;
        }

        for (B = R[A]; (cnt[B] + C2[P2 - 1][B] - C2[P1][B] == 0) && (B > L[A]) ; --B);
    }

    Minus(x, r[P1]), Minus(l[P2], y);
    return val[B];
}
inline int Nex(int x, int y, int k) {
    int P1 = bel[x], P2 = bel[y], pos = BEL[k], A = pos + 1, B = k + 1;

    if (P1 == P2) {
        Add(x, y);

        while (B <= R[pos] && cnt[B] == 0)
            ++B;

        if (B == R[pos] + 1) {
            while (Cnt[A] == 0 && A <= Num)
                ++A;

            if (A == Num + 1) {
                Minus(x, y);
                return INF;
            }

            for (B = L[A]; (!cnt[B]) && (B < R[A]); ++B);
        }

        Minus(x, y);
        return val[B];
    }

    Add(x, r[P1]), Add(l[P2], y);

    while (B <= R[pos] && cnt[B] + C2[P2 - 1][B] - C2[P1][B] == 0)
        ++B;

    if (B == R[pos] + 1) {
        while (Cnt[A] + C1[P2 - 1][A] - C1[P1][A] == 0 && A <= Num)
            ++A;

        if (A == Num + 1) {
            Minus(x, r[P1]), Minus(l[P2], y);
            return INF;
        }

        for (B = L[A]; (cnt[B] + C2[P2 - 1][B] - C2[P1][B] == 0) && (B < R[A]); ++B);
    }

    Minus(x, r[P1]), Minus(l[P2], y);
    return val[B];
}
int main() {
    Init_Data();

    for (int i = 1; i <= m; ++i) {
        if (d[i].opt == 1)
            printf("%d\n", Rank(d[i].F, d[i].S, a[d[i].E]));
        else if (d[i].opt == 2)
            printf("%d\n", Get(d[i].F, d[i].S, d[i].E - 1));
        else if (d[i].opt == 3)
            Modify(d[i].F, a[d[i].E]);
        else if (d[i].opt == 4)
            printf("%d\n", Pre(d[i].F, d[i].S, a[d[i].E]));
        else
            printf("%d\n", Nex(d[i].F, d[i].S, a[d[i].E]));
    }

    return 0;
}