// This is the main tree where the tree
Expr_Tree::Expr_Tree():
root(nullptr)
{

}

Expr_Tree::Expr_Tree(Expr_Node* root):
root(root)
{
	
}	

// Check if empty tree, close it up
Expr_Tree::~Expr_Tree()
{
	if(root != nullptr)
	{
		delete root;
	}
}

// Setting the top most root to the value in the argument
void Expr_Tree:: set_root(Expr_Node* root)
{
	root = root;
}
// Returning the top most root to the value
Expr_Node* Expr_Tree:: get_root()
{
	return this->root;
}

Expr_Node* Expr_Tree:: get_leaf()
{
        return this->leaf;
}

