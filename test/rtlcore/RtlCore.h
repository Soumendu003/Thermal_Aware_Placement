#ifndef RTLCORE_H_
#define RTLCORE_H_

// This file contains the RtlCore class definition, which is
// used to control all operations on rtlcore benchmarks from
// top.

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif


class RtlCore
{
private:
    // All 'RtlCore' API routines are 'static', constructor need not be called.

    // Prevent compiler from defining the following
    RtlCore() ;                           // Purposely leave unimplemented
    ~RtlCore() ;                          // Purposely not virtual, and leave unimplemented
    RtlCore(const RtlCore &) ;            // Purposely leave unimplemented
    RtlCore& operator=(const RtlCore &) ; // Purposely leave unimplemented

public:


} ; // class RtlCore


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif


#endif
