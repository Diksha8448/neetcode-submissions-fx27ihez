class TrieNode{
public:

    TrieNode* children[26];
    bool isEnd;

    TrieNode(){

        isEnd = false;

        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for(char ch : word){

            int index = ch - 'a';

            if(node->children[index] == NULL)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->isEnd = true;
    }
        bool dfs(string &word,
             int index,
             TrieNode* node){

        if(node == NULL)
            return false;

        if(index == word.size())
            return node->isEnd;

        char ch = word[index];

        // Wildcard
        if(ch == '.'){

            for(int i=0;i<26;i++){

                if(node->children[i] &&
                   dfs(word,index+1,node->children[i]))
                    return true;
            }

            return false;
        }

        // Normal character
        return dfs(word,
                   index+1,
                   node->children[ch-'a']);
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
