//
// Created by cory on 3/7/24.
//

#include <iostream>
#include "../collatz.hpp"
#include "parser.hpp"
#include "../util/stringutil.hpp"


void Parser::collatz( unsigned long num ) const
{
    // CollatzRunner::collatz( num );
}

void Parser::help() const
{
    Command* current = commands;

    // iterate through commands and print info about them
    std::cout << "Commands:" << std::endl;
    do
    {
        // print each initial root for the command (the 'first' alias)
        std::cout << "- " << current->aliases[ 0 ];
        // time to print the params

        std::string param;
        for ( const unsigned char &c : current->subcommands->params )
        {
            // this just calculates what is needed to be added based on the parameter unsigned char array
            static std::string paramMapping[] = { "char", "short", "int", "long", "float", "double" };
            // build the parameters
            if ( c & UNSIGNED )
            {
                param += "unsigned ";
            }
            for ( int i = 0; i < 6; i++ )
            {
                if ( c & ( 0b1 << i ))
                {
                    param += paramMapping[ i ];
                }
            }
            std::cout << " <" << param << ">";
        }

        std::cout << std::endl;
        // print the spaces only if there are any aliases. The for loop would terminate,
        // but the spaces would still print so we need this check for formatting.
        if ( current->aliases.size() > 1 )
        {
            std::cout << "  ";
            for ( std::size_t i = 1; i < current->aliases.size() - 1; i++ )
            {
                // std::cout << i << std::endl;
                // print all the rest of the aliases
                std::cout << current->aliases[ i ] << ", ";
            }
            std::cout << current->aliases[ current->aliases.size() - 1 ] << std::endl;
        }

    } while (( current = current->next ) != nullptr );
}

Parser::Parser() : terminators( { "exit", "stop", "quit", "leave", "close", "terminate", "escape" } )
{
    commands = new Command;

    commands->aliases = { "collatz" };
    commands->subcommands = new SubCommand( this, &Parser::collatz, { UNSIGNED | LONG } );

    auto* next = new Command;
    commands->next = next;

    next->aliases = { "help", "commands", "cmds" };
    next->subcommands = new SubCommand( this, &Parser::help ); // no params to set here
    Parser::help(); // call help to list commands after init of all commands
}

Parser::~Parser()
{
    delete commands;
}

bool Parser::parse( std::string in )
{
    StringUtil::lower( in );
    // split by spaces to get arguments
    std::vector<std::string> args = StringUtil::split( ' ', in );

    // the first element is always added in the split method, so it's not args.empty();
    // if empty ignore input
    if ( args[ 0 ].empty())
    {
        return true;
    }

    // check if first arg says to exit
    for ( auto &s : terminators )
    {
        if ( s == args[ 0 ] )
        {
            std::cout << "exit" << std::endl;
            // return false if terminate
            return false;
        }
    }

    // SELECT FUNCTION THAT FIRST ARGUMENT REFERS TO
    Command* current = commands;

    do
    {
        // debug functions
        // StringUtil::printVec( current->aliases );
        // iterate through commands until found matching

        // if arg[0] is listed in the current command as an alias, break because
        // we've selected the correct command object with all the functional data
        for ( const auto &s : current->aliases )
        {
            if ( s == args[ 0 ] )
            {
                goto found;
            }
        }

    } while (( current = current->next ) != nullptr );

    // not found if loop is escaped
    std::cout << "Unknown Command: " << in << std::endl;
    return true;

    found:
    // std::cout << "found: ";
    // print found to make sure
    // StringUtil::printVec( current->aliases );
    // BY THIS POINT THE COMMAND HAS BEEN SELECTED, THAT IS IT, TIME TO FIGURE OUT ARGUMENTS

    // iterate through the rest of the args
    // should terminate immediately if no args
    for ( int i = 1; i < args.size(); i++ )
    {

    }

    return true;
}

void Parser::start()
{
    std::cout
            << R"(________/\\\\\\\\\________________/\\\\\\_____/\\\\\\_______________________________________________)"
            << std::endl <<
            R"( _____/\\\////////________________\////\\\____\////\\\_______________________________________________)"
            << std::endl <<
            R"(  ___/\\\/____________________________\/\\\_______\/\\\_______________________/\\\____________________)"
            << std::endl <<
            R"(   __/\\\_________________/\\\\\_______\/\\\_______\/\\\_____/\\\\\\\\\_____/\\\\\\\\\\\__/\\\\\\\\\\\_)"
            << std::endl <<
            R"(    _\/\\\_______________/\\\///\\\_____\/\\\_______\/\\\____\////////\\\___\////\\\////__\///////\\\/__)"
            << std::endl <<
            R"(     _\//\\\_____________/\\\__\//\\\____\/\\\_______\/\\\______/\\\\\\\\\\_____\/\\\___________/\\\/____)"
            << std::endl <<
            R"(      __\///\\\__________\//\\\__/\\\_____\/\\\_______\/\\\_____/\\\/////\\\_____\/\\\_/\\_____/\\\/______)"
            << std::endl <<
            R"(       ____\////\\\\\\\\\__\///\\\\\/____/\\\\\\\\\__/\\\\\\\\\_\//\\\\\\\\/\\____\//\\\\\____/\\\\\\\\\\\_)"
            << std::endl <<
            R"(        _______\/////////_____\/////_____\/////////__\/////////___\////////\//______\/////____\///////////__)"
            << std::endl << std::endl << "- - - - - - - - - -" << std::endl << "Cory Torode   " << std::endl
            << std::endl;

    std::string in;

    do
    {
        std::cout << "> ";
        std::getline( std::cin, in );

        // run while exit == 0 and parse says to continue
    } while ( exit == 0 && parse( in ) );
}
