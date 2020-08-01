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
    explicit RtlCoreScope(RtlCoreScope *upper = 0, RtlCoreIdDef *owner = 0): _upper(upper), _owner(owner) 
    {
        _curr_scope = new UnorderedMap<const char *, RtlCoreIdDef *, StringHash<const char *>> ;
    }
    ~RtlCoreScope()                         
    {
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
    // Set existing_id if Declare() fails because of already declared name.
    unsigned Declare(VeriIdDef *id, VeriIdDef **existing_id)
    {
       VeriIdDef *pre_id = Find(id->GetName()) ;
        if (!pre_id){
            _curr_scope->insert({name, id}) ;
            return 1 ;
        }
        *existing_id = pre_id ;
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
