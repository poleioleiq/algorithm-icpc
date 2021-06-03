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
const int MAXN=100010;
struct Node
{
    int l,r;
    int lazy,tag;
    int sum;
}segTree[MAXN*3];
void Build(int i,int l,int r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].lazy=0;
    segTree[i].tag=0;
    if(l==r)
    {
        segTree[i].sum=1;
        return;
    }
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid+1,r);
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
void update(int i,int l,int r,int v)
{
    if(segTree[i].l==l&&segTree[i].r==r)//成段更新
    {
        segTree[i].lazy=1;
        segTree[i].tag=v;
        segTree[i].sum=(r-l+1)*v;
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(segTree[i].lazy==1)
    {
        segTree[i].lazy=0;
        update(i<<1,segTree[i].l,mid,segTree[i].tag);
        update((i<<1)|1,mid+1,segTree[i].r,segTree[i].tag);
        segTree[i].tag=0;
    }
    if(r<=mid) update(i<<1,l,r,v);
    else if(l>mid)update((i<<1)|1,l,r,v);
    else
    {
        update(i<<1,l,mid,v);
        update((i<<1)|1,mid+1,r,v);
    }
    segTree[i].sum=segTree[i<<1].sum+segTree[(i<<1)|1].sum;
}
int main()
{
      //  freopen("in.txt","r",stdin);
 //  freopen("out.txt","w",stdout);
    int x,y,z;
    int n;
    int m;
    int T;
    read(T);
    int iCase=0;
    while(T--)
    {
        iCase++;
        read(n),read(m);
        Build(1,1,n);
        while(m--)
        {
            read(x),read(y),read(z);
            update(1,x,y,z);
        }
        printf("Case %d: The total value of the hook is %d.\n",iCase,segTree[1].sum);
    }
    return 0;
}