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
#include <iomanip>
using namespace std;
#define maxn 400005
#define Fol(i, j, n) for(register int i = j ; i >= n ; i--)
#define For(i, j, n) for(register int i = j ; i <= n ; i++)
int k, n, T, ans, cnt, last;
int fa[maxn], len[maxn], num[maxn], siz[maxn], sum[maxn], tot[maxn], go[maxn][30];
char s[maxn];

inline void insert(int x){
    int p = last, np = ++cnt;
    last = np, siz[np] = 1, len[np] = len[p] + 1; 
    for( ; !go[p][x] && p ; p = fa[p]) go[p][x] = np;
    if(!p) return fa[np] = 1, void();
    int nq = go[p][x];
    if(len[nq] == len[p] + 1) fa[np] = nq;
    else{
        int q = ++cnt;
        fa[q] = fa[nq], fa[nq] = fa[np] = q;
        len[q] = len[p] + 1;
        memcpy(go[q], go[nq], sizeof(go[q]));
        for( ; go[p][x] == nq ; p = fa[p]) go[p][x] = q;
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        cnt = last = 1, scanf("\n %s %d", s + 1, &k),  n = strlen(s + 1), ans = n + 1; 
        For(i, 1, n) insert(s[i] - 'a');
        For(i, 1, cnt) ++tot[len[i]];
        For(i, 1, n) tot[i] += tot[i - 1];
        For(i, 1, cnt) num[tot[len[i]]--] = i;
        Fol(i, cnt, 1){
            int x = num[i];
            if(siz[x] == k) ++sum[len[x]], --sum[len[fa[x]]];
            siz[fa[x]] += siz[x];
        }
        Fol(i, n, 1) sum[i] += sum[i + 1];
        Fol(i, n, 1) if(sum[i] > sum[ans]) ans = i;
        printf("%d\n", sum[ans] ? ans : -1);
        For(i, 0, n) tot[i] = 0;
        For(i, 0, cnt) siz[i] = sum[i] = 0, memset(go[i], 0, sizeof(go[i])); 
    }
    return 0;
}