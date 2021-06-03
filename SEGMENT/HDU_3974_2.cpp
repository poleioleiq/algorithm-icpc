#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
#define ll long long
using namespace std;
const int mod=10007;
const int M=100010;
struct node
{
    int l,r;
    int a,b,c;//a是乘数，b是加数，c是替换的数
    int sum[3];//分别记录1次，2次，3次和
}t[M<<2];
void pushup(int p)
{
    int i;
    for (i = 0; i < 3; i++)
        t[p].sum[i] = (t[ls].sum[i] + t[rs].sum[i]) % mod;//每个和都等于左子树加右子树
}
void pushdown(int p)
{
    if (t[p].l == t[p].r)//到了节点返回
        return;
    int a = t[p].a, b = t[p].b, c = t[p].c;
    if (c)//替换
    {
        t[ls].a = t[rs].a = a;//之前以为这个可以直接改成1，但是同一个root不一定全部都改变值
        t[ls].b = t[rs].b = b;
        t[ls].c = t[rs].c = c;
        t[ls].sum[2] = (t[ls].r - t[ls].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[ls].sum[1] = (t[ls].r - t[ls].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[ls].sum[0] = (t[ls].r - t[ls].l + 1) * (a * c % mod + b) % mod;
        t[rs].sum[2] = (t[rs].r - t[rs].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[rs].sum[1] = (t[rs].r - t[rs].l + 1) * (a * c % mod + b) % mod * (a * c % mod + b) % mod;
        t[rs].sum[0] = (t[rs].r - t[rs].l + 1) * (a * c % mod + b) % mod;
    }
    else
    {
        t[ls].a = (t[ls].a * a) % mod;
        t[ls].b = (t[ls].b * a + b) % mod;
        t[rs].a = (t[rs].a * a) % mod;
        t[rs].b = (t[rs].b * a + b) % mod;
        t[ls].sum[2] = (a * a % mod * a % mod * t[ls].sum[2] % mod + 3 * a % mod * a % mod * b % mod * t[ls].sum[1] % mod + 3 * a % mod * b % mod * b % mod * t[ls].sum[0] % mod + b * b % mod * b % mod * (t[ls].r - t[ls].l + 1) % mod) % mod;
        t[ls].sum[1] = (a * a % mod * t[ls].sum[1] % mod + b * b % mod * (t[ls].r - t[ls].l + 1) % mod + 2 * a * b % mod * t[ls].sum[0] % mod) % mod;
        t[ls].sum[0] = (a * t[ls].sum[0] % mod + b * (t[ls].r - t[ls].l + 1) % mod) % mod;
        t[rs].sum[2] = (a * a % mod * a % mod * t[rs].sum[2] % mod + 3 * a % mod * a % mod * b % mod * t[rs].sum[1] % mod + 3 * a % mod * b % mod * b % mod * t[rs].sum[0] % mod + b * b % mod * b % mod * (t[rs].r - t[rs].l + 1) % mod) % mod;
        t[rs].sum[1] = (a * a % mod * t[rs].sum[1] % mod + b * b % mod * (t[rs].r - t[rs].l + 1) % mod + 2 * a * b % mod * t[rs].sum[0] % mod) % mod;
        t[rs].sum[0] = (a * t[rs].sum[0] % mod + b * (t[rs].r - t[rs].l + 1) % mod) % mod;
    }
    t[p].b = t[p].c = 0;
    t[p].a = 1;
}
void build(int p,int l,int r)
{
    t[p].l = l, t[p].r = r;
    t[p].a = 1, t[p].b = t[p].c = 0;
    t[p].sum[0] = t[p].sum[1] = t[p].sum[2] = 0;
    if(l==r)
    {
        return ;
    }
    int mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void update(int p,int l,int r,int x,int y,int val,int flag)
{
    if(x<=l&&r<=y)//找到更新区间
    {
        if (flag == 0)//加val
        {
            t[p].b = (t[p].b + val) % mod;//加数改变
            t[p].sum[2] = (t[p].sum[2] + 3 * val % mod * t[p].sum[1] % mod + 3 * val % mod * val % mod * t[p].sum[0] % mod + val * val % mod * val % mod * (t[p].r - t[p].l + 1) % mod) % mod;
            t[p].sum[1] = (t[p].sum[1] + val * val % mod * (t[p].r - t[p].l + 1) % mod + 2 * val * t[p].sum[0] % mod) % mod;
            t[p].sum[0] = (t[p].sum[0] + val * (t[p].r - t[p].l + 1)) % mod;
        }
        else if (flag == 1)
        {
            t[p].a = (t[p].a * val) % mod;//乘数改变
            t[p].b = (t[p].b * val) % mod;//加数也改变
            t[p].sum[2] = val * val % mod * val % mod * t[p].sum[2] % mod;
            t[p].sum[1] = val * val % mod * t[p].sum[1] % mod;
            t[p].sum[0] = val * t[p].sum[0] % mod;
        }
        else if (flag == 2)
        {
            t[p].a = 1;//乘数变为1
            t[p].b = 0;//加数变成0
            t[p].c = val;
            t[p].sum[2] = (t[p].r - t[p].l + 1) % mod * val % mod * val % mod * val % mod;
            t[p].sum[1] = (t[p].r - t[p].l + 1) % mod * val % mod * val % mod;
            t[p].sum[0] = (t[p].r - t[p].l + 1) * val % mod;
        }
        return;
    }
    pushdown(p);//向下更新
    int mid=l+r>>1;
    if(x<=mid)
    {
        update(ls,l,mid,x,y,val,flag);
    }
    if(y>mid)
    {
        update(rs,mid+1,r,x,y,val,flag);
    }
    pushup(p);//求和向上更新
}
ll query(int p,int l,int r,int x,int y,int flag)
{
    if(x<=l&&r<=y)//找到区间
    {
        return t[p].sum[flag];
    }
    pushdown(p);//向下更新
    int mid=l+r>>1;
    int ans=0;
    if(x<=mid)
    {
        ans+=query(ls,l,mid,x,y,flag);
    }
    if(y>mid)
    {
        ans+=query(rs,mid+1,r,x,y,flag);
    }
    return ans%mod;
}
int main( )
{
    int n,q,x,y,w,c;
    while(~scanf("%d%d",&n,&q)&&(n+q))
    {
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d%d%d",&c,&x,&y,&w);
            if(c==1)
            {
                update(1,1,n,x,y,w,0);

            }
            else if(c==2)
            {
                update(1,1,n,x,y,w,1);

            }
            else if(c==3)
            {
                update(1,1,n,x,y,w,2);

            }
            else
            {
                cout<<query(1,1,n,x,y,w-1)<<endl;
            }

        }
    }
    return 0;
}