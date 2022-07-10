#ifndef DIV_EXPR_H
#define DIV_EXPR_H

#include "Binary_Expr_Node.h"

class Divide_Expr_Node :public Binary_Expr_Node
{
	public:
		Divide_Expr_Node (void);
		//virtual ~Divide_Expr_Node (void);
		int eval (void);
		int op_precedence(void);
		virtual void accept ( Expr_Node_Visitor & v);
};

#include "Divide_Expr_Node.cpp"

#endif
