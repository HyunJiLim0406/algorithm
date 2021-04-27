#include <iostream>

using namespace std;

struct Node { //트리의 요소
    int data;
    Node *left;
    Node *right;
};

Node *makeTree(Node *node, int data) {
    if (node == NULL) { //null이면 새로운 트리 노드 생성
        node = new Node();
        node->data = data;
        node->left = node->right = NULL;
    } else if (node->data > data) //작으면 왼쪽 노드로
        node->left = makeTree(node->left, data);
    else //크면 오른쪽 노드로
        node->right = makeTree(node->right, data);
    return node;
}

void postorder(Node *node) {
    if (node->left != NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    cout << node->data << '\n';
}

int main() {
    int input;
    Node *root = NULL; //루트노드

    while (cin >> input) {
        if (input == EOF)
            break;
        root = makeTree(root, input);
    }
    postorder(root);
}