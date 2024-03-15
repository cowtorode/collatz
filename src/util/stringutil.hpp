//
// Created by cory on 3/7/24.
//

#ifndef COLLATZ_STRINGUTIL_HPP
#define COLLATZ_STRINGUTIL_HPP

#include <string>
#include <vector>

class StringUtil
{
public:
    static void lower( std::string &s );

    static std::vector<std::string> split( char ch, const std::string &in );

    static bool equalsIgnoreCase( const std::string &s0, const std::string &s1 );

    static void printVec(const std::vector<std::string> &vec);
};


#endif //COLLATZ_STRINGUTIL_HPP
