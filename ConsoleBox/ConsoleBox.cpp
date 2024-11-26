#include "ConsoleBox.h"
#include <iostream>

using namespace std;

void ConsoleBox::new_text() {
    cout << "Se ha cargado nuevo texto en la consola." << endl;
}

void ConsoleBox::set_text(const string& text) {
    cout << "Contenido del archivo cargado en la consola:" << endl;
    cout << text << endl;
}
