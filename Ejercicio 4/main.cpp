#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

using namespace std;

bool stringTextComparison(string text1, string text2) {
    if (text1.length() != text2.length()) return false;

    if (text1.length() == 1) return text1[0] == text2[0];

    return text1[0] == text2[0] && stringTextComparison(text1.substr(1), text2.substr(1));
};

bool charTextComparison(const char* text1, const char* text2) {
    if (*text1 == '\0' && *text2 == '\0') return true;
    
    if (*text1 == '\0' || *text2 == '\0' || *text1 != *text2) return false;
    
    return charTextComparison(text1 + 1, text2 + 1);
};

constexpr bool constExprTextComparison(const char* text1, const char* text2) {
    if (*text1 == '\0' && *text2 == '\0') return true;
    
    if (*text1 == '\0' || *text2 == '\0' || *text1 != *text2) return false;
    
    return constExprTextComparison(text1 + 1, text2 + 1);
};

int main() {
    string stringText1 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";
    string stringText2 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";

    auto startTime = chrono::high_resolution_clock::now();

    bool stringComparison = stringTextComparison(stringText1, stringText2);

    auto endTime = chrono::high_resolution_clock::now();
    auto stringElapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    
    cout << endl << (stringComparison ? "Los textos son iguales" : "Los textos no son iguales") << endl;

    cout << endl << "La comparación de textos de tipo <string> le tomó: " << stringElapsedTime.count() << " nanosegundos" << endl;

    const char* charText1 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";
    const char* charText2 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";

    startTime = chrono::high_resolution_clock::now();

    bool charComparison = charTextComparison(charText1, charText2);

    endTime = chrono::high_resolution_clock::now();
    auto charElapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout << endl << (charComparison ? "Los textos son iguales" : "Los textos no son iguales") << endl;

    cout << endl << "La comparación de textos de tipo <char*> le tomó: " << charElapsedTime.count() << " nanosegundos" << endl;
    
    startTime = chrono::high_resolution_clock::now();

    constexpr bool constExprComparison = constExprTextComparison(
        "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?",
        "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?"
    );

    endTime = chrono::high_resolution_clock::now();
    auto constExprElapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    
    cout << endl << (constExprComparison ? "Los textos son iguales" : "Los textos no son iguales") << endl;

    cout << endl << "La comparación de textos de tipo <constexpr const char*> le tomó: " << constExprElapsedTime.count() << " nanosegundos" << endl;

    if (charElapsedTime < stringElapsedTime && charElapsedTime < constExprElapsedTime) {
        cout << endl << "Elijo hacer la comparación con los tipos <char*> ya que tarda menos tiempo." << endl;
    } else if (stringElapsedTime < charElapsedTime && stringElapsedTime < constExprElapsedTime) {
        cout << endl << "Elijo hacer la comparación con los tipos <string> ya que tarda menos tiempo." << endl;
    } else {
        cout << endl << "Elijo hacer la comparación con <constexpr> ya que tarda menos tiempo." << endl;
    };
};
    
/*
 * Conclusión sobre tiempos de ejecución:
 * La versión <constexpr> suele ser significativamente más rápida, porque la comparación
 * se realiza en tiempo de compilación, en cambio en el resto, se realizan en tiempo de ejecución.
 * Por lo tanto cuando el programa se ejecuta, el resultado ya está calculado.
 */