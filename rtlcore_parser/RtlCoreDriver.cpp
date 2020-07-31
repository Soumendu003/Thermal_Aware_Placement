#include <cctype>
#include <fstream>
#include <iostream>

#include "ThermPlannerSystem.h"
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
    THERMPLANNER_ASSERT(filename) ;
    std::ifstream in_file(filename) ;
    if (!in_file.good()) exit( EXIT_FAILURE ) ;
    Parse_Helper(in_file) ;
    return ;
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
   }
   return ;
}

