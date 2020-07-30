#ifndef RTLCORELIBRARY_H_
#define RTLCORELIBRARY_H_

#include "ThermPlannerSystem.h"
#include "Map.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreModule ;
class RtlCoreGate ;

class RtlCoreLibrary
{
public:
    RtlCoreLibrary(): {}
    ~RtlCoreLibrary() {}
    
private:
    // Prevent compiler from defining the following
    RtlCoreLibrary(const RtlCoreLibrary &) ;            // Purposely leave unimplemented
    RtlCoreLibrary& operator=(const RtlCoreLibrary &) ; // Purposely leave unimplemented

public:

    void InsertModule(const std::string& module_name, RtlCoreModule* module)    { _module_table->insert({module_name, module}) ; }
    void InsertGate(const std::string& gate_name, RtlCoreGate* gate)            { _gate_table->insert({gate_name, gate}) ; }


private:

    ParallelFlatMap<const std::string&, RtlCoreModule *> *_module_table ;
    ParallelFlatMap<const std::string&, RtlCoreGate *> *_gate_table ;

} ; // class RtlCoreLibrary



#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif // #ifndef RTLCORELIBRARY_H_

