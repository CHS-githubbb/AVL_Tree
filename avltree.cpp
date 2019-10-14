#include"avltree.hpp"
#include<iostream>
using namespace std;

int AVL_Tree::height(AVLnode * & t) {
	return ((t == nullptr) ? -1 : t->height);
}


void AVL_Tree::balance(AVLnode * & t) {
	if (t == nullptr)
		return;

	if (height(t->left) - height(t->right) > ALLOWED_BALABCE)
		if (height(t->left->left) >= height(t->left->right))
			rotate_with_leftchild(t);
		else
			double_with_rightchild(t);
	else if (height(t->right) - height(t->left) > ALLOWED_BALABCE)
		if (height(t->right->right) >= height(t->right->left))
			rotate_with_rightchild(t);
		else
			double_with_leftchild(t);

	t->height = max(height(t->left), height(t->right)) + 1;
}


void AVL_Tree::rotate_with_leftchild(AVLnode * & k2) {
	auto k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->left), height(k2->right)) + 1;

	k2 = k1;
}
//void AVL_Tree::double_with_leftchild(AVLnode * & k3) {
//	auto k1 = k3->left;
//	auto k2 = k1->right;
//	k1->right = k2->left;
//	k3->left = k2->right;
//	k2->left = k1;
//	k2->right = k3;
//	k1->height = max(height(k1->left), height(k1->right)) + 1;
//	k2->height = max(height(k2->left), height(k2->right)) + 1;
//	k3->height = max(height(k3->left), height(k3->right)) + 1;
//	k3 = k2;
//}

void AVL_Tree::double_with_leftchild(AVLnode * & k3) {
	rotate_with_rightchild(k3->left);
	rotate_with_leftchild(k3);
}

void AVL_Tree::rotate_with_rightchild(AVLnode * & k2) {
	auto k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->left), height(k2->right)) + 1;

	k2 = k1;
}

void AVL_Tree::double_with_rightchild(AVLnode * & k3) {
	rotate_with_leftchild(k3->right);
	rotate_with_rightchild(k3);
}


AVL_Tree::AVLnode * AVL_Tree::find_min(AVLnode * & t) {
	if (t == nullptr)
		return nullptr;
	else if (t->left == nullptr)
		return t;
	else
		return find_min(t->left);
}

void AVL_Tree::insert(int item, AVLnode * & t) {
	if (t == nullptr)
		t = new AVLnode(item, nullptr, nullptr);
	else if (item < t->value)
		insert(item, t->left);
	else if (item > t->value)
		insert(item, t->right);

	balance(t);
}


void AVL_Tree::remove(int target, AVLnode * & t) {
	if (t == nullptr)
		return;
	else if (target < t->value)
		remove(target, t->left);
	else if (target > t->value)
		remove(target, t->right);
	else {
		if (t->left != nullptr && t->right != nullptr) {
			t->value = find_min(t->right)->value;
			remove(t->value, t->right);
		}
		else {
			auto save = t;
			t = (t->left) ? t->left : t->right;
			delete save;
		}
	}

	balance(t);
}


void AVL_Tree::tranverse(AVLnode * & t) {
	if (t == nullptr)
		return;
	tranverse(t->left);
	cout << t->value << " ";
	tranverse(t->right);
}


void AVL_Tree::insert(int item) {
	insert(item, root);
}

void AVL_Tree::remove(int target) {
	remove(target, root);
}

void AVL_Tree::tranverse() {
	tranverse(root);
}
