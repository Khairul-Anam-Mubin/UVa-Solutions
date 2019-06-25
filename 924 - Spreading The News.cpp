#include <bits/stdc++.h>

using namespace std;

int main(){
    int e ;
    while(scanf("%d",&e) == 1){
        vector <int> v[e];
        for(int i = 0 ; i < e ; i++){
            int n ;
            scanf("%d",&n);
            while(n--){
                int x ;
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        int tc ;
        scanf("%d",&tc);
        while(tc--){
            int source ;
            scanf("%d",&source);
            //Starting BFS and if maximum visited found then that visited level is the day
            map <int,int> vis;
            map <int,int> level;
            map <int,int> cnt;
            queue <int> q;
            vis[source] = 1;
            level[source] = 0;
            q.push(source);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(int i = 0 ; i < v[top].size() ; i++){
                    int now = v[top][i];
                    if(!vis[now]){
                        vis[now] = 1;
                        level[now] = level[top] + 1;
                        cnt[level[now]]++;
                        q.push(now);
                    }
                }
            }
            int mx = 0;
            int day = 0;
            for(int i = 0 ; i < e ; i++){
                if(cnt[i] > mx){
                    mx = cnt[i];
                    day = i;
                }
            }
            if(!mx){
                printf("%d\n",mx);
            }
            else{
                printf("%d %d\n",mx,day);
            }
        }
    }
    return 0;
}
