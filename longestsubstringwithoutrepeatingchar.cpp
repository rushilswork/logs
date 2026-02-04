#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;
    int l =0 ;
    int r = 0;
    map<char,int> m;
    int len =0;
    int maxlen = INT_MIN;
    while(r < s.length()){
        // we are not removing the char from map after l is moved forward, like maintaining only specifically for l to r window, to make sure it works even while maintaining for whole, check if it exisited after l or before l, if before l , assume as if it is new
        if(m.find(s[r])!=m.end() && m[s[r]] >= l){
            l = m[s[r]] + 1;
        }
        len = r - l + 1;
        m[s[r]] = r;   
        maxlen = max(maxlen,len);
        r++;
    }
    cout << maxlen << endl;
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}

/*

brute force, hashmap + substring 2 loop logic
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;
    int maxcnt = INT_MIN;
    for(int i =0 ;i<s.length();i++){
        vector<int>v(26,0);        
        int cnt = 0;
        for(int j = i;j<s.length();j++){
            if(v[s[j] - 'a'] == 0){
                cnt++;
                v[s[j] - 'a'] = 1;
            }
            else{
                break;
            }
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
*/