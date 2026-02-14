#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef pair<int,int> p;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    priority_queue<int, vector<int>,greater<int>> pq;

    for(auto x: v){
        pq.push(x);
    }

    int ans = 0;
    if(pq.size() < 2){
        cout << ans << endl;
        return;
    }
    while(!pq.empty()){
        // at any point, 2 minimums
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        int z = x + y;
        ans = ans + z;
        if(pq.empty()){
            break;
        }
        pq.push(z);
    }

    cout << ans << endl;

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
