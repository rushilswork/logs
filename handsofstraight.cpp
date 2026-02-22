#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int k;
    cin >> k;


    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto x: v){
        pq.push(x);
    }
    int cnt = 0;

    vector<int> store;

    int ngroups = 0;
    while(!pq.empty()){
        cnt = k-1;
        store.clear();
        int x = pq.top();
        pq.pop();
        while(!pq.empty() && cnt){
                int res = abs(x - pq.top());
                if(res == 0){
                    store.push_back(pq.top());
                    pq.pop();
                }
                else if(res == 1){
                    cnt--;
                    x = pq.top();
                    pq.pop();
                }
                else{
                    break;
                }
        }
        if(cnt != 0){
            cout << "No groups are possible" << endl;
            return;
        }
        else{
            ngroups++;
        }
        // once this loop ends we get the k size group, dont forget to add the elements in store back to pq
        for(auto x: store){
            pq.push(x);
        }
    }

    cout << ngroups << " are possible" << endl;
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
