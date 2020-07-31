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
    explicit RtlCoreLibrary(const char *name): _name(name) 
    {
        _module_table = new UnorderedMap<const char *, RtlCoreModule *, StringHash<const char *>> ;
        _gate_table = new UnorderedMap<const char *, RtlCoreModule *, StringHash<const char *>> ;
    }
    ~RtlCoreLibrary() 
    {
        delete _module_table ;
        delete _gate_table ;
    }
    
private:
    // Prevent compiler from defining the following
    RtlCoreLibrary(const RtlCoreLibrary &) ;            // Purposely leave unimplemented
    RtlCoreLibrary& operator=(const RtlCoreLibrary &) ; // Purposely leave unimplemented

public:

    void InsertModule(const char *module_name, RtlCoreModule *module)    { _module_table->insert({module_name, module}) ; }
    void InsertGate(const char *gate_name, RtlCoreGate *gate)            { _gate_table->insert({gate_name, gate}) ; }
    const char* GetName()                                                { return _name ; }


private:
    const char *_name ;
    UnorderedMap<const char *, RtlCoreModule *, StringHash<const char *>> *_module_table ;
    UnorderedMap<const char *, RtlCoreModule *, StringHash<const char *>> *_gate_table ;

} ; // class RtlCoreLibrary



#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif // #ifndef RTLCORELIBRARY_H_

