class TrieNode{
    public:
        int data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char c) {
            data = c;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class WordDictionary {
    TrieNode *root;

public:
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void addWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if(word[0] == '.') {
            for(auto c: root->children) {
                if(c && searchUtil(c, word.substr(1))) return true;
            }
        }
        else if(root->children[index] != NULL) {
            child = root->children[index];
            return searchUtil(child, word.substr(1));
        }else{
            return false;
        }

        return false;
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
};
