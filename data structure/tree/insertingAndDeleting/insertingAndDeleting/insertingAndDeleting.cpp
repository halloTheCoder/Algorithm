// insertingAndDeleting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

class Tree {
private:
	Tree *left, *right;
	Tree *newNode(int item);
	Tree *minNode(Tree *root);

public:
	int key;
	Tree *root;
	Tree *insertItem(Tree *root,int item);
	Tree *deleteItem(Tree *root, int item);
	void inorder(Tree *root);
	void preorder(Tree *root);
	void postorder(Tree *root);
	Tree *commonAncestor(Tree *root,int num1,int num2);
};

Tree *Tree::commonAncestor(Tree *root, int num1, int num2) {
	if (root == nullptr)
		return nullptr;
	if (root->key < num1 && root->key < num2)
		commonAncestor(root->right,num1,num2);
	if (root->key > num1 && root->key > num2)
		commonAncestor(root->left, num1, num2);
	return root;
}

Tree *Tree::newNode(int item) {
	Tree *temp = new Tree;
	temp->key = item;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

Tree *Tree::insertItem(Tree *root, int item) {
	if (root == nullptr)
		return newNode(item);
	if (root->key > item) {
		root->left = insertItem(root->left, item);
	}
	else if (root->key < item) {
		root->right = insertItem(root->right,item);
	}
	return root;
}

Tree *Tree::minNode(Tree *root) {
	while (root->left != nullptr)
		root = root->left;
	return root;
}

Tree * Tree::deleteItem(Tree * root, int item)
{
	if (root == nullptr)
		return root;
	if (root->key > item)
		root->left = deleteItem(root->left, item);
	else if (root->key < item)
		root->right = deleteItem(root->right, item);
	else {
		if (root->left == nullptr) {
			Tree *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			Tree *temp = root->left;
			delete root;
			return temp;
		}
		Tree *temp = minNode(root->right);
		root->key = temp->key;
		root->right = deleteItem(root->right, temp->key);
	}
	return root;
}

void Tree::inorder(Tree *root) {
	using std::cout;
	if (root == nullptr)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

void Tree::preorder(Tree *root) {
	using std::cout;
	if (root == nullptr)
		return;
	cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
}

void Tree::postorder(Tree *root) {
	using std::cout;
	if (root == nullptr)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->key << " ";
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int n;
	sc(n);
	int *a = new int[n];
	forL(i, n) sc(a[i]);
	Tree t;
	t.root = nullptr;
	t.root = t.insertItem(t.root, a[0]);
	for (int i = 1; i < n; i++)
		t.insertItem(t.root, a[i]);
	cout << "Inorder : ";
	t.inorder(t.root);
	cout << endl;
	cout << "Preorder : ";
	t.preorder(t.root);
	cout << endl;
	cout << "Postorder : ";
	t.postorder(t.root);
	cout << endl;
	
	t.deleteItem(t.root,a[0]);
	
	cout << "Inorder : ";
	t.inorder(t.root);
	cout << endl;
	cout << "Preorder : ";
	t.preorder(t.root);
	cout << endl;
	cout << "Postorder : ";
	t.postorder(t.root);
	cout << endl;

	t.deleteItem(t.root, a[n - 2]);
	
	cout << "Inorder : ";
	t.inorder(t.root);
	cout << endl;
	cout << "Preorder : ";
	t.preorder(t.root);
	cout << endl;
	cout << "Postorder : ";
	t.postorder(t.root);
	cout << endl;
	int num1, num2;
	cout << "Enter num1: ";
	cin >> num1;
	cout << "Enter num2: ";
	cin >> num2;
	cout << (t.commonAncestor(t.root, num1, num2))->key << endl;
	system("pause");
    return 0;
}
