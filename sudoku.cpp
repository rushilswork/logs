#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isfeasible(vector<vector<char>> &v,int row,int col, int c){
    for(int i =0 ;i<v.size();i++){
        // 0 -> 9
        if(v[row][i] == c + '0'){
            // already exists
            return false;
        }

        if(v[i][col] == c + '0'){
            return false;
        }

        // mini chunk check
        // to know row falls into which chunk /3 as each chunk is of 3 elements -> you get the row axis
        // similarly for the column axis /3 -> get the col axis
        // row/3 and col/3 determine the axis of mini matrix
        // now time to figure out the starting row and col index for mini matrix
        // (/3 -> number of chunks crossed) x (number of elements in chunk) => starting row index
        // similarly for the col starting index
        // to iterate formulate with i
        // for every 3 elements one row crosses, 
        // i/3 determine row incremental index for mini matrix
        // i%3 determine col incremental index for mini matrix
        // every element beyond 3 index falls into 0 1 2 indexes % ( cyclic chain )
        if(v[3*(row/3) + i/3][3*(col/3) + i%3] == c + '0'){
            return false;
        }
    }

    return true;
}
bool sudoku(vector<vector<char>> &v){
    for(int row =0 ;row<v.size();row++){
        for(int col =0 ;col<v[row].size();col++){
            // if empty take a chance and fill it up
            if(v[row][col] == '.'){
                for(int c = 1;c<10;c++){
                    if(isfeasible(v,row,col,c)){
                        v[row][col] = c + '0';
                        // as only one solution will be present for the given configuration
                        // once figured out return true;
                        // and also the reason for calling recursion and not just looping over
                        // is the need of state, if something in the future doesn't work i need to roll back and change my decision
                        if(sudoku(v)){
                            return true;
                        }

                        // dont think as if the override will happen, it might be possible no other number would satisfy the case and the work will not be undone and you'll return to the previous state with the changes and you'll never update current in the future even after you started from the first, cuz the value will not be empty this time
                        v[row][col] = '.';
                        // so need to undo and move to next options
                    }
                }

                // if nothing works then theres something wrong with the previous decision
                // need to roll back
                return false;
            }
        }
    }

    // if everyupdate is done, nothing else remaining to update return
    return true;
}

void TCSOLVE(){
    vector<vector<char>> v(9,vector<char>(9,'.'));
    for(int i =0;i<9;i++){
        for(int j =0 ;j<9;j++){
            char x;
            cin >> x;
            v[i][j] = x;
        }
    }

    cout << endl;
    if(!sudoku(v)){
        cout << "Somethings wrong sensai" << endl;
    }
    else{
        for(auto x: v){
            for(auto y: x){
                cout << y << " ";
            }
            cout << endl;
        }
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
