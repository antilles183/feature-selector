#include "InputOutput.h"


/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# INPUT FUNCTIONS
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */

/*******************************************************************************
 * @brief 
 * 
 * @return std::string 
*******************************************************************************/
std::string InputOutput::getInput() {

    std::string userInput = "";
    std::cin >> userInput;
    return userInput;
}


/*******************************************************************************
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return std::string 
*******************************************************************************/
std::string InputOutput::getValidInput(unsigned argc, std::string argv[]) {

    std::string userInput = "";

    while(true) {
        
        std::cin >> userInput;
        
        // test input is valid
        for (unsigned i = 0; i < argc; i++){
            if (userInput == argv[i]) {
                return userInput;
            }
        }

        // warn user and display valid inputs
        std::cout << "Invalid Input. Please select: ";
        for (unsigned i = 0; i < argc; i++) {
            std::cout << argv[i] << " ";
        }

        // clear out buffer
        std::cin.ignore(1000, '\n');
        std::cout << std::endl;

    }
}


/*******************************************************************************
 * @brief 
 * 
 * @param l_min 
 * @param l_max 
 * @param l_default 
 * @return int 
*******************************************************************************/
int InputOutput::getValidInteger(int l_min, int l_max, int l_default) {

    // GUARD: default must be in range
    if( !(l_min <= l_default) || !(l_default <= l_max) ) {
        exit(1);
    }

    std::string userInput = "";
    bool valid{true};
    int userInt;

    while(true) {
        
        std::getline(std::cin, userInput);
        
        // user hits ENTER returns default integer
        if(userInput == "") {
            return l_default;
        }

        // PARSE: user input
        // test input is all digits
        for (char c : userInput) {
            if(!std::isdigit(c) && c != ' ') {
                valid = false;
                break;
            }
        }

        // convert to integer & check if in valid range
        if(valid) { 
            userInt = std::stoi(userInput); 

            valid = l_min <= userInt && userInt <= l_max;
        }

        // return if valid else issue warning and clear buffer
        if(valid) {
            return userInt;
        } else {
            // warn user and display valid inputs
            std::cout << "Invalid Input. Please select from ";
            std::cout << l_min << " - " << l_max << "\n";
        }
        
        // std::cout << std::endl;
        userInput = "";

        // reset flag
        valid = true;
    }

}


/*******************************************************************************
 * @brief 
 * 
 * @param l_sentinal 
 * @return true 
 * @return false 
*******************************************************************************/
bool InputOutput::getSentinal(std::string l_sentinal) {

    std::string userInput = "";
        
    std::getline(std::cin, userInput);

    return userInput == l_sentinal;
    
}


/* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# OUTPUT FUNCTIONS
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # */

/*******************************************************************************
 * @brief 
 * 
 * @param l_symbol 
 * @param l_repeat 
 * @param l_newline 
*******************************************************************************/
void InputOutput::console(char l_symbol, unsigned l_repeat, bool l_newline) {

    for(unsigned i = 0; i < l_repeat; i++) {
        std::cout << l_symbol;
    }

    if(l_newline) { std::cout << '\n'; }

}