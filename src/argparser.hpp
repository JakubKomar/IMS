/**
 * Ims projekt: infrastruktura prepravy LNG 
 * @file  argparser.hpp
 *
 * @authors Jakub Komarek (xkomar33)
 * @authors Kroupa Dominik (xkroup12)
 */

#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

#include "main.hpp"

/**
 * safe conversion from string to integer - preventing exception
 * @param  optarg string to convert
 * @return        converted value
 */
int safeStoi(char *optarg);

/**
 * safe conversion from string to double - preventing exception
 * @param  optarg string to convert
 * @return        converted value
 */
double safeStod(char *optarg);

/**
 * parse input arguments from command line
 * @param argc argc from main - number of arguments
 * @param argv argv from main - array of string arguments
 */
void argparse(int argc, char** argv);

#endif