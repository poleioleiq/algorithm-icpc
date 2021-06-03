/** 
 * TREE_CHAIN_SPLIT_ZJOI_2008_CPP
 * @author : MaWeiTao 
 * @date : 15:15 2020/3/21 
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
#define int long long
#define Rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

using namespace std;
typedef long long LL;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

const LL maxn=60000+10,inf=0x3f3f3f3f;
LL n,m;
LL e,beg[maxn],to[maxn],nex[maxn],w[maxn],wt[maxn],ind[maxn];
LL cnt,fa[maxn],dep[maxn],top[maxn],id[maxn],son[maxn],siz[maxn],root;
LL Sum[maxn<<2],Max[maxn<<2];

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

inline void add(LL x,LL y){
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
inline void pushup(LL rt){
    LL l=(rt<<1),r=(rt<<1|1);
    Sum[rt]=Sum[l]+Sum[r];
    Max[rt]=max(Max[l],Max[r]);
}
inline void built(LL rt,LL l,LL r){
    if(l==r){Sum[rt]=(LL)wt[l];Max[rt]=(LL)wt[l];return;}

    built(lson);
    built(rson);
    pushup(rt);
}
inline void update(LL rt,LL l,LL r,LL pos,LL k){
    if(l==r){
        Sum[rt]=(LL)k;
        Max[rt]=(LL)k;
        return;
    }

    if(pos<=mid)update(lson,pos,k);
    else update(rson,pos,k);
    pushup(rt);
}
inline LL querySum(LL rt,LL l,LL r,LL L,LL R){
    LL res=0;
    if(L<=l&&r<=R)return Sum[rt];
    if(l==r)return 0LL;

    if(L<=mid)res+=querySum(lson,L,R);
    if(R>mid)res+=querySum(rson,L,R);
    return res;
}
inline LL queryMax(LL rt,LL l,LL r,LL L,LL R){
    LL res=-inf;
    if(L<=l&&r<=R)return Max[rt];
    if(l==r)return -inf;

    if(L<=mid)res=max(res,queryMax(lson,L,R));
    if(R>mid)res=max(res,queryMax(rson,L,R));
    return res;
}
inline void dfs1(LL x,LL f,LL deep){
    fa[x]=f;
    siz[x]=1;
    dep[x]=deep;
    LL maxson=-1;
    for(Rint i=beg[x];i;i=nex[i]){
        LL y=to[i];
        if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson)maxson=siz[y],son[x]=y;
    }
}
inline void dfs2(LL x,LL topf){
    id[x]=++cnt;
    wt[cnt]=w[x];
    top[x]=topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(Rint i=beg[x];i;i=nex[i]){
        LL y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}
inline void updPos(LL p,LL k){
    update(1,1,n,id[p],k);
}
inline LL qSum(LL x,LL y){
    LL res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res+=querySum(1,1,n,id[top[x]],id[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    res+=querySum(1,1,n,id[x],id[y]);
    return res;
}
inline LL qMax(LL x,LL y){
    LL res=-inf;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res=max(res,queryMax(1,1,n,id[top[x]],id[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    res=max(res,queryMax(1,1,n,id[x],id[y]));
    return res;
}

signed  main(){
    read(n);
    for(Rint i=1;i<n;i++){
        LL x,y;
        read(x);read(y);
        add(x,y);
        add(y,x);
    }
    for(Rint i=1;i<=n;i++)read(w[i]);
    root=1;
    dfs1(root,0,1);
    dfs2(root,root);
    built(1,1,n);
    read(m);
    char ch[10];
    LL x,y;
    while(m--){
        scanf("%s",ch);
        read(x);read(y);
        if(ch[0]=='C')updPos(x,y);
        else if(ch[1]=='S')printf("%lld\n",qSum(x,y));
        else printf("%lld\n",qMax(x,y));;
    }
    return 0;
}

