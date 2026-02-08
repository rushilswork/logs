#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;
    int n = s.length();

    int k;
    cin >> k;
    int r = 0;
    int l = 0;
    int maxlen = INT_MIN;
    int maxfreq = INT_MIN;
    // always keep track of max frequency in the substring so that the total length - maxfreq, gives us the rest of the characters that can be replacable, in k operations, in a substring eg: ABABBB - > we can replace A's or B's, but replacing the A's takes less replacements rather than B's, so as we have constraints and to make the most out of it, we keep track of maxfreq such that length - maxfreq tells us currently how many we can replace


    /*
    
    Intuition in plain words

    “How far is this substring from being uniform?”

    → Exactly the number of characters that are not the majority character.

*/
    vector<int>m(26,0);
    while(r < n){
        m[s[r] - 'A']++;
        maxfreq = max(maxfreq,m[s[r] - 'A']);

        // this loop can be optimized , as we are focusing only on the length and not on the chars in the string, as we are looking for value > current maxlen, there is no point in downgrading the window and then again adding elements then going upto current maxlen
        // while(r - l + 1 - maxfreq > k){  
        if(r - l + 1 - maxfreq > k){ // this conditional statement tells us howmany replacements are possible and we are checking if it is in the limits, else shrink
            m[s[l] - 'A']--;
            // we need to update the maxfreq , while shrinking
            // for cases like: AABCC
            // to optimize this O(26), we actually dont need this,
            /*
                AAABB 
                maxfreq = 3
                len = 5
                k = 2

                len - maxfreq <= k valid case, now the maxlen is 5
                we are looking for maxlen > 5, so  to get that
                requirements: 
                len = 6, maxfreq = 4
                len - maxfreq <= k

                as we've seen the maxfreq need to be more than 3, as we want more length > 5, maxfreq should also be more, so there is no point in updating as updating while shrinking might reduce maxfreq, if we update it goes < 3 like 2, and again we need to update it to 3..4.... and so on.
                = = = = = -> length of 5
                = = =     -> maxfreq 
            
                k = 2

                = = = = = = -> length of 6
                = = = =     -> maxfreq should be 4,5,6 such that len - maxfreq can be <= k (2)


                so there is not point of updating the maxfreq, we should wait for it to update automatically, the extra O(26) loop only downgrade the maxfreq
            */
            // maxfreq = *max_element(m.begin(),m.end());
            l++;
        }
        maxlen = max(maxlen,r - l + 1);
        r++;
    }

    cout << maxlen << endl;
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
