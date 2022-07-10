#ifndef MOD_EXPR_H
#define MOD_EXPR_H

#include "Binary_Expr_Node.h"

class Modulo_Expr_Node :public Binary_Expr_Node
{
	public:
		Modulo_Expr_Node (void);
		//virtual ~Modulo_Expr_Node (void);
		int eval(void);
		int op_precedence(void);
		virtual void accept ( Expr_Node_Visitor & v);
};

#include "Modulo_Expr_Node.cpp"

#endif
