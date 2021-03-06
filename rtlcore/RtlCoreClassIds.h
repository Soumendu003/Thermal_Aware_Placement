#ifndef RTLCORECLASSIDS_H_
#define RTLCORECLASSIDS_H_

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

// The following enum contains all non-abstract rtlcore class ids.
// We use GetClassIds() instead RTTI, because ANSI's C++ RTTI is too expensive (extra item
// in virtual function table).

enum RTLCORE_CLASS_ID
{
    ID_RTLCORE_BEGIN_TABLE = 0xc0000000, // The first marker (unused) - specifies starting value

    // RtlCoreUnit
    ID_RTLCORE_MODULE,          ID_RTLCORE_GATE,
    
    // RtlCoreIdDef
    ID_RTLCORE_VARIABLE,        ID_RTLCORE_INSTID

    // RtlCoreExpression
    ID_RTLCORE_IDREF,           ID_RTLCORE_CONCAT,          ID_RTLCORE_PORTCONNECT,         ID_RTLCORE_RANGE,
    ID_RTLCORE_INDEXEDID,       ID_RTLCORE_DATATYPE

} ;

#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif
