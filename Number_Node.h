#ifndef NUM_NODE
#define NUM_NODE

#include "Expr_Node.h"

class Number_Node: public Expr_Node
{
	public:
		Number_Node(void);
		Number_Node(int number);
		int op_precedence(void);
		int get_value(void);
		void set_value(int number);
		virtual void accept (Expr_Node_Visitor & v);

	private:
		int number_;
	
};

#include "Number_Node.cpp"

#endif
