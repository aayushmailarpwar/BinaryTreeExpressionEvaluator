

Number_Node::Number_Node()
{

}

Number_Node::Number_Node(int number):
number_(number)
{
	
}	
// Setter
void Number_Node::set_value(int number)
{
	this->number_ = number;	
}

// Lowest precedence
int Number_Node::op_precedence(void)
{
	return 1;	
}	

// Getter
int Number_Node::get_value(void)
{
	return number_;	
}

// Using the Visitor pattern to visit the Node
void Number_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Number_Node(*this);
}
