#ifndef SET_H_
#define SET_H_

#include "ThermPlannerSystem.h"
#include "Hash.h"
#include <set>
#include <unordered_set>
#include <memory>


#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

    template <class K, class H = DefaultHash<K>>
    using Set = std::set <K, typename H::less, std::allocator<K>> ;

    template <class K, class V, class H = DefaultHash<K>>
    using MultiSet = std::multiset <K, typename H::less, std::allocator<K>> ;

    template <class K, class H = DefaultHash<K>>
    using UnorderedSet = std::unordered_set <K, typename H::hash, typename H::equal_to, std::allocator<K>> ;

    template <class K, class V, class H = DefaultHash<K>>
    using UnorderedMultiSet = std::unordered_multiset <K, typename H::hash, typename H::equal_to, std::allocator<K>> ;




#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif


#endif // #ifndef SET_H_
