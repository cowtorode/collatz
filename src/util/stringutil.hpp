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
    static std::vector<std::string> split( char ch, const std::string &in );

    static bool equalsIgnoreCase( const std::string &s0, const std::string &s1 );

    static bool continues( const std::string &in );
};


#endif //COLLATZ_STRINGUTIL_HPP
