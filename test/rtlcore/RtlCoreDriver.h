#ifndef RTLCOREDRIVER_H_
#define RTLCOREDRIVER_H_

#include <string>
#include <cstddef>
#include <istream>
#include <iostream>

//#include "rtlcore_parser.tab.hh"

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreScanner ;
class RtlCoreParser ;

class RtlCoreDriver{
public:
    
    RtlCoreDriver(): chars(0), words(0), lines(0), uppercase(0), lowercase(0), _parser(0), _scanner(0) {}

    virtual ~RtlCoreDriver() ;
   
    /** 
     * parse - parse from a file
     * @param filename - valid string with input file
     */
    void Parse (const char* const filename) ;
    /** 
     * parse - parse from a c++ input stream
     * @param is - std::istream&, valid input stream
     */
    void Parse (std::istream &iss) ;

    void add_upper();
    void add_lower();
    void add_word( const std::string &word );
    void add_newline();
    void add_char();

    void CommitModule(const std::string &module_name) { std::cout << "Successfully parsed module = " << module_name << std::endl ; }
    void AddPort(const std::string &port_name) { std::cout << "Port name = " << port_name << std::endl ; }
    void CommitStatement() {}
    void AddConnect(const std::string &port_name) {}
    void UpdateRange() {} 
    

    std::ostream& print(std::ostream &stream);
private:

   void Parse_Helper (std::istream &stream) ;

   static unsigned _line ;

   std::size_t  chars ;
   std::size_t  words ;
   std::size_t  lines ;
   std::size_t  uppercase ;
   std::size_t  lowercase ;
   RtlCoreParser  *_parser ;
   RtlCoreScanner *_scanner ;
   
};

#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif 
