#include <iostream>

// the tree node struct
struct TreeNode  {
    int info;
    TreeNode *left = nullptr, *right = nullptr;
};
int count(TreeNode* rt);
// the binary search tree class
// this is a very minimal implementation
// for example we should have destructor
// also we could have search, delete etc.
class BinSearchTree {
public:
    bool insert(int newInt);
    void traverseNodes(TreeNode* root);
    void traverseNodes();
    int countLarger(TreeNode*, int x);
    int countLvl(TreeNode*);
    TreeNode* getRoot(){
        return root;
    }
public:
    TreeNode* root = nullptr;
};

// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* p = root;
    TreeNode* q = nullptr;

    while (p != nullptr) {
        if (p->info == newInt) {
            return false;
        }
        q = p;
        if (newInt < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    // new node
    TreeNode* v = new TreeNode;
    v->info = newInt;

    if (q == nullptr) {
        std::cout << "Insert at root " << v->info << std::endl;
        root = v;
    }
    else if (newInt < q->info) {
        std::cout << "Insert " << v->info << " left to " << q->info << std::endl;
        q->left = v;
    }
    else{
        std::cout << "Insert " << v->info << " right to " << q->info << std::endl;
        q->right = v;
    }
    return true;
}

// traversal
void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private

}

void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr)
        return;
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);

}

////////////////////////////////////////////

int main() {
    BinSearchTree st = BinSearchTree(); // the tree object

    st.insert(8);
    st.insert(4);
    st.insert(9);
    st.insert(2);
    st.insert(3);
    st.insert(14);
    st.insert(15);
    st.insert(16);
    st.insert(13);
    st.insert(12);
    st.insert(11);



    std::cout << "count: " << st.countLarger(st.getRoot(),12);
    std::cout << std::endl;

    // now traverse
    std::cout << "\ninorder traversal:  ";
    st.traverseNodes();
    std::cout << "\nNumber of Tree Nodes: " << count(st.root) << "\n";
    std::cout << "BT level: " << st.countLvl(st.root);
}

int BinSearchTree::countLarger(TreeNode* p, int x) {
        if(p != nullptr) {
            if (x < p->info) {
                return countLarger(p->left,x) + countLarger(p->right,x) + 1;
            }
            else if(x >= p->info){
                return countLarger(p->left,x) + countLarger(p->right,x);
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
}

int BinSearchTree::countLvl(TreeNode * p) {
    if(p == nullptr) return 0;
    int a = countLvl(p->left) + 1;
    int b = countLvl(p->right) + 1;
        if( a < b ){
            return b;
         }
        else return a;
}

int count(TreeNode* rt) {
    if (rt == nullptr) return 0; // Nothing to count
    return 1 + count( rt->left) + count(rt->right);
}