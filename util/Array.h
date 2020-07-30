#ifndef ARRAY_H_
#define ARRAY_H_

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_MEMORY_MANAGER
#define ARRAY_ALLOC mi_stl_allocator
#else
#include <memory>
#define ARRAY_ALLOC std::allocator
#endif // #ifdef THERMPLANNER_MEMORY_MANAGER

#include <vector>

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

    template < class T, class Alloc = ARRAY_ALLOC<T> > 
    using Array = std::vector<T, Alloc> ;


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif // #ifndef ARRAY_H_

