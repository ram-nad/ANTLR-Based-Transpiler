lexer grammar BasicLexer;

import LiteralLexer;

VAR: 'var';
RETURN: 'return';
PROC: 'proc';
RECORD: 'record';
EXTERN: 'extern';
THIS: 'this';

VOID: 'void';
INT: 'int' ('(' ('8' | '16' | '32' | '64') ')')?;
UINT: 'uint' ('(' ('8' | '16' | '32' | '64') ')')?;
STRING: 'string';
REAL: 'real' ('(' ('32' | '64') ')')?;
BOOL: 'bool';

DOT: '.';
COLON: ':';
SEMICOLON: ';';
COMMA: ',';
OPEN_BRACES: '{';
CLOSE_BRACES: '}';
OPEN_PARENTHESES: '(';
CLOSE_PARENTHESES: ')';

ASSIGN: '=';
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';