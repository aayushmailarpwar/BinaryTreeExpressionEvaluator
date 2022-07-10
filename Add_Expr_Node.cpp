

Add_Expr_Node:: Add_Expr_Node (void):
Binary_Expr_Node()
{

}

// We have eval which retrieves values and adds them together
int Add_Expr_Node::eval(void)
{
	int n1 = get_left() ->eval();
	int n2 = get_right() -> eval();
	return (n1 + n2);
}
// Each operator is associated with a precedence
int Add_Expr_Node::op_precedence(void)
{
	return 2;
}	

// Using the visitor pattern to compute called by Eval_Expr_Tree class
void Add_Expr_Node :: accept (Expr_Node_Visitor & v)
{
	v.Visit_Add_Node (*this);
}
