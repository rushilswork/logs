#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n,m;
    cin >> n;
    m = n;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i =0 ;i<n;i++){
        for(int j =0 ;j<m;j++){
            ll x;
            cin >> x;
            v[i][j] = x;
        }
    }

// this optimized approach talks about the logic is where if 'i' to be the celebrity he should not know anyone, even if he knows one person , i cannot be the celebrity, similarly everyone should know him, even if one person doesn't know him, he cannot be the celebrity
/*
    i know j, here i cannot be the celebrity as celebrities should not know anyone, j might be the celebrity here
    i doesnt know j, i might be the celebritiy here, j cannot be the celebrity
*/
    int low =0 ;
    int high = n - 1;
    while(low < high){
        if(v[low][high] == 1){
            low++;
        } 
        else if(v[high][low] == 1){
            high--;
        }
        else{
            // both low and high are not celebrities , 
            // i doesn't know j, j cannot be the celebrity, i might be the celebrity
            // j doesnt know i, aswell, now both cannot be the celebrities
            //lets check other options
            
            low++;
            high--;
        }
    }
    
    if(low > high){
        cout << -1 << " is the celebrity " << endl;
    }
    else{
        // got the ans, but make a check 
        for(int i =0 ;i<n;i++){
            // we dont check if the same person knows himself
            if(low == i){
                continue;
            }
            if(v[low][i] == 1 || v[i][low] == 0 ){
                cout << -1 << " is the celebrity " << endl;
                return;
            }
        }

        cout << low << " is the celebrity " << endl;
        
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

/*
TC - > O(NXN) + O(N)
SC - O(2N)
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n,m;
    cin >> n;
    m = n;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i =0 ;i<n;i++){
        for(int j =0 ;j<m;j++){
            ll x;
            cin >> x;
            v[i][j] = x;
        }
    }

    vector<int> howmanyknowsj(n,0);
    vector<int> iknowhowmany(n,0);

    for(int i =0 ;i<n;i++){
        for(int j =0 ;j<m;j++){
            if(i!=j){
                if(v[i][j] == 1){
                    iknowhowmany[i]++;
                    howmanyknowsj[j]++;
                }
            }
        }
    }

    for(int i =0;i<n;i++){
        if(howmanyknowsj[i] == n - 1 && iknowhowmany[i] == 0){
            cout << i << " is the celebrity " << endl;
            break;
            return;
        }
    }
    cout << -1 << " is the celebrity " << endl;
    
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
*/