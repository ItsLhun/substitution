#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

string offsetKey(int arr[], string text);

int main(int argc, string argv[])
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphabetDouble[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string mainKey = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else
    {
        //check for string length
        if (strlen(mainKey) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        //check all chars
        for (int i = 0; i < 26; i++)
        {
            //check for invalid chars
            char workChar = toupper(mainKey[i]);
            if (workChar < 65 || workChar > 122 || (workChar > 90 && workChar < 97))
            {
                printf("Invalid character in key");
                return 1;
            }
            else if (alphabetDouble[(workChar - 65)] == 0)
            {
                printf("Key cannot contain duplicates");
                return 1;
            }
            int num = alphabetDouble[(workChar - 65)];
            alphabetDouble[(workChar - 65)] -= num;
        }
        // get input from the user
        string text = get_string("Plaintext: ");
        //make an array of offsets
        int offsets[26];
        for (int i = 0; i < 26; i++)
        {
            offsets[i] = toupper(argv[1][i]) - alphabet[i];
        }
        string encrypted = offsetKey(offsets, text);
        printf("ciphertext: %s\n", encrypted);
    }
}

string offsetKey(int arr[], string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] > 64 && text[i] < 91)
        {
            text[i] += arr[text[i] - 65];
        }
        else if (text[i] > 96 && text[i] < 123)
        {
            text[i] += arr[text[i] - 97];
        }
    }
    return text;
}
