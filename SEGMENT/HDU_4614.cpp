	#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x7f7f7f7f
#define N 100050
int n,m;
template<typename T>void read(T&x)
{
    ll k=0; char c=getchar();
    x=0;
    while(!isdigit(c)&&c!=EOF)k^=c=='-',c=getchar();
    if (c==EOF)exit(0);
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    x=k?-x:x;
}
void read_char(char &c)
{while(!isalpha(c=getchar())&&c!=EOF);}
struct Node{int l,r,lazy,sum;};
struct segmentTree
{
    Node tr[N<<2];
    void push_up(int x);
    void push_down(int x);
    void bt(int x,int l,int r);
    void update(int x,int l,int r,int tt);
    int query(int x,int l,int r);
    int ef(int k,int x,int l,int r);
}seg;
void segmentTree::push_up(int x)
{
    int len=tr[x].r-tr[x].l+1;
    if (len>1)tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
    if (tr[x].lazy!=-1)tr[x].sum=tr[x].lazy*len;
}
void segmentTree::push_down(int x)
{
    if (tr[x].lazy==-1)return;
    tr[x<<1|1].lazy=tr[x<<1].lazy=tr[x].lazy;
    push_up(x<<1);
    push_up(x<<1|1);
    tr[x].lazy=-1;
}
void segmentTree::bt(int x,int l,int r)
{
    tr[x]=Node{l,r,0,0};
    if (l==r)return;
    int mid=(l+r)>>1;
    bt(x<<1,l,mid);
    bt(x<<1|1,mid+1,r);
}
void segmentTree::update(int x,int l,int r,int tt)
{
    if (l<=tr[x].l&&tr[x].r<=r)
    {
        tr[x].lazy=tt;
        push_up(x);
        return;
    }
    int mid=(tr[x].l+tr[x].r)>>1;
    push_down(x);
    if (l<=mid)update(x<<1,l,r,tt);
    if (mid<r)update(x<<1|1,l,r,tt);
    push_up(x);
}
int segmentTree::query(int x,int l,int r)
{
    if (l<=tr[x].l&&tr[x].r<=r)return tr[x].sum;
    int mid=(tr[x].l+tr[x].r)>>1,ans=0;
    push_down(x);
    if (l<=mid)ans+=query(x<<1,l,r);
    if (mid<r)ans+=query(x<<1|1,l,r);
    return ans;
}
int segmentTree::ef(int k,int x,int l,int r)
{
    if (l==r)return l;
    int mid=(l+r)>>1;
    int tp=mid-x+1-query(1,x,mid);
    if (tp<k)return ef(k,x,mid+1,r);
    if (tp>=k)return ef(k,x,l,mid);
}
void work()
{
    read(n); read(m);
    seg.bt(1,0,n-1);
    for(int i=1;i<=m;i++)
    {
        int id,x,y;
        read(id); read(x); read(y);
        if (id==1)
        {
            int k=seg.query(1,x,n-1);
            if (k==n-x){printf("Can not put any one.\n");continue;}
            int ds=seg.ef(1,x,x,n-1);
            int dw=seg.ef(min(n-x-k,y),x,x,n-1);
            seg.update(1,ds,dw,1);
            printf("%d %d\n",ds,dw);
        }
        if (id==2)
        {
            printf("%d\n",seg.query(1,x,y));
            seg.update(1,x,y,0);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("aa.in","r",stdin);
#endif
    int T;
    read(T);
    while(T--)work(),printf("\n");
}