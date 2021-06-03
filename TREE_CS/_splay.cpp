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
const int N = 100005;
int rt, tot, fa[N], ch[N][2], val[N], cnt[N], sz[N];
struct Splay {
  void maintain(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }  /*更新sz操作*/
  bool get(int x) { return x == ch[fa[x]][1]; }/*判断左右儿子，左儿子返回0，右儿子返回1*/
  void clear(int x) {
    ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;  /*消除该节点操作*/
  }
  void rotate(int x) {     /*旋转操作，根据x的儿子属性来判断旋转的方向*/
    int y = fa[x], z = fa[y], chk = get(x); /*x的父亲y必定在旋转后成为x的另一个儿子节点，原先x的某一个子节点必定成为y的代替x的节点）*/
    ch[y][chk] = ch[x][chk ^ 1];
    fa[ch[x][chk ^ 1]] = y;
    ch[x][chk ^ 1] = y;
    fa[y] = x;
    fa[x] = z;
    if (z) ch[z][y == ch[z][1]] = x;  /*存在z的话，将x节点置于与原先y节点一样的位置*/
    maintain(x);/*合并操作*/
    maintain(y);
  }
  void splay(int x) {
    /*判断是否存在z节点，若存在，则分为两种情况，第一种若x，y在同一性质，那么先将y左旋或右旋，再将x右旋或左旋，否则直接将x rotate()两次*/
    for (int f = fa[x]; f = fa[x], f; rotate(x))  
      if (fa[f]) rotate(get(x) == get(f) ? f : x);
    rt = x;
  }
  /*插入操作，如果树为空，那么增加这个节点*/
  void ins(int k) {
    if (!rt) {
      val[++tot] = k;
      cnt[tot]++;
      rt = tot;
      maintain(rt);
      return;
    }
    /*如果存在一个节点的值等于k，直接个数++，并且进行旋转操作*/
    int cnr = rt, f = 0;
    while (1) {
      if (val[cnr] == k) {
        cnt[cnr]++;
        maintain(cnr);
        maintain(f);
        splay(cnr);
        break;
      }
      /*一直找下去，很好理解，如果val[cnr]<k,就找有子树，反之亦然*/
      f = cnr;
      cnr = ch[cnr][val[cnr] < k];
      /*一直找下去，到最后如果没找到（子树为空），那么就也直接新增一个节点，并在f的子节点中选择一个节点存放该位置*/
      /*如果val[f]<k，那么就在f的右儿子位置放置该节点，反之就在左儿子防止该节点，使splay始终保持平衡*/
      if (!cnr) {
        val[++tot] = k;
        cnt[tot]++;
        fa[tot] = f;
        ch[f][val[f] < k] = tot;
        maintain(tot);
        maintain(f);
        splay(tot);
        break;
      }
    }
  }
  /*如果目前节点的值小=大于k，那么就找当前节点的左儿子，如果比当前节点的sz大，那么直接加上左子树的sz加上当前节点cnt的大小，并且继续找下右子树找下去*/
  /*如果找到了k在当前基础上加上1，进行splay操作*/
  int rk(int k) {
    int res = 0, cnr = rt;
    while (1) {
      if (k < val[cnr]) {
        cnr = ch[cnr][0];
      } else {
        res += sz[ch[cnr][0]];
        if (k == val[cnr]) {
          splay(cnr);
          return res + 1;
        }
        res += cnt[cnr];
        cnr = ch[cnr][1];
      }
    }
  }
  /*查询排名为x的数*/
  int kth(int k) {
    int cnr = rt;
    while (1) {
    	/*如果左子树非空，并且左子数sz大于k，那么就在左子树中找下去*/
      if (ch[cnr][0] && k <= sz[ch[cnr][0]]) {
        cnr = ch[cnr][0];
        /*否则就减去左子树的sz和根的sz，如果减去后k<=0,那么很明显k就是当前节点cnt中的一个，否则继续找他的右子树*/
      } else {
        k -= cnt[cnr] + sz[ch[cnr][0]];
        if (k <= 0) {
          splay(cnr);
          return val[cnr];
        }
        cnr = ch[cnr][1];
      }
    }
  }
  /*可以等价于将x插入节点左子树最右的那个*/
  int pre() {
    int cnr = ch[rt][0];
    while (ch[cnr][1]) cnr = ch[cnr][1];/*一直找左子树的最右位置*/
    splay(cnr);
    return cnr;
  }
  /*类似找右子树的最左位置*/
  int nxt() {
    int cnr = ch[rt][1];
    while (ch[cnr][0]) cnr = ch[cnr][0];
    splay(cnr);
    return cnr;
  }
  void del(int k) {
    rk(k);
    /*如果cnt大于1的话，就直接--，更新sz*/
    if (cnt[rt] > 1) {
      cnt[rt]--;
      maintain(rt);
      return;
      /*没有儿子节点就直接clear()*/
    }
    if (!ch[rt][0] && !ch[rt][1]) {
      clear(rt);
      rt = 0;
      return;
    }
    /*如果只有一个儿子，那么就将当前节点clear()并且将唯一的儿子节点作为根节点*/
    if (!ch[rt][0]) {
      int cnr = rt;
      rt = ch[rt][1];
      fa[rt] = 0;
      clear(cnr);
      return;
    }
    if (!ch[rt][1]) {
      int cnr = rt;
      rt = ch[rt][0];
      fa[rt] = 0;
      clear(cnr);
      return;
    }
    /*否则将x前驱旋转操作作为根节点，将原来x的右儿子连接到目前的根节点上去*/
    int cnr = rt;
    int x = pre();  //前驱节点
    splay(x);
    fa[ch[cnr][1]] = x;
    ch[x][1] = ch[cnr][1];
    clear(cnr);
    maintain(rt);
  }
} tree;

int main() {
  int n, opt, x;
  for (scanf("%d", &n); n; --n) {
    read(opt),read(x);
    if (opt == 1)
      tree.ins(x);
    else if (opt == 2)
      tree.del(x);
    else if (opt == 3)
      printf("%d\n", tree.rk(x));
    else if (opt == 4)
      printf("%d\n", tree.kth(x));
    else if (opt == 5)
      tree.ins(x), printf("%d\n", val[tree.pre()]), tree.del(x);
    else
      tree.ins(x), printf("%d\n", val[tree.nxt()]), tree.del(x);
  }
  return 0;
}