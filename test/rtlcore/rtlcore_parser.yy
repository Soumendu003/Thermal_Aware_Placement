%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {ThermPlanner}
/**
 * bison 3.3.2 change
 * %define parser_class_name to this, updated
 * should work for previous bison versions as 
 * well. -jcb 24 Jan 2020
 */
%define parser_class_name {RtlCoreParser}

%code requires{
   namespace ThermPlanner {
      class RtlCoreDriver ;
      class RtlCoreScanner ;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#   define YY_NULLPTR 0
# endif

}

%parse-param { RtlCoreScanner  &scanner  }
%parse-param { RtlCoreDriver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "RtlCoreDriver.h"
   #include "RtlCoreScanner.h"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

/* Tokens
 * ------
 */

%token                  END    0     "end of file"
%token                  ERROR
%token < unsigned >     INTEGER
%token < std::string >  ID BINARY_VAL
%token                  VERI_MODULE VERI_ENDMODULE VERI_INPUT VERI_OUTPUT VERI_WIRE VERI_ASSIGN // Keywords
%token                  LEFT_PAREN RIGHT_PAREN COMMA SEMI_COLON LEFT_CURL RIGHT_CURL LEFT_BRAKET RIGHT_BRAKET COLON DOT EQUAL // symbols 

/* Non-terminal types
 * ------------------
 */

%type < std::string >   ModuleDecl

%locations

%%

Program         : END | ModuleDeclList END ;

ModuleDeclList  : ModuleDeclList ModuleDecl             { driver.CommitModule($2) ; }
                | ModuleDecl                            { driver.CommitModule($1) ; }
                ;

ModuleDecl      : VERI_MODULE ID LEFT_PAREN ModulePorts RIGHT_PAREN SEMI_COLON StatementList VERI_ENDMODULE 
                                                        { $$ = $2 ; /* Get Module Name */ } ;

ModulePorts     : ModulePorts COMMA ID                  { driver.AddPort($3) ; }
                | ID                                    { driver.AddPort($1) ; }
                ;

StatementList   : StatementList Statement SEMI_COLON    { driver.CommitStatement() ; }   
                | Statement SEMI_COLON                  { driver.CommitStatement() ; }
                ;

Statement       : VERI_INPUT ConnectList
                | VERI_OUTPUT ConnectList
                | VERI_WIRE ConnectList
                | Instantiation
                | Assignment
                ;

Assignment      : VERI_ASSIGN ID LEFT_BRAKET INTEGER RIGHT_BRAKET EQUAL BINARY_VAL ; /* Currently ignore these */ 

ConnectList     : ConnectList COMMA Connect                  
                | Connect
                ;

Connect         : Range ID                              { driver.AddConnect($2) ; }
                | ID                                    { driver.AddConnect($1) ; }
                ;

Range           : LEFT_BRAKET INTEGER COLON INTEGER RIGHT_BRAKET
                                                        { driver.UpdateRange() ; } ;

Instantiation   : ID InstId LEFT_PAREN PortValList RIGHT_PAREN ;

InstId          : ID LEFT_BRAKET INTEGER RIGHT_BRAKET
                | ID
                ;

PortValList     : PortValList COMMA PortValBus
                | PortValList COMMA PortVal
                | PortVal
                | PortValBus
                ;

PortValBus      : LEFT_CURL PortValList RIGHT_CURL ;

PortVal         : BINARY_VAL 
                | ID 
                | ID LEFT_BRAKET INTEGER RIGHT_BRAKET
                | ID LEFT_BRAKET INTEGER COLON INTEGER RIGHT_BRAKET
                | DOT ID LEFT_PAREN PortValList RIGHT_PAREN
                ;


%%


void ThermPlanner::RtlCoreParser::error (const location_type &l, const std::string &err_message)
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
