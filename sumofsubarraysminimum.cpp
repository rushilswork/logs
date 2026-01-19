#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// this approach is like reverse engineering, how many number of times a particular value contributing to the ans instead of figuring out all the subarays and finding the min and adding them up

// here we are finding out the number of times a value can be minimum and them (number of times it is min)*(min value)

/*

    edge case: 1 1
    1, 1 1 -> 2 subarrays starting from 0 index
    1, 1 1 -> 2 subarrays ending at 1 index,

    here 1,1 is considered twice, so you either consider it once either from the front or from the back, i.e, either pse or nse, i.e, if you find the same element dont remove consider it, either in nse or pse, lets do it for pse

 */
ll mod = (1e9+7);
vector<int> previoussmallerelement(vector<int> v){
    stack<int> s;
    int n = v.size();
    vector<int> pse(n);
    for(int i = 0;i<n;i++){
        // removed <= and replaced < to handle edge case
        while(!s.empty() && v[i] < v[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            pse[i] = s.top();
        }
        else{
            pse[i] = -1;
        }
        s.push(i);
    }

    return pse;
}

vector<int> nextsmallerelement(vector<int> v){
    stack<int> s;
    int n = v.size();
    vector<int> nse(n);
    for(int i = n - 1;i>=0;i--){
        while(!s.empty() && v[i] <= v[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            nse[i] = s.top();
        }
        else{
            nse[i] = n;
        }
        s.push(i);
    }

    return nse;
}


void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    // these will be storing indexes
    vector<int> pse = previoussmallerelement(v);
    vector<int> nse = nextsmallerelement(v);

    /* 
        1 4 6 7 3 7 8 1
        how to find the number of subarrays where 3 can be the minimum
        4 6 7 3 7 8  - val
        1 2 3 4 5 6 - index

        for 3 to be the minimum

        the starting point can be from 4,6,7,3
        (before 3 or at 3)
        the ending point can be 3,7,8
        (after 3 or at 3)

        (before 3 or at 3) x (after 3 or at 3)
        number of possible choices
        (4) x (3) => 12 ( AND operation as both need to happen )

        combining all possible starting points and ending points yield us subarrays, total of 12

    */
    int total = 0;
    for(int i = 0;i<n;i++){
        int cnse = nse[i] - i;
        int cpse = i - pse[i];
        
        total = (total + (cnse*cpse*1ll*v[i])%mod)%mod;
    }

    cout << total << endl;
    
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
