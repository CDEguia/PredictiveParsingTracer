# PredictiveParsingTracer
Using a Predictive Parsing Table to trace input strings, and dispaly stack as it changes.

|states	|	i|	+|	-|	*|	/|	(|	)|	$|~|
|---|---|---|---|---|---|---|---|---|---|
|E	0	|	TQ|	~	|~|	~	|~|	TQ|	~	|~	|~	|
|Q	1	|	~	|+TQ|	-TQ	|~	|~	|~|	L|	L|~	|
|T	2	|	FR|	~	|~|	~	|~|	FR	|~|	~|~	|
|R	3	|	~	|L	|L|	*FR	|/FR|	~	|L|	L|~	|
|F	4	|	i|	~	|~|	~|	~|	(E)|	L	|L|~	|
