#include<bits/stdc++.h>
using namespace std;
#define yes "YES"
#define no "NO"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
void removeNode(vector<vector<int>>& adjList, int node) {
    adjList[node].clear();

    for (int i = 1; i < adjList.size(); ++i) {
        auto it = find(adjList[i].begin(), adjList[i].end(), node);
        if (it != adjList[i].end()) {
            adjList[i].erase(it);
        }
    }
}
int main(){
    fast;
    int n , m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool>vis(n+1, false);
    queue<int>q;
    q.push(1);
    vis[1]=true;
    removeNode(adj , 3);
    while(!q.empty()){
         int node = q.front();
            q.pop();
            cout<< node << endl;
            vector<int> :: iterator it;
             for(it=adj[node].begin(); it!=adj[node].end();it++){
                if(!vis[*it]){
                    vis[*it]=true;
                    q.push(*it);
                }
             }
    }


}

