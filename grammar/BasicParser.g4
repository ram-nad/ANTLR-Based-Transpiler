parser grammar BasicParser;

options {
	tokenVocab = BasicLexer;
}

file: (varDef | exprStmt | funcDef | extFuncDecl | recDecl)*;

statements: exprStmt | blckStmt;

retStmt: RETURN expr SEMICOLON;

blckStmt:
	OPEN_BRACES (varDef | exprStmt | retStmt)* CLOSE_BRACES;

exprStmt: expr SEMICOLON;

primTypes: INT | UINT | REAL | STRING | BOOL;

varType: IDENTIFIER | primTypes;

typeDecl: COLON varType;

varDecl:
	IDENTIFIER (COMMA IDENTIFIER)* (
		typeDecl
		| typeDecl? ASSIGN expr
	);

varDef: VAR varDecl (COMMA varDecl)? SEMICOLON;

varParam: IDENTIFIER typeDecl;

argList: varParam (COMMA varParam)*;

recDecl:
	RECORD IDENTIFIER OPEN_BRACES (
		VAR varParam SEMICOLON
		| funcDef
	)* CLOSE_BRACES;

funcSignature:
	PROC IDENTIFIER OPEN_PARENTHESES argList? CLOSE_PARENTHESES typeDecl?;

funcDef: funcSignature blckStmt;

extFuncDecl: EXTERN IDENTIFIER? funcSignature SEMICOLON;

funcParams: expr (COMMA expr)*;

funcCall: OPEN_PARENTHESES funcParams? CLOSE_PARENTHESES;

lVal:
	THIS										# this
	| IDENTIFIER								# iden
	| lVal DOT IDENTIFIER funcCall				# method
	| lVal DOT IDENTIFIER						# member
	| lVal funcCall								# call
	| OPEN_PARENTHESES expr CLOSE_PARENTHESES	# pExpr;

literal:
	STRING_LITERAL	# string
	| REAL_LITERAL	# real
	| TRUE			# boolT
	| FALSE			# boolF
	| DEC_LITERAL	# intDec
	| HEX_LITERAL	# intHex
	| OCT_LITERAL	# intOct;

expr:
	expr typeDecl						# cast
	| literal							# litExpr
	| lVal								# lvalExpr
	| expr op = (MUL | DIV | MOD) expr	# mul
	| expr op = (ADD | SUB) expr		# add
	| lVal ASSIGN expr					# asg;