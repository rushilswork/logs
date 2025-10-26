#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


void ratinmaze(vector<vector<int>> &maze,int row,int col,string track, 
vector<vector<int>>&vis){

    if(row == maze.size() - 1 && col == maze[0].size() - 1){
        cout << track << endl;
        return;
    }
    // we have four options
    // D,L,R,U

    vis[row][col] = 1;

/*
    if(row + 1 < maze.size() && maze[row + 1][col] == 1 && vis[row + 1][col] != 1){
        ratinmaze(maze,row + 1, col, track+'D', vis);
    }

    if(col - 1 >= 0 && maze[row][col - 1] == 1 && vis[row][col - 1] != 1){
        ratinmaze(maze,row, col - 1, track+'L', vis);
    }

    if(col + 1 < maze[0].size() && maze[row][col + 1] == 1 && vis[row][col + 1] != 1){
        ratinmaze(maze,row, col + 1, track+'R', vis);
    }
    
    if(row - 1 >= 0 && maze[row - 1][col] == 1 && vis[row - 1][col] != 1){
        ratinmaze(maze,row - 1, col, track+'U', vis);
    }
    
*/

    // instead of writing this complex not so easy to read recursive calls, we shorten them using loop and make once recursive call dynamic adaptive to variations

    // 4 choices in every stack frame / stage / step 

    // same procedure different implmentation for readability
/*
    string choices = "DLRU";
    for(int i =0 ;i<4;i++){
        int r =0 ;
        int c = 0;
        if(choices[i] == 'D' && row + 1 < maze.size() && vis[row + 1][col] != 1 && maze[row + 1][col] == 1){
            r = 1;
        }   
        else if(choices[i] == 'L' && col - 1 >= 0 && vis[row][col - 1] != 1 && maze[row][col - 1] == 1){
            c = -1;
        }
        else if(choices[i] == 'R' && col + 1 < maze[0].size() && vis[row][col + 1] != 1 && maze[row][col + 1] == 1){
            c = 1;
        }
        else if(choices[i] == 'U' && row  - 1 >= 0 && vis[row - 1][col] != 1 && maze[row - 1][col] == 1){
            r = -1;
        }
        else{
            continue;
        }

        ratinmaze(maze,row + r,col + c,track+choices[i], vis);  
    }
*/

// same approach different implementation for readabiility as we can see the if and else cases conditional cases pilled up, to shorten that

    string choices = "DLRU";
    // down = +1,0
    // left = 0,-1
    // right = 0, +1
    // up = -1,0
    int rows[4] = {1,0,0,-1};
    int cols[4] = {0,-1,+1,0};
    // coordinates for directions preprocessed for quick access
    for(int i =0 ;i<4;i++){
        // modified row and col 
        // from current place we are looking for possibilities , to check if the step is valid or not, first we need to find if the index is valid or not within in bounds?
        // so what is the index of the step we are going to take
        int mrow = row + rows[i];
        int mcol = col + cols[i];

        if(mrow >= 0 && mrow < maze.size() && mcol >= 0 && mcol <= maze[0].size() && vis[mrow][mcol] == 0 && maze[mrow][mcol] == 1){
            ratinmaze(maze, mrow, mcol, track+choices[i],vis);
        }
    }
    // while returning
    vis[row][col] = 0;

}
void TCSOLVE(){
    ll n,m;
    cin >> n >> m;
    vector<vector<int>>maze(n,vector<int>(m,0));
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i =0;i<n;i++){
        for(int j =0 ;j<m;j++){
            ll x;
            cin >> x;
            maze[i][j] = x;
        }
    }
    
    string s = "";
    ratinmaze(maze,0,0,s, vis);

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
