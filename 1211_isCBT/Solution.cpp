#include <iostream>

template<typename T>
class tree {

private:
    struct Node {
        T val;
        Node *left;
        Node *right;

        Node() : left(nullptr), right(nullptr) {}

        Node(T v, Node *L = nullptr, Node *R = nullptr)
                : val(v), left(L), right(R) {}
    };

    Node *root;

    void clear(Node *p) {
        if (p->left != nullptr)clear(p->left);
        if (p->right != nullptr)clear(p->right);
        delete p;
    }

    void NLR(Node *r) {
        if (r) {
            std::cout << r->val << " ";
            NLR(r->left);
            NLR(r->right);
        }
    }

    void LNR(Node *r) {
        if (r) {
            LNR(r->left);
            std::cout << r->val << " ";
            LNR(r->right);
        }
    }

    void LRN(Node *r) {
        if (r) {
            LNR(r->left);
            LNR(r->right);
            std::cout << r->val << " ";
        }
    }

    int depth(Node *r) {
        if (r) {
            int ld = depth(r->right);
            int rd = depth(r->left);
            return (ld > rd) ? (ld + 1) : (rd + 1);
        } else
            return 0;
    }


public:
    tree() : root(nullptr) {};

    tree(T val) : root(new Node(val)) {};

    tree(T val, tree l, tree r) : root(new Node(val, l.root, r.root)) {};

    tree(T val, tree *l, tree *r)
            : root(new Node(val)) {
        if (l) {
            root->left = l->root;
        }
        if (r) {
            root->right = r->root;
        }
    };

    tree(T val, T lval, T rval) :
            root(new Node(val, new Node(lval), new Node(rval))) {};

    void setTree(tree *l, tree *r) {
        if (l) {
            root->left = l->root;
        } else
            root->left = nullptr;
        if (r) {
            root->right = r->root;
        } else
            root->right = nullptr;
    }

    T getVal() const { return root->val; }

    void setVal(T v) { root->val = v; }

    T getRoot() const { return root->val; }

    bool haveLeft() const { return root->left; }

    T getLeft() const { return root->left->val; }

    bool haveRight() const { return root->right; }

    T getRight() const { return root->right->val; }

    void delLeft() {
        Node *temp = root->left;
        root->left = nullptr;
        temp->clear();
    }

    void delRight() {
        Node *temp = root->right;
        root->right = nullptr;
        temp->clear();
    }

    bool isEmpty() const { return root == nullptr; }

    void clear() {
        if (root != nullptr)
            clear(root);
        root = nullptr;
    }

    void NLR() {
        NLR(root);
    }

    void LNR() {
        LNR(root);
    }

    void LRN() {
        LRN(root);
    }

    int Depth() {
        return depth(root);
    }
};

const int max_len = 1e6 + 7;
std::pair<tree<int> *, int> queue[max_len];
int rear = 0, front = 0;
int size, l, r;
std::pair<tree<int> *, int> treeList[max_len] = {{nullptr, 0}};
bool root[max_len] = {true};

int main() {
    std::cin >> size;
    treeList[0] = {nullptr, 0};
    tree<int> *temp = nullptr;
    for (int i = 1; i < size + 1; i++) {
        temp = new tree<int>(i);
        treeList[i].first = temp;
    }

    for (int i = 1; i < size + 1; i++) {
        std::cin >> l >> r;
        treeList[i].first->setTree(treeList[l].first, treeList[r].first);
        root[l] = true;
        root[r] = true;
    }

    int r = 0;
    for (int i = 1; i < size + 1; i++) {
        if (!root[i]) {
            r = i;
        }
    }

    treeList[r].second = 1;
    queue[rear++] = treeList[r];

    while (rear != max_len && rear != front) {
        if (queue[front].first) {
            if (queue[front].first->haveLeft()) {
                queue[rear] = treeList[queue[front].first->getLeft()];
                treeList[queue[rear].first->getVal()].second = treeList[queue[front].first->getVal()].second * 2;
                rear++;
            }
            if (queue[front].first->haveRight()) {
                queue[rear] = treeList[queue[front].first->getRight()];
                treeList[queue[rear].first->getVal()].second = treeList[queue[front].first->getVal()].second * 2 + 1;
                rear++;
            }
        }
        front++;
    }

    if (treeList[queue[rear - 1].first->getVal()].second == size) {
        std::cout << "Y";
    } else {
        std::cout << "N";
    }
    return 0;
}