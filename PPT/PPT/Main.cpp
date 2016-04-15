//------------------------------------------------------------------------------------------
//          Name		Jeremy Driesler & Candelario "Daniel" Eguia
//          Course		CMPS-455
//          Project		No. 8
//			Part		No. 1
//          Due date	Mar. 15, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
/*	The trace of the input string and shows content of the stack after each match.
-----------------Table---------------
states	|	i	+	-	*	/	(	)	$
E	0	|	TQ	~	~	~	~	TQ	~	~	
Q	1	|	~	+TQ	-TQ	~	~	~	L	L
T	2	|	FR	~	~	~	~	FR	~	~
R	3	|	~	L	L	*FR	/FR	~	L	L
F	4	|	i	~	~	~	~	(E)	L	L
------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string table[5][8] = { { "QT","~","~","~","~","QT","~","~" },{ "~","QT+","QT-","~","~","~","L","L" },{ "RF","~","~","~","~","RF","~","~" },{ "~","L","L","RF*","RF-","~","L","L" },{ "i","~","~","~","~",")E(","~","~" } };
	char again;
	do {
		string w, stack = "$E";		//w will hold input string
		cout << "Enter a equation ending with '$' i.e. (i+i)$ : "; cin >> w;
		// initialize values
		int i = 0, col, state = 0;
		//will loop through the letters in the word until it encounters a '$'
		while (w[i] != '$') {
			//print the word letter by letter to prevent printing the '$' at the end
			cout << "\nRead: " << w[i] << endl;
			cout << "Stack\tPoped\tPushed\n";
			cout << stack << "\t";
			cout << stack.back() << "\t";
			while ( stack.back() != w[i] ) {
				if ( stack.back() != 'L' ) {		// L = Lamda state
					switch ( stack.back() ) {		// converts char to integer state
					case 'E':state = 0; break;
					case 'Q':state = 1; break;
					case 'T':state = 2; break;
					case 'R':state = 3; break;
					case 'F':state = 4; break;
					}
					switch ( w[i] ) {
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
					stack.pop_back();				// removes last char from stack
					stack += table[state][col];		// Push new states / terminals
					cout << table[state][col] << "\n";
					cout << stack << "\t";
				}
				else {						// used when a Lamda state is reached
					stack.pop_back();
					cout << endl << stack << '\t'; 
				}
				cout << stack.back() << "\t";	// display next poped state
				if ( stack.back() == '~' ) break;	// exits loop if in a null state
			}
			if ( stack.back() == '~' ) break;		// exits loop if in a null state
			stack.pop_back();					// removes last char
			cout << endl;
			i++;
		}
		//output result user
		if ( w[i] != '$' && stack.back() != '$' ) cout << "Not accepted";
		else cout << "Accepted";
		cout << "\n\nContinue (y/n): "; cin >> again;
	} while ( again == 'y' );
	//terminate the program
	system( "pause" );
	return 0;
}
/*-----------------output---------------------
--------------------------------------------*/