// Default class making our main tree equal to nullptr
// Most important part of calling a tree
Facade::Facade():
buildTree(nullptr)
{

}

// When tree goes out of scope, we are to delete that tree
Facade::~Facade()
{
	if(buildTree != nullptr)
	{
		delete buildTree;
	}
}

// This starts our calculator when the client calls it
void Facade::start ()
{
	
	std::string infix;
	bool continue_ = true;
	
	// Continue until QUIT is typed in
	while(continue_)
	{
		std::getline(std::cin, infix);
		if(infix == "QUIT")
		{
			continue_ = false;
			break;
		}
		
		// If input is not empty
		if(infix != "")
		{
			// Create pointers to newExpression using the Builder pattern
			// Also make the top most root of the tree
			// Create new tree
			Expr_Tree_Builder * newExpression = nullptr;
			Expr_Node * root_expr;
			Expr_Tree * newTree;
			try
			{
				
				// We send the infix expression to be executed 
				// This could possibly lead to an error and therefore it is in
				// the try catch block
				newExpression = execute(infix);
				
				// If there are no exceptions found, I retrieve
				// the tree 
				newTree = newExpression ->get_expression();
				
				// On retrival of the tree, we get the root which is 
				// the highest point of the tree
				root_expr = newTree->get_root();
				
				// Calling all the functions involved in computation
				// by implementing the visitor patterns
				// accept method and result method
				Eval_Expr_Tree compute;
				root_expr->accept(compute);
		                std::cout <<" Answer is : " << compute.result() << std::endl;

			}
			catch(const std::exception& e)
			{
				std::cout << e.what()<<" : Invalid Input" <<std::endl;

			}
		}

		else
		{
			std::cout << "Empty Input Detected" <<std::endl;
		}
	}
}
// COMMENT You should put precedence on the nodes as suggested in assignment 3.
// RESPONSE Removed the op_precedence method and made it a number for each operator
Expr_Tree_Builder * Facade::execute(std::string infix)
{
	//Making a new builder everytime execute is called
	buildTree = new Expr_Tree_Builder();
	
	// Flagging the respective input token by token
	bool isOperator = false;
	bool isOperand = false;
	bool isOpenParenthesis = false;
	bool isCloseParenthesis = false;

	// Create token variable
	std::istringstream input(infix);
	std::string token;
	
	while(!input.eof())
	{
		// Push one by one
		input >> token;
		// Token by token we get the input and we call the respective build methods
		if(token == "+")
		{	
			buildTree->build_add_operator();
			isOperator = true;
		}

		else if(token == "-")
                {
			buildTree->build_subtract_operator();
			isOperator = true;
                }

		else if(token == "*")
                {
			buildTree->build_multiply_operator();
                        isOperator = true;

                }

		else if(token == "/")
                {
			buildTree->build_divide_operator();
                        isOperator = true;

                }

		else if(token == "%")
		{
			buildTree->build_modulo_operator();
                        isOperator = true;

                }	
		else if(token == "(")
                {
                        //buildTree->build_open_parenthesis();
                        isOpenParenthesis = true;

                }
		else if(token == ")")
                {
			// buildTree->build_close_parenthesis();
                        isCloseParenthesis = true;

                }
		else
		{
			// Converting the string to integer
			int number_ = std::stoi(token);
			buildTree->build_number(number_);
			isOperand = true;	
		}
		std::cout <<"This is " << token;
	}
	// return a pointer to the tree
	return buildTree;
}

void Facade::parenthesisEncountered()
{
	// We flag that a new calculator has been created
	//this.newCalc = true;
	// We start the expression for the parenthesis
	//buildTree->start_expression();
		
}
