#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;

    for(int i =0;i<n;i++){
        ll x;
        cin >> x;
        v1.push_back(x);
    }

    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v2.push_back(x);
    }

    int k;
    cin >> k;


    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),greater<int>());


    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> visited;

    // initial push is always the 1st max, as we are adding up the max's of two arrays
    pq.push({v1[0] + v2[0],{0,0}});
    visited.insert({0,0});

    while(!pq.empty() && k--){
        // pairofpairs -> pops
        auto pops = pq.top();
        pq.pop();
        int sum = pops.first;
        pair<int,int> idx = pops.second;
        cout << sum << " ";

        // time to add the neighbours
        if(idx.first + 1 < n && visited.find({idx.first + 1, idx.second}) == visited.end()){
            pq.push({v1[idx.first + 1] + v2[idx.second],{idx.first + 1, idx.second}});
            visited.insert({idx.first + 1,idx.second});
        }

        // simultaneously do the other 
        if(idx.second + 1 < n && visited.find({idx.first, idx.second + 1}) == visited.end()){
            pq.push({v1[idx.first] + v2[idx.second + 1],{idx.first, idx.second + 1}});
            visited.insert({idx.first,idx.second + 1});
        }
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
