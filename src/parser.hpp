//
// Created by cory on 3/7/24.
//

#ifndef COLLATZ_PARSER_HPP
#define COLLATZ_PARSER_HPP

#include <string>

class CommandParser
{
private:
    /**
     * @param in Input command that requests an execution of a specific operation
     */
    void parse( const std::string &in );
public:
    int exit = 0;

    void start();
};


#endif //COLLATZ_PARSER_HPP
