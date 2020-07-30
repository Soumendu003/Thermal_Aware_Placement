#include "ThermPlannerSystem.h"
#include "Cmdparser.h"

#include "RtlCoreDriver.h"
#include "Map.h"
#include "Set.h"
#include "Array.h"
#include "String.h"
#include <iostream>

#ifdef THERMPLANNER_NAMESPACE
using namespace ThermPlanner ;
#endif


int main(int argc, const char **argv)
{
    
    char *val = String::save("Guddu", "Hazard", 0, "Kante") ;

    const char *val1 = String::CreateConstantString("Guddu") ;
    const char *val2 = String::CreateConstantString("Guddu") ;

    if (val1 != val2) {
        std::cout << "Wrong" << std::endl ;
    } else {
        std::cout << "Correct" << std::endl ;
    }
    
    std::cout<< "Joined string = " << val << std::endl ;

    return 0 ;
        
    /*Parser cmdline = Parser(argc, argv) ;*/

    //cmdline.set_required<std::string>("f", "file", "File to be parsed") ;

    //cmdline.run_and_exit_if_error() ;

    //std::string file = cmdline.get<std::string>("f") ;

    //RtlCoreDriver driver;

    /*driver.Parse(file.c_str()) ;*/

    return( EXIT_SUCCESS );
}
