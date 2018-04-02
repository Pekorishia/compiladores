#ifndef _RULES_
#define _RULES_

#include "../token.c"

void program(Token* t){
    switch (t->key){
        case PROG:
        case ID:
        case ';':
            printf("\n%d", t->key);
            break;
        default:
            printf("\n%d", t->key);
    }
}
    
//      program -> "prog" "id" ";" prevdec block 
// block -> "inicio" prevcommand "fim" 
// prevdec -> declaration ";" prevdec | LAMBDA

// declaration -> vardec | usertype | labeldec | constdec | abstractiondec 

// arraydec -> "vetor" "[" rangelist "]" "de" type arraydecaux 
// arraydecaux -> "=" "(" expressionlist ")" | LAMBDA
// rangelist -> range rangelistaux 
// rangelistaux -> "," range rangelistaux |  LAMBDA   
// range -> atomic ".." atomic 
// vardec -> "var" idlist ":" varconstruction
// varconstruction ->  type decwithassign | arraydec
 
// decwithassign -> "=" expression | LAMBDA
// usertype -> "tipo" "id" typedec
// typedec -> arraydec | ":=" typedecaux
// typedecaux -> "registro" vardeclist "fim" | "value" | "(" idlist ")" | range

// vardeclist -> vardec vardeclistaux 
// vardeclistaux -> ";" vardec vardeclistaux | LAMBDA
// labeldec -> "rotulo" idlist
// constdec -> "const" "id" "=" expression
// abstractiondec -> procdec | funcdec
// procdec -> "proc" "id" "(" parameters ")" prevdec ";" block
// funcdec -> "func" "id" "(" parameters ")" ":" type ";" prevdec block
// parameters -> paramsaux | LAMBDA
// paramsaux -> "id" ":" type paramslist   | "ref" "id" ":" type paramslist 
// paramslist -> "," paramslist | LAMBDA
// prevcommand -> commands | LAMBDA
// callcommand ->  "pare" | write | read  | loop | block | return |  "continue" | id callidbegin | calllabel | conditional | block
// commands -> callcommand commandsaux

// commandsaux -> ";"  commands | LAMBDA



// callidbegin  -> ":" callcommand  | ":=" expression | LAMBDA

// calllabel -> "pule" "id"
// write -> "escreva" "(" expressionlist ")"
// read -> "leia" "(" expressionlist ")"
// return -> "retorne" expression
// loop -> forloop | whileloop | repeatloop
// forloop -> "para" "(" forstruct ")" "faca" callcommand
// forstruct -> prevfor ";" expression ";" posfor
// prevfor -> varassignlist | 
// varassignlist -> assign varassignlistaux
  
// varassignlistaux -> "," assign varassignlistaux | LAMBDA
// posfor -> posforaux | LAMBDA
// posforaux ->  commands posforaux2
// posforaux2 -> "," commands posforaux2 | LAMBDA
// whileloop -> "enquanto" "(" expression ")" "faca" callcommand
// repeatloop -> "repita" commands "ate" expression
// conditional -> ifcond | casecond
// ifcond ->  "se" "(" expression ")" "entao" callcommand ifcondaux 
// ifcondaux -> "senao" callcommand | LAMBDA

// casecond -> "caso" "(" expression ")" "seja" caselist casecondaux
   
// casecondaux -> "fim"| "senao" commands "fim"
   
// caselist -> caseclause caselistaux
// caselistaux -> ";" caselistaux2   | LAMBDA
// caselistaux2 ->  caseclause caselistaux | LAMBDA
// caseclause -> atomiclist ":" callcommand 

// expressionlist -> expression expressionlistaux
// expressionlistaux -> "," expression expressionlistaux
// expression -> logicexpr 
// logicexpr -> logicexprinter exprand
// exprand -> "and" logicexprinter exprand  | "or" logicexprinter exprand  | "==" logicexprinter exprand | "!=" logicexprinter exprand | LAMBDA
   
// exprleq -> ">" logicexprinter   | "<" logicexprinter   | ">=" logicexprinter  | "<=" logicexprinter   | LAMBDA
// logicexprinter -> numericexpr exprleq |  "~" numericexpr exprleq 

// numericexpr -> numericexprinter exprsum
// exprsum -> "+" numericexprinter exprsum  | "-" numericexprinter exprsum | LAMBDA

// numericexprinter -> simpleexpr exprmul
// exprmul -> "*" simpleexpr exprmul | "/" simpleexpr exprmul  | LAMBDA
// simpleexpr -> atomic optrange | optminus "(" logicexpr ")"
// optrange -> ".." atomic | LAMBDA
// optminus -> "-" | LAMBDA
// idlist -> "id" idlistaux 

// idlistaux -> "," "id" idlistaux |LAMBDA
// type -> "inteiro" | "real" | "logico" | "texto" | "id" 
// literal -> "literalint" | "literalreal" | "literallogico" | "literaltexto"  
// atomic -> literal | id
   
// id -> "id" idaux
   
// idaux -> "[" expressionlist "]" |  "." id |  "(" expressionlist ")" | LAMBDA
   

// atomiclist -> atomic atomiclistaux
// atomiclistaux ->  "," atomic atomiclistaux | LAMBDA

#endif 