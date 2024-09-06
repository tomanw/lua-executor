#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "lua_run.h"

void listFiles(const char* path) {
   struct dirent *entry;
   DIR *dp = opendir("scripts");
   char Script[1024];

   if (dp == NULL) {
      perror("Unable to open directory");
      return;
   }

   while (( entry =  readdir(dp) )) {
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
         snprintf(Script, sizeof(Script), "%s/%s", path, entry->d_name);
         RunLua(Script);
      }
   }
   closedir(dp);
}
