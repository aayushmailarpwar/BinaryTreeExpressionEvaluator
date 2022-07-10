#ifndef EXPR_BUILDER_H
#define EXPR_BUILDER_H

#include "Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulo_Expr_Node.h"
#include "Number_Node.h"

class Expr_Builder
{
	public:
		
		Expr_Builder(void);
	
		// All the functions below are PURE VIRTUAL FUNCTIONS
		virtual ~Expr_Builder(void) = 0;
		virtual void start_expression(void) = 0;
		virtual void build_number (int n) = 0;
		virtual void build_add_operator (void) = 0;
		virtual void build_subtract_operator (void) = 0;
		virtual void build_multiply_operator (void) = 0;
		virtual void build_divide_operator (void) = 0;
		virtual void build_modulo_operator (void) = 0;
		virtual void build_open_parenthesis (void) = 0;
		virtual void build_close_parenthesis (void) = 0;

};


#include "Expr_Builder.cpp"

#endif
