#ifndef BIN_EXPR_H
#define BIN_EXPR_H

#include "Expr_Node.h"
#include<string>
#include <iostream>


class Binary_Expr_Node : public Expr_Node
{
	public:
		Binary_Expr_Node (void);
		~Binary_Expr_Node(void);
		
		virtual int eval (void) = 0;

		void set_right(Expr_Node * right_node);
		void set_left(Expr_Node * left_node);
		
		Expr_Node * get_right(void);
		Expr_Node * get_left(void);
		
		virtual void accept (Expr_Node_Visitor & v) = 0;

	protected:
		Expr_Node * left_node_;
		Expr_Node * right_node_;
};

#include "Binary_Expr_Node.cpp"
#endif
