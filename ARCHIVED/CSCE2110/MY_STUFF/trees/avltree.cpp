//C++ program to implement an AVL Tree.

#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#define pow2(n) (1 << (n))

using namespace std;

//Node declaration

struct avl_node
{
	int data;
	struct avl_node *left;
	struct avl_node *right;
}*root;

//Class declaration

class avl_tree
{
	public:
		int height(avl_node *);
		int diff(avl_node *);
		avl_node *rr_rotation(avl_node *);
		avl_node *ll_rotation(avl_node *);
		avl_node *lr_rotation(avl_node *);
		avl_node *rl_rotation(avl_node *);
		avl_node* balance(avl_node *);
		avl_node* insert(avl_node *, int);
		void display(avl_node *, int);
		void inorder(avl_node *);
		void preorder(avl_node *);
		void postorder(avl_node *);

		avl_tree()
		{
			root = NULL;
		}
};

//Main

int main(){

	int choice, item;
	avl_tree avl;
	while(1){

		cout << "\n--------------------" << endl;
		cout << "AVL Tree Implementation" << endl;
		cout << "\n--------------------" << endl;
		cout << "1. Insert Element into the tree" << endl;
		cout << "2. Display Balanced AVL Tree" << endl;
		cout << "3. InOrder Traversal" << endl;
		cout << "4. PreOrder Traversal" << endl;
		cout << "5. PostOrder Traversal" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";

		cin  >> choice;

		switch(choice){

		case 1:
			cout << "Enter value to be inserted: ";
			cin  >> item;

			root = avl.insert(root, item);

			break;

		case 2:
			if (root == NULL){

				cout << "Tree is Empty" << endl;
				continue;

			}
			
			cout << "Balanced AVL Tree:" << endl;
			
			avl.display(root, 1);

			break;

		case 3:
			cout << "InOrder Traversal:" << endl;

			avl.inorder(root);

			cout << endl;

			break;

		case 4:
			cout << "PreOrder Traversal:" << endl;

			avl.preorder(root);

			cout << endl;

			break;

		case 5:
			cout << "PostOrder Traversal:" << endl;

			avl.postorder(root);

			cout << endl;

			break;

		case 6:
			exit(1);

			break;

		default:
			cout << "Wrong Choice" << endl;
		}

	}

	return 0;
}


//Height of AVL Tree

int avl_tree::height(avl_node *temp){

	int h = 0;
	if (temp != NULL){

		int l_height = height (temp->left);
		int r_height = height (temp->right);
		int max_height = max (l_height, r_height);
		h = max_height + 1;

	}

	return h;

}

//Height Difference

int avl_tree::diff(avl_node *temp){
	
	int l_height = height (temp->left);
	int r_height = height (temp->right);
	int b_factor = l_height - r_height;

	return b_factor;

}

//Right-Right Rotation

avl_node *avl_tree::rr_rotation(avl_node *parent){

	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;

	return temp;

}

//Left-Left Rotation

avl_node *avl_tree::ll_rotation(avl_node *parent){

	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;

	return temp;

}

//Left-Right Rotation

avl_node *avl_tree::lr_rotation(avl_node *parent){

	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);

	return ll_rotation(parent);

}

//Right-Left Rotation

avl_node *avl_tree::rl_rotation(avl_node *parent){

	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);

	return rr_rotation(parent);

}

//Balancing AVL Tree

avl_node *avl_tree::balance(avl_node *temp){

	int bal_factor = diff(temp);
	if (bal_factor > 1){

		if (diff(temp->left) > 0){

			temp = ll_rotation(temp);

		}
		else{

			temp = lr_rotation(temp);

		}

	}
	else if (bal_factor < -1){

		if (diff(temp->right) > 0){

			temp = rl_rotation(temp);

		}
		else{

			temp = rr_rotation(temp);

		}

	}

	return temp;

}

//Insert Element into the Tree

avl_node *avl_tree::insert(avl_node *root, int value){

	if (root == NULL){

		root = new avl_node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;

	}
	else if (value < root->data){

		root->left = insert(root->left, value);
		root = balance(root);

	}
	else if (value >= root->data){

		root->right = insert(root->right, value);
		root = balance(root);

	}

	return root;
}

//Display AVL Tree

void avl_tree::display(avl_node *ptr, int level){

	int i;
	if (ptr != NULL){

		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root){

			cout << "Root -> ";

		}
		for (i = 0; i < level && ptr != root; i++){//potential problems here

			cout << "	";

		}
		cout << ptr->data;

		display(ptr->left, level + 1);

	}


}

//InOrder Traversal of AVL Tree

void avl_tree::inorder(avl_node *tree){

	if (tree == NULL){

		return;

	}
	inorder(tree->left);

	cout << tree->data << "  ";

	inorder(tree->right);

}

//PreOrder Traversal of AVL Tree

void avl_tree::preorder(avl_node *tree){

	if (tree == NULL){

		return;

	}
	cout << tree->data << "  ";

	preorder(tree->left);

	preorder(tree->right);

}

//PostOrder Traversal of AVL Tree

void avl_tree::postorder(avl_node *tree){

	if (tree == NULL){

		return;

	}
	postorder(tree->left);

	postorder(tree->right);

	cout << tree->data << "  ";

}
