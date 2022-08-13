#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>ar(n+1);
    for(int i=0;i<m;i++){
        int e1,e2;
        cin>>e1>>e2;
        ar[e1].push_back(e2);
        ar[e2].push_back(e1);
    }
    vector<int>vis(n+1,-1);
    queue<int>q;
    q.push(1);
    int ans = 1;
    while(!q.empty()){
        int p = q.size();
        while(p--){
            int ft = q.front();
            q.pop();
            if(ft==n){
                vector<int>ret;
                int i = n;
                ret.push_back(n);
                while(i!=1){
                    ret.push_back(vis[i]);
                    i = vis[i];
                }
                reverse(ret.begin(),ret.end());
                cout<<ret.size()<<"\n";
                for(int l:ret)cout<<l<<" ";
                return 0;
            }
            for(int u:ar[ft]){
                if(vis[u]==-1){
                    q.push(u);
                    vis[u] = ft;
                }
            }

        }
        ans++;
    }
    cout<<"IMPOSSIBLE"<<"\n";
}