/** 
 * TREE_CHAIN_SPLIT_HAOI2015_CPP
 * @author : MaWeiTao 
 * @date : 21:30 2020/3/14 
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
#define Rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long LL;
typedef pair<int, int> pii;

template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

const int maxn=1e5+10,maxm=2e5+10;
int n,m;
int tot,head[maxn];
LL w[maxn],wt[maxn];
LL a[maxn<<2],laz[maxn<<2];
int top[maxn],son[maxn],siz[maxn],id[maxn],dep[maxn],fa[maxn],cnt;
LL res=0;
struct Edge{
    int to,next;
}e[maxn<<1];
namespace SEG{
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)
    inline void pushup(int rt){
        a[rt]=a[rt<<1]+a[rt<<1|1];
    }
    inline void pushdown(int rt,int lenn){
        int L=(rt<<1),R=(rt<<1|1);
        LL k=laz[rt];
        a[L]+=k*(LL)(lenn-(lenn>>1)),a[R]+=k*(LL)(lenn>>1);
        laz[L]+=k,laz[R]+=k;
        laz[rt]=0;
    }
    inline void build(int rt,int l,int r){
        if(l==r){a[rt]=wt[l];return;}
        build(lson),build(rson);
        pushup(rt);
    }
    inline void query(int rt,int l,int r,int x,int y){
        if(x<=l&&r<=y){res+=a[rt];return;}
        if(laz[rt])pushdown(rt,len);
        if(x<=mid)query(lson,x,y);
        if(y>mid)query(rson,x,y);
    }
    inline void update(int rt,int l,int r,int x,int y,LL k){
        if(x<=l&&r<=y){a[rt]+=k*(LL)len;laz[rt]+=k;return;}
        if(laz[rt])pushdown(rt,len);
        if(x<=mid)update(lson,x,y,k);
        if(y>mid)update(rson,x,y,k);
        a[rt]=a[rt<<1]+a[rt<<1|1];
    }
}
using namespace SEG;
namespace TREE_CHAIN{
    inline void add(int x,int y){
        e[++tot].to=y;
        e[tot].next=head[x];
        head[x]=tot;
    }
    inline void dfs1(int x,int f,int deep){
        fa[x]=f;
        dep[x]=deep;
        siz[x]=1;
        LL maxson=-1;
        for(Rint i=head[x];i;i=e[i].next){
            int y=e[i].to;
            if(y==f)continue;
            dfs1(y,x,deep+1);
            siz[x]+=siz[y];
            if(siz[y]>maxson)son[x]=y,maxson=siz[y];
        }
    }
    inline void dfs2(int x,int tp){
        top[x]=tp;
        id[x]=++cnt;
        wt[cnt]=w[x];
        if(son[x])dfs2(son[x],tp);
        for(Rint i=head[x];i;i=e[i].next){
            int y=e[i].to;
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);
        }
    }
    inline LL query_path(int x,int y){
        LL ans=0LL;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            res=0;
            query(1,1,n,id[top[x]],id[x]);
            ans+=res;
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        res=0;
        query(1,1,n,id[x],id[y]);
        ans+=res;
        return ans;
    }
}
using namespace TREE_CHAIN;

signed main(){
    read(n);read(m);
    for(Rint i=1;i<=n;i++)read(w[i]);
    for(Rint i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(1,0,1),dfs2(1,1);
    build(1,1,n);
    while(m--){
        int opt;read(opt);
        if(opt==1){
            int x;LL k;
            read(x);read(k);
            update(1,1,n,id[x],id[x],k);
        }
        else if(opt==2){
            int x;LL k;
            read(x);read(k);
            update(1,1,n,id[x],id[x]+siz[x]-1,k);
        }
        else{
            int x;read(x);
            printf("%lld\n",query_path(1,x));
        }
    }
}