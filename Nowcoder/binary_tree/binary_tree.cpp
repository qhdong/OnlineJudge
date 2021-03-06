#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>

// #define ONLINE_JUDGE

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    static string serialize(TreeNode* root);
    static void serialize(TreeNode* root, ostringstream& os);
    static TreeNode* deserialize(string& str);
    static TreeNode* deserialize(istringstream& is);
    static vector<int> preorder(TreeNode* root);
    static vector<int> inorder(TreeNode* root);
    static vector<int> postorder(TreeNode* root);
};

string
Tree::serialize(TreeNode* root) {
    ostringstream os;
    serialize(root, os);
    return os.str();
}

void
Tree::serialize(TreeNode* root, ostringstream& os) {
    if (root) {
        os << root->val << " ";
        serialize(root->left, os);
        serialize(root->right, os);
    } else {
        os << "# ";
    }
}

TreeNode*
Tree::deserialize(string& str) {
    istringstream is(str);
    return deserialize(is);
}

TreeNode*
Tree::deserialize(istringstream& is) {
    string val;
    is >> val;
    if (val != "#") {
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(is);
        root->right = deserialize(is);
        return root;
    } else {
        return nullptr;
    }
}


vector<int>
Tree::preorder(TreeNode* root) {
    vector<int> ret;
    TreeNode* p = root;
    stack<TreeNode*> st;
    while (p || !st.empty()) {
        while (p) {
            ret.push_back(p->val);
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
    return ret;
}

vector<int>
Tree::inorder(TreeNode* root) {
    vector<int> ret;
    auto p = root;
    stack<TreeNode*> st;
    while (p != nullptr || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            st.pop();
            ret.push_back(p->val);
            p = p->right;
        }
    }
    return ret;
}

vector<int>
Tree::postorder(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> st;
    st.push(root);

    TreeNode *cur = nullptr;
    TreeNode *pre = nullptr;

    while (!st.empty()) {
        cur = st.top();
        if ((!cur->left && !cur->right)
        ||  (pre && (pre == cur->left || pre == cur->right))) {
            ret.push_back(cur->val);
            pre = cur;
            st.pop();
        } else {
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
    }

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    string str;
    while (getline(cin, str)) {
        auto root = Tree::deserialize(str);
        cout << Tree::serialize(root) << endl;

        // auto pre = Tree::preorder(root);
        // auto traversal = Tree::inorder(root);
        auto traversal = Tree::postorder(root);
        copy(traversal.begin(), traversal.end(),
                ostream_iterator<int>(cout, " "));
        cout << endl;
    }

#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif

}
