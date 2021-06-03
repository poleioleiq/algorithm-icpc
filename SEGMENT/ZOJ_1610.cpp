#include<bits/stdc++.h>
#define lson root<<1
#define rson root<<1|1
#define MID int mid = (l + r) / 2;
#define rls 1,1,8010
#define N 8010
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define sca(a) scanf("%d",&a);
#define sca2(a, b) scanf("%d%d",&a,&b)
#define sca3(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define scac(a) scanf("%c",a);
#define scacc(a, b) scanf("%c%c",a,b)
#define mem(a, b) memset(a,b,sizeof(a))
#define Rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;


template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int a[N * 4], color[N], vis[N];
void pushdown(int root, int l, int r)//向下更新
{
    if(a[root] != -1)//有颜色
    {
        a[lson] = a[rson] = a[root];//向下更新颜色
        a[root] = -1;
    }
}
void updata(int root, int l, int r, int ul, int ur, int v)
{
    if(ul <= l && r <= ur)
    {
        a[root] = v;
        return ;
    }
    pushdown(root, l, r);
    MID;
    if(ul <= mid) updata(lson, l, mid, ul, ur, v);
    if(ur > mid) updata(rson, mid + 1, r, ul, ur, v);
}
void dfs(int root, int l, int r)//将颜色向下更新。
{
    if(l == r)
    {
        color[l] = a[root];//color存最后1-N的颜色
        return;
    }
    pushdown(root, l, r);
    MID;
    dfs(lson, l, mid);
    dfs(rson, mid + 1, r);
}
int main()
{
    int n, i, ul, ur, v;
    while(~scanf("%d", &n))
    {
        memset(a, -1, sizeof(a));//初始化-1，因为颜色是0开始
        memset(color, -1, sizeof(color));//用来存最后1-N的颜色
        memset(vis, 0, sizeof(vis));//后面记录颜色出现的条数
        for(i = 0; i < n; i++)
        {
            read(ul),read(ur),read(v);
            ul++;//细节
            updata(rls, ul, ur, v);//区间更新ul-ur的颜色为v
        }
        dfs(rls);//将所有颜色pushdown到最底层。也就是1-N
        for(i = 1; i <= N; i++)
        {
            if(color[i] != color[i - 1] && color[i] != -1)//颜色不一样同时有颜色。条数++
            {
                vis[color[i]]++;
            }
        }
        for(i = 0; i <= N; i++)//输出就好了
        {
            if(vis[i])
            {
                printf("%d %d\n", i, vis[i]);
            }
        }
        printf("\n");
    }
    return 0;
}