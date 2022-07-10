

Modulo_Expr_Node:: Modulo_Expr_Node (void):
Binary_Expr_Node()
{

}

// Using the visitor pattern to compute called by Eval_Expr_Tree class
void Modulo_Expr_Node :: accept (Expr_Node_Visitor & v)
{
	v.Visit_Modulo_Node (*this);
}

// We have eval which retrieves values and modulos them together
int Modulo_Expr_Node::eval(void)
{
	int n1 = get_left()->eval();
	int n2 = get_right()->eval();
	
	// Check for divide by zero
	if(n2 == 0)
	{
		
	}
	else
	{
		return (n1 % n2);
	}
}

// Each operator is associated with a precedence: same as Divide and Multiply
int Modulo_Expr_Node::op_precedence(void)
{
	return 3;
}
