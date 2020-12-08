#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree,int root=0,ll mx=LONG_LONG_MAX,ll mn=LONG_LONG_MIN) {
  // Implement correct algorithm here
  if(root==-1 || tree.size()==0) return 1;

	int val = tree[root].key;

  return (tree[root].key>mn && tree[root].key<mx) and IsBinarySearchTree(tree,tree[root].left,val,mn) and IsBinarySearchTree(tree,tree[root].right,mx,val);

}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
