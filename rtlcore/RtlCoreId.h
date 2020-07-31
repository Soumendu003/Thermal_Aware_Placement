#ifndef RTLCOREID_H_
#define RTLCOREID_H_

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreIdDef
{
public:
    explicit RtlCoreIdDef(const char *name): _name(name) {}
    ~RtlCoreIdDef() {}


private:
    // Prevent compiler from defining the following
    RtlCoreIdDef(const RtlCoreIdDef &) ;            // Purposely leave unimplemented
    RtlCoreIdDef& operator=(const RtlCoreIdDef &) ; // Purposely leave unimplemented

public:
    const char * GetName const { return _name ; }

private:
    const char *_name ;


} ; // class RtlCoreIdDef


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif
