/**
 * Ims projekt: infrastruktura přepravy LNG 
 * @file  argparser.hpp
 *
 * @authors Jakub Komárek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

#include "main.hpp"

/**
 * parse input arguments from command line
 * @param argc argc from main - number of arguments
 * @param argv argv from main - array of string arguments
 */
void argparse(int argc, char** argv);

#endif