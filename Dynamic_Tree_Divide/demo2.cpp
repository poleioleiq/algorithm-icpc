/** 
 * ALGORIHTM_DEMO2_CPP
 * @author : MWT 
 * @date : 20:03 2020/5/22 
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
#define mem(a, b) memset(a,b,sizeof(a))
#define int long long
#define ri register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

template <typename T>inline void read(T& t)
{
    ri c=getchar();t=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void read(T& t, Args&... args)
{
    read(t);read(args...);
}
const int maxn=1e5+5;
int f[maxn];

inline void access(int x){for(int y=0;x;y=x,x=f[x]) splay(x),c[x][1]=y,pushr(x);}