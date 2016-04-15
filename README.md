# Predictive Parsing Tracer

Used with the following table:

| states | a | b | + | - | * | / | ( | ) | $ | ~ | 
| :---: | :---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| S | a=E | ~ | ~ | ~ | ~ | ~ | ~ | ~  | ~ | ~ | 
|E|	TD|	TD|	~|	|~|	~|	~|	TD|	~|	~|	~|
|D|	~|	~|	+TD|	-TD|	~	|~|	~|	L|	L|	~|
|T|FU|	FU|	~|	~	|~	|~|	FU|	~|	~|	~|
|U|	~	|~	|L	|L	|*FU	|/FU	|~	|L	|L	|~|
|F|	a|	b|	~|	~|	~|	~|	(E)|	~	|~	|~|

Using a Predictive Parsing Table to trace the input strings, and show content of the stack after each match.
