#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> p;
bool magic(p p1, p p2){
    // we are calculating the unit profit ( which gives more profit with less weight)
    return (float)p1.first/(float)p1.second > (float)p2.first/(float)p2.second;
}
void TCSOLVE(){
    ll n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i =0 ;i<n;i++) {
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    int k;
    cin >> k;

    sort(v.begin(),v.end(),magic);

    float tprofit = 0;
    int i =0;
    while(i < n && k > 0){
        if(k >= v[i].second){
            k-=v[i].second;
            tprofit+=v[i].first;
        }
        else{
            tprofit+=((float)v[i].first/(float)v[i].second)*((float)k);
            k = 0;
        }
        i++;
    }

    cout << tprofit << endl;
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
