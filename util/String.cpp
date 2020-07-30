#include "String.h"
#include "ThermPlannerSystem.h"
#include <cstring> // strlen(), memcpy()
#include <cstdlib> // atoi(), stoi()
#include<cstdio>   // sprintf()
#include <cctype>  // tolower()
#include <iostream>

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif 

// Initialize the static string set of String Class.
UnorderedSet<const char*, StringHash<const char*>> * String::_static_string_set = 0 ;

void String::InsertConstantString(const char *s)
{
    if (!String::_static_string_set) String::_static_string_set = new  UnorderedSet<const char*, StringHash<const char*>> ;
    String::_static_string_set->insert(s) ;
}


unsigned String::len(const char *s)
{
    return (unsigned)strlen(s) ;
}

void String::free(char *s)
{
    delete[] s ;
}

void String::CleanupStaticStringSet()
{
    if (!String::_static_string_set) return ;

    for(auto it = String::_static_string_set->begin(); it != String::_static_string_set->end(); it++) {
        delete[] *(it) ;
    }
    delete String::_static_string_set ;
}

char* String::itoa(int i, int base)
{
    char *ret_val = new char[sizeof(int)*8+1] ; // 1 more for terminating nulll.
    if (base == 10) {
        THERMPLANNER_ASSERT_MSG(sprintf(ret_val, "%d", i) >= 0, "Failed itoa() for decimal base") ;
    } else if (base == 16) {
        THERMPLANNER_ASSERT_MSG(sprintf(ret_val, "%x", i) >= 0, "Failed itoa() for hexadecimal base") ;
    } else if (base == 8) {
        THERMPLANNER_ASSERT_MSG(sprintf(ret_val, "%o", i) >= 0, "Failed itoa() for octal base") ;
    } else {
        THERMPLANNER_ASSERT_MSG(0, "Can't have base other than 10, 16, 8 for itoa()") ;
    }

    return ret_val ;
}

int String::atoi(const char *s)
{
    return atoi(s) ; // atoi() in <cstdlib>
}

unsigned String::compare(const char *str1, const char *str2)
{
    if (str1 == str2) return 1 ;   // Pointing to same memory location. So must be equal.

    if (!str1 || !str2) return 0 ; // If any one is null, then can't be equal logically.

    unsigned i = 0 ;
    while(str1[i] != 0 && str2[i] != 0) 
    {
        if (str1[i] != str2[i]) return 0 ;
        i += 1 ;
    }

    if (str1[i] == str2[i]) return 1 ; // checks if both str1[i] and str2[i] is null.

    return 0 ;
}

unsigned String::compare_nocase(const char *str1, const char *str2)
{
    if (str1 == str2) return 1 ;   // Pointing to same memory location. So must be equal.

    if (!str1 || !str2) return 0 ; // If any one is null, then can't be equal logically.

    unsigned i = 0 ;
    while(str1[i] != 0 && str2[i] != 0) 
    {
        if (tolower(str1[i]) != tolower(str2[i])) return 0 ;
        i += 1 ;
    }

    if (str1[i] == str2[i]) return 1 ; // checks if both str1[i] and str2[i] is null.

    return 0 ;
}

unsigned String::compare_n(const char *str1, const char *str2, unsigned n)
{
    if (str1 == str2) return 1 ;   // Pointing to same memory location. So must be equal.

    if (!str1 || !str2) return 0 ; // If any one is null, then can't be equal logically.

    unsigned i = 0 ;
    while(str1[i] != 0 && str2[i] != 0 && i < n) 
    {
        if (str1[i] != str2[i]) return 0 ;
        i += 1 ;
    }

    if (i == n) return 1 ;

    if (str1[i] == str2[i]) return 1 ; // checks if both str1[i] and str2[i] is null.

    return 0 ;
}

unsigned String::compare_nocase_n(const char *str1, const char *str2, unsigned n)
{
    if (str1 == str2) return 1 ;   // Pointing to same memory location. So must be equal.

    if (!str1 || !str2) return 0 ; // If any one is null, then can't be equal logically.

    unsigned i = 0 ;
    while(str1[i] != 0 && str2[i] != 0 && i < n) 
    {
        if (tolower(str1[i]) != tolower(str2[i])) return 0 ;
        i += 1 ;
    }

    if (i == n) return 1 ;

    if (str1[i] == str2[i]) return 1 ; // checks if both str1[i] and str2[i] is null.

    return 0 ;
}

char* String::save(const char *s)
{
    if (!s) return 0 ;

    unsigned len = String::len(s) ;

    char *ret_val = new char[len+1] ; // 1 more for the terminating null character

    memcpy(ret_val, s, len+1) ;
    return ret_val ;
}
    
char* String::save(const char *s1, const char *s2, const char *s3, const char *s4)
{
    unsigned len_array[4] ;

    len_array[0] = s1 ? String::len(s1) : 0 ;
    len_array[1] = s2 ? String::len(s2) : 0 ;
    len_array[2] = s3 ? String::len(s3) : 0 ;
    len_array[3] = s4 ? String::len(s4) : 0 ;

    unsigned tot_len = 0 ;

    for (unsigned i = 0; i < 4; i++) {
        tot_len += len_array[i] ;
    }

    char *ret_val = new char[tot_len + 1] ;
    
    unsigned last_ptr = 0 ;

    memcpy(ret_val, s1, len_array[0]) ;
    last_ptr = len_array[0] ;

    memcpy(ret_val+last_ptr, s2, len_array[1]) ;
    last_ptr += len_array[1] ;

    memcpy(ret_val+last_ptr, s3, len_array[2]) ;
    last_ptr += len_array[2] ;

    memcpy(ret_val+last_ptr, s4, len_array[3]) ;
    ret_val[tot_len] = 0 ; // puts terminating null

    return ret_val ;
}

const char*  String::CreateConstantString(const char *s)
{
    if (String::_static_string_set) {
        auto it = String::_static_string_set->find(s) ;
        if (it != String::_static_string_set->end()) {
            return *(it) ;
        }
    }
    const char *ret_val = String::save(s) ;
    String::InsertConstantString(ret_val) ;
    return ret_val ;
}

#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif
