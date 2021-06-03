/** 
 * TREE_CHAIN_SPLIT_P3384_CPP
 * @author : MaWeiTao 
 * @date : 18:32 2020/3/14 
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
#define iint register int
#define lson(x) x << 1
#define rson(x) x << 1 | 1
#define int long long
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

template <typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int maxn=2e5+5;
int top[maxn],id[maxn],fa[maxn],dep[maxn],son[maxn],siz[maxn];
int head[maxn],cnt,ncnt,res=0,wt[maxn],w[maxn];
int a[maxn<<2],laz[maxn<<2];
int mod,n,m,r;
struct Edge{
    int next,to,w;
}e[maxn<<1];
namespace SEG{
#define mid (l+r)>>1
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)
     void add(int x,int y){
         e[++cnt].to=y,e[cnt].next=head[x];
         head[x]=cnt;
     }
     void pushup(int rt){a[rt]=(a[rt<<1]+a[rt<<1])%mod;}
     inline void pushdown(int rt,int lenn){
         laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
         a[rt<<1]=laz[rt]*(lenn-(lenn>>1)),a[rt<<1|1]=laz[rt]*(lenn>>1);
         a[rt<<1]%=mod,a[rt<<1|1]%=mod;
     }
     inline void build(int rt,int l,int r){
         if(l==r){
             a[rt]=wt[l];
             if(a[rt]>mod)a[rt]%mod;
             return ;
         }
         build(lson),build(rson);
         pushup(rt);
     }
     inline void  query(int rt,int l,int r,int x,int y){
         if(l>=x&&r<=y){res+=a[rt];res%=mod;return ;}
         else{
             if(laz[rt])pushdown(rt,len);
             if(x<=mid)query(lson,x,y);
             if (y>mid)query(rson,x,y);
         }
     }
     inline void update(int rt,int l,int r,int x,int y,int w){
         if(l>=x&&r<=y){a[rt]+=len*w;laz[rt]+=w;}
         else{
             if(laz[rt])pushdown(rt,len);
             if(x<=mid)update(lson,x,y,w);
             if(y>mid)update(rson,x,y,w);
             a[rt]=a[rt<<1]+a[rt<<1|1]%mod;
         }
     }
}
//using namespace SEG;
namespace TREE{
    inline int query_path(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            res=0;
            SEG::query(1,1,n,id[top[x]],id[x]);
            ans+=res;ans%=mod;
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        res=0;
        SEG::query(1,1,n,id[x],id[y]);
        ans+=res;
        return res;
    }
    inline void update_path(int x,int y,int w) {
        w %= mod;
        while (top[x] != top[y]){
            if (dep[top[x]] < dep[top[y]])swap(x, y);
            SEG::update(1,1,n,id[top[x]],id[x],w);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        SEG::update(1,1,n,id[x],id[y],w);
    }
    inline int query_son(int x){res=0;SEG::query(1,1,n,id[x],id[x]+siz[x]-1);return res;}
    inline void update_son(int x,int w){SEG::update(1,1,n,id[x],id[x]+siz[x]-1,w);}
    inline void dfs(int u,int f){
        siz[u]=1;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].to;
            if(v==f)continue;
            dep[v]=dep[u]+1;
            fa[v]=u;
            dfs(v,u);siz[u]+=siz[v];
            if(siz[v]>siz[son[u]])
                siz[u]=v;
        }
    }
    inline void dfs2(int u,int tp){
        id[u]=++cnt;
        wt[cnt]=w[u];
        top[u]=tp;
        if(!son[u])return ;
        dfs(son[u],tp);
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].to;
            if(v==fa[u]||v==son[u])continue;
            dfs2(v,v);
        }
    }
}
using namespace TREE;

signed main(){
    read(n),read(m),read(r),read(mod);
    for(iint i=1;i<=n;i++)read(w[i]);
    for(iint i=1;i<n;i++){
        int a,b;read(a),read(b);
        SEG::add(a,b),SEG::add(b,a);
    }
    dfs(r,0),dfs2(r,r);
    SEG::build(1,1,n);
    while(m--){
        int k,x,y,z;
        read(k);
        if(k==1){read(x),read(y),read(z);update_path(x,y,z);}
        else  if(k==2){read(x),read(y);printf("%d\n",query_path(x,y));}
        else if(k==3){read(x),read(y);update_son(x,y);}
        else{read(x);printf("%d\n",query_son(x));}
    }
    return 0;
}