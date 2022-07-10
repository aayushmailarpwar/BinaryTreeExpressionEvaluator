#ifndef EXPR_NODE_VISIT
#define EXPR_NODE_VISIT
#include <iostream>


class Expr_Node_Visitor
{
	public:
			Expr_Node_Visitor(void);			
		virtual ~Expr_Node_Visitor (void);
		virtual void Visit_Add_Node (Add_Expr_Node & node) = 0;
		virtual void Visit_Number_Node (Number_Node & node) = 0;
		virtual void Visit_Subtract_Node (Subtract_Expr_Node & node) = 0;
		virtual void Visit_Multiply_Node (Multiply_Expr_Node & node) = 0;
		virtual void Visit_Divide_Node (Divide_Expr_Node & node) = 0;
		virtual void Visit_Modulo_Node (Modulo_Expr_Node & node) = 0;
	

};

// This is to get rid of the forward declarations during compile time
class Expr_Node;
class Binary_Expr_Node;
class Add_Expr_Node;
class Subtract_Expr_Node;
class Multiply_Expr_Node;
class Divide_Expr_Node;
class Modulo_Expr_Node;
class Number_Node;



#include "Expr_Node_Visitor.cpp"

#endif
