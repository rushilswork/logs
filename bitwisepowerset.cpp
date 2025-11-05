#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


// logic behind using bitmasking is:
// we have 3 elements ( lets suppose : 1 2 3) to find all subsets ( powerset ) we try out all combinations choosing and not choosing elements to makeout all possible combinations
// mathematically for powerset , the total count of possible subsets is 2 ^ n here it is 2 ^ 3 (or) (1 << n) here ( 1 << 3 )
// similarly suppose we have 3 bits, number of possible combinations that we can make out of 0 and 1 ( binary numbers ) are 2 ^ 3
// choosing and not choosing ( 2 choices ) are mapped to 1 and 0, and the total number of combinations of these 3 bits mapped to total combinations of 3 numbers which yields subsets
// considering the set bits in the possible combinations tells us what number to be choosen for the instance of subset combination / binary combination
// 1 (set bit) - choose
// 0 (unset bit) - dont choose

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int subsets = 1 << n;

    vector<vector<int>> subsetslist;
    for(int i = 0;i<subsets;i++){
        vector<int>subset;
        // for every ith subsets we are representing 'i' in binary form which mapps to index of vcetors and helps in selection of subset elements
        for(int j = 0;j<n;j++){
            if((i >> j) & 1 == 1){
                subset.push_back(v[j]);
            }
        }

        subsetslist.push_back(subset);
    }   

    for(auto x: subsetslist){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
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
