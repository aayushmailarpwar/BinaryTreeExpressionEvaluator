

Subtract_Expr_Node:: Subtract_Expr_Node (void):
Binary_Expr_Node()
{

}

// Using the visitor pattern to compute called by Eval_Expr_Tree class
void Subtract_Expr_Node :: accept (Expr_Node_Visitor & v)
{
	v.Visit_Subtract_Node (*this);
}

// We have eval which retrieves values and adds them together
int Subtract_Expr_Node::eval(void)
{
	int n1 = get_left()->eval();
	int n2 = get_right()->eval();
	return (n1 - n2);
}

// Each operator is associated with a precedence
int Subtract_Expr_Node::op_precedence(void)
{
	return 2;
}
