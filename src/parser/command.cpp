//
// Created by cory on 3/13/24.
//

#include "command.hpp"

Command::~Command()
{
    delete next;
    delete subcommands;
}