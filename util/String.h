#ifndef STRING_H_
#define STRING_H_

#include "ThermPlannerSystem.h"
#include "Set.h"

#ifdef THERMPLANNER_NAMESPACE
namespace ThermPlanner{
#endif 

class String 
{
private :
    String() ;  // This class should never get instantiated (make this private)
    ~String() ;

    // Prevent compiler from defining the following
    String(const String &) ;            // Purposely leave unimplemented
    String& operator=(const String &) ; // Purposely leave unimplemented

public:

    static unsigned      len(const char *s) ;

    // Save and concatenate Strings
    static char *        save(const char *s) ; // save a single string to new memory
    static char *        save(const char *s1, const char *s2, const char *s3=0, const char *s4=0) ; // concatenate strings and return in new memory

    static const char *  CreateConstantString(const char *s) ; // This method returns a constant string for the given input. The constant string is cached in a static set. If the string already exists in the set, the same string is returned. Naturally the string should not be modified or free'd as it is shared by many objects

    // static char *        allocate(unsigned long size);

    // Free strings
    static void          free(char *s) ;
    static void          CleanupStaticStringSet() ; // Method to free the static string set including its elements, typically when deleting the parse tree


    // Translate integer to saved Strings or opposite
    static char *        itoa(int i, int base = 10) ;
    static int           atoi(const char *s) ;

    // Compare Strings. Return 1 if equal. 0 if not
    static unsigned      compare(const char *str1, const char *str2) ;
    static unsigned      compare_nocase(const char *str1, const char *str2) ;
    static unsigned      compare_n(const char *str1, const char *str2, unsigned n) ;
    static unsigned      compare_nocase_n(const char *str1, const char *str2, unsigned n) ;

private:
    static void InsertConstantString(const char *s) ;

private:
    static UnorderedSet<const char*, StringHash<const char*>>    *_static_string_set ; // To cache constant char pointers in the parse tree

} ; // class String

#ifdef THERMPLANNER_NAMESPACE
} // end definitions in ThermPlanner namespace
#endif

#endif // #ifndef STRING_H_

