#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

class AVL_Tree {
private:
	struct AVLnode {
		int value;
		AVLnode * left;
		AVLnode * right;
		int height;
		AVLnode(int value_, AVLnode * left_, AVLnode * right_, int height_ = 0):
			value(value_), left(left_), right(right_), height(height_){}
	};

	static const int ALLOWED_BALABCE = 1;

	int max(int h1, int h2) { return h1 > h2 ? h1 : h2; };
	int height(AVLnode * & t);
	void balance(AVLnode * & t);
	void rotate_with_leftchild(AVLnode * & k2);
	void double_with_leftchild(AVLnode * & k3);
	void rotate_with_rightchild(AVLnode * & k2);
	void double_with_rightchild(AVLnode * & k3);

	AVLnode * find_min(AVLnode * & t);

	void insert(int item, AVLnode * & t);
	void remove(int target, AVLnode * & t);
	void tranverse(AVLnode * & t);

	AVLnode * root;

public:
	AVL_Tree():root(nullptr){}
	void insert(int item);
	void remove(int target);
	void tranverse();
};

#endif
