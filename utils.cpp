#include "utils.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <cstdlib>
#endif

void clearScreen() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}