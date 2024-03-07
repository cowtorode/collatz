//
// Created by cory on 3/7/24.
//

#include <iostream>
#include "collatz.hpp"
#include "parser.hpp"
#include "util/stringutil.hpp"

void CommandParser::parse( const std::string &in )
{
    std::vector<std::string> args = StringUtil::split( ' ', in );

    switch ( args.size())
    {
        case 2:
            if ( StringUtil::equalsIgnoreCase( args[ 0 ], "collatz" ))
            {
                CollatzRunner::CollatzResult result = CollatzRunner::collatz( std::stoul( args[ 1 ] ));

                std::cout << "Number: " << result.num << std::endl
                          << "Steps: " << result.steps << std::endl
                          << "Max: " << result.peak << std::endl;
            }
            break;
    }

}

void CommandParser::start()
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
            << std::endl << std::endl;

    std::string in;

    do
    {
        std::cout << "> ";
        std::getline( std::cin, in );

        parse( in );
    } while ( exit == 0 && StringUtil::continues( in ));
}
