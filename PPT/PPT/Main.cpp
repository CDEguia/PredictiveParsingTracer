//------------------------------------------------------------------------------------------
//          Name		Jeremy Driesler & Candelario "Daniel" Eguia
//          Course		CMPS-455
//          Project		No. 8
//			Part		No. 2
//          Due date	Mar. 15, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
/*	The trace of the input string and shows content of the stack after each match.
-----------------Table---------------
states	|	a	b	+	-	*	/	(	)	$	~
S	0	|	a=E	~	~	~	~	~	~	~	~	~
E	1	|	TD	TD	~	~	~	~	TD	~	~	~
D	2	|	~	~	+TD	-TD	~	~	~	L	L	~
T	3	|	FU	FU	~	~	~	~	FU	~	~	~
U	4	|	~	~	L	L	*FU	/FU	~	L	L	~
F	5	|	a	b	~	~	~	~	(E)	~	~	~
------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string table[6][10] = { { "E=a","~","~","~","~","~","~","~","~","~" },
	{ "DT","DT","~","~","~","~","DT","~","~","~" },{ "~","~","DT+","DT-","~","~","~","L","L","~" },
	{ "UF","UF","~","~","~","~","UF","~","~","~" },{ "~","~","L","L","UF*","UF/","~","L","L","~" },
	{ "a","b","~","~","~","~",")E(","~","~","~" } };
	char again;
	do {
		string w, stack = "$S";		//w will hold input string
		cout << "Enter a equation ending with '$' i.e. a=a$ : "; cin >> w;
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
					case 'S':state = 0; break;
					case 'E':state = 1; break;
					case 'D':state = 2; break;
					case 'T':state = 3; break;
					case 'U':state = 4; break;
					case 'F':state = 5; break;
					}
					switch ( w[i] ) {
					case 'a':col = 0; break;
					case 'b':col = 1; break;
					case '+':col = 2; break;
					case '-':col = 3; break;
					case '*':col = 4; break;
					case '/':col = 5; break;
					case '(':col = 6; break;
					case ')':col = 7; break;
					case '$':col = 8; break;
					default: col = 9;		//is used for any letter not in the lanuage
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
Enter a equation ending with '$' i.e. a=a$ : a=(a+a)*b$

Read: a
Stack   Poped   Pushed
$S      S       E=a
$E=a    a

Read: =
Stack   Poped   Pushed
$E=     =

Read: (
Stack   Poped   Pushed
$E      E       DT
$DT     T       UF
$DUF    F       )E(
$DU)E(  (

Read: a
Stack   Poped   Pushed
$DU)E   E       DT
$DU)DT  T       UF
$DU)DUF F       a
$DU)DUa a

Read: +
Stack   Poped   Pushed
$DU)DU  U       L
$DU)DL  L
$DU)D   D       DT+
$DU)DT+ +

Read: a
Stack   Poped   Pushed
$DU)DT  T       UF
$DU)DUF F       a
$DU)DUa a

Read: )
Stack   Poped   Pushed
$DU)DU  U       L
$DU)DL  L
$DU)D   D       L
$DU)L   L
$DU)    )

Read: *
Stack   Poped   Pushed
$DU     U       UF*
$DUF*   *

Read: b
Stack   Poped   Pushed
$DUF    F       b
$DUb    b
Accepted

Continue (y/n): y
Enter a equation ending with '$' i.e. a=a$ : a=a*(b-a)$

Read: a
Stack   Poped   Pushed
$S      S       E=a
$E=a    a

Read: =
Stack   Poped   Pushed
$E=     =

Read: a
Stack   Poped   Pushed
$E      E       DT
$DT     T       UF
$DUF    F       a
$DUa    a

Read: *
Stack   Poped   Pushed
$DU     U       UF*
$DUF*   *

Read: (
Stack   Poped   Pushed
$DUF    F       )E(
$DU)E(  (

Read: b
Stack   Poped   Pushed
$DU)E   E       DT
$DU)DT  T       UF
$DU)DUF F       b
$DU)DUb b

Read: -
Stack   Poped   Pushed
$DU)DU  U       L
$DU)DL  L
$DU)D   D       DT-
$DU)DT- -

Read: a
Stack   Poped   Pushed
$DU)DT  T       UF
$DU)DUF F       a
$DU)DUa a

Read: )
Stack   Poped   Pushed
$DU)DU  U       L
$DU)DL  L
$DU)D   D       L
$DU)L   L
$DU)    )
Accepted

Continue (y/n): y
Enter a equation ending with '$' i.e. a=a$ : a=(a+a)b$

Read: a
Stack   Poped   Pushed
$S      S       E=a
$E=a    a

Read: =
Stack   Poped   Pushed
$E=     =

Read: (
Stack   Poped   Pushed
$E      E       DT
$DT     T       UF
$DUF    F       )E(
$DU)E(  (

Read: a
Stack   Poped   Pushed
$DU)E   E       DT
$DU)DT  T       UF
$DU)DUF F       a
$DU)DUa a

Read: +
Stack   Poped   Pushed
$DU)DU  U       L
$DU)DL  L
$DU)D   D       DT+
$DU)DT+ +

Read: a
Stack   Poped   Pushed
$DU)DT  T       UF
$DU)DUF F       a
$DU)DUa a

Read: )
Stack   Poped   Pushed
$DU)DU  U       L
$DU)DL  L
$DU)D   D       L
$DU)L   L
$DU)    )

Read: b
Stack   Poped   Pushed
$DU     U       ~
$D~     ~       Not accepted

Continue (y/n): n
Press any key to continue . . .
--------------------------------------------*/