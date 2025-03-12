#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class ERROR_TYPE {DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string message, ERROR_TYPE errorType) {
    ofstream outFile("log.txt", ios::app);
        if (outFile.is_open()) {

            switch (errorType)
            {
            case ERROR_TYPE::DEBUG:
                outFile << "[DEBUG] " << message << endl;
                break;
            case ERROR_TYPE::INFO:
                outFile << "[INFO] " << message << endl;
                break;
            case ERROR_TYPE::WARNING:
                outFile << "[WARNING] " << message << endl;
                break;
            case ERROR_TYPE::ERROR:
                outFile << "[ERROR] " << message << endl;
                break;
            case ERROR_TYPE::CRITICAL:
                outFile << "[CRITICAL] " << message << endl;
                break;
            default:
                break;
            }

            outFile.close();
        } else
            cerr << "Error abriendo el archivo!\n";
}

int main() {
    for (int i = 0; i < 5; i++) {
        logMessage("Error", ERROR_TYPE(i));
    }
    return 0;
}