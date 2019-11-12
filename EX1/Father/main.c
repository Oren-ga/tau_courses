/*o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-
		Authors – Oren Ganon 038247508, Gary Berkinfand
		Project – exercise2  - Father
		Description – This is the Son program
		Input from Command-Line text like X+Y or X*Y
		Output : result as exit code
o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o- */


// Includes --------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h> 

#include "main.h"
#include "HardCodedData.h"
#include "stack.h"




typedef struct tokenStruct
{
	tokenType type;
	char      op;
	int       val;
} token;

token getInputToken(FILE *in);



// Function Definitions --------------------------------------------------------



int main(int argc, char* argv[]) // argv is a pointer to the first element in an array of pointers.
{
	//FILE *writing_file;

	char in_text_line[MAX_INPUT_LINE_LEN]; // input line from cmd shell
	char in_text_char = NULL;			   // single char from in_text_line


	struct StackNode* input_number = NULL;   //stack to store the numbers from in_text_line
	struct StackNode* input_operand = NULL;  //stack to store the operand from in_text_line
	int p_text = 0, start_barcket = 0, end_barcket = 0;
	bool  find_bark; // Flag indecate if found barcke or not

	DEBUG_PRINT("DEBUG : start program\n");

	/* command shell  */
	DEBUG_PRINT("DEBUG : Num of Argument=%d", argc);

	/* First argument is executable name only */
	DEBUG_PRINT("DEBUG : Exe name=%s\n", argv[0]);

	/* Secand argument is input data - math-argument */
	DEBUG_PRINT("DEBUG : Argument#1 = %s\n", argv[1]);

	/* check for : valid number of argument in cmd line */
	if (argc > VALID_NUM_ARGUMENTS)
	{
		printf("\nERROR: too many arguments in cmd-shell  (father ");
		return STATUS_CODE_FAILURE;
	}


	// strncpy to char array in_text_line
	strcpy_s(in_text_line, MAX_INPUT_LINE_LEN, argv[1]);
	in_text_char = in_text_line[p_text];



	while ('\0' != in_text_char)
	{
		//printf("\nchar : %c ", in_text_line[p_text]);

		while (isspace(in_text_char)) // progress the text index pointer while we have space
		{
			p_text++;
		}

		if ('(' == in_text_char)
		{
			find_bark = FALSE;
			end_barcket = p_text;

			p_text++;
			in_text_char = in_text_line[p_text];

		}
		else if (')' == in_text_char)
		{
			find_bark = FALSE;
			end_barcket = p_text;

			p_text++;
			in_text_char = in_text_line[p_text];

		}
		else if ('*' == in_text_char || '+' == in_text_char)
		{
			push(&input_operand, in_text_char);
			find_bark = TRUE;
			start_barcket = p_text;

			p_text++;
			in_text_char = in_text_line[p_text];

		}
		else
		{
			int value = 0;
			int *p = NULL;
			while (isdigit(in_text_char))
			{
				value = value * 10 + in_text_char - '0';
				p_text++;
				in_text_char = in_text_line[p_text];


			}
			p = &value;
			push(&input_number, value);


		}





	}



	printf("\n\n input_number list is \n");

	display(&input_number);

	printf("\n\n input_operand list is \n");

	display(&input_operand);

	printf("\n\n pop .....%d \n", pop(&input_number));
	printf("\n\n input_number list is \n");

	display(&input_number);


	/*printf("\n\n Integer linked list is \n");
	printList(input_number, printInt);

	printf("\n\n Char linked list is \n");
	printList(input_operand, printInt);*/

	//	/* check for a ? for quit */
	//	if ('?' == ch)
	//	{
	//		rettoken.type = help;
	//		return rettoken;
	//	}

	//	/* check for the newline */
	//	if ('\n' == ch)
	//	{
	//		rettoken.type = eoln;
	//		return rettoken;
	//	}

	//	/* check for an operator: + - * / ( ) */
	//	if (('+' == ch) || ('-' == ch) || ('*' == ch) ||
	//		('/' == ch) || ('(' == ch) || (')' == ch))
	//	{
	//		rettoken.type = operator;
	//		rettoken.op = ch;
	//		return rettoken;
	//	}

	//	/* check for a number */

	//
	//
	//
	//
	//}



	//printf("Popped %d from s1\n", *((int *)pop(&s1)));

	//Opening the file to write data to Computation.tx, if file already exisit we overied it
/*
	writing_file = fopen("txt.C" "w");
	if (writing_file == NULL) //if there is an error
	{
		printf("Error opening writing\n");
		exit(-1);
	}
	*/

	// clean up 

	destroy(&input_number);   // Destroy and release memory for stack\linked list 
	destroy(&input_operand);  // Destroy and release memory for stack\linked list 



	DEBUG_PRINT(("DEBUG : end program\n"));
	return 0;
}


token getInputToken(FILE *in)
{
	token retToken;
	retToken.type = OPERATOR; // QUIT;

	int ch;
	ch = getc(in);
	if (ch == EOF)
		return retToken;


	/* else token is invalid */
	retToken.type = ERROR;
	return retToken;



}
