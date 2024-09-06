#include "files.h"

extern int RunLua(const char* ScriptPath);

int main(int argc, char *argv[]) {
   listFiles("scripts");
   //RunLua("scripts/script.lua");
}
