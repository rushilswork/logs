#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isplacable(int row, int col, vector<string> &v){
    // check backwards in the same column
    int r = row;
    int c = col;

    while(r >= 0){
        if(v[r][c] == 'Q'){
            return false;
        }
        r--;
    }

    // check crossways top left and top right

    // top left check
    r = row;
    while(r >= 0 && c >= 0){
        if(v[r][c] ==  'Q'){
            return false;
        }
        r--;
        c--;
    }

    r = row;
    c = col;
    // top right check
    while(r >= 0 && c < v[0].size()){
        if(v[r][c] ==  'Q'){
            return false;
        }
        r--;
        c++;
    }
    
    // no negative reporting sir return true
    return true;
}

void nqueens(vector<string> &v, int row){
    //here im considering row as the state, each step we try to fillup the row
    // for every row we have columns as options

    if(row == v[0].size()){
        for(auto x: v){
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int col = 0;col<v[0].size();col++){
        // check if we can place
        // if so place and move to next row
        if(isplacable(row,col,v)){
            v[row][col] = 'Q';
            nqueens(v,row + 1);
            v[row][col] = '.';
        }
    }
}
void TCSOLVE(){
    ll n;
    cin >> n;

    vector<string> v;

    for(int i =0 ;i<n;i++){
        string s(n,'.');
        v.push_back(s);
    }

    nqueens(v, 0);
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
