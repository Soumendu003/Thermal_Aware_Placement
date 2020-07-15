#ifndef RTLCORESCANNER_H_
#define RTLCORESCANNER_H_

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "rtlcore_parser.tab.hh"
#include "location.hh"

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreScanner : public yyFlexLexer
{
public:
   
   RtlCoreScanner(std::istream *in) : yyFlexLexer(in), _yylval(0) /*, _loc(0), _curLineNum(1), _curColNum(1)*/ {}

   virtual ~RtlCoreScanner() {}

   //get rid of override virtual function warning
   using FlexLexer::yylex;

   virtual int yylex (RtlCoreParser::semantic_type * const lval, RtlCoreParser::location_type *location) ;
   // YY_DECL defined in rtlcore_lexer.l
   // Method body created by flex in rtlcore_lexer.yy.cc
   //inline unsigned GetLineNo() { return _curLineNum ; }
   //inline unsigned GetColNo() { return _curColNum ; }

private:
   /* yyval ptr */
   RtlCoreParser::semantic_type *_yylval ;
   /* location ptr */
   //RtlCoreParser::location_type *_loc ;
   /*unsigned _curLineNum ;*/
   /*unsigned _curColNum ;*/
};

#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif 
