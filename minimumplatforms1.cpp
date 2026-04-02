#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }       

    // in brute force we try to look for the maximum collisions or intersections so that we have to maintain atleast i.e, minimum number of stations to prevent such collisions/ intersections

    int maxcnt = INT_MIN;
    for(int i =0 ;i<n;i++){
        int cnt = 1;
        for(int j = i+1;j<n;j++){
            // types of intersections
            /*
                -  -  
                  -  -
                  
                -    -
                  - -

                   -   -
                -    -

                    - -
                -       -
            */

            // this covers 4 cases
            if(((v[i].second >= v[j].first) && (v[i].first <= v[j].first)) || ((v[j].second >= v[i].first) && (v[i].first >= v[j].first))){
                cnt++;
            }
        }
        maxcnt = max(maxcnt,cnt);
    }

    cout << maxcnt << endl;
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
