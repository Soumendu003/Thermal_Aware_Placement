#ifndef MAP_H_
#define MAP_H_

#include "ThermPlannerSystem.h"
#include "Hash.h"
#include <map>
#include <unordered_map>
#include <memory>


#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

    template <class K, class V, class H = DefaultHash<K>>
    using Map = std::map <K, V, typename H::less, std::allocator<std::pair<const K,V>>> ;

    template <class K, class V, class H = DefaultHash<K>>
    using MultiMap = std::multimap <K, V, typename H::less, std::allocator<std::pair<const K,V>>> ;

    template <class K, class V, class H = DefaultHash<K>>
    using UnorderedMap = std::unordered_map <K, V, typename H::hash, typename H::equal_to, std::allocator<std::pair<const K,V>>> ;

    template <class K, class V, class H = DefaultHash<K>>
    using UnorderedMultiMap = std::unordered_multimap <K, V, typename H::hash, typename H::equal_to, std::allocator<std::pair<const K,V>>> ;




#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif


#endif // #ifndef MAP_H_
