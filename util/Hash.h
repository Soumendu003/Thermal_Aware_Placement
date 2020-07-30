#ifndef HASH_H_
#define HASH_H_

#include "ThermPlannerSystem.h"
#include <functional>
#include <cstring>

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif

class Hash
{
private :
    Hash() ;  // This class should never get instantiated (make this private)
    ~Hash() ;

    // Prevent compiler from defining the following
    Hash(const Hash &) ;            // Purposely leave unimplemented
    Hash& operator=(const Hash &) ; // Purposely leave unimplemented

public :
    static std::size_t ComputeStringHash_4bit(const char *str) ;
    static std::size_t ComputeStringHash_8bit(const char *str) ;

} ; // class Hash

template <class T>
struct StringHashVal
{
    inline std::size_t operator()(const T &val) const noexcept
    {
        THERMPLANNER_ASSERT_MSG(0, "Using anything except const char* or char* as StringHash is prohibited") ;
        return std::hash<T>()(val);
    }
} ;

template <class T>
struct StringHashVal<T *>
{
    inline std::size_t operator()(const T *val) const noexcept
    {
        THERMPLANNER_ASSERT_MSG(0, "Using anything except const char* or char* as StringHash is prohibited") ;
        return static_cast<size_t>(reinterpret_cast<const uintptr_t>(val)) ; 
    }
} ;

template <>
struct StringHashVal<const char *>
{
    inline std::size_t operator()(const char *val) const noexcept
    {
        if (sizeof(std::size_t) == 8) return Hash::ComputeStringHash_8bit(val) ;
        else return Hash::ComputeStringHash_4bit(val) ;
    }
} ;

template <>
struct StringHashVal<char *>
{
    inline std::size_t operator()(const char *val) const noexcept
    {
        if (sizeof(std::size_t) == 8) return Hash::ComputeStringHash_8bit(val) ;
        else return Hash::ComputeStringHash_4bit(val) ;
    }
} ;

template <class T>
struct StringEq
{
    inline bool operator()(const T &a, const T &b) const
    {
        THERMPLANNER_ASSERT_MSG(0, "Using anything except const char* or char* as StringEq is prohibited") ;
        return std::equal_to<T>(a, b) ;
    }
} ;

template <class T>
struct StringEq<T *>
{
    inline bool operator()(const T *a, const T *b) const
    {
        THERMPLANNER_ASSERT_MSG(0, "Using anything except const char* or char* as StringEq is prohibited") ;
        return (a == b) ;
    }
} ;

template<>
struct StringEq<const char *>
{
    inline bool operator()(const char *a, const char *b) const
    {
        return (strcmp(a,b) == 0) ;
    }
} ;

template<>
struct StringEq<char *>
{
    inline bool operator()(const char *a, const char *b) const
    {
        return (strcmp(a,b) == 0) ;
    }
} ;

template <class T>
struct StringLess
{
    inline bool operator()(const T &a, const T &b) const
    {
        THERMPLANNER_ASSERT_MSG(0, "Using anything except const char* or char* as StringLess is prohibited") ;
        return std::less<T>(a, b) ;
    }
} ;

template <class T>
struct StringLess<T *>
{
    inline bool operator()(const T *a, const T *b) const
    {
        THERMPLANNER_ASSERT_MSG(0, "Using anything except const char* or char* as StringLess is prohibited") ;
        return a < b ;
    }
} ;

template<>
struct StringLess<const char *>
{
    inline bool operator()(const char *a, const char *b) const
    {
        return (strcmp(a,b) < 0) ;
    }
} ;

template<>
struct StringLess<char *>
{
    inline bool operator()(const char *a, const char *b) const
    {
        return (strcmp(a,b) < 0) ;
    }
} ;


template <class T, class E = void>
struct DefaultHash
{
    using hash = std::hash<T> ;
    using equal_to = std::equal_to<T> ;
    using less = std::less<T> ;
} ;

template <class T, class E = void>
struct StringHash
{
    using hash = StringHashVal<T> ;
    using equal_to = StringEq<T> ;
    using less = StringLess<T> ;
} ;


#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif
    

#endif // #ifndef HASH_H_

