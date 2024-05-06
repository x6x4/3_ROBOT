%option noyywrap

TYPE         "BOOL" | "INT" | "CELL" | "VAR"

TRUE         T[RUE]
FALSE        F[ALSE]
BOOL_UNDEF   U[NDEF]

UNDEF        "UNDEF"
EMPTY        "EMPTY"
WALL         "WALL"
BOX          "BOX"
EXIT         "EXIT"

INF          "INF"
NEG_INF      "-INF"
NAN          "NAN"

spaces      [ \t]+
ID          [a-zA-Z][a-zA-Z0-9_.]*
INT_VALUE   [0-9]+("e"|[Ee]+|-)?[0-9]+ | [0-9]+

SUM_UP_ARR    "#"

ASSIGN        "="

LESS    "<"
GREATER ">"
EQUAL   "="

IF      "if"
ELDEF    "eldef"
ELUND    "elund"
WHILE   "while"
FINISH  "finish"

FORWARD "forward"
BACKWARD "backward"
LOAD "load"
DROP "drop"
LOOK "look"
TEST "test"

FUNC "function" 
FUNC_NAME ID | ""
DO "do"
DONE "done"
RETURN "return"

ENTRYPOINT "main"