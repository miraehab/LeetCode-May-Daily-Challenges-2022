/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public: 
    Node* get_next_leftmost(Node* node) {
        Node* next = node->next;

        while(next != NULL) {
            if (next->left != NULL) return next->left;
            if (next->right != NULL) return next->right;
            next = next->next;
        }
        return NULL;
    }
    
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
    
        Node* next_leftmost = get_next_leftmost(root);
		
        if (root->left) root->left->next = root->right ? root->right : next_leftmost;
		
        if (root->right) root->right->next = next_leftmost;

        connect(root->right);
        connect(root->left);

        return root;
    }
};