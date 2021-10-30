#include <iostream>
#include <vector>
#include <random>

using namespace std;

random_device rd;
mt19937 rnd(rd());

struct Node {
   int size;
   int value;
   int priority;
   Node* left;
   Node* right;

   Node(int val) {
       size = 1;
       value = val;
       priority = rnd();
       left = right = 0;
   }
};

int size(Node* root) {
   if (root) {
       return root->size;
   }
   return 0;
}

void relax(Node* root) {
   if (root) {
       root->size = size(root->left) + size(root->right) + 1;
   }
}

pair<Node*, Node*> split(Node* root, int k) {
   if (!root) {
       return {0, 0};
   }
   if (k == 0) {
       return {0, root};
   }
   if (size(root->left) >= k) {
       auto [left_res, right_res] = split(root->left, k);
       root->left = right_res;
       relax(root);
       return {left_res, root};
   } else {
       auto [left_res, right_res] = split(root->right, k - size(root->left) - 1);
       root->right = left_res;
       relax(root);
       return {root, right_res};
   }
}

Node* merge(Node* left, Node* right) {
   if (!left) {
       return right;
   }
   if (!right) {
       return left;
   }
   if (left->priority > right->priority) {
       left->right = merge(left->right, right);
       relax(left);
       return left;
   } else {
       right->left = merge(left, right->left);
       relax(right);
       return right;
   }
}

Node* build_treap(int n) {
   Node* root = 0;
   for (int i = 0; i < n; ++i) {
       auto node = new Node(i + 1);
       root = merge(root, node);
   }
   return root;
}

Node* move_soldiers(int l, int r, Node* root) {
   auto [left, mid0] = split(root, l - 1);
   auto [mid, right] = split(mid0, r - l + 1);
   return merge(mid, merge(left, right));
}

void print(Node* root) {
   if (root->left) {
       print(root->left);
   }
   cout << root->value << " ";
   if (root->right) {
       print(root->right);
   }
}

int main() {
   freopen("movetofront.in", "r", stdin);
   freopen("movetofront.out", "w", stdout);
   int n, m;
   cin >> n >> m;
   auto treap = build_treap(n);
   for (int i = 0; i < m; ++i) {
       int l, r;
       cin >> l >> r;
       treap = move_soldiers(l, r, treap);
   }
   print(treap);
   cout << endl;
}