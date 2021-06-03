#include <bits/stdc++.h>
#define lson l, mid, id<<1
#define rson mid+1, r, id<<1|1

using namespace std;
typedef long long ll;
const int maxn = 10005;

int cov[maxn<<2];  //区间覆盖次数
int sum[maxn<<2];  //覆盖一次的总长度
int sum2[maxn<<2]; //覆盖两次的总长度
int sum3[maxn<<2]; //覆盖大于等于三次的总长度
int x[maxn];
int z[maxn<<1];

struct seg {
    int l, r, y; int p;
    seg() {}
    seg(int l, int r, int y, int p): l(l), r(r), y(y), p(p) {}
}node[maxn<<2], tmp[maxn<<2];


struct cube
{
    int x1, y1, x2, y2, z1, z2;
    cube() {}
    cube(int x1, int y1, int x2, int y2, int z1, int z2): x1(x1), y1(y1), x2(x2), y2(y2), z1(z1), z2(z2) {}
}cubes[maxn<<1];

bool cmp(seg a, seg b){
    return a.y<b.y;
}

//如果>=3，说明已经被覆盖了三次
//如果==2，说明被覆盖了两次
//如果==1，说明这个位置已经被覆盖了一次，那就从子节点传上来（子节点如果已被覆盖一次，加起来就是两次）
//如果==0，这个地方没有被覆盖，那么我们只有从子节点将覆盖的结果传上来。
void pushUp(int l, int r, int id){
    if(cov[id]) sum[id] = x[r+1]-x[l];
    else if(l==r) sum[id] = 0;
    else sum[id] = sum[id<<1] + sum[id<<1|1];

    //更新sum2
    if(cov[id]>=2) sum2[id] = x[r+1]-x[l];
    else if(l==r) sum2[id] = 0;
    else if(cov[id]==1) sum2[id] = sum[id<<1]+sum[id<<1|1];
    else if(cov[id]==0) sum2[id] = sum2[id<<1]+sum2[id<<1|1];

    //更新sum3
    if(cov[id]>=3) sum3[id] = x[r+1]-x[l];
    else if(l==r) sum3[id] = 0;
    else if(cov[id]==2) sum3[id] = sum[id<<1]+sum[id<<1|1];
    else if(cov[id]==1) sum3[id] = sum2[id<<1]+sum2[id<<1|1];
    else if(cov[id]==0) sum3[id] = sum3[id<<1]+sum3[id<<1|1];
}

void update(int L, int R, int v, int l, int r, int id){
    if(L<=l && r<=R){
        cov[id] += v;
        pushUp(l, r, id);
        return;
    }
    int mid = (l+r)>>1;
    if(L<=mid) update(L, R, v, lson);
    if(R> mid) update(L, R, v, rson);
    pushUp(l, r, id);
}


int main(int argc, char const *argv[])
{
    int n;
    int ka = 1;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int x1, x2, y1, y2, z1, z2;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
            node[i] = seg(x1, x2, y1, 1);
            node[i+n]  = seg(x1, x2, y2, -1);
            cubes[i] = cube(x1, y1, x2, y2, z1, z2);
            x[i] = x1;
            x[i+n] = x2;
            z[i] = z1;
            z[i+n] = z2;
        }
        n = n<<1;
        //sort(node+1, node+n+1, cmp);
        sort(x+1, x+n+1);
        sort(z+1, z+n+1);
        int m1 = unique(x+1, x+n+1) - x - 1;
        int m2 = unique(z+1, z+n+1) - z - 1;
        n = n>>1;
        for(int i = 1; i < m2; i++){
            ll res = 0;
            int cnt = 0;
            memset(cov, 0, sizeof(cov));
            memset(sum, 0, sizeof(sum));
            memset(sum2, 0, sizeof(sum2));
            memset(sum3, 0, sizeof(sum3));
            for(int j = 1; j <= n; j++){
                if(cubes[j].z1<=z[i] && cubes[j].z2>z[i]){
                    tmp[cnt++] = node[j];
                    tmp[cnt++] = node[j+n];
                }
            }
            sort(tmp, tmp+cnt, cmp);
            for(int j = 0; j < cnt-1; j++){
                int l = lower_bound(x+1, x+m1+1, tmp[j].l) - x;
                int r = lower_bound(x+1, x+m1+1, tmp[j].r) - x;
                //cout << l << " " << r-1 << endl;
                if(l<r) update(l, r-1, tmp[j].p, 1, m1, 1);
                
                res += (ll)sum3[1]*(tmp[j+1].y-tmp[j].y);
            }
            ans += res*(z[i+1]-z[i]);
        }
        printf("Case %d: %lld\n", ka++, ans);
    }
    return 0;
}