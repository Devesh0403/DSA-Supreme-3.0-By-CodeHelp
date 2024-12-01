class TrieNode{
    public: 
    char val;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    
    TrieNode(char data){
        val=data;
        isTerminal =false;
    } 
};
void insertWord(string word,TrieNode* root){
        if(word.empty()){
            root->isTerminal=true;
            return;

        }

        //1 case solve 
        char ch=word[0];
        TrieNode* child;

        if(root->children.find(ch)!=root->children.end()){
            child=root->children[ch];
        }
        else{
            child=new TrieNode(ch);
            root->children[ch]=child;
        }
        
        insertWord(word.substr(1),child);

}
bool searchWord(string word,TrieNode* root){
    if(word.length()==0){
        return root->isTerminal;
    }


    char ch=word[0];

    TrieNode* child;

    if(root->children.find(ch)!=root->children.end()){
        child=root->children[ch];
    }
    else{
        return false;
    }

    return searchWord(word.substr(1),child);
}

bool searchPrefix(string word,TrieNode* root){
    if(word.length()==0){
        return true;
    }


    char ch=word[0];

    TrieNode* child;

    if(root->children.find(ch)!=root->children.end()){
        child=root->children[ch];
    }
    else{
        return false;
    }

    return searchPrefix(word.substr(1),child);
}



class Trie {
public:
    TrieNode* root;

    Trie() {
        root=new TrieNode('-');

        
    }
    
    
    void insert(string word) {
        insertWord(word,root);

        
    }
    
    bool search(string word) {
        return searchWord(word,root);
        
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix,root);

        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */