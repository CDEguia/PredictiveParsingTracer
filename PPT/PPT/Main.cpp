//------------------------------------------------------------------------------------------
//          Name		Jeremy Driesler & Candelario "Daniel" Eguia
//          Course		CMPS-455
//          Project		No. 8
//			Part		No. 1
//          Due date	Mar. 15, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
//       The trace of the input string and shows content of the stack after each match.
/*				/any other letter always goes to the non-inclusion state

-----------------Table---------------
states	|	i	+	-	*	/	(	)	$
E	0	|	TQ					TQ			
Q	1	|		
T	2	|	4	0	0	0	0	4	0	0
R	3	|	0	9	9	5	6	0	9	9
F	4	|	7	0	0	0	0	8	0	0


*/
//------------------------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//table of the language
	//the starting state is 0
	string table[5][8] = { { "TQ",0,0,0,0,"TQ",0,0 },{ 0,"+TQ","-TQ",0,0,0,"L","L" },{ "FR",0,0,0,0,"FR",0,0 },{ 0,"L","L","*FR","-FR",0,"L","L" },{ "i",0,0,0,0,"(E)",0,0 } };
	//w will hold the string of the individual words to check
	string w, stack = "$0";
		char pop;
	cout << "Enter a equation ending with '$' i.e. (i+i)*i$ : "; cin >> w;
	//loop through the words in the text file
	
		//initialize values		
		int i = 0, col, state = 0;
		//will loop through the letters in the word until it encounters a '$'
		while (w[i] != '$')
		{
			//print the word letter by letter to prevent printing the '$' at the end
			cout << w[i];
			pop = stack.back();		// set pop to last char
			stack.pop_back();		// remove last char
			while (pop != w[i]) {
				switch (pop) {		// converts char to integer
				case 'E':state = 0; break;	
				case 'Q':state = 1; break;
				case 'T':state = 2; break;
				case 'R':state = 3; break;
				case 'F':state = 4; break;
				}
				
				switch (w[i])
				{
				case 'i':col = 0; break;
				case '+':col = 1; break;
				case '-':col = 2; break;
				case '*':col = 3; break;
				case '/':col = 4; break;
				case '(':col = 5; break;
				case ')':col = 6; break;
				case '$':col = 7; break;
				default: col = 8;		//is used for any letter not in the lanuage
				}
				//move to the new state
				stack += table[state][col];
				pop = stack.back();		// set pop to last char
				stack.pop_back();		// remove last char
			}
			cout << stack;
			i++;
		}
		//output the result to the user
		if (state == 4)
			cout << " is not accepted\n";
		else
			cout << " is accepted\n";

	//terminate the program
	system("pause");
	return 0;
}
/*-----------------output---------------------
--------------------------------------------*/