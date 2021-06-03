
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

typedef long long ll;
typedef pair<int, int> pii;


template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}


const int maxn=2e5+10;
int n,m,r,mod;
int tot,head[maxn],w[maxn],wt[maxn];
int res=0;

struct Edge{
    int to,next;
}e[maxn<<1];
namespace SEG{
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)
    inline void add(int x,int y){//链式前向星加边
        e[++tot].to=y;
        e[tot].next=head[x];
        head[x]=tot;
    }
    inline void pushup(int rt){a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;}
    inline void pushdown(int rt,int lenn){

        int a[maxn<<2],laz[maxn<<2];
        int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn];     laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
        a[rt<<1]+=laz[rt]*(lenn-(lenn>>1)),a[rt<<1|1]+=laz[rt]*(lenn>>1);
        a[rt<<1]%=mod,a[rt<<1|1]%=mod;
        laz[rt]=0;
    }
    inline void build(int rt,int l,int r){
        if(l==r){
            a[rt]=wt[l];
            if(a[rt]>mod)a[rt]%=mod;
            return;
        }
        build(lson),build(rson);
        pushup(rt);
    }

    inline void query(int rt,int l,int r,int x,int y){
        if(x<=l&&r<=y){res+=a[rt];res%=mod;return;}
        else{
            if(laz[rt])pushdown(rt,len);
            if(x<=mid)query(lson,x,y);
            if(y>mid)query(rson,x,y);
        }
    }

    inline void update(int rt,int l,int r,int L,int R,int k){
        if(L<=l&&r<=R){ laz[rt]+=k;a[rt]+=k*len;}
        else{
            if(laz[rt])pushdown(rt,len);
            if(L<=mid)update(lson,L,R,k);
            if(R>mid)update(rson,L,R,k);
            a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
        }
    }
}
using namespace SEG;
namespace TREE_CHAIN{
    inline int query_path(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            res=0;
            query(1,1,n,id[top[x]],id[x]);
            ans+=res;
            ans%=mod;
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        res=0;
        query(1,1,n,id[x],id[y]);
        ans+=res;
        return ans%mod;
    }

    inline void update_path(int x,int y,int k){
        k%=mod;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            update(1,1,n,id[top[x]],id[x],k);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        update(1,1,n,id[x],id[y],k);
    }

    inline int query_son(int x){res=0;query(1,1,n,id[x],id[x]+siz[x]-1);return res;}
    inline void update_Son(int x,int k){update(1,1,n,id[x],id[x]+siz[x]-1,k);}
    inline void dfs1(int x,int f,int deep){
        dep[x]=deep;
        fa[x]=f;
        siz[x]=1;
        int maxson=-1;
        for(Rint i=head[x];i;i=e[i].next){
            int y=e[i].to;
          if(y==f)continue;
dfs1(y,x,deep+1);
siz[x]+=siz[y];
if(siz[y]>maxson)son[x]=y,maxson=siz[y];
}
}

inline void dfs2(int x,int tp){
    id[x]=++cnt;
    wt[cnt]=w[x];
    top[x]=tp;
    if(!son[x])return;
    dfs2(son[x],tp);
    for(Rint i=head[x];i;i=e[i].next){
        int y=e[i].to;
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}
}
using namespace TREE_CHAIN;

signed main(){
    read(n);read(m);read(r);read(mod);
    for(Rint i=1;i<=n;i++)read(w[i]);
    for(Rint i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(r,0,1),dfs2(r,r);
    build(1,1,n);
    while(m--){
        int k,x,y,z;
        read(k);
        if(k==1){read(x);read(y);read(z);update_path(x,y,z);}
        else if(k==2){read(x);read(y);printf("%d\n",query_path(x,y));}
        else if(k==3){read(x);read(y);update_Son(x,y);}
        else{read(x);printf("%d\n",query_son(x));}
    }
}
