#ifndef EXPR_TREE_BUILDER
#define EXPR_TREE_BUILDER



// Child class of Expr_Builder
class Expr_Tree_Builder : public Expr_Builder
{
	public:
	
		Expr_Tree_Builder (void);
		~Expr_Tree_Builder (void); 
		
		
		void start_expression (void);
		
		void build_number (int n);
		
		void build_add_operator (void);
		
        	void build_subtract_operator (void);
		
        	void build_multiply_operator (void);
		
        	void build_divide_operator (void);
		
        	void build_modulo_operator (void);
		
	        void build_open_parenthesis (void);
		
	        void build_close_parenthesis (void);
	
		bool findOpening(Expr_Node* starting, Expr_Node* curr_node);
		
		bool addToTree(Expr_Node* newNode);
		
		Expr_Tree * get_expression (void);

	private:
		// This is the tree 
		Expr_Tree *tree_;
};

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulo_Expr_Node.h"
#include "Number_Node.h"

#include "Expr_Tree_Builder.cpp"
#endif
