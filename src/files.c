#include <stdio.h>
#include <dirent.h>
#include <string.h>

void listFiles(const char* path) {
   struct dirent *entry;
   DIR *dp = opendir(path);

   if (dp == NULL) {
      perror("Unable to open directory");
      return;
   }

   while (( entry =  readdir(dp) )) {
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
         printf("%s/%s\n", path, entry->d_name);

      }
   }
   closedir(dp);
}
