

Binary_Expr_Node :: Binary_Expr_Node():
left_node_(nullptr),
right_node_(nullptr)	
{
	
}

Binary_Expr_Node :: ~Binary_Expr_Node()
{

	if (left_node_ != nullptr)
	{
		delete left_node_;
	}
	
	if (right_node_ != nullptr)
	{
		delete right_node_;
	}
	
	
}

// Setters for setting up the left and right nodes
void Binary_Expr_Node::set_right (Expr_Node * right_node)
{
	this->right_node_ = right_node;
}

void Binary_Expr_Node::set_left (Expr_Node * left_node)
{
	this->left_node_ = left_node;
}

// Getters for getting the left and right nodes
Expr_Node* Binary_Expr_Node::get_right(void)
{
	return right_node_;
}


Expr_Node* Binary_Expr_Node::get_left(void)
{
	return left_node_;
}



