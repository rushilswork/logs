#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s,t;
    cin >> s >> t;

    int minlen = INT_MAX;
    int len = 0;

    int sidx = -1;
    for(int i =0 ;i<s.length();i++){
        // at every point you start fresh, as we make modifications if count in the map
        map<char,int> m;
        for(auto x: t){
            m[x]++;
        }        
        int cnt = 0;
        for(int j = i;j<s.length();j++){
            // this approach is slightly optimized from the extreme brute force, where in the extreme brute force you apply the normal loop check for the charcters if they exists in the window of size j - i + 1 of not , unlike using map, map approach has made the logic from n^3 ==> n^2

            // you can also reduce this logic from n^2 ==> nlogn, using binary search, apply binary search and check if the low to mid or mid to high is valid window or not, based on the you move accordingly, instead of checking through everywindows like in brute force, you check for windows in logn approach
            
            m[s[j]]--;
            if(m[s[j]] == 0){
                cnt++;
            }
            if(cnt == t.length()){
                len = j - i + 1;
                minlen = min(minlen,len);
                sidx = i;
                break;
            }
        }
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
