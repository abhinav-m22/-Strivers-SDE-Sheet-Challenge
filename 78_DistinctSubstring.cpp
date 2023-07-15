#include <bits/stdc++.h> 
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    TrieNode(){
        for(int i = 0; i < 26; i++) child[i] = 0;
    }
};

int distinctSubstring(string &word) {
    TrieNode* root = new TrieNode();
    int cnt = 0;
    for(int i = 0; i < word.size(); i++){
        TrieNode* curr = root;
        for(int j = i; j < word.size(); j++){
            int index = word[j] - 'a';
            if(curr->child[index] == NULL){
                cnt++;
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
    }
    return cnt;
}
