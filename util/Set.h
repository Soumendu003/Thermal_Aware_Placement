#ifndef SET_H_
#define SET_H_

#include "ThermplannerSystem.h"

#ifdef THERMPLANNER_PARALLEL_HASHMAP
    #include "phmap.h"
    #include "btree.h"
#else   // uses stl map
    #include <set> 
    #include <unordered_set>
#endif 

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

#ifdef THERMPLANNER_PARALLEL_HASHMAP


#else


#endif // #ifdef THERMPLANNER_PARALLEL_HASHMAP


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif


#endif // #ifndef MAP_H_
