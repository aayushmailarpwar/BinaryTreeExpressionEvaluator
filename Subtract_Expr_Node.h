#ifndef SUB_EXPR_H
#define SUB_EXPR_H

#include "Binary_Expr_Node.h"

class Subtract_Expr_Node :public Binary_Expr_Node
{
	public:
		Subtract_Expr_Node (void);
		//virtual ~Subtract_Expr_Node (void);
		int eval(void);
	
		int op_precedence(void);
		virtual void accept ( Expr_Node_Visitor & v);
};

#include "Subtract_Expr_Node.cpp"

#endif
