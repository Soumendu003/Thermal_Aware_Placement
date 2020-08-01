#include "RtlCoreExpression.h"

#include "RtlCoreId.h"

void RtlCoreIdRef::BindId(RtlCoreIdDef *id)
{
    if (!_id) THERMPLANNER_ASSERT_MSG(0, "Can't reassign identifier definition for idref") ;
    _id = id ;
}
