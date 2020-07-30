#include "Hash.h"
#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif 

std::size_t Hash::ComputeStringHash_4bit(const char *val) 
{
    unsigned len = strlen(val) ;
    auto OffsetBasis = UINT32_C(2166136261) ;
    auto Prime = UINT32_C(16777619) ;

    const auto cdata = reinterpret_cast<const unsigned char *>(const_cast<const char *>(val));
    auto acc = OffsetBasis ; 

    for (auto i = size_t {}; i < len; ++i)
    {
        const auto next = std::size_t {cdata[i]};
        acc = (acc ^ next) * Prime;
    }
    return acc ;
}

std::size_t Hash::ComputeStringHash_8bit(const char *val) 
{
    unsigned len = strlen(val) ;
    auto OffsetBasis = UINT64_C(14695981039346656037) ;
    auto Prime = UINT64_C(1099511628211) ;

    const auto cdata = reinterpret_cast<const unsigned char *>(const_cast<const char *>(val));
    auto acc = OffsetBasis ; 

    for (auto i = size_t {}; i < len; ++i)
    {
        const auto next = std::size_t {cdata[i]};
        acc = (acc ^ next) * Prime;
    }
    return acc ;
}


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif
