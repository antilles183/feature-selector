#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>


class InputOutput {

    public:

        // INPUT FUNCTIONS
        std::string getInput();
        std::string getValidInput(unsigned argc, std::string argv[]);
        int getValidInteger(int l_min, int l_max, int l_default);
        bool getSentinal(std::string l_sentinal);

        // OUTPUT FUNCTIONS
        void console(char l_symbol, unsigned l_repeat = 1, bool l_newline = false);

};