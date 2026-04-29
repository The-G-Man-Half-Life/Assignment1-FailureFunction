//Includes for all the required elements
#include "iostream"
#include <string>
#include <iomanip>
#include <limits>
#include "vector"

//Execution of the code itself
std::vector<int> findFailureSpotsKMP(const std::string& input) {
    //Variables
    int inputSize = input.size();
    std::vector<int> failurePlaces(inputSize, 0); // All the values in the vector started as 0
    int lastPrefixLength = 0; // Size of the last prefix
    int currentPosition = 1;   // Current position executing at

    //cycle to go through the entirety of the input comparing
    while (currentPosition < inputSize) {
        // if the letters do match the current position increases by 1
        if (input[currentPosition] == input[lastPrefixLength]) {
            lastPrefixLength++;
            //Inserts value into the vector
            failurePlaces[currentPosition] = lastPrefixLength;
            currentPosition++;
        } 
        else {
            /*If these values do not match then we go to the last failing position
            so we don't have to review everything 1 by 1*/
            if (lastPrefixLength != 0) {
                lastPrefixLength = failurePlaces[lastPrefixLength - 1]; 
            } 
            else {
                /*In case we arrive to 0 it means that there is no match*/
                failurePlaces[currentPosition] = 0;
                currentPosition++;
            }
        }
    }
    return failurePlaces;
}

//Function to print more organizedly
void printKMP(const std::vector<int>& failureSpotsKMP, const std::string& input) {
    int inputSize = input.size();

    //Calculate the width dinamicly
    int maxDigits = std::to_string(inputSize).length();
    int sWidth = std::max(4, maxDigits + 2); 
    int pWidth = 6; 
    int fWidth = 6; 

    //print the headers (s | P[s] | f(s))
    std::cout << std::right << std::setw(sWidth) << "s" << " | "
              << std::setw(pWidth) << "P[s]" << " | "
              << std::setw(fWidth) << "f(s)" << std::endl;

    //Print separating lines
    int totalWidth = sWidth + pWidth + fWidth + 6; 
    std::cout << std::string(totalWidth, '-') << std::endl;

    //Print data line by line
    for (int i = 0; i < inputSize; i++) {
        std::cout << std::right << std::setw(sWidth) << (i + 1) << " | "
                  << std::setw(pWidth) << input[i] << " | "
                  << std::setw(fWidth) << failureSpotsKMP[i] << std::endl;
    }
}

int main(){
    //Variables
    std::vector<int> failureSpotsKMP;
    std::string input;
    std::string decision;
    
    while(true){
        //stopping the program for a bit to execute next line
        std::cout << "Ingrese enter para continuar";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;

        //showing menu and receiving decision
        std::cout << "Algoritmo KMP" << std::endl;
        std::cout << "1. Ingresar Palabra Propia" << std::endl;
        std::cout << "2. Soluciones ejercicio 3.4.3" << std::endl;
        std::cout << "(Cualquier otra entrada) Terminar programa" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> decision;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;

    
        if(decision == "1"){
        //Receiving the input from the user
        std::cout << "Ingrese una palabra: ";
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //getting the vector 
        failureSpotsKMP = findFailureSpotsKMP(input);
        //printing result
        std::cout << "Esta es la Palabra " << input << " Procesada por el algoritmo KMP" << std::endl;
        printKMP(failureSpotsKMP, input);
        std::cout << std::endl;
        }
        else if (decision == "2")
        {
            // set of words to check from exercise 3.4.3
            std::vector<std::string> words = {"abababaab", "aaaaaa", "abbaabb"};
            for (std::string word: words){
                //Getting the vector of integers from the function
                failureSpotsKMP = findFailureSpotsKMP(word);
                //printing results
                std::cout << "Esta es la Palabra " << word << " Procesada por el algoritmo KMP" << std::endl;   
                printKMP(failureSpotsKMP, word);  
                std::cout << std::endl;       
            }   
        }
        else{
            //finishing program
            break;
        }
    }
}