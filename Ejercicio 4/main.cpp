#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

using namespace std;

bool textComparison(string text1, string text2) {
    if (text1.length() != text2.length()) return false;

    if (text1.length() == 1) return text1[0] == text2[0];

    return text1[0] == text2[0] && textComparison(text1.substr(1), text2.substr(1));
}

bool textComparison(const char* text1, const char* text2) {
    if (strlen(text1) != strlen(text2)) return false;

    if (strlen(text1) == 1) return *text1 == *text2;

    return *text1 == *text2 && textComparison(text1 + 1, text2 + 1);
}

int main() {
    auto startTime = chrono::high_resolution_clock::now();

    string stringText1 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";
    string stringText2 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";

    cout << endl << (textComparison(stringText1, stringText2) ? "Los textos son iguales" : "Los textos no son iguales") << endl;

    auto endTime = chrono::high_resolution_clock::now();
    auto stringElapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout << endl << "La comparación de textos de tipo <string> le tomó: " << stringElapsedTime.count() << " nanosegundos" << endl;

    startTime = chrono::high_resolution_clock::now();

    const char* charText1 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";
    const char* charText2 = "Hola, soy Fede. ¿Cómo estás? Me alegro. ¿Qué haces hoy a la tarde?";

    cout << endl << (textComparison(charText1, charText2) ? "Los textos son iguales" : "Los textos no son iguales") << endl;

    endTime = chrono::high_resolution_clock::now();
    auto charElapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout << endl << "La comparación de textos de tipo <char*> le tomó: " << charElapsedTime.count() << " nanosegundos" << endl;

    if (charElapsedTime < stringElapsedTime) {
        cout << endl << "Elijo hacer la comparación con los tipos <char*> ya que tarda menos tiempo que realizarlo con el tipo <string>." << endl;
    } else {
        cout << endl << "Elijo hacer la comparación con los tipos <string> ya que tarda menos tiempo que realizarlo con el tipo <char*>." << endl;
    }
}