
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
    
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        // for keeping track of cloned nodes and marking visited nodes
        unordered_map<Node*,Node*> map;
        if(node==NULL){
            return NULL;
        }

        map[node] = new Node(node->val);
        q.push(node);

        while(q.empty()==false){
            Node* temp = q.front();
            q.pop();
            vector<Node*> currN;

            if(temp!=NULL){
            currN = temp->neighbors;

            for(int i=0;i<currN.size();i++){
                if(map.find(currN[i])==map.end()){
                    map[currN[i]] = new Node(currN[i]->val);
                    q.push(currN[i]);
                }
                // defining members of cloned nodes to cloned neighbors
                map[temp]-> neighbors.push_back(map[currN[i]]);
            }
            
            }
        }
        return map[node];
    }
};