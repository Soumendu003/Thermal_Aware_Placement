#ifndef RTLCOREEXPRESSION_H_
#define RTLCOREEXPRESSION_H_

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class RtlCoreIdDef ;

class RtlCoreExpression
{
protected: // Abstract class
    RtlCoreExpression() {}
    virtual ~RtlCoreExpression() {}

private:
    // Prevent compiler from defining the following
    RtlCoreExpression(const RtlCoreExpression &) ;            // Purposely leave unimplemented
    RtlCoreExpression& operator=(const RtlCoreExpression &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const = 0 ; // Ids defined in RtlCoreClassIds.h

} ; // class RtlCoreExpression


class RtlCoreIdRef: public RtlCoreExpression
{
public:
    RtlCoreIdRef(const char *name, RtlCoreIdRef *id = 0): _name(name), _id(id) {}
    ~RtlCoreIdRef() {}

private:
    // Prevent compiler from defining the following
    RtlCoreIdRef(const RtlCoreIdRef &) ;            // Purposely leave unimplemented
    RtlCoreIdRef& operator=(const RtlCoreIdRef &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_IDREF ; } // Ids defined in RtlCoreClassIds.h

    const char *GetName()                             { return _name ; }  

    void BindId(RtlCoreIdDef *id) ;
    RtlCoreIdDef * GetId()                            { return _id ; }

private:
    const char      *_name ; // name of the identifier
    RtlCoreIdDef    *_id ;   // id definition

} ; // class RtlCoreIdRef

class RtlCoreConcat: public RtlCoreExpression
{
public:
    RtlCoreConcat() {}
    ~RtlCoreConcat() {}

private:
    // Prevent compiler from defining the following
    RtlCoreConcat(const RtlCoreConcat &) ;            // Purposely leave unimplemented
    RtlCoreConcat& operator=(const RtlCoreConcat &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_CONCAT ; } // Ids defined in RtlCoreClassIds.h

} ; // class RtlCoreConcat

class RtlCorePortConnect: public RtlCoreExpression
{
public:
    RtlCorePortConnect() {}
    ~RtlCorePortConnect() {}

private:
    // Prevent compiler from defining the following
    RtlCorePortConnect(const RtlCorePortConnect &) ;            // Purposely leave unimplemented
    RtlCorePortConnect& operator=(const RtlCorePortConnect &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_PORTCONNECT ; } // Ids defined in RtlCoreClassIds.h

} ; // class RtlCorePortConnect


class RtlCoreRange: public RtlCoreExpression
{
public:
    RtlCoreRange() {}
    ~RtlCoreRange() {}

private:
    // Prevent compiler from defining the following
    RtlCoreRange(const RtlCoreRange &) ;            // Purposely leave unimplemented
    RtlCoreRange& operator=(const RtlCoreRange &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_RANGE ; } // Ids defined in RtlCoreClassIds.h

} ; // class RtlCoreRange

class RtlCoreIndexedId: public RtlCoreExpression
{
public:
    RtlCoreIndexedId() {}
    ~RtlCoreIndexedId() {}

private:
    // Prevent compiler from defining the following
    RtlCoreIndexedId(const RtlCoreIndexedId &) ;            // Purposely leave unimplemented
    RtlCoreIndexedId& operator=(const RtlCoreIndexedId &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_INDEXEDID ; } // Ids defined in RtlCoreClassIds.h

} ; // class RtlCoreIndexedId

class RtlCoreDataType: public RtlCoreExpression
{
public:
    RtlCoreDataType() {}
    ~RtlCoreDataType() {}

private:
    // Prevent compiler from defining the following
    RtlCoreDataType(const RtlCoreDataType &) ;            // Purposely leave unimplemented
    RtlCoreDataType& operator=(const RtlCoreDataType &) ; // Purposely leave unimplemented

public:
    // ThermPlanner's RTTI method.  (ANSI's C++ RTTI is too expensive)
    virtual RTLCORE_CLASS_ID       GetClassId() const { return ID_RTLCORE_DATATYPE ; } // Ids defined in RtlCoreClassIds.h

} ; // class RtlCoreDataType





#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif
