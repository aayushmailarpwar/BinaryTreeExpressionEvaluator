#include "Expr_Node_Visitor.h"
// We have to implement these functions so Expr_Node is an abstract class with pure virtual functions
Expr_Node::Expr_Node(void)
{
	
}

Expr_Node::~Expr_Node (void)
{

}

Expr_Node * Expr_Node::get_left(void)
{
	return nullptr;
}

Expr_Node * Expr_Node::get_right(void)
{
	return nullptr;
}

void Expr_Node::set_left(Expr_Node * left_node)
{
	
}

void Expr_Node::set_right(Expr_Node * right_node)
{
	
}
