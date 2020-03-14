lexer grammar LiteralLexer;

fragment DIGIT: '0' ..'9';
fragment HEX_DIGIT: '0' ..'9' | 'a' ..'f' | 'A' ..'F';
fragment OCT_DIGIT: '0' ..'7';

fragment LETTER: 'a' ..'z' | 'A' ..'Z';

fragment UNDERSCORE: '_';

fragment ESCAPED_CHAR:
	'\\' (
		'n'
		| 'a'
		| 'b'
		| 'f'
		| 'r'
		| 't'
		| 'v'
		| '\''
		| '"'
		| '?'
		| '\\'
	);

fragment SIGN: '+' | '-';

IDENTIFIER: (LETTER | UNDERSCORE) (LETTER | UNDERSCORE | DIGIT)*;

STRING_LITERAL: '"' (~["'\n] | ESCAPED_CHAR)* '"';

TRUE: 'true';
FALSE: 'false';

DEC_LITERAL: SIGN? DIGIT (UNDERSCORE? DIGIT)*;
HEX_LITERAL:
	SIGN? '0' ('x' | 'X') HEX_DIGIT (UNDERSCORE? HEX_DIGIT)*;
OCT_LITERAL:
	SIGN? '0' ('o' | 'O') OCT_DIGIT (UNDERSCORE? OCT_DIGIT)*;

REAL_LITERAL: SIGN? DIGIT+ '.' DIGIT+;

SINGLE_LINE_COMMENT: '//' ~[\n]* -> skip;

WHITESPACE: ('\n' | '\r' | '\t' | ' ')+ -> skip;

MULTILINE_COMMENT_START:
	'/*' -> pushMode(MULTILINE_COMMENT), skip;
MULTILINE_COMMENT_END: '*/' -> popMode, skip;

mode MULTILINE_COMMENT;
COMMENT_START: '/*' -> pushMode(MULTILINE_COMMENT), skip;
COMMENT_END: '*/' -> popMode, skip;
ANYCHAR: . -> skip;