#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isOverlap(pair<int,int> p1, pair<int,int> p2){
    if(p1.first > p2.second || p2.first > p1.second){
        return false;
    }
    return true;
}
void TCSOLVE(){
    ll n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i =0 ;i<n;i++){
        ll x,y;
        cin >> x>> y;
        v.push_back({x,y});
    }

    vector<int> vis(n,0);
    vector<pair<int,int>> ans;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            vis[i] = 1;
        }
        else{
            continue;
        }
        
        while(1){
            int flag = 0;
            for(int j =0 ;j<n;j++){
                if(!vis[j] && isOverlap(v[i],v[j])){
                    vis[j] = 1;
                    v[i].first = min(v[i].first,v[j].first);
                    v[i].second = max(v[i].second,v[j].second);
                    flag = 1;
                }
            }

            if(flag == 0){
                break;
            }
        }
        ans.push_back(v[i]);
    }
    sort(ans.begin(),ans.end());

    for(auto x: ans){
        cout << x.first << " " << x.second << endl;
    }
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
