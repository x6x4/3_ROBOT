%option noyywrap

TRUE         T[RUE]
FALSE        F[ALSE]
BOOL_UNDEF   U[NDEF]
BOOL         "BOOL"
INT          "INT"
CELL         "CELL"
UNDEF        "UNDEF"
EMPTY        "EMPTY"
WALL         "WALL"
BOX          "BOX"
EXIT         "EXIT"
INF          "INF"
NEG_INF      "-INF"
NAN          "NAN"

ID      [a-zA-Z][a-zA-Z0-9_.]*
INT_VALUE   [0-9]+("e"|[Ee]+|-)?[0-9]+ | [0-9]+

SUM_UP_ARR    .+

ASSIGNMENT   "="

LESS    "<"
GREATER ">"
EQUAL   "=="
LEQ     "<="
GEQ     ">="

IF      "IF"
THEN    "THEN"
ELSE    "ELSE"
WHILE   "WHILE"

FORWARD "forward"
BACKWARD "backward"
LOAD "load"
DROP "drop"
LOOK "look"
TEST "test"