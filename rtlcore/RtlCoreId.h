#ifndef RTLCOREID_H_
#define RTLCOREID_H_

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreIdDef
{
protected: // Abstract class
    explicit RtlCoreIdDef(const char *name): _name(name) {}
    virtual ~RtlCoreIdDef() {}

private:
    // Prevent compiler from defining the following
    RtlCoreIdDef(const RtlCoreIdDef &) ;            // Purposely leave unimplemented
    RtlCoreIdDef& operator=(const RtlCoreIdDef &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const = 0 ; // Ids defined in RtlCoreClassIds.h

    const char * GetName const { return _name ; }

protected:
    const char *_name ;


} ; // class RtlCoreIdDef

class RtlCoreVariable: public VeriIdDef
{
public:
    explicit RtlCoreVariable(const char *name): VeriIdDef(name) {}
    ~RtlCoreVariable() {}

private:
    // Prevent compiler from defining the following
    RtlCoreVariable(const RtlCoreVariable &) ;            // Purposely leave unimplemented
    RtlCoreVariable& operator=(const RtlCoreVariable &) ; // Purposely leave unimplemented


public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_VARIABLE ; } // Ids defined in RtlCoreClassIds.h


} ; // class RtlCoreVariable 


class RtlCoreInstId: public VeriIdDef
{
public:
    explicit RtlCoreInstId(const char *name): VeriIdDef(name) {}
    ~RtlCoreInstId() {}

private:
    // Prevent compiler from defining the following
    RtlCoreInstId(const RtlCoreInstId &) ;            // Purposely leave unimplemented
    RtlCoreInstId& operator=(const RtlCoreInstId &) ; // Purposely leave unimplemented


public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_INSTID ; } // Ids defined in RtlCoreClassIds.h


} ; // class RtlCoreInstId 


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif
