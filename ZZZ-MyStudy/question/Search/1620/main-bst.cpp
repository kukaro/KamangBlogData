#include <iostream>
#include <cctype>

using namespace std;

int N, M;
int deb;

class Node {
public:
    string name;
    int num;
    Node *left;
    Node *right;

    Node(string name, int num) : name(name), num(num) {
        left = nullptr;
        right = nullptr;
    };
};

class BSTName {
public:
    Node *root;

    BSTName() {
        root = nullptr;
    }

    Node *search(string name) {
        return search_in(root, name);
    }

    void insert(Node *n) {
        //cout<<deb++<<endl;
        if (root == nullptr) {
            root = n;
        } else {
            insert_in(root, n);
        }
    }

    void pre_order() {
        cout << "**********" << endl;
        pre_order_in(root);
        cout << "**********" << endl;
    }

private:
    Node *search_in(Node *n, string name) {
        //cout<<deb++<<endl;
        if (n == nullptr) {
            return nullptr;
        }
        if (name.compare(n->name) < 0) {
            return search_in(n->left, name);
        } else if (name.compare(n->name) > 0) {
            return search_in(n->right, name);
        } else {
            return n;
        }
    }

    void insert_in(Node *n, Node *p) {
        if (p->name.compare(n->name) <= 0) {
            if (n->left == nullptr) {
                n->left = p;
            } else {
                insert_in(n->left, p);
            }
        } else if (p->name.compare(n->name) > 0) {
            if (n->right == nullptr) {
                n->right = p;
            } else {
                insert_in(n->right, p);
            }
        }
    }

    void pre_order_in(Node *n) {
        if (n == nullptr) {
            return;
        }
        cout << n->name << ":" << n->num << endl;
        pre_order_in(n->left);
        pre_order_in(n->right);
    }
};

class BSTNumber {
public:
    Node *root;

    BSTNumber() {
        root = nullptr;
    }

    Node *search(int num) {
        return search_in(root, num);
    }

    void insert(Node *n) {
        //cout<<deb++<<endl;
        if (root == nullptr) {
            root = n;
        } else {
            insert_in(root, n);
        }
    }

    void pre_order() {
        cout << "**********" << endl;
        pre_order_in(root);
        cout << "**********" << endl;
    }

private:
    Node *search_in(Node *n, int num) {
        //cout<<deb++<<endl;
        if (n == nullptr) {
            return nullptr;
        }
        if (num < n->num) {
            return search_in(n->left, num);
        } else if (num > n->num) {
            return search_in(n->right, num);
        } else {
            return n;
        }
    }

    void insert_in(Node *n, Node *p) {
        if (p->num <= n->num) {
            if (n->left == nullptr) {
                n->left = p;
            } else {
                insert_in(n->left, p);
            }
        } else if (p->num > n->num) {
            if (n->right == nullptr) {
                n->right = p;
            } else {
                insert_in(n->right, p);
            }
        }
    }

    void pre_order_in(Node *n) {
        if (n == nullptr) {
            return;
        }
        cout << n->name << ":" << n->num << endl;
        pre_order_in(n->left);
        pre_order_in(n->right);
    }
};

int main() {
    string tname;
    cin >> N >> M;
    BSTName bstName;
    BSTNumber bstNumber;
    for (int n = 1; n <= N; n++) {
        cin >> tname;
        bstName.insert(new Node(tname, n));
        bstNumber.insert(new Node(tname, n));
    }
    bstName.pre_order();
    bstNumber.pre_order();
//    for (int m = 1; m <= M; m++) {
//        cin >> tname;
//        if (isdigit(tname.at(0))) {
//            cout << bstNumber.search(atoi(tname.c_str()))->name << endl;
//        } else {
//            cout << bstName.search(tname)->num << endl;
//        }
//    }
    return 0;
}
