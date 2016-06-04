#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<fstream>
using namespace std;

const int len = 2;

struct Trie{
    Trie *next[len];
    Trie(){
        for(int i = 0; i < len; i++){
            next[i] = NULL;
        }
    }
};

void insert_trie(Trie *root, string str){
    Trie *p = root;
    unsigned int slen = str.size();
    for(unsigned i = 0; i < slen; i++){
        int a = (str[i] == '0') ? 0 : 1 ;
        if(p->next[a] == NULL){
            p->next[a] = new Trie();
        }
        p = p->next[a];
    }
}

void delete_trie(Trie *&root){
    if(root == NULL) return;
    for(int i = 0; i < len; i++){
        if(root->next[i]){
            delete_trie(root->next[i]);
        }
    }
    delete root;
    root = NULL;
}

void print_trie(Trie *root){
    if(root == NULL) return;
    for(int i = 0; i < len; i++){
        if(root->next[i]){
            cout << i << " ";
        }
        print_trie(root->next[i]);
    }
}

void pre_trie(Trie *root, int depth, unordered_map<int,int>& result){
    if(root == NULL) return;
    bool isbranch = true;
    for(int i = 0; i < len; i++){
        if(root->next[i] == NULL){
            isbranch = false;
        }
    }
    if(isbranch){
        if(result.find(depth) == result.end()){
            result.insert({depth, depth});
        }
    }
    for(int i = 0; i < len; i++){
        if(root->next[i]){
            pre_trie(root->next[i], depth+1, result);
        }
    }
}

void print_str(vector<string> &str){
    for(unsigned int i = 0; i < str.size(); i++){
            for(unsigned int j = 0; j < str[i].size(); j++){
                cout << str[i][j] ;
            }
            cout << ":" << str[i].size() << endl;
    }
}

void test(){
    int N, M, K;
    while(cin >> N >> M >> K){
        Trie *root = new Trie();
        int len = N * M;
        vector<string> str(K, string(len,'0'));
        char fin;
        for(int k = 0; k < K; k++){
            cin.get();
            for(int n = 0; n < N; n++){
                for(int m = 0; m < M; m++){
                    cin >> fin;
                    str[k][n*M+m] = fin;
                }
            }
            insert_trie(root, str[k]);
        }
        unordered_map<int,int> result;
        pre_trie(root, 0, result);
        cout << result.size() << endl;
        delete_trie(root);
    }
}

int main()
{
    test();
    return 0;
}
