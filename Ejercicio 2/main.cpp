#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class ERROR_TYPE {DEBUG, INFO, WARNING, ERROR, CRITICAL};

string addLabel(string message, ERROR_TYPE errorType) {
    switch (errorType)
            {
            case ERROR_TYPE::DEBUG:
                message = "[DEBUG] " + message;
                break;
            case ERROR_TYPE::INFO:
                message = "[INFO] " + message;
                break;
            case ERROR_TYPE::WARNING:
                message = "[WARNING] " + message;
                break;
            case ERROR_TYPE::ERROR:
                message = "[ERROR] " + message;
                break;
            case ERROR_TYPE::CRITICAL:
                message = "[CRITICAL] " + message;
                break;
            default:
                break;
            };

    return message;
};

void logMessage(string message, ERROR_TYPE errorType) {
    ofstream outFile("log.txt", ios::app);
        if (outFile.is_open()) {

            message = addLabel(message, errorType);
            
            outFile << message << endl;

            outFile.close();
        } else {
            cerr << "Error abriendo el archivo!\n";
        };
};

void logMessage(string errorMessage, string file, int errorLine) {
    ofstream outFile("log.txt", ios::app);
        if (outFile.is_open()) {
            
            outFile << "[ERROR] " << file << ":" << errorLine << " " << errorMessage << endl;

            outFile.close();
        } else {
            cerr << "Error abriendo el archivo!\n";
        };
};

void logMessage(string accesMessage, string userName) {
    ofstream outFile("log.txt", ios::app);
        if (outFile.is_open()) {
            
            outFile << "[SECURITY] " << userName << " - " << accesMessage << endl;

            outFile.close();
        } else {
            cerr << "Error abriendo el archivo!\n";
        };
};

int main() {
    for (int i = 0; i < 5; i++) {
        logMessage("Error", ERROR_TYPE(i));
    };

    logMessage("Mensaje de error", "main.cpp", 10);

    logMessage("Acces Granted", "Fede");

    try
    {
        throw runtime_error("ERROR");
    }
    catch(const runtime_error& error)
    {
        logMessage("ERROR", "main.cpp", __LINE__);
        cerr << error.what() << '\n';
        return 1;
    };

    return 0;
}