//
// Created by Alexander Kourkoumelis on 12/7/17.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H
#include <iostream>
using namespace std;

//size of alphabet
const int R = 256; //extended ASCII

//r-way trie code
struct Node {
    Node* next[R];
    string val;
};

class Trie{
private:
    Node* root;
    Node* put(Node* x, const string& key, const string& val, int d){
        if (!x) {
            x = new Node();
        }
        if (d == key.size()){
            x->val = val;
            return x;
        }
        char c = key[d];
        x->next[c] = put(x->next[c], key, val, d + 1);

        return x;
        }
    Node* get(Node* x, const string& key, int d){
        if (!x) {
            return nullptr;
        }
        if (d == key.size()) {
            return x;
        }
        char c = key[d];
        return get(x->next[c], key, d + 1);
    }
public:
    void put(const string& key, const string& val){
        root = put(root, key, val, 0);
    }

    string get(const string& key){
        Node* x = get(root, key, 0);
        if(!x){
            return "";
        } else {
            return x->val;
        }
    }
};

#endif //TRIE_TRIE_H
