#ifndef ADD_EXPR_H
#define ADD_EXPR_H

#include "Binary_Expr_Node.h"


class Add_Expr_Node :public Binary_Expr_Node
{
	public:
		Add_Expr_Node (void);
		int eval (void);
		int op_precedence(void);
		virtual void accept ( Expr_Node_Visitor & v);
};

#include "Add_Expr_Node.cpp"

#endif
