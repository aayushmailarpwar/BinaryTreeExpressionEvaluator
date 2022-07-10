#ifndef MUL_EXPR_H
#define MUL_EXPR_H

#include "Binary_Expr_Node.h"

class Multiply_Expr_Node :public Binary_Expr_Node
{
	public:
		Multiply_Expr_Node (void);
		//virtual ~Multiply_Expr_Node (void);
		int eval(void);
		int op_precedence(void);
		virtual void accept ( Expr_Node_Visitor & v);
};


#include "Multiply_Expr_Node.cpp"

#endif
