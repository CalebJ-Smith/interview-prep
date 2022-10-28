//https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
//Acceptd. Slightly worse than median speed, 97%ile memory


#include <map>
using namespace std;


class Trie {
    struct Node{
        map<char, Node*> children;
    };
    map<char, Node*> root;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        word.push_back('\0');
        map<char, Node*>* current_map = &root;
        auto current_char = word.begin();
        while(current_char != word.end()){
            auto found = current_map->find(*current_char);
            if(found == current_map->end()){
                Node* inserted = new Node;
                current_map->insert(found, {*current_char, inserted});
                current_map = &inserted->children;
            }else{
                current_map = &found->second->children;
            } 
            ++current_char;
        }
    }
    
    bool search(string word) {
        word.push_back('\0');
        return startsWith(word);
    }
    
    bool startsWith(string prefix) {
        map<char, Node*>* current_map = &root;
        auto current_char = prefix.begin();
        while(!current_map->empty()){
            if(current_char == prefix.end()){
                return true;
            }
            auto found = current_map->find(*current_char);
            if(found == current_map->end()){
                return false;
            }
            current_map = &found->second->children;
            
            ++current_char;
        }
        return current_char == prefix.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */