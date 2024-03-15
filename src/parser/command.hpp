//
// Created by cory on 3/13/24.
//

#ifndef COLLATZ_COMMAND_HPP
#define COLLATZ_COMMAND_HPP

#include "subcommand.hpp"

struct Command
{
    /**
     * Linked list of commands
     */
    Command* next = nullptr;

    /**
     * Aliases of the Command used by the parser to select if the first argument up to the first ' '
     * is an element of this list. For all Command objects, each element is uniquely defined in only
     * one array.
     */
    std::vector<std::string_view> aliases;
    /**
     * List of SubCommand data, ...
     */
    SubCommand* subcommands;

    /**
     * Delete next Command and SubCommands
     */
    ~Command();
};


#endif //COLLATZ_COMMAND_HPP
