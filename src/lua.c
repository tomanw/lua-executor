#include "lua.h"
int RunLua(int argc, char* argv[]) {
   // if there isn't a script put in
   if (argc != 2) {
      fprintf(stderr, "Usage: %s <script.lua>\n", argv[0]);
      return 1;
   }

   // gets the script path
   const char *ScriptPath = argv[1];

   // makes a new lua state
   lua_State *LuaState = luaL_newstate();

   // if the lua state cant be made for whatever reason
   if (LuaState == NULL) {
      fprintf(stderr, "Cannot create Lua state\n");
      return 1;
   }

   // loading the lua libraries
   luaL_openlibs(LuaState);

   // if the script has an error
   // or cant load for some reason
   if (luaL_dofile(LuaState, ScriptPath) != LUA_OK) {
      fprintf(stderr, "Error loading script: %s", lua_tostring(LuaState, -1));
      return 1;
   }

   // closing the lua state
   lua_close(LuaState);
   return 0;
}