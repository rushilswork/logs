#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){

    // array contains 1 - n elements and size of array is n + 1
    // definately duplicate is present
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }


    // finding both in same array -> equations of sum and xor can fix this
    
    // new ways
    // find missing number -> cyclic sort the one who doesnt sit in it place
    // finding duplicate -> cyclic sort if elem is already at asli index, already set so this elm is duplicate - linear lookup - O(n)

    // find duplicate -> tortoise and haze approach - o(n/2)

    // intuition is if we onserve at index i and index j both index have the same value, i -> x and j -> x, from this if we consider the elements in the array to be the pointers and having values which are indexes of another pointers/elements
    // we map the chain of elements/pointers and we happen to see the loop from i -> x and j -> x. starting point of loop is x
    // we know how to detect a loop using tortoise and haze, and find the starting point of the loop

    int slow = 0;
    int fast = 0;

    while(slow != fast || (slow == 0 && fast == 0)){
        slow = v[slow];
        fast = v[fast];
    }

    // now slow and fast are at the same point but it is not the starting point of the loop, usually the starting point of the loop will be the duplicate
    // x -> z and y -> z, z is pointed by 2 indexes

    // no need to worry that what if the slow and fast meet at 0 and instead of stopping the loop it proceeds further
    // as all the elements are from 1 - n , there wouldn't be a single pointer/element pointing to 0 
    
    // no they'll never meet at 0, 0 is just a starting point we look for the index 1 - 9 

    slow = v[0];
    while(fast!=slow){
        slow = v[slow];
        fast = v[fast];
    }

    cout << v[slow] << endl;

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
