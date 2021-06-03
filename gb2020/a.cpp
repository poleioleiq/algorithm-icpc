/** 
 * ALGORIHTM_A_CPP
 * @author : MWT 
 * @date : 22:33 2020/12/30 
 *
 */
//#pragma GCC optimize(2)
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
#include <map>

#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define mem(a, b) memset(a,b,sizeof(a))
using namespace std;

int t,a,b,d,e;
const int maxn=1e3;
int aa[maxn];
int bb[maxn];

int main(){

    cin>>a;

    while(a--){
        int cc=0;
        mem(aa,0);
        mem(bb,0);
        cin>>b;
        for(int i=0;i<b;i++){
            cin>>d;
            aa[i]=d;
        }
//        for(int i=0;i<b;i++)cout<<aa[i]<<endl;

        for(int  i=0;i<b-1;i++){
            bb[aa[i+1]-aa[i]]+=1;
        }
//        for(int i=0;i<maxn;i++)cout<<bb[i]<<endl;
        for(int i=1;i<maxn;i++){
            if(bb[i]!=0)cc+=1;
        }
//        cout<<b;

//       cout<<cc<<endl;
        if(bb[0]!=0&&cc==0) cout<<'0'<<endl;
        if(bb[0]!=0)b-=bb[0];
        else        cout<<(b-1)+((cc-1)*cc)/2<<endl;
//        cout<<endl;




    }

}