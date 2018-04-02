#ifndef _TOKEN_
#define _TOKEN_

#include "constants.c"

//STRUCTS
typedef struct {
    KEYWORD key;
    const char* name;
    const char* value;
    int line;
    int column;
}Token;

#endif