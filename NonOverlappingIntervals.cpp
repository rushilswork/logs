#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// More intervals fit → more intervals kept → fewer intervals removed
 
// Non overlapping intervals -> we need to return number of intervals removed, by maximizing number of intervals kept

/*

    we can maximize the number of non overlapping intervals by removing minimum number of intervals: arranging them on the basis of the ending time so that we can leave lots of space for other intervals and indirectly maximizing the number of non overlapping intervals , with this approach we try to find the max non overlapping intervals but the problems need the number of intervals that are removed to make it max, total - max non overlappping = removed intervals
    
*/
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

    cout << v.size() - s.size() << endl;
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

