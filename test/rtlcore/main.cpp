#include <iostream>
#include <cstdlib>
#include <cstring>

#include "ThermPlannerSystem.h"

#include "RtlCoreDriver.h"
#include "Map.h"

#ifdef THERMPLANNER_NAMESPACE
using namespace ThermPlanner ;
#endif


int main(const int argc, const char **argv)
{
    FlatMap<int, int> *map = new FlatMap<int, int> ;
    delete map ;
    /** check for the right # of arguments **/
    if( argc == 2 )
    {
      RtlCoreDriver driver;
      /** example for piping input from terminal, i.e., using cat **/ 
      if( std::strncmp( argv[ 1 ], "-o", 2 ) == 0 )
      {
         driver.Parse( std::cin );
      }
      /** simple help menu **/
      else if( std::strncmp( argv[ 1 ], "-h", 2 ) == 0 )
      {
         std::cout << "use -o for pipe to std::cin\n";
         std::cout << "just give a filename to count from a file\n";
         std::cout << "use -h to get this menu\n";
         return( EXIT_SUCCESS );
      }
      /** example reading input from a file **/
      else
      {
         /** assume file, prod code, use stat to check **/
         driver.Parse( argv[1] );
      }
      driver.print( std::cout ) << "\n";
    }
    else
    {
      /** exit with failure condition **/
      return ( EXIT_FAILURE );
    }
    return( EXIT_SUCCESS );
}
