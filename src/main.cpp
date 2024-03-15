#include "parser/parser.hpp"

int main()
{
    // start input loop
    Parser parser;
    parser.start();
    // return exit code of the parser, if there were any errors, it gets reported back here
    return parser.exit;
}
