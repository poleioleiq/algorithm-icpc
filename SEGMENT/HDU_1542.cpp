#include<bits/stdc++.h>
 
using namespace std;
const double eps = 1e-8;
const int MAX = 100 + 5;
double pre[MAX << 2];
//空间需要开8倍。。
int n;
struct Node {
    double l,r,h;
    int f;
    Node(){}
    Node(double l,double r,double h,int f):l(l),r(r),h(h),f(f){}
     
} seg[16*MAX];
struct TREE {
    int l,r;
    double val;
    int f;
} tree[16*MAX];
bool cmp(const Node & a,const Node & b) {
    return a.h < b.h;
}
void pushup(int cur) {
    if(tree[cur].f >0) tree[cur].val = pre[tree[cur].r+1] - pre[tree[cur].l];
    else {
        if(tree[cur].l == tree[cur].r) tree[cur].val = 0;
        else tree[cur].val=tree[2*cur].val+tree[2*cur+1].val;
    }
} 
void build(int l,int r,int cur) {
    tree[cur].l = l;
    tree[cur].r = r;
    tree[cur].val = 0;
    tree[cur].f = 0;
    if(l == r) return ;
    int m = (l + r)/2;
    build(l,m,2*cur);
    build(m+1,r,2*cur+1);
}
void scan(int pl,int pr,int f,int cur) {
    if(pl <= tree[cur].l && pr>=tree[cur].r) {
        tree[cur].f+=f;
        pushup(cur);
        return;
    }
    if(pl<=tree[2*cur].r) scan(pl,pr,f,2*cur);
    if(pr>=tree[2*cur+1].l) scan(pl,pr,f,2*cur+1);
    pushup(cur);
}
int main()
{
    int iCase = 0;
    double x1,x2,y1,y2,ans;
    while(~scanf("%d",&n) ) {
        if(n == 0) break;
        //离散化
        int top = 0;
        for(int i = 1; i<=n; i++) {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            seg[++top] = Node(x1,x2,y1,1);
            pre[top] = x1;
            seg[++top] = Node(x1,x2,y2,-1);
            pre[top] = x2;
        }
        sort(pre+1,pre+2*n+1);
        int x = unique(pre+1,pre+2*n+1) - pre-1;
//      for(int i = 1; i<=x; i++) printf("%f ",pre[i]);
//      printf("\n");
        build(1,x,1);
        sort(seg+1,seg+2*n+1,cmp);
        ans = 0;
        for(int i = 1; i<2*n; i++) {
            //左闭右开区间
            int ll = lower_bound(pre+1,pre+x+1,seg[i].l) - (pre+1);
            int rr = lower_bound(pre+1,pre+x+1,seg[i].r) - pre-2;
            ll++,rr++;
        //  printf("ll = %d rr = %d\n",ll,rr);
            scan(ll,rr,seg[i].f,1);
            ans += (seg[i+1].h - seg[i].h) * tree[1].val;
        //  printf("ans = %lf  h2=%f h1=%f val = %f\n",ans,seg[i+1].h,seg[i].h,tree[1].val);
             
        }
        printf("Test case #%d\n",++iCase);
        printf("Total explored area: %.2f\n\n",ans);
         
    }
     
    return 0 ;
}