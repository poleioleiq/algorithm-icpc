#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n,sz[1000005],deep[1000005],bc[1000005],mx=0,ans[1000005];
vector<int> vec[1000005];
map<int,int>mp;

void dfs1(int u,int fa)
{
    sz[u]=1;
    deep[u]=deep[fa]+1;
    int bctmp=0;
    for (int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];
        if (v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if (!bctmp||sz[bctmp]<sz[v]) bctmp=v;
    }
    bc[u]=bctmp;
}

void add(int fa,int u)
{
    //cout<<"!u="<<u<<endl;
    mp[deep[u]]++;
    //cout<<"!u="<<u<<" mpdepu="<<mp[deep[u]]<<" mpmx="<<mp[mx]<<endl;
    if (mp[deep[u]]>mp[mx] || mp[deep[u]]==mp[mx] && deep[u]<mx)
    {
        mx=deep[u];
    }
    for (int i=1; i<=vec[u].size(); i++)
    {
        int v=vec[u][i];
        if (v==fa) continue;
        add(u,v);
    }
    //cout<<"!mx="<<mx<<endl;
}

void dfs2(int u,int fa)
{
    for (int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];
        if (fa==v) continue;
        if (v==bc[u]) continue;
        dfs2(v,u);
        mp.clear();
        mx=0;
    }
    if (bc[u]) dfs2(bc[u],u);
    for (int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];
        if (fa==v) continue;
        if (v==bc[u]) continue;
        add(u,v);
    }
    mp[deep[u]]++;
    //cout<<"u="<<u<<" mpdepu="<<mp[deep[u]]<<" mpmx="<<mp[mx]<<endl;
    if (mp[deep[u]]>mp[mx] || mp[deep[u]]==mp[mx] && deep[u]<mx)
    {
        mx=deep[u];
    }
    //cout<<"u="<<u<<" mx="<<mx<<endl;
    ans[u]=mx-deep[u];
    //cout<<"ans="<<ans[u]<<endl;
}

int main()
{
    scanf("%d",&n);
    for (int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i=1; i<=n; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}