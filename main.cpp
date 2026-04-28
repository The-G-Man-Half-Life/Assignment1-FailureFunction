//Includes for all the required elements
#include "iostream"
#include "vector"

//Execution of the code itself
std::vector<int> findFailureSpotsKMP(const std::string& input) {
    int n = input.size();
    std::vector<int> failurePlaces(n, 0); // Todo inicia en 0
    
    int len = 0; // Tamaño del prefijo anterior
    int i = 1;   // Posición actual (currentPosition)

    while (i < n) {
        // Si las LETRAS coinciden, el tamaño crece en 1
        if (input[i] == input[len]) {
            len++;
            failurePlaces[i] = len;
            i++;
        } 
        else {
            // Si NO coinciden, aquí está la magia del KMP en vez de usar un ciclo "for"
            if (len != 0) {
                // Retrocedemos al fallo anterior en lugar de probar uno por uno
                len = failurePlaces[len - 1]; 
            } 
            else {
                // Si llegamos a 0, simplemente no hay coincidencia
                failurePlaces[i] = 0;
                i++;
            }
        }
    }
    return failurePlaces;
}

int main(){
    std::vector<int> failureSpotsKMP = findFailureSpotsKMP("ababaa");

    for (int number : failureSpotsKMP){
        std::cout << number << std::endl;
    }
    
}