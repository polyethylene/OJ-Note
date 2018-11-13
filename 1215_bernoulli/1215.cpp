#include <iostream>

const int max_len = 32;

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class BTree {
private:
    struct Node {
        int val;
        Node *bro;
        Node *son;

        Node() : val(0), bro(nullptr), son(nullptr) {}

        Node(int v, Node *b = nullptr, Node *s = nullptr)
                : val(v), bro(b), son(s) {}
    };

    Node *TreeList[max_len];

public:
    BTree() {
        for (int i = 0; i < 32; i++) {
            TreeList[i] = nullptr;
        }
    }

    BTree(int v) {
        TreeList[0] = new Node(v);
        for (int i = 1; i < 32; i++) {
            TreeList[i] = nullptr;
        }
    }

    friend Node *mergeNode(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->val > b->val) {
            swap(a, b);
        }
        b->bro = a->son;
        a->son = b;
        return a;
    }

    void merge(BTree &rhs) {
        Node *carry = nullptr;
        for (int i = 0; i < max_len; i++) {
            if (TreeList[i] && rhs.TreeList[i]) {
                Node *temp = mergeNode(TreeList[i], rhs.TreeList[i]);
                TreeList[i] = carry;
                carry = temp;
            } else if (TreeList[i]) {
                if(carry){
                    Node *temp = mergeNode(TreeList[i], carry);
                    TreeList[i] = nullptr;
                    carry = temp;
                }
            } else if (rhs.TreeList[i]) {
                if(carry){
                    Node *temp = mergeNode(rhs.TreeList[i], carry);
                    TreeList[i] = nullptr;
                    carry = temp;
                } else {
                    TreeList[i] = rhs.TreeList[i];
                }
            } else {
                TreeList[i] = carry;
                carry = nullptr;
            }
        }
    }

    std::pair<int, int> findMin() {
        int ans = 0x7fffffff, index;
        for (int i = 0; i < 32; i++) {
            if (TreeList[i] && TreeList[i]->val < ans) {
                ans = TreeList[i]->val;
                index = i;
            }
        }
        return {index, ans};
    }

    void Insert(int v) {
        BTree *temp = new BTree(v);
        merge(*temp);
    }

    void Delete() {
        std::pair<int, int> tar = findMin();
        int index = tar.first;
        BTree temp;
        Node *t = TreeList[index]->son;
        for (int i = index - 1; i >= 0; i--) {
            temp.TreeList[i] = t;
            t = t->bro;
        }
        TreeList[index] = nullptr;
        merge(temp);
    }
};

int size;
char ctrl[10];

int main() {
    std::cin >> size;
    BTree TREE;
    for (int i = 0; i < size; i++) {
        std::cin >> ctrl;
        if (ctrl[0] == 'i') {
            int a;
            std::cin >> a;
            TREE.Insert(a);
        } else if (ctrl[0] == 'd') {
            TREE.Delete();
        } else if (ctrl[0] == 'm') {
            int ret = TREE.findMin().second;
            std::cout << ret << '\n';
        }
    }
    return 0;
}