#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    class Node {
    public:    
        int freq;
        Node *left, *right;
        
        Node(int f) {
            freq = f;
            left = right = NULL;
        }
    };
    class cmp {
    public:
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };
    
    void dfs(Node* root, string curr, vector<string> &ans) {
        if (!root->left && !root->right) {
            ans.push_back(curr);
            return;
        }
        dfs(root->left, curr + '0', ans);
        dfs(root->right, curr + '1', ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        for (int i = 0; i < N; i++) {
            pq.push(new Node(f[i]));
        }
        
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* merged = new Node(left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            
            pq.push(merged);
        }
        
        vector<string> ans;
        dfs(pq.top(), "", ans);
        return ans;
    }
};


int main() {
    Solution s;
    string S = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    int N = freq.size();
    vector<string> codes = s.huffmanCodes(S, freq, N);
    for (auto &code : codes) {
        cout <<code<<" ";
    }
    return 0;
}
