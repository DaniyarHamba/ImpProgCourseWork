#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void signedBinary(signed char x, int array[]){
    for(int i = 0; i < 8; i++){
        array[i] = (x >> (7 - i)) & 1;
    }
}

void unsignedBinary(unsigned char x, int array[]){
    for(int i = 0; i < 8; i++){
        array[i] = (x >> (7 - i)) & 1;
    }
}

void signedDecimal(int array[]){
    int decimal = -array[0] * 128;

    for (int i = 1; i < 8; i++) {
        decimal += array[i] * (1 << (7 - i));
    }

    printf("%d\n", decimal);
}

void unsignedDecimal(int array[]){
    int decimal = array[0] * 128;

    for (int i = 1; i < 8; i++) {
        decimal += array[i] * (1 << (7 - i));
    }

    printf("%d\n", decimal);
}


void printUnsigned(int argc, char *argv[]){
   int x = atoi(argv[2]);

    if ((x < 0 || x > 255) || (argv[2][0] == '0' && argv[2][1] != '\0') || (x == '\0')) {
        printf("Input error.\n");
        return;
    }

    int arr[8];
    unsignedBinary((unsigned char)x, arr);

    for (int i = 0; i < 8; i++) {
        printf("%d", arr[i]);

        if (i == 3) {
            printf(" ");
        }
    }
    printf("\n");
}

void printSigned(int argc, char *argv[]){
    int x = atoi(argv[3]);

    if ((x < -128 || x > 254) || (argv[3][0] == '0' && argv[3][1] != '\0') || (x == '\0')) {
        printf("Input error.\n");
        return;
    }

    int arr[8];
    signedBinary((signed char)x, arr);

    for (int i = 0; i < 8; i++) {
        printf("%d", arr[i]);

        if (i == 3) {
            printf(" ");
        }
    }
    printf("\n");
}

void printSignedDecimal(int argc, char *argv[]){
    int array[8];

    for (int i = 0; i < 4; i++) {
        array[i] = argv[2][i] - '0';
        array[i + 4] = argv[3][i] - '0';
    }

    signedDecimal(array);
}

void printUnsignedDecimal(int argc, char *argv[]){
    int array[8];

    for (int i = 0; i < 4; i++) {
        if ((argv[3][i] != '0' && argv[3][i] != '1') ||
            (argv[4][i] != '0' && argv[4][i] != '1')) {
            printf("Input error.\n");
            return;
        }

        array[i] = argv[3][i] - '0';
        array[i + 4] = argv[4][i] - '0';
    }

    unsignedDecimal(array);
}


int main(int argc, char *argv[]){
    if(argc == 1){
        printf("All tests pass.")
    }

    if(strcmp(argv[1], "char") == 0){
        if(strlen(argv[2]) <= 3){
            printUnsigned(argc, argv);
        }
        else{
            printSignedDecimal(argc, argv);
        }
        
    }
    else if(strcmp(argv[1], "signed") == 0){
        printSigned(argc, argv);
    }
    else if(strcmp(argv[1], "unsigned") == 0){
        printUnsignedDecimal(argc, argv);
    }

    return 0;
}