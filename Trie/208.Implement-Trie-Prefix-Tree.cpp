//method 1
class TrieNode{
    public:
        int data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        //assumption, word will be in small letter
        int index = word[0] - 'a';
        TrieNode *child;

        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode* root, string word) {
        //base case 
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }else{
            //absent
            return false;
        }

        //recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool prefixUtil(TrieNode* root, string word) {
        //base case 
        if(word.length() == 0) {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        //present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }else{
            //absent
            return false;
        }

        //recursion
        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

//method 2
struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            //moves to the reference trie
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }

            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
         Node* node = root;
        for(int i=0; i<prefix.length(); i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
