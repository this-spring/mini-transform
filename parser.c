// #include <dirent.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//   DIR *d;
//   struct dirent *dir;
//   FILE *fptr;
//   char ch;
//   d = opendir("./source");
//   if (d) {
//     while ((dir = readdir(d) != NULL))
//     {
//       // fptr = fopen(dir->d_name, "r");
//       // printf("%s\n", fptr->d);
//       printf("%s\n", dir->d_name);
//     }

//   }
// }
// printf("%s\n", fptr->d);
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int do_mkdir(char base[], char path[]) {
  char path_name[100];
  memset((char *)path_name, 0, sizeof(path_name));
  strcat((char *)path_name, (char *)base);
  strcat((char *)path_name, (char *)path);
  int ret = mkdir((char *)path_name, 0755);
  return ret;
}

int main(void)
{
  DIR *d;
  struct dirent *dir;
  FILE *fptr;
  char ch;
  char content[100000];

  d = opendir("./source");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {

      fptr = fopen(dir->d_name, "r");
      printf("%s %d\n", dir->d_name, dir->d_type);
      if (dir->d_type == DT_DIR) {
        char path[50] = "./target/wx/";
        do_mkdir(path, dir->d_name);
        // char pathname[100];
        // memset(pathname, 0, sizeof(pathname));
        // strcpy(pathname, path);
        // strcpy(pathname + strlen(path), dir->d_name);
        // printf("name:%s\n", pathname);
        // mkdir(pathname, 0755);
      }
      // dir->

      // if (fptr != NULL)
      // {
      //   printf("%s\n", dir->d_name);
      //   ch = fgetc(fptr);
      //   while (ch != EOF)
      //   {
      //     printf("%c", ch);
      //     ch = fgetc(fptr);
      //   }
      //   printf("\n\n");
      //   fclose(fptr);
      // }
    }
    closedir(d);
  }
  return (0);
}
