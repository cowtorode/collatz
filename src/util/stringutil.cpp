//
// Created by cory on 3/7/24.
//

#include "stringutil.hpp"

std::vector<std::string> StringUtil::split( char ch, const std::string &in )
{
    std::vector<std::string> ret;
    std::string curr;

    for ( const char &c : in )
    {
        if ( c == ch )
        {
            ret.push_back( curr );
            curr = "";
        } else
        {
            curr += c;
        }
    }
    // account for last iteration
    ret.push_back(curr);

    return ret;
}

bool StringUtil::equalsIgnoreCase( const std::string &s0, const std::string &s1 )
{
    // if lengths are not equal, then the strings definitely can't be equal
    if ( s0.length() != s1.length())
    {
        return false;
    }

    // length here doesn't matter since they're the same
    for ( int i = 0; i < s0.length(); i++ )
    {
        if ( tolower( s0[ i ] ) != tolower( s1[ i ] ))
        {
            return false;
        }
    }

    // they are equal (if they pass all the checks)
    return true;
}

bool StringUtil::continues( const std::string &in )
{
    return !equalsIgnoreCase( in, "exit" );
}
