#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <assert.h>

typedef struct NodeT {
  int height;
  int size;
  int value;
  struct NodeT* left;
  struct NodeT* right;
} Node;

typedef struct TreeT {
  Node* root;
  int height;
  int size;
} Tree;

Tree* createTree();
void destroyTree(Tree* tree);
Node* createNode();
void destroyNode(Node* node);
Node* insertNode(Node* root, Node* node);
void insert(Tree* tree, int value);
void prefixWalkNode(Node* root, void (*walk) (Node* node));
void infixWalkNode(Node* root, void (*walk) (Node* node));
void postfixWalkNode(Node* root, void (*walk) (Node* node));
void printNode(Node* node);


Tree* createTree() {
  Tree* tree = (Tree*)malloc(sizeof(Tree));
  tree->height = 0;
  tree->size = 0;
  return tree;
}

void destroyTree(Tree* tree) {
  postfixWalkNode(tree->root, destroyNode);
  free(tree);
}

Node* createNode(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->left = NULL; 
  node->right = NULL;
  node->height = 1;
  node->size = 1;
  return node;
}

void destroyNode(Node* node) {
  free(node);
}

int calcSize1Level(Node* node) {
  if (node->left && node->right) {
    return 1 + node->left->height + node->right->height;
  }
  if (node->left) {
    return 1 + node->left->size;
  }
  if (node->right) {
    return 1 + node->right->size;
  }

  return 1;
}

int calcHeight1Level(Node* node) {
  if (node->left && node->right) {
    return 1 + (node->left->value < node->right->value)? node->right->height : node->left->height;
  }
  if (node->left) {
    return 1 + node->left->height;
  }
  if (node->right) {
    return 1 + node->right->height;
  }

  return 1;
}

Node* insertNode(Node* root, Node* node) {
  if (!root) 
    return node;
  if (node->value <= root->value) {
    root->left = insertNode(root->left, node);
  } else {
    root->right = insertNode(root->right, node);
  }
  root->height = calcHeight1Level(root);
  root->size = calcSize1Level(root);

  return root;
}

void insert(Tree* tree, int value) {
  Node* newNode = createNode(value);
  tree->root = insertNode(tree->root, newNode);
  tree->height = tree->root->height;
  tree->size = tree->root->size;
}

void prefixWalkNode(Node* root, void (*walk) (Node* node)) {
  if (root == NULL) return;
  walk(root);
  prefixWalkNode(root->left, walk);
  prefixWalkNode(root->right, walk);
}

void infixWalkNode(Node* root, void (*walk) (Node* node)) {
  if (root == NULL) return;
  infixWalkNode(root->left, walk);
  walk(root);
  infixWalkNode(root->right, walk);
}

void postfixWalkNode(Node* root, void (*walk) (Node* node)) {
  if (root == NULL) return;
  postfixWalkNode(root->left, walk);
  postfixWalkNode(root->right, walk);
  walk(root);
}

Node* find(Node* node, int value) {
  if (!node) return NULL;
  if (node->value == value) return node;
  Node* found;
  found = find(node->left, value);
  if (found) return found;
  return find(node->right, value);
}

void printNode(Node* node) {
  printf("%d ", node->value);
}

int main(void) {
  Tree* tree = createTree();
  insert(tree, 4);
  insert(tree, 1);
  insert(tree, 5);
  insert(tree, 2);
  insert(tree, 0);
  insert(tree, 9);
  insert(tree, 2);
  insert(tree, 3);
  insert(tree, 1);
  insert(tree, 8);

  prefixWalkNode(tree->root, printNode);
  putchar('\n');
  infixWalkNode(tree->root, printNode);
  putchar('\n');
  postfixWalkNode(tree->root, printNode);
  putchar('\n');

  assert(find(tree->root, 5));
  assert(find(tree->root, 1));
  assert(find(tree->root, 8));

  assert(!find(tree->root, 1008));
  assert(!find(tree->root, -18));

  destroyTree(tree);
  return 0;
}

