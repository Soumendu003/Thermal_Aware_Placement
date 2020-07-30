#ifndef BITARRAY_H_
#define BITARRAY_H_

#include "ThermPlannerSystem.h"

#include <bitset>

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

    template< std::size_t N >
    using BitArray = std::bitset<N> ;


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif



#endif // #ifndef BITARRAY_H_
