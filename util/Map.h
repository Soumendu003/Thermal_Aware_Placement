#ifndef MAP_H_
#define MAP_H_

#include "ThermPlannerSystem.h"

#ifdef THERMPLANNER_PARALLEL_HASHMAP
    #include "phmap.h"
    #include "btree.h"

    #ifdef THERMPLANNER_MEMORY_MANAGER
    #define MAP_ALLOC mi_stl_allocator
    #else
    #include <memory>
    #define MAP_ALLOC std::allocator
    #endif // #ifdef THERMPLANNER_MEMORY_MANAGER

#else   // uses stl map
    #include <map>  
    #include <unordered_map>
#endif 

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

#ifdef THERMPLANNER_PARALLEL_HASHMAP

    /* **********************************************************************************************************************
     * Key decision points for hash containers:
     *
     * The flat hash maps will move the keys and values in memory. So if you keep a pointer to something inside a flat 
     * hash map, this pointer may become invalid when the map is mutated. 
     *
     *
     * The parallel hash maps are preferred when you have a few hash maps that will store a very large number of values. 
     * The non-parallel hash maps are preferred if you have a large number of hash maps, each storing a relatively small 
     * number of values.
     *
     *
     * The benefits of the parallel hash maps are:
     *      a. reduced peak memory usage (when resizing), and
     *      b. multithreading support (and inherent internal parallelism)
     *
     * *********************************************************************************************************************
     */

    template <class K, class V,
              class Hash  = phmap::container_internal::hash_default_hash<K>,
              class Eq    = phmap::container_internal::hash_default_eq<K>,
              class Alloc = MAP_ALLOC<phmap::container_internal::Pair<const K, V>>> 
    using FlatMap = phmap::flat_hash_map<K, V, Hash, Eq, Alloc> ;

    template <class K, class V,
              class Hash  = phmap::container_internal::hash_default_hash<K>,
              class Eq    = phmap::container_internal::hash_default_eq<K>,
              class Alloc = MAP_ALLOC<phmap::container_internal::Pair<const K, V>>, 
              size_t N    = 4,                  // 2**N submaps
              class Mutex = phmap::NullMutex>   // use std::mutex to enable internal locks
    using ParallelFlatMap = phmap::parallel_flat_hash_map<K, V, Hash, Eq, Alloc, N, Mutex> ; 

    template <typename Key, typename Value, typename Compare = phmap::Less<Key>,
              typename Alloc = MAP_ALLOC<phmap::container_internal::Pair<const Key, Value>>>
    using BtreeMap = phmap::btree_map<Key, Value, Alloc> ;

    template <typename Key, typename Value, typename Compare = phmap::Less<Key>,
              typename Alloc = MAP_ALLOC<phmap::container_internal::Pair<const Key, Value>>>
    using BtreeMultiMap =  phmap::btree_multimap<Key, Value, Compare, Alloc> ;


#else


#endif // #ifdef THERMPLANNER_PARALLEL_HASHMAP


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif


#endif // #ifndef MAP_H_
