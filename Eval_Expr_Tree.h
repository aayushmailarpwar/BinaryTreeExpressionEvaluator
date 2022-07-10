#ifndef EVAL_EXPR_TREE
#define EVAL_EXPR_TREE
#include <string>
#include <exception>
#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
	public:
		Eval_Expr_Tree (void);
		virtual ~Eval_Expr_Tree (void);
		virtual void Visit_Number_Node (Number_Node & node); 
		virtual void Visit_Add_Node (Add_Expr_Node & node);
		virtual void Visit_Subtract_Node (Subtract_Expr_Node & node);
		virtual void Visit_Multiply_Node (Multiply_Expr_Node & node);
		virtual void Visit_Divide_Node (Divide_Expr_Node & node);
		virtual void Visit_Modulo_Node (Modulo_Expr_Node & node);
		int result (void);

	private:
		int result_;
};		

#include "Eval_Expr_Tree.cpp"


#endif
