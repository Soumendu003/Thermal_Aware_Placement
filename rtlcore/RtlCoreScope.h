#ifndef RTLCORESCOPE_H_
#define RTLCORESCOPE_H_

#include "ThermPlannerSystem.h"
#include "Map.h"
#include "RtlCoreId.h"


#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif


class RtlCoreScope
{
public:
    explicit RtlCoreScope(RtlCoreScope *upper = 0, RtlCoreIdDef *owner): _upper(upper), _owner(owner) 
    {
        _curr_scope = new UnorderedMap<const char *, RtlCoreIdDef *, StringHash<const char *>> ;
    }
    ~RtlCoreScope()                         
    {
        for (auto it = _curr_scope->begin(); it != _curr_scope->end(); it++) delete it->second ; // since values created by VeriScope.
        delete _curr_scope ; 
    }

private:
    // Prevent compiler from defining the following
    RtlCoreScope(const RtlCoreScope &) ;            // Purposely leave unimplemented
    RtlCoreScope& operator=(const RtlCoreScope &) ; // Purposely leave unimplemented

public:
    void SetUpper(RtlCoreScope *upper)      { _upper = upper ; }
    void SetOwner(RtlCoreIdDef *owner)      { _owner = owner ; }

    RtlCoreScope * GetUpperScope()           { return _upper ; }
    RtlCoreScope * GetOwner()                { return _owner ; }

    UnorderedMap<const char *, RtlCoreIdDef *, StringHash<const char *>>* GetCurrentScope() { return _curr_scope ; }

    // Add identifier to the scope. (return 1 if id by that name was not there, 0 if such a name is already declared here).
    // Set var_id with newly created VeriIdDef if successfull. Otherwise assign it the previous id.
    unsigned Declare(const char *name, VeriIdDef **var_id)
    {
       VeriIdDef *id = Find(name) ;
        if (!id){
            VeriIdDef *tem = new VeriIdDef(name) ;
            _curr_scope->insert({name, tem}) ;
            *var_id = tem ;
            return 1 ;
        }
        *var_id = id ;
        return 0 ;
    }

    // Find identifiers in the scope
    VeriIdDef * Find(const char *name)
    {
        auto it = _curr_scope->find(name) ;
        if (it != _curr_scope->end())   return it->second ;
        else                            return 0 ;
    }

private:
    RtlCoreScope    *_upper ;
    RtlCoreIdDef    *_owner ;
    UnorderedMap<const char *, RtlCoreIdDef *, StringHash<const char *>> *_curr_scope ;

} ; // class RtlCoreScope


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif
