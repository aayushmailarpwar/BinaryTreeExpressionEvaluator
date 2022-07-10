#ifndef EXPR_NODE
#define EXPR_NODE


class Expr_Node_Visitor;

class Expr_Node
{
	public:
		Expr_Node (void);
		virtual ~Expr_Node(void);
	
		virtual int eval (void) = 0;
		virtual void accept (Expr_Node_Visitor & v) = 0;
	
		virtual Expr_Node* get_left(void);
		virtual Expr_Node* get_right(void);
		
		virtual void set_left( Expr_Node * left_node);
		virtual void set_right( Expr_Node * right_node);
	
		virtual int op_precedence (void) = 0;
};

#include "Expr_Node.cpp"
#endif
