#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findparent(int node)
    {
        if(parent[node]==node)
        return node;

        return parent[node]=findparent(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv)
        return;

        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pu]++;
        }
    }
};

void bfs(int r,int c,vector<vector<int>>arr)
{
    int n=arr.size();
    vector<vector<int>>vis(n,vector<int>(n,0));
    queue<pair<int,int>>que;
    que.push({r,c});
    vis[r][c]=1;
    int rarr[4]={-1,0,1,0};
    int carr[4]={0,1,0,-1};

    while (que.size())
    {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();

        for(int i=0;i<4;i++)
        {
            int nr=row+rarr[i];
            int nc=col+carr[i];

            if(nr>=0 and nr<n and nc>0 and nc<n and vis[nr][nc]==0)
            {
                vis[nr][nc]=1;
                que.push({nr,nc});
            }
        }
    }
    
}

int main()
{
    DisjointSet a(4);
}