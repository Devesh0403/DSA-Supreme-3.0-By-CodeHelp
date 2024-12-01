// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <unordered_map>

class TrieNode{
    public:
    char value;
    unordered_map<int,TrieNode*>children; // to 
    bool isTerminal;//to check if the word is ending or not
    
    //Constructor
    TrieNode(char data){
        value=data;
        isTerminal=false;
        
    }
};

void insertIntoTrie(TrieNode* root,string word){
    if(word.empty()){
        root->isTerminal=true;
        return;
    }
    
    
    char ch=word[0];
    TrieNode* child;
    
    if(root->children.count(ch)==1){
        child=root->children[ch];
    }
    else{
        child=new TrieNode(ch);
        root->children[ch]=child;
        
    }
    
    insertIntoTrie(child,word.substr(1));
}

bool searchInTrie(TrieNode* root,string word){
    
    if(word.length()==0){
       return root->isTerminal;
    }
    
    char ch=word[0];
    TrieNode* child;
    
    if(root->children.find(ch)!=root->children.end()){
        root=root->children[ch];
        
        
    }
    else{
        return false;
        
    }
    return searchInTrie(root,word.substr(1));
}
int main() {
    TrieNode* root=new TrieNode('-');
    
    insertIntoTrie(root,"helo");
    insertIntoTrie(root,"snake");
    insertIntoTrie(root,"tag");
    insertIntoTrie(root,"blue");
    insertIntoTrie(root,"blur");
    insertIntoTrie(root,"vote");
    
    cout<< searchInTrie(root,"heloo")?"Found":"Not Found";
    
    
    
    
    
    
    
    
    
    
}