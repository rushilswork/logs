#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool magic(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> start;
    vector<int> end;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        start.push_back(x);
    }

    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        end.push_back(x);
    }

    vector<pair<int,int>> v;

    for(int i =0 ;i<start.size();i++){
        v.push_back({start[i],end[i]});
    }

    sort(v.begin(),v.end(),magic);



    stack<pair<int,int>> s;
    for(auto x: v){
        if(s.empty()){
            s.push(x);
        }
        else{
            if(s.top().second < x.first){
                s.push(x);
            }
        }
    }

    cout << s.size() << endl;
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
