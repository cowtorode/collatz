//
// Created by cory on 3/14/24.
//

#ifndef COLLATZ_SUBCOMMAND_HPP
#define COLLATZ_SUBCOMMAND_HPP

// mapping of data types for the methods stored in SubCommand.
// If a parameter to one of those functions is unsigned char, it would be equal to UNSIGNED | CHAR.
// The list of parameters is then used by the parser to select the proper function to call.
constexpr unsigned char CHAR = 0b1 << 0;
constexpr unsigned char SHORT = 0b1 << 1;
constexpr unsigned char INT = 0b1 << 2;
constexpr unsigned char LONG = 0b1 << 3;
constexpr unsigned char FLOAT = 0b1 << 4;
constexpr unsigned char DOUBLE = 0b1 << 5;
constexpr unsigned char UNSIGNED = 0b1 << 6;

#include <vector>
#include <string>
#include <functional>

struct SubCommand
{
    /**
     * Function that takes in a list of arguments, converts them to
     * the labels expected arguments, and calls that function.
     */
    const std::function<void( const std::vector<std::string_view> & )> call;
    /**
     * List of parameters that the label function is defined for takes in
     * according to the mapping listed
     * \n\n
     * constexpr unsigned char CHAR = 0b1 << 0;\n
     * constexpr unsigned char SHORT = 0b1 << 1;\n
     * constexpr unsigned char INT =  0b1 << 2;\n
     * constexpr unsigned char LONG =  0b1 << 3;\n
     * constexpr unsigned char FLOAT =  0b1 << 4;\n
     * constexpr unsigned char DOUBLE =  0b1 << 5;\n
     * constexpr unsigned char UNSIGNED =  0b1 << 6;\n
     */
    const std::vector<unsigned char> params;
    const void* instance;

    template<typename T, typename... Params>
    SubCommand( T* instance, void (T::* label)( Params... ) const, std::vector<unsigned char> params )
            : call(
            // create wrapper method to handle the conversion
            [ label, &params, &instance ]( const std::vector<std::string_view> &args )
            {

                if ( params.empty())
                {
                    // instance->*label();
                }

            } ), params( std::move( params )), instance( instance )
    {
    }

    template<typename T, typename... Params>
    SubCommand( T* instance, void (T::* label)( Params... ) const ) : SubCommand( instance, label, { } )
    {
    }
};

#endif //COLLATZ_SUBCOMMAND_HPP
