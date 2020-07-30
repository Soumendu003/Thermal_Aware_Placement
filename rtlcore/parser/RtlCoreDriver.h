#ifndef RTLCOREDRIVER_H_
#define RTLCOREDRIVER_H_

#include "String.h"
#include <istream>

//#include "rtlcore_parser.tab.hh"

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreScanner ;
class RtlCoreParser ;

class RtlCoreDriver{
public:
    
    RtlCoreDriver(): _parser(0), _scanner(0) {}

    virtual ~RtlCoreDriver() ;

public:

    /** 
     * parse - parse from a file
     * @param filename - valid string with input file
     */
    void Parse (const char* const filename) ;

protected:

    void CommitModule(const std::string &module_name) { /*std::cout << "Successfully parsed module = " << module_name << std::endl ;*/ }
    void AddPort(const std::string &port_name) { /*std::cout << "Port name = " << port_name << std::endl ;*/ }
    void CommitStatement() {}
    void AddConnect(const std::string &port_name) {}
    void UpdateRange() {} 
    
private:

   void Parse_Helper (std::istream &stream) ;
   
   RtlCoreParser  *_parser ;
   RtlCoreScanner *_scanner ;

protected:
   friend class RtlCoreParser ;

} ; // class RtlCoreDriver

#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif 
