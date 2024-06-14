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


    HINSTANCE handle = LoadLibrary(TEXT("C:\\Users\\kovko\\CLionProjects\\Paradigms_Assignment3\\cezar.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
    {
        cout << "Lib not found" << endl;
        return -1;
    }

    typedef char*(*function1_ptr)(char*, int);
    function1_ptr encrypt = (function1_ptr)GetProcAddress(handle, TEXT("encrypt"));
    if (encrypt == nullptr)
    {
        cout << "Proc not found" << endl;
        return -1;
    }

    typedef char*(*function2_ptr)(char*, int);
    function2_ptr decrypt = (function2_ptr)GetProcAddress(handle, TEXT("decrypt"));
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