#include "lua.h"
#include "files.h"

extern int RunLua(int argc, char* argv[]);

int main(int argc, char *argv[]) {
   RunLua(argc, argv);
   listFiles("../src/")
}
