#include <cctype>
#include <fstream>
#include <cassert>
#include <iostream>

#include "RtlCoreDriver.h"
#include "RtlCoreScanner.h"
#include "rtlcore_parser.tab.hh"

#ifdef THERMPLANNER_NAMESPACE
using namespace ThermPlanner ;
#endif

RtlCoreDriver::~RtlCoreDriver()
{
   delete(_scanner) ;
   _scanner = 0 ;
   delete(_parser) ;
   _parser = 0 ;
}

void RtlCoreDriver::Parse(const char* const filename)
{
   assert (filename);
   std::ifstream in_file(filename) ;
   if (!in_file.good()) exit( EXIT_FAILURE ) ;
   Parse_Helper(in_file) ;
   return ;
}

void RtlCoreDriver::Parse(std::istream &stream)
{
   if (!stream.good() && stream.eof()) return ;
   //else
   Parse_Helper(stream) ; 
   return;
}


void RtlCoreDriver::Parse_Helper(std::istream &stream)
{
   delete(_scanner);
   try
   {
      _scanner = new RtlCoreScanner(&stream) ;
   }
   catch(std::bad_alloc &ba)
   {
      std::cerr << "Failed to allocate scanner: (" << ba.what() << "), exiting!!\n" ;
      exit(EXIT_FAILURE) ;
   }
   
   delete(_parser) ; 
   try
   {
      _parser = new RtlCoreParser( (*_scanner) /* scanner */, (*this) /* driver */) ;
   }
   catch(std::bad_alloc &ba)
   {
      std::cerr << "Failed to allocate parser: (" << ba.what() << "), exiting!!\n" ;
      exit(EXIT_FAILURE) ;
   }
   const int accept(0);
   if(_parser->parse() != accept)
   {
      std::cerr << "Parse failed!!\n" ;
      //std::cerr << "Line number = " << _scanner->GetLineNo() << ". Col number = " << _scanner->GetColNo() << "\n" ;
   }
   return ;
}

void RtlCoreDriver::add_upper()
{ 
   uppercase++; 
   chars++; 
   words++; 
}

void RtlCoreDriver::add_lower()
{ 
   lowercase++; 
   chars++; 
   words++; 
}

void RtlCoreDriver::add_word( const std::string &word )
{
   words++; 
   chars += word.length();
   //std::cout << "word obtained = " << word << std::endl ;
}

void RtlCoreDriver::add_newline()
{ 
   lines++; 
   chars++; 
}

void RtlCoreDriver::add_char()
{ 
   chars++; 
}


std::ostream& RtlCoreDriver::print( std::ostream &stream )
{
   stream << "Results: \n";
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   return(stream);
}
