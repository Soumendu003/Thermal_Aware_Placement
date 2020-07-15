%{
/* C++ string header, for string ops below */
#include <string>
#include <iostream>

/* Implementation of yyFlexScanner */ 
#include "RtlCoreScanner.h"
#undef  YY_DECL
#define YY_DECL int ThermPlanner::RtlCoreScanner::yylex( ThermPlanner::RtlCoreParser::semantic_type * const lval, ThermPlanner::RtlCoreParser::location_type *loc )

/* typedef to make the returns for the tokens shorter */
using token = ThermPlanner::RtlCoreParser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step() ; loc->columns(yyleng) ; 

%}

%option debug
%option nodefault
%option yyclass="ThermPlanner::RtlCoreScanner"
%option noyywrap
%option c++

/* Definitions
 * -----------
 * To make our rules more readable, we establish some definitions here.
 */
DIGIT             ([0-9])
INTEGER           ({DIGIT}+)
BINARY            ([0-9]"'b"[0-1]+)
IDENTIFIER        ([a-zA-Z][a-zA-Z_0-9]*)
SPECIAL_ID        ([\\]{IDENTIFIER}"["{INTEGER}"]") 
BEG_COMMENT       ("/*")
END_COMMENT       ("*/")
SINGLE_COMMENT    ("//"[^\n]*)

%%
%{          /** Code executed at the beginning of yylex **/
            _yylval = lval;
%}

[ \t]+          {/* ignore all spaces */}
<*>\n           {
                    // Update line number
                    loc->lines() ;
                }

 /* -------------------- Comments ----------------------------- */

{SINGLE_COMMENT}       { /* skip to end of line for // comment */ }

 /* --------------------- Operators ------------------------------- */

[(]             { return (token::LEFT_PAREN) ; }
[)]             { return (token::RIGHT_PAREN) ; }
[,]             { return (token::COMMA) ; }
[;]             { return (token::SEMI_COLON) ; }
[{]             { return (token::LEFT_CURL) ; }
[}]             { return (token::RIGHT_CURL) ; }
[[]             { return (token::LEFT_BRAKET) ; }
[\]]            { return (token::RIGHT_BRAKET) ; }
[:]             { return (token::COLON) ; }
[.]             { return (token::DOT) ; }   
[=]             { return (token::EQUAL) ; }

 /* ---------------------- Literals ------------------------------ */

{BINARY}        {
                    _yylval->build< std::string >(yytext) ;
                    std::cout << "Binary val = " << yytext << std::endl ;
                    return (token::BINARY_VAL) ;
                }

{INTEGER}       { 
                    _yylval->build< unsigned > ((unsigned)atoi(yytext)) ;
                    std::cout << "Integer val = " << yytext << std::endl ;
                    return (token::INTEGER) ; 
                }


 /* --------------------- Keywords ------------------------------- */

"module"        { return (token::VERI_MODULE) ; }
"endmodule"     { return (token::VERI_ENDMODULE) ; }
"input"         { return (token::VERI_INPUT) ; }
"output"        { return (token::VERI_OUTPUT) ; }
"wire"          { return (token::VERI_WIRE) ; }
"assign"        { return (token::VERI_ASSIGN) ; }

 /* -------------------- Identifiers --------------------------- */
{IDENTIFIER}    {
                    /**
                     * Section 10.1.5.1 of the 3.0.2 Bison Manual says the 
                     * following should work:
                     * _yylval.build( yytext );
                     * but it doesn't.
                     * ref: http://goo.gl/KLn0w2
                     */
                    _yylval->build< std::string >( yytext ) ;
                    std::cout << "Id = " << yytext << std::endl ;
                    return (token::ID) ;
                }

{SPECIAL_ID}    {
                    _yylval->build< std::string >( yytext ) ;
                    std::cout << "Special Id = " << yytext << std::endl ;
                    return (token::ID) ;
                }
 /* -------------------- Default rule (error) -------------------- */
.               {
                    return( token::ERROR );
                }
%%
