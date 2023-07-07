/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
#define n Node*
unordered_map<int,n>vis;
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        n temp=new Node(node->val);
        vis[node->val]=temp;
        for(auto & a:node->neighbors){
            if(vis.find(a->val)!=vis.end()){
                temp->neighbors.push_back(vis[a->val]);
            }else{
                temp->neighbors.push_back(cloneGraph(a));
            }
        }
        return temp;
    }
};