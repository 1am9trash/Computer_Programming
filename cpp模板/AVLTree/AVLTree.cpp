#include <iostream>
using namespace std;

class AVL {
private:
    struct node {
        int data;
        int height;
        node *left;
        node *right;
    };

    node *root;

    node *insert(int data, node *now) {
        if (now == NULL) {
            now = new node;
            now->data = data;
            now->height = 0;
            now->left = NULL;
            now->right = NULL;
        } else if (data < now->data) {
            now->left = insert(data, now->left);
            if (calHeight(now->left) - calHeight(now->right) > 1) {
                if (data < now->left->data) {
                    // LL case
                    now = rRotation(now);
                } else {
                    // LR case
                    now->left = lRotation(now->left);
                    now = rRotation(now);
                }
            }
        } else if (data > now->data) {
            now->right = insert(data, now->right);
            if (calHeight(now->left) - calHeight(now->right) < -1) {
                if (data > now->right->data) {
                    // RR case
                    now = lRotation(now);
                } else {
                    // RL case
                    now->right = rRotation(now->right);
                    now = lRotation(now);
                }
            }
        }
        now->height = max(calHeight(now->left), calHeight(now->right)) + 1;
        return now;
    }

    node *remove(int data, node *now) {
        if (now == NULL) {
            return NULL;
        }
        if (data > now->data) {
            now->right = remove(data, now->right);
        } else if (data < now->data) {
            now->left = remove(data, now->left);
        } else {
            node *temp;
            if (now->left != NULL && now->right != NULL) {
                temp = findMin(now->right);
                now->data = temp->data;
                now->right = remove(now->data, now->right);
            } else {
                temp = now;
                if (now->left != NULL) {
                    now = now->left;
                } else if (now->right != NULL) {
                    now = now->right;
                } else {
                    now = NULL;
                }
                delete temp;
            }
        }

        if (now == NULL) {
            return NULL;
        }
        now->height = max(calHeight(now->left), calHeight(now->right)) + 1;

        if (calHeight(now->left) - calHeight(now->right) > 1) {
            if (calHeight(now->left->left) - calHeight(now->left->right) >= 0) {
                // LL case
                now = rRotation(now);
            } else {
                // LR case
                now->left = lRotation(now->left);
                now = rRotation(now);
            }
        } else if (calHeight(now->left) - calHeight(now->right) < -1) {
            if (calHeight(now->right->left) - calHeight(now->right->right) <= 0) {
                // RR case
                now = lRotation(now);
            } else {
                // RL case
                now->right = rRotation(now->right);
                now = lRotation(now);
            }
        }
        return now;
    }

    int calHeight(node *now) {
        if (now == NULL) {
            return -1;
        }
        return now->height;
    }

    node *lRotation(node *now) {
        node *temp = now->right;
        now->right = temp->left;
        temp->left = now;
        now->height = max(calHeight(now->left), calHeight(now->right)) + 1;
        temp->height = max(calHeight(temp->left), calHeight(temp->right)) + 1;
        return temp;
    }

    node *rRotation(node *now) {
        node *temp = now->left;
        now->left = temp->right;
        temp->right = now;
        now->height = max(calHeight(now->left), calHeight(now->right)) + 1;
        temp->height = max(calHeight(temp->left), calHeight(temp->right)) + 1;
        return temp;
    }

    node *findMin(node *now) {
        if (now == NULL) {
            return NULL;
        }
        if (now->left == NULL) {
            return now;
        }
        return findMin(now->left);
    }

    node *findMax(node *now) {
        if (now == NULL) {
            return NULL;
        }
        if (now->right == NULL) {
            return now;
        }
        return findMax(now->right);
    }

    void inOrder(node *now) {
        if (now == NULL) {
            return;
        }
        inOrder(now->left);
        cout << now->data << " ";
        inOrder(now->right);
    }

public:
    AVL() {
        root = NULL;
    }

    void insert(int data) {
        root = insert(data, root);
    }

    void remove(int data) {
        root = remove(data, root);
    }

    void inOrder() {
        inOrder(root);
        cout << "\n";
    }
};

int main() {
    AVL t;
    int array[] = {100, 55, 50, 45, 47, 70, 80, 78, 77, 79, 82, 81, 83, 150, 140, 135, 142, 143, 180, 170, 165, 160, 175, 173, 200, 190, 195, 500, 1000, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000};

    for (int i = 0; i < 38; i++) {
        t.insert(array[i]);
    }
    cout << "insertion done"
         << "\n";

    t.remove(45);
    t.remove(47);
    t.remove(50);
    t.remove(55);
    t.remove(70);
    t.remove(77);
    t.remove(78);
    t.remove(79);
    t.remove(80);
    t.remove(81);
    t.remove(82);
    t.remove(83);
    t.remove(100);
    t.remove(135);
    t.remove(140);
    t.inOrder();

    return 0;
}
