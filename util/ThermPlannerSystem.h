#ifndef THERMPLANNER_H_
#define THERMPLANNER_H_

// This header file is intended as a system header file for all Thermplanner code.
// Basic operations like assertion, new and delete can be defined here.
//
// This system header should (can) be included in every application cpp
// files that needs to use Thermplanner code.
//
//

/*-------------------------------------------------------------------------------------
    THERMPLANNER_NAMESPACE Compile Flag : (active in all projects)
  -------------------------------------------------------------------------------------
    To avoid potential name collisions between Thermplanner classes and customer
    classes, a "Thermplanner" namespace will be created if this flag is set.  By
    default it is ifdef'ed out.  All Thermplanner classes will obtain the Thermplanner::
    prefix if this flag is set, which makes them unique within your application.
    To make all Thermplanner class names directly visible (without a Thermplanner::
    prefix), use header file ThermplannerSystem.h in your application code, or type
    "using namespace Thermplanner". Otherwise, class names are still visible by
    selection with Thermplanner:: prefix.

    The following #ifndef block allows the build user to force on the "Thermplanner"
    namespace, regardless of flag settings in the Makefiles/(Msdev project
    settings). Comment out the #define if you want to control this flag from the
    Makefiles/(Msdev project settings).
*/

#define THERMPLANNER_NAMESPACE // <--- Comment this line out to control flag from build environment, or uncomment to force on.


/*-------------------------------------------------------------------------------------------
    THERMPLANNER_MEMORY_MANAGER Compile Flag : (active in all projects)
  -------------------------------------------------------------------------------------------
    Thermplanner has uses a open source memory manager code available on github.

    The repository of the memory manager code : https://github.com/microsoft/mimalloc.git

    The memory manager code is stored in the local repository MemManager.
    
*/

//#define THERMPLANNER_MEMORY_MANAGER // <--- Comment this line out to control flag from build environment, or uncomment to force on.

/*-------------------------------------------------------------------------------------------
    THERMPLANNER_PARALLEL_HASHMAP Compile Flag : (active in all projects)
  -------------------------------------------------------------------------------------------
    Thermplanner has uses a open source Map, Set, Hash implementation code available on github.

    The repository of the memory manager code : https://github.com/greg7mdp/parallel-hashmap.git

    The hash_map code is stored in the local repository ParallelHashmap.
    
*/

//#define THERMPLANNER_PARALLEL_HASHMAP // <--- Comment this line out to control flag from build environment, or uncomment to force on.



/* -------------------------------------------------------------- */

#ifndef THERMPLANNER_ASSERT
// All Thermplanner code calls this ASSERT macro. By default, we use regular system 'assert()'.
// Feel free to re-define it.
#include <cassert>
#include <iostream>
#define THERMPLANNER_ASSERT(exp) assert(exp)
#define THERMPLANNER_ASSERT_MSG(exp, msg) if (!(exp)) { std::cerr << "ASSERT_MSG :" << (msg) << std::endl ; assert(exp) ; }
#endif


#ifdef THERMPLANNER_MEMORY_MANAGER
#ifndef MI_MALLOC_H_
#define MI_MALLOC_H_
    #include <mimalloc.h>
#endif
    // Define macro for global new delete. Insert it only in main file.
    #define GLOBAL_NEW_DELETE <mimalloc-new-delete.h>

    #define MEM_STATS \
        mi_version() ; \
        mi_option_enable(mi_option_show_stats) ; \
        mi_option_enable(mi_option_show_errors) ; \
        mi_option_enable(mi_option_verbose) ;

#endif // #ifdef THERMPLANNER_MEMORY_MANAGER

#endif // #ifndef THERMPLANNER_H_
