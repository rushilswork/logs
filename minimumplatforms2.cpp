#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


void TCSOLVE(){
    ll n;
    cin >> n;
    vector<pair<int,char>> v;
    for(int i = 0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,'A'});
        v.push_back({y,'D'});
    }       

/*


instead of checking which train is overlapping with what all trains and what is the maximum cnt of overlapps

we are interestedin finding the number of trains present at the point of time


*/
    sort(v.begin(),v.end());

    int maxcnt = INT_MIN;
    int cnt = 0;
    for(auto x: v){
        if(x.second == 'A'){
            cnt++;
        }
        else{
            cnt--;
        }

        maxcnt = max(cnt,maxcnt);
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
