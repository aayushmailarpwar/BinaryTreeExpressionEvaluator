#ifndef EXPR_TREE
#define EXPR_TREE

#include "Expr_Node.h"

class Expr_Tree
{
	public:
		Expr_Tree();
		~Expr_Tree();
		Expr_Tree (Expr_Node * root);
		void set_root(Expr_Node * root);
		Expr_Node * get_root(void);
		Expr_Node * get_leaf(void);

	private:
		// Top of the tree after computation
		Expr_Node* root;
		// End of the tree
		Expr_Node* leaf;

	
};

#include "Expr_Tree.cpp"


#endif

