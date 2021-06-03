#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int N = 50005;
struct employee{
    int task, t;
} e[N];
int par[N];
 
int main()
{
    int cas, a, b, n, m;
    char op[5];
    read(cas);
    for(int k = 1; k <= cas; ++k)
    {
        printf("Case #%d:\n", k);
        memset(par, -1, sizeof(par));
        read(n);
        for(int i = 1; i < n; ++i)
        {
            e[i].t = e[i].task = 0;
            read(a),read(b), par[a] = b;
        }
        e[n].t = e[n].task = 0;
 
        read(m);
        int t = 0, last, ans;
        while(m--)
        {
            scanf("%s",op),read(a);
            if(op[0] == 'C')
            {
                last = 0;//所有祖先节点最晚任务的时间
                while(a != -1)
                {
                    if(e[a].t > last)
                        last = e[a].t, ans = e[a].task;
                    a = par[a];
                }
                printf("%d\n", last ? ans : -1);
            }
            else
            {
                read(b);
                e[a].task = b, e[a].t = ++t;
            }
        }
    }
    return 0;
}