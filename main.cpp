#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

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


    HINSTANCE handle = LoadLibrary(TEXT("cezar.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        cout << "Lib not found" << endl;
        return -1;
    }

    typedef char*(*function_ptr)(char*, int);
    function_ptr encrypt = (function_ptr)GetProcAddress(handle, TEXT("encrypt"));
    if (encrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    typedef char*(*function_ptr)(char*, int);
    function_ptr decrypt = (function_ptr)GetProcAddress(handle, TEXT("decrypt"));
    if (encrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    char* encryptedText = encrypt(text, key);
    cout << encryptedText << endl;
    char* decryptedText = decrypt(encryptedText, key);
    cout << decryptedText << endl;
    return 0;
}