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
T	2	|	
R	3	|	
F	4	|	


*/
//------------------------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//table of the language
	//the starting state is 0
	string table[5][8] = { { "QT","~","~","~","~","QT","~","~" },{ "~","QT+","QT-","~","~","~","L","L" },{ "RF","~","~","~","~","RF","~","~" },{ "~","L","L","RF*","RF-","~","L","L" },{ "i","~","~","~","~",")E(","~","~" } };
	
	char again;
	do {
		string w, stack = "$E";		//w will hold the string of the individual words to check
		//char pop;
		cout << "Enter a equation ending with '$' i.e. (i+i)*i$ : "; cin >> w;
		//loop through the words in the text file

			//initialize values		
		int i = 0, col, state = 0;
		//will loop through the letters in the word until it encounters a '$'
		while (w[i] != '$')
		{
			//print the word letter by letter to prevent printing the '$' at the end
			cout << "\nRead: " << w[i] << endl;
			cout << "Stack\tPoped\tPushed\n";
			cout << stack << "\t";
			//pop = stack.back();		// set pop to last char
			//stack.pop_back();		// remove last char
			cout << stack.back() << "\t";
			while (stack.back() != w[i]) {
				if (stack.back() != 'L') {
					switch (stack.back()) {		// converts char to integer
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
					cout << table[state][col] << "\n";
					stack.pop_back();
					stack += table[state][col];
					cout << stack << "\t";
				}
				
				else {
					stack.pop_back();
					cout << endl << stack << '\t'; 
				}

				//pop = stack.back();		// set pop to last char
				//stack.pop_back();		// remove last char
				cout << stack.back() << "\t";
				if (stack.back() == '~')break;
			}
			if (stack.back() == '~')break;
			stack.pop_back();
			
			cout << stack << endl;
			i++;
		}
		//output the result to the user
		if (w[i] != '$' && stack.back() != '$')
			cout << " is not accepted";
		else
			cout << " is accepted";
		
		cout << "\n\nContinue (y/n): "; cin >> again;
	} while (again == 'y');
	//terminate the program
	system("pause");
	return 0;
}
/*-----------------output---------------------
--------------------------------------------*/