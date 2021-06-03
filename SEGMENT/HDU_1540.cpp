#pragma GCC optimize(2)

#include<bits/stdc++.h>
#define lc lp, s, mid
#define rc rp, mid+1, e
#define lp p<<1
#define rp p<<1|1
#define mid ((s+e)>>1)
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

using namespace std;
const int N = 50005;
int len[N * 4], lr[N * 4], ll[N * 4];
int n, m;
 
void pushup(int p, int s, int e)
{
    len[p] = max(len[lp], len[rp]);
    len[p] = max(len[p], lr[lp] + ll[rp]);
    ll[p] = ll[lp], lr[p] = lr[rp];
    if(ll[p] == mid - s + 1) ll[p] += ll[rp];
    if(lr[p] == e - mid) lr[p] += lr[lp];
}
 
void build(int p, int s, int e)
{
    if(s == e)
    {
        len[p] = ll[p] = lr[p] = 1;
        return;
    }
    build(lc);
    build(rc);
    pushup(p, s, e);
}
 
void update(int p, int s, int e, int x, int v)
{
    if(s == e && e == x)
    {
        len[p] = ll[p] = lr[p] = v;
        return;
    }
    if(x <= mid) update(lc, x, v);
    else update(rc, x, v);
    pushup(p, s, e);
}
 
int query(int p, int s, int e, int x)
{
    if(len[p] == 0 || len[p] == e - s + 1)	return len[p];
    if(x <= mid)
        return x > mid - lr[lp] ? lr[lp] + ll[rp] : query(lc, x);
    return x <= ll[rp] + mid ? ll[rp] + lr[lp] : query(rc, x);
}
 
int main()
{
    char op[10];
    int p;
    while(~scanf("%d%d", &n, &m))
    {
        stack<int> s;
        build(1, 1, n);
        while(m--)
        {
            scanf("%s", op);
            if(op[0] == 'R' && !s.empty())
            {
                p = s.top(), s.pop();
                update(1, 1, n, p, 1);
            }
            else if(op[0] == 'D')
            {
                read(p);
                update(1, 1, n, p, 0);
                s.push(p);
            }
            else
            {
                read(p);
                printf("%d\n", query(1, 1, n, p));
            }
        }
    }
    return 0;
}
