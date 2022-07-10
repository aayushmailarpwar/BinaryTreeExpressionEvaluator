
// Setting current tree to nullptr
Expr_Tree_Builder::Expr_Tree_Builder(void):
tree_(nullptr)
{
	// Make a new tree
	start_expression();
}

Expr_Tree_Builder:: ~Expr_Tree_Builder (void)
{
	if(tree_ != nullptr)
	{
		delete tree_;
	}		
}

// Create a new Tree
void Expr_Tree_Builder :: start_expression (void)
{
	this->tree_ = new Expr_Tree();
	
}

// The next 5 methods build the operator node and add it to the 
// tree without showing the client what is going on in the process
// of building a new node.
void Expr_Tree_Builder:: build_number(int n)
{
	// We build a new Number Node here to push onto the tree
	Number_Node* newNode = new Number_Node(n);				
	addToTree(newNode);

}

void Expr_Tree_Builder:: build_add_operator(void)
{
	Add_Expr_Node* newNode = new Add_Expr_Node();
	addToTree(newNode);
}

void Expr_Tree_Builder:: build_subtract_operator(void)
{
	Subtract_Expr_Node* newNode = new Subtract_Expr_Node();
	addToTree(newNode);

}

void Expr_Tree_Builder:: build_multiply_operator(void)
{
	Multiply_Expr_Node* newNode = new Multiply_Expr_Node();
	addToTree(newNode);

}

void Expr_Tree_Builder:: build_divide_operator(void)
{
	 Divide_Expr_Node* newNode = new Divide_Expr_Node();
	 addToTree(newNode);
	
}

void Expr_Tree_Builder:: build_modulo_operator(void)
{
	 Modulo_Expr_Node* newNode = new Modulo_Expr_Node();
	 addToTree(newNode);

}

// When we encounter an open parenthesis, we start up a new calculator
// by calling the Facade class and we therefore need to push a new builder for it
// I have commented due to it not working and blocking my program from doing 5 + 4
void Expr_Tree_Builder::build_open_parenthesis(void)
{
	//Expr_Tree_Builder* sub_tree = new Expr_Tree_Builder();
	//Facade * sub_calculator = new Facade(sub_tree);
	// Call the helper function in the Facade class
	// stating that a parenthesis is encountered, 
	// please start and new Calculator and do everything
	// as being told
	//sub_calculator->parenthtesisEncountered();	
}

void Expr_Tree_Builder::build_close_parenthesis()
{
	//int sub_result = sub_calculator->result();
	//delete sub_calculator;
	//delete sub_Tree;
	//build_number(sub_result);
	
}


bool Expr_Tree_Builder:: addToTree(Expr_Node * newNode)
{
	// Nodes for the left and right
	Expr_Node * left_node;
	Expr_Node * right_node;
	Expr_Node * starting;
	bool added_to_tree = false;
	
	// If this is first number then add to root
	// If this is leaf number then add to root
	// set the right node and set the left node accordingly
	// We must consider if the node has been set to something or
	// not and execute the function accordingly using the precedence rules
	try
	{	
		// If the newNode has the lowest precedence
		// 1 - Number 
		if(newNode->op_precedence() == 1)
		{	
			// if root is not set, set the root
			// and return true stating that adding is done
			if(this->tree_->get_root() == nullptr)
			{	
				this->tree_->set_root(newNode);
				return true;
			}
			// If root is already set, find an available position in the tree
			else
			{
				added_to_tree = findOpening (this->tree_->get_root(), newNode);
				return added_to_tree;
			}		
		
		}
		// Else higher precedence including add, sub, mul, div, mod
		else
		{	
			// If the roots prec is still low
			if(this->tree_->get_root()->op_precedence() == 1)
			{	
				// swap nodes so that tree has correct precedence
				left_node = this->tree_->get_root();
				this->tree_ ->set_root(newNode);
				tree_->get_root()->set_left(left_node);
			}
			// If lower/equal prec exists, then change the root node if left is null
			else if((newNode->op_precedence() <= this->tree_->get_root()->op_precedence()) && (newNode->get_left() == nullptr))
			{
				// Again we use the swap algorithm
				// by putting root into left and then replacing root 
				// with current node and setting left with original root
				left_node = this->tree_->get_root();
				this->tree_->set_root(newNode);
				this->tree_->get_root()->set_left(left_node);
			}
			// Else: higher precednence or left is not null
			else
			{
				if((this->tree_->get_root()->get_right() != nullptr) && (newNode->get_left() == nullptr))
				{
					// Swap nodes with root
					right_node = this->tree_->get_root()->get_right();
					this->tree_->get_root()->set_right(newNode);
					this->tree_->get_root()->get_right()->set_left(right_node);
				}	
				else if (newNode->get_left() == nullptr)
				{
					this->tree_->get_root()->set_right(newNode);
				}
				// When the sub expression's head is trying be added
				else
				{
					starting = this->tree_->get_root();
					while((starting->get_right() != nullptr) && (starting->op_precedence() != 1))
					{
						starting = starting->get_right();
					}	
					if(starting->get_right() == nullptr)
					{
						starting->set_right(newNode);
					}
					// Not doable
					else
					{
						return false;
					}	
					
				}	
			}	
			
		}		
	}
	catch(...)
	{
		
	}		
		
	return added_to_tree;	
	
}

// Using the precendence of each class, we want to match the insertion of the node
// either on the left or right and while traversing, we must check if it is open
bool Expr_Tree_Builder::findOpening(Expr_Node * starting, Expr_Node * curr_node)
{
	bool continue_ = false;
	// If lowest precedence, then set the right node with the current node
	if(starting->op_precedence() == 1)
	{
		if((starting->get_right() == nullptr) && (!continue_))
		{
			starting->set_right(curr_node);
			return true;
		}
		// But then if left is empty, set the left		
		if((starting->get_left() == nullptr) && (!continue_))
		{			
			starting->set_left(curr_node);
			return true;
		}
		// If the right is empty, then use recursion to see what we can do with the right 
		// node and current nodes placement
		if(starting->get_right() != nullptr && !continue_)
		{	
			continue_ = findOpening(starting->get_right(),curr_node);
		}
		// But now we have left occupied
		if((starting->get_left()) != nullptr && (!continue_))
		{
			// Again find an opening and iterate recursively	
			continue_ = findOpening(starting->get_left(),curr_node);
		}
	}
	return false;
}	

// Called by the Facade class
Expr_Tree * Expr_Tree_Builder::get_expression(void)
{
	return this->tree_;
}
