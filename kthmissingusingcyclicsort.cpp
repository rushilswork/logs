#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >>x;
        v.push_back(x);
    }

    ll k;cin >> k;
    for(int i =0 ;i<n;){
        int aslindex = v[i] - 1;
        if(aslindex == i){
            i++;
            continue;
        }
        if(aslindex >= 0 && aslindex < n){
            swap(v[aslindex],v[i]);
        }
        else{
            i++;
        }
    }

    int missingcount =0 ;
    for(int i =0 ;i<n;i++){
        if(v[i] - 1 != i){
            missingcount++;
            if(missingcount == k){
                cout << i+1 << " ";
                break;
                return;
            }
        }
    }

    if(missingcount < k){
        // so far we've looked into the search space of 1 - n elements and in these elements there are less missing numbers than we required
        // so the required mising number lies beyond the search space
        k -= missingcount;
        // this updates the required number of elements we need to look for from n + 1
    }

    unordered_map<int,int> m;
    for(int i =0 ;i<n;i++){
        m[v[i]] = 1; // to get a quick access to know who is present and who is not
    }

    /* consider there is chunk of k missing elements, init => k+=n
    im considering the ans to be k , check if anything between start number and k occurs the chunk no longer stays intact it'll shrink as the element we considered to missing not longer missing so remove it from the chunk. To keep up the size of chunk add additional numbers
    */

    // The above can be implemented but we need to sort the vector and look for elements from starting number i.e, n + 1 between n + 1 and k

    // but below approach works without sorting
    
    int cnt = k; // 3 more elements to look for
    int elm = n + 1;
    while(1){
        if(!m[elm])// start from elm
        {
            cnt--;
        }
        if(cnt == 0){
            break;
        }
        elm++;
    }

    cout << elm << endl;
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
