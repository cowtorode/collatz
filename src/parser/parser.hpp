//
// Created by cory on 3/7/24.
//

#ifndef COLLATZ_PARSER_HPP
#define COLLATZ_PARSER_HPP

#include <string>
#include <vector>
#include "command.hpp"

class Parser
{
private:
    /**
     * A list of std::string_view's that when the first part of
     * the input up to the first ' ' is equal to an
     * element of this list, the input loop is closed
     */
    std::vector<std::string_view> terminators;
    /**
     * Linked list of Command objects, each storing a list of
     * aliases which the parser uses to select the specific Command
     * object, each storing further SubCommand data.
     */
    Command* commands;

    /**
     * Collatz print method
     * @param num Parameter 0, ...
     */
    void collatz( unsigned long num ) const;

    /**
     * Iterates through the commands linked list and prints
     * information about each Command according to it's structure.
     */
    void help() const;

    /**
     * Parses and executes a specified string command.
     * @param in Input command that requests an execution of a specific operation
     * @return True if continues loop, false if broken due to termination, but not to exit being set.
     */
    bool parse( std::string in );

public:
    /**
     * Resulting exit code set in case of any errors during processing.
     * If this is not 0, the input loop is broken.
     */
    int exit = 0;

    /**
     * Construct Commands and terminators.
     */
    Parser();

    /**
     * Delete Command linked list, and recursively all SubCommands.
     */
    ~Parser();

    /**
     * Start input loop.
     */
    void start();
};


#endif //COLLATZ_PARSER_HPP
