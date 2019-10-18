#include <stdio.h>
#include <string.h>

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
    // printf("%s\n", alpha1.cipherAlpha);

    int c = 0;
    while(c != 35){
        c = fgetc(fp);
        if (c >= 65 && c <= 90){
            printf("%c", alpha1.plainAlpha[letterIndex(alpha1, c)]);
        }else if (c == 10 || c == 32){
            printf("%c", c);
        }
    }
    fclose(fp);
    return 0;
}

