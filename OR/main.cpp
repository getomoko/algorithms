#include <iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

typedef long long ll;

const int len = 10;

int a[len] = {1,2,3,4,5,6,7,8,9,10};

struct Trie{
    Trie* next[2];
    Trie(){
        for(unsigned int i = 0; i < 2; i++){
            next[i] = NULL;
        }
    }
};

void insert_trie(Trie *root, int n){
    Trie *p = root;
    for(int i = 31; i >= 0; i--){
        int id = (n>>i) & 1;
        if(p->next[id] == NULL){
            p->next[id] = new Trie();
        }
        p = p->next[id];
    }
}

void delete_trie(Trie *p) {
    if(p == NULL) return;
    for(int i = 0; i < 2; i++) {
        if(p->next[i] != NULL) {
            Trie *t = p->next[i];
            delete_trie(t);
        }
    }
    delete p;
    p = NULL;
}

int search_trie(Trie *root, int n){
    n = ~n;
    Trie *p = root;
    int ans = 0;
    for(int i = 31; i >= 0; i--){
        ans = (ans << 1);
        int bit = (n >> i) & i;
        if(bit){
            if(p->next[1]){
                p = p->next[1];
                ans++;
            }
            else{
                p = p->next[0];
            }
        }
        else{
            if(p->next[0]){
                p = p->next[0];
            }
            else{
                p = p->next[1];
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ifstream cin(".\\in.txt");
    int n;
    Trie *root = new Trie();
    for(int i = 0; i < len; i++){
        insert_trie(root, a[i]);
    }
    while(cin >> n){
        cout << search_trie(root, n) <<endl;
    }
    delete_trie(root);
    return 0;
}
