#include "ScriptLoader.h"
#include "../ConsoleBox/ConsoleBox.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto reset = "\033[0m";
};

ConsoleBox* consoleBox = new ConsoleBox();


void load_script(const char* filename, bool show_script) {
    string script;
    FILE* file = nullptr;

    try {
        file = fopen(filename, "rb");
        if (!file) {
            cerr << "Error: No se pudo abrir el archivo '" << filename << "'." << endl;
            return;
        }

        char buffer[4001];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer) - 1, file)) > 0) {
            buffer[bytesRead] = '\0'; // Asegurar que el buffer es una cadena
            script.append(buffer);
        }

        fclose(file);
        file = nullptr;

        if (show_script) {
            cout << ColorConsole::fg_blue << script << ColorConsole::reset << endl;
        }


        consoleBox->new_text();
        consoleBox->set_text(script);
    } catch (...) {
        cerr << "Error: Ocurrió un problema durante la lectura del archivo." << endl;
        if (file) {
        }
    }
}


void load_script() {
    char filename[500];
    cout << "Introduce el nombre del archivo: ";
    cin.getline(filename, sizeof(filename));
    load_script(filename, true);
}
