#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int *left;
    int *right;
    int freq;
    char c;
    Node(char ch, int f): freq(f), left(nullptr), right(nullptr), c(ch){}
};

class compare{
public:
    bool operator(Node *l, Node *r){
        return l->freq > r->freq;
    }
};
void encode(string str, map<char ,string>huffman, Node *root){
    if(!root)return; //khaali hai

    //leaf exist krta hai 
    if (!root->left && !root->right) {
        huffman[root->ch] = str;
    }
    
    encode(root->left, str + "0", huffman); //left tree mei ghuso
    encode(root->right, str + "1", huffman); // right tree mei ghuso
}

string decode(Node *root, string s){
    string ans = "";
    for (char bit : s) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            ans += curr->ch;
            curr = root;
        }
    }
    return ans;
}

int main(){
    string str;cin>>str;
    map<char, int> m;
    
    for(int i = 0; i<str.size(); ++i){
        m[str[i]]++;
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
            pq.push(new Node(pair.first, pair.second));
    }
    while (pq.size() != 1) {
        Node *left = pq.top();pq.pop();
        Node *right = pq.top();pq.pop();
        Node *top = new Node('#', left->freq + right->freq);
        top->left = left, top ->right = right;
        
        pq.push(top);
    }
    
    
    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);
    
    return 0;
}
