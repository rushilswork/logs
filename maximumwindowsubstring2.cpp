#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s,t;
    cin >> s >> t;

    int minlen = INT_MAX;
    int sidx = -1;
    int len = 0;

    map<char,int> m;

    int l = 0;
    int r = 0;
    
    for(auto x: t){
        m[x]++;
    }
    
    int cnt =0;
    
        while(r < s.length()){
            m[s[r]]--;
            if(m[s[r]] == 0){
                cnt++;
            }
            while(cnt == t.length()){
                len = r - l + 1;
                if(minlen > len){
                    minlen = len;
                    sidx = l;
                }
                // check if next step is going to decrease cnt
                if(m[s[l]] + 1 > 0){
                    break;
                }
                // if not proceed forward
                m[s[l]]++;
                l++;
            }
            r++;
        }

    if(minlen != INT_MAX){
        cout << s.substr(sidx,minlen);
    }
    else{
        cout << "no such substring exists" << endl;
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
