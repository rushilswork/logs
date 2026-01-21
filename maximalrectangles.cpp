#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int largestareahistogram(vector<int>&v){
    stack<int> s;
    int maxarea = INT_MIN;
    int n = v.size();
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
    return maxarea;
}

void TCSOLVE(){
    ll n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i =0 ;i<n;i++){
        for(int j =0 ;j<m;j++){
            ll x;
            cin >> x;
            v[i][j] = x;
        }
    }
    
    // to  find the maximum area of the rectangle in the give matrix, we can apply the same logic of largest area of histogram, but here we need to apply for every row and look for the connecting ones, but if we traverse vertically for every column in every row it has more time complexity so we use prefix matrix for vertical length of histograms, if any length is interrupted by 0 will be relapsed


    for(int j =0 ;j<m;j++){
        for(int i = 1;i<n;i++){
            v[i][j]  = v[i][j] + v[i - 1][j]*((v[i][j] != 0)?1:0);
        }
    }
    int maxarea = INT_MIN;
    for(auto x: v){
        maxarea = max(maxarea,largestareahistogram(x));
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