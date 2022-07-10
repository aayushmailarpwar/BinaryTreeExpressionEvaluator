#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
#include "Expr_Node.h"
#include "Expr_Tree.h"
#include "Expr_Builder.h"
#include "Expr_Node_Visitor.h"

class Facade 
{
	public:
		Facade();
	
		~Facade();
	
		void start();
	
		Expr_Tree_Builder * execute(std::string infix);	
		
		void parenthesisEncountered();	
	private:
	Expr_Tree_Builder * buildTree;
};

#include "Facade.cpp"

#endif
