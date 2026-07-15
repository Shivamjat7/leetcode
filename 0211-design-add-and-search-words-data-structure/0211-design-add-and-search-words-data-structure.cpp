struct Node {
    Node* child[26];
    bool isEnd;

    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class WordDictionary {
    Node* root = new Node();

    bool dfs(Node* node, string &word, int idx) {
        if (node == nullptr)
            return false;

        if (idx == word.size())
            return node->isEnd;

        char ch = word[idx];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] && dfs(node->child[i], word, idx + 1))
                    return true;
            }
            return false;
        }

        return dfs(node->child[ch - 'a'], word, idx + 1);
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        Node* node = root;

        for (char ch : word) {
            int i = ch - 'a';
            if (node->child[i] == nullptr)
                node->child[i] = new Node();

            node = node->child[i];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};