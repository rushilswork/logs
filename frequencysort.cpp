#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef pair<int,int> pp;

/* way 1
struct magic{
    bool operator ()(pp p1,pp p2){
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        else{
            return p1.first < p2.first;
        }
    }   
}; 
*/

auto magic = [](pp p1,pp p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else{
        return p1.first > p2.first;
    }
};

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    // way 1
    // priority_queue<pp,vector<pp>, magic> pq;

    // way 2
    priority_queue<pp,vector<pp>, decltype(magic)> pq(magic);


    map<int,int> m;
    for(int i =0 ;i<n;i++){
        m[v[i]]++;
    }

    for(int i =0 ;i<n;i++){
        pq.push({m[v[i]],v[i]});
    }
    while(!pq.empty()){
        cout << pq.top().second << " ";
        pq.pop();
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
