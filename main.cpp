#include <iostream>
#include <string.h>
using namespace std;

char* encrypt(char* rawText, int key) {
    for (int i=0; i < strlen(rawText); i++) {
        if (rawText[i] >= 'A' && rawText[i] <= 'Z') {
            rawText[i] = (rawText[i] + key - 'A') % 26 + 'A';
        }
        else if (rawText[i] >= 'a' && rawText[i] <= 'z') {
            rawText[i] = (rawText[i] + key - 'a') % 26 + 'a';
        }
    }
    return rawText;
}

char* decrypt(char* rawText, int key) {
    for (int i=0; i < strlen(rawText); i++) {
        if (rawText[i] >= 'A' && rawText[i] <= 'Z') {
            rawText[i] = ((rawText[i] - key - 'A' + 26) % 26) + 'A';
        }
        else if (rawText[i] >= 'a' && rawText[i] <= 'z') {
            rawText[i] = (rawText[i] - key - 'a' + 26) % 26 + 'a';
        }
    }
    return rawText;
}

int main() {
    int key;
    cout << "Enter text to append: " << endl;
    int allocated_size = 10;
    int len = 0;
    auto text = static_cast<char *>(calloc(allocated_size, sizeof(char)));
    char ch;
    do {
        ch = getchar();
        text[len] = ch;
        len++;

        if (len > allocated_size) {
            allocated_size *= 2;
            char *temp = static_cast<char *>(realloc(text, allocated_size * sizeof(char)));
            if (temp == nullptr) {
                free(text);
                exit(1);
            }
            text = temp;
        }
    } while(ch != '\n');
    if (text[len-1] == '\n'){
        text[len-1] = '\0';}

    cout << "Enter the key: " << endl;
    cin >> key;

    char* encryptedText = encrypt(text, key);
    cout << encryptedText << endl;
    char* decryptedText = decrypt(encryptedText, key);
    cout << decryptedText << endl;
    return 0;
}