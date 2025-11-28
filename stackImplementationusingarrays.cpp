#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Implementation fo stack using arrays

int top = -1;
int size = 0;
// lets just keep the inital predefined size of stack 

int arr[10];
int isEmpty = 1;


void push(int x){
    if(size == 10){
        return;
    }
    top++;
    arr[top] = x;
    if(isEmpty){
        isEmpty = 0;
    }
    size++;
}

void pop(){
    if(top == -1){
        return;
    }
    top--;
    if(top == -1){
        isEmpty = 1;
    }
}


int Empty(){
    return isEmpty;
}

void TCSOLVE(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    while(!Empty()){
        cout << arr[top] << " ";
        pop();
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
