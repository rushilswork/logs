#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    
    
    stack<int> s;
    int maxarea = INT_MIN;
    for(int i =0;i<=n;i++){
        // v[i] * ( nse - pse - 1)

        // on the fly finding out pse and when we are popping something out for that element the current element i.e, v[i] is the nse, when we have both pse and nse we compute the are for the popping element
        // extra iteration for the leftout elements
        while(!s.empty() && (i == n || v[s.top()] > v[i])){
            int index = s.top();
            s.pop();
            int nsei = i;
            int psei = (!s.empty())?s.top():-1;
            maxarea = max(maxarea,v[index]*(nsei - psei - 1));
            // before popping out compute the area, as you have nse and pse
        }
        s.push(i);
    }

    // after this operation, still some elements might be leftout in the stack

    // the reason why element leftout in the stack is, for them there is no next smaller element, because only the element smaller than you will remove you in the process of finding pse, so there was no one to remove you, in this case we take the last index as next smaller element
   
   /*
    we can add this in the same above code with just one extra iteration
   while(!s.empty()){
        int index = s.top();
        s.pop();
        int nsei = n;
        int psei = (!s.empty())?s.top():-1;
        maxarea = max(maxarea,v[index]*(psei - nsei - 1)); 
    }
*/
    cout << maxarea << endl;
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
    optimal - 1
    
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long int ll;

    vector<int> previoussmallerelement(vector<int> v){
        stack<int> s;
        int n = v.size();
        vector<int> pse(n);
        for(int i = 0;i<n;i++){
            /// removed <= and replaced < to handle edge case
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

        vector<int> nse = nextsmallerelement(v);
        vector<int> pse = previoussmallerelement(v);

        int ans = INT_MIN;
        for(int i =0 ;i<n;i++){
            ans = max(ans,(v[i]*(nse[i] - pse[i] - 1)));
        }
        cout << ans << endl;
        
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

/*
    /// brute force
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int maxarea = INT_MIN;
    for(int i =0 ;i<n;i++){
        int minheight = INT_MAX;
        for(int j = i;j<n;j++){
            
                the reason for this calculation is that

                suppose we have 3 2 1
                3 alone has 3 area,
                3,2 -> we cant maintain the height 3 and move forward, combining 3 and 2 width we can maintain a height of 2 and area is 4 i.e, 2x2, this is more like from 2 we move backward and maintain a height of 2 and width 2
                3,2,1, just like the case of 3,2 we maintain a height of 1 and move forward and gett the area as 3, this is more like from 1 we move backward maintaining the height of 1
            
            minheight = min(minheight,v[j]);

            int area = (j - i + 1)*minheight;
            maxarea = max(maxarea,area);
        }
    }

    cout << maxarea << endl;
    
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