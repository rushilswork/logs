#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node{
    struct node* prev;
    struct node* next;
    pair<int,int> p;
};

map<int,node*> m;
int k = 100;
// LRUCache size

struct node* head = (struct node*)malloc(sizeof(struct node));
struct node* tail = (struct node*)malloc(sizeof(struct node));

void get(int key){
    if(m.find(key)==m.end()){
        cout << "key not found " << endl;
        return;
    }
    struct node* temp = m[key];
    cout << temp->p.second << endl;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    // latest accessed should be at first so removed from where ever it is and placed at front
    temp->next = head->next;
    head->next->prev = temp;
    head->next = temp;
    temp->prev = head;
}
void put(int key, int value){
    struct node* temp = head;
    
    if(m.find(key)!=m.end()){
        // update if ket already exists
        m[key]->p.second = value;
        struct node* temp = m[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        return;
    }
    else if(m.size() == k){
        // last but one node from tail
        m.erase(tail->prev->p.first); 
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
    }


    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->p.first = key;
    newnode->p.second = value;
    m.insert({newnode->p.first,newnode});

    temp = head;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;

}
void TCSOLVE(){
    head->p.first = -1;
    head->p.second = -1;
    tail->p.first = -1;
    tail->p.second = -1;
    head->next = tail;
    tail->prev = head;

    head->prev = NULL;
    tail->next = NULL;
    
    /*
    SAME NODE                        tail = head;
    Copy full struct	            *tail = *head;
    Copy only data (safe for lists)	tail->p = head->p;
    */
    int n;
    cin >> n;
    k = n;
    // for(int i =0 ;i<n;i++){
    //     ll x,y;
    //     cin >> x >> y;
    //     put(x,y);
    // }        

    // 5,7 7,10 8,11 2,6
    // get(2);
    // get(8);

    // put(5,6)
    // get(7);
    // put(5,7);

    put(1,1);
    put(2,2);
    get(1);
    put(3,3);
    get(2);
    put(4,4);
    get(1);
    get(3);
    get(4);
    head = head->next;
    while(head!=tail){
        cout << head->p.first << " ->" << head->p.second << endl;
        head = head->next;
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
