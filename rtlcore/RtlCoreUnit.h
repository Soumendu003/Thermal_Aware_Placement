#ifndef RTLCOREUNIT_H_
#define RTLCOREUNIT_H_

#include "ThermPlannerSystem.h"
#include "RtlCoreClassIds.h"
#include "Array.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreExpression ;
class RtlCoreScope ;

class RtlCoreUnit
{
protected: // Abstract class
    explicit RtlCoreUnit(const char *name): _name(name) {}
    virtual ~RtlCoreUnit() {}

private:
    // Prevent compiler from defining the following
    RtlCoreUnit(const RtlCoreUnit &) ;            // Purposely leave unimplemented
    RtlCoreUnit& operator=(const RtlCoreUnit &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const = 0 ; // Ids defined in RtlCoreClassIds.h

protected:
    const char          *_name ;
    
} ; // class RtlCoreUnit


class RtlCoreModule : public RtlCoreUnit
{
public:
    RtlCoreModule(const char *name, Array<RtlCoreExpression *> *port_connects, RtlCoreScope *scope):
        RtlCoreUnit(name), _port_connects(port_connects), _scope(scope) {}
    ~RtlCoreModule() {}

private:
    // Prevent compiler from defining the following
    RtlCoreModule(const RtlCoreModule &) ;            // Purposely leave unimplemented
    RtlCoreModule& operator=(const RtlCoreModule &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_MODULE ; } // Ids defined in RtlCoreClassIds.h

    Array<RtlCoreExpression *>     GetPortConnects()  { return _port_connects ; }
    RtlCoreScope *                 GetScope()         { return _this_scope ; }  

private:
    Array<RtlCoreExpression *>      *_port_connects ; 
    RtlCoreScope                    *_this_scope ;

} ; // class RtlCoreModule


class RtlCoreGate : public RtlCoreUnit
{
public:
    explicit RtlCoreGate(const char *name): RtlCoreUnit(name) {}
    ~RtlCoreGate() {}

private:
    // Prevent compiler from defining the following
    RtlCoreGate(const RtlCoreGate &) ;            // Purposely leave unimplemented
    RtlCoreGate& operator=(const RtlCoreGate &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_GATE ; } // Ids defined in RtlCoreClassIds.h

} ; // class RtlCoreGate


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif
