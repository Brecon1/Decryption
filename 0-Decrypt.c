#include <stdio.h>
#include <string.h>
#define BUFF_LEN 255

struct alphabet{
  char *cipherAlpha;
  char *plainAlpha;
};

struct alphabet newAlphabet();
int letterIndex(struct alphabet alpha, char letter);

struct alphabet newAlphabet(){
  struct alphabet alpha;
  alpha.plainAlpha = "SECURITYABDFGHJKLMNOPQVWXZ";
  return alpha;
}

int letterIndex(struct alphabet alpha, char letter){
  for(int i = 0; i < strlen(alpha.cipherAlpha); i++){
    if(letter == alpha.cipherAlpha[i]){
      return i;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  FILE *fp;
  fp = fopen("ciphertext.txt", "r");

  struct alphabet alpha1 = newAlphabet();
  alpha1.cipherAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%s\n", alpha1.cipherAlpha);

  char buff[BUFF_LEN];
  while(fgets(buff, BUFF_LEN, (FILE*) fp) != NULL){
    for(int i = 0; i < BUFF_LEN; i++){
      if(buff[i] <'A' || buff[i] > 'Z'){
         if(buff[i] != '\n'){
           printf("%c", buff[i]);
        }
    }else{
      printf("%c", alpha1.plainAlpha[letterIndex(alpha1, buff[i])]);}
    }
  }




  fclose(fp);
  return 0;
}
