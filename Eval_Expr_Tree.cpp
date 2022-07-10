
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Modulo_Expr_Node.h"
#include "Number_Node.h"

// Initialize the value to 0
Eval_Expr_Tree::Eval_Expr_Tree(void):
result_(0)
{

}

Eval_Expr_Tree::~Eval_Expr_Tree(void)
{

}

// Get the number and store it into the result 
void Eval_Expr_Tree::Visit_Number_Node (Number_Node &node)
{
	this->result_ = node.get_value();
}

// Here I am getting the right and left node concretely and pushing it into the
// current result data member
//
void Eval_Expr_Tree:: Visit_Add_Node(Add_Expr_Node & node)
{
	// COMMENT: You are not using the visitor pattern correctly.
	// Instead, you have mixed the visitor with the composite version
        // of evaluate. You are to visit the left and right node via the
        // accept method to correctly implement the visitor pattern.
        // (e.g., left->accept (*this))
	
	// RESPONSE: Used the notes and comments to use the visitor pattern correctly

	if((node.get_left() != nullptr) && (node.get_right() != nullptr))
	{		
		node.get_left()->accept(*this);
		int n1_ = this->result_;
		
		node.get_right()->accept(*this);
		int n2_ = this->result_;
		
		this->result_ = n1_ + n2_;
	}	
}

void Eval_Expr_Tree:: Visit_Subtract_Node(Subtract_Expr_Node &node)
{
	// COMMENT: You are not using the visitor pattern correctly.
	// Instead, you have mixed the visitor with the composite version
        // of evaluate. You are to visit the left and right node via the
        // accept method to correctly implement the visitor pattern.
        // (e.g., left->accept (*this))
	
	// RESPONSE: Used the notes and comments to use the visitor pattern correctly 
	if((node.get_left() != nullptr) && (node.get_right() != nullptr))
	{		
		node.get_left()->accept(*this);
		int n1_ = this->result_;
		
		node.get_right()->accept(*this);
		int n2_ = this->result_;
		
		this->result_ = n1_ - n2_;
	}

}
void Eval_Expr_Tree:: Visit_Multiply_Node(Multiply_Expr_Node &node)
{	
	// COMMENT: You are not using the visitor pattern correctly.
	// Instead, you have mixed the visitor with the composite version
        // of evaluate. You are to visit the left and right node via the
        // accept method to correctly implement the visitor pattern.
        // (e.g., left->accept (*this))
	
	// RESPONSE: Used the notes and comments to use the visitor pattern correctly
	
	if((node.get_left() != nullptr) && (node.get_right() != nullptr))
	{		
		node.get_left()->accept(*this);
		int n1_ = this->result_;
		
		node.get_right()->accept(*this);
		int n2_ = this->result_;
		
		this->result_ = n1_ * n2_;
	}

}

// Must check for Divide by zero
void Eval_Expr_Tree:: Visit_Divide_Node(Divide_Expr_Node &node)
{	
	// COMMENT: You are not using the visitor pattern correctly.
	// Instead, you have mixed the visitor with the composite version
        // of evaluate. You are to visit the left and right node via the
        // accept method to correctly implement the visitor pattern.
        // (e.g., left->accept (*this))
	
	// RESPONSE: Used the notes and comments to use the visitor pattern correctly
	if((node.get_left() != nullptr) && (node.get_right() != nullptr))
	{		
		node.get_left()->accept(*this);
		int n1_ = this->result_;
		
		node.get_right()->accept(*this);
		int n2_ = this->result_;
		if (n2_ != 0)
		{			
			this->result_ = n1_ / n2_;
		}
		else
		{
			throw std::invalid_argument("Divide by zero ");

		}	
	}

}

// Must check for divide by zero
void Eval_Expr_Tree:: Visit_Modulo_Node(Modulo_Expr_Node &node)
{
	// COMMENT: You are not using the visitor pattern correctly.
	// Instead, you have mixed the visitor with the composite version
        // of evaluate. You are to visit the left and right node via the
        // accept method to correctly implement the visitor pattern.
        // (e.g., left->accept (*this))
	
	// RESPONSE: Used the notes and comments to use the visitor pattern correctly
	if((node.get_left() != nullptr) && (node.get_right() != nullptr))
	{		
		node.get_left()->accept(*this);
		int n1_ = this->result_;
		
		node.get_right()->accept(*this);
		int n2_ = this->result_;
		if (n2_ != 0)
		{			
			this->result_ = n1_ % n2_;
		}
		else
		{
			throw std::invalid_argument("Divide by zero ");

		}	
	}

}

int Eval_Expr_Tree::result(void)
{
	return this->result_;
}


