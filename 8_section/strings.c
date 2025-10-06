#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lesson_131();
void lesson_132();
void lesson_133();
void lesson_134();
void lesson_135();
void lesson_136();
void lesson_137();
void lesson_138();
void lesson_139();
int string_length(char* string);
void string_switch_case(char* string);
void string_to_lowercase(char* string);
int string_is_alphanumeric(char* string);
void string_reverse(char* string);

int main()
{
    // lesson_131();
    // lesson_132();
    // lesson_133();
    // lesson_134();
    // lesson_135();
    // lesson_136();
    // lesson_137();
    // lesson_138();
    lesson_139();
    return 0;
}

void lesson_131()
{
    char x[] = {'a', 'b', 'c', 'd', 'e'};
    char y[5] = {'a', 'b', 'c', 'd', 'e'}; 
    char z[5] = {97, 98, 99, 100, 101};
    
    // %c formatter prints the character
    printf("%c\n", x[1]);
    printf("%c\n", y[1]);
    printf("%c\n", z[1]);

    // %d prints the ASCII of the character
    printf("%d\n", x[1]);
    printf("%d\n", y[1]);
    printf("%d\n", z[1]);

    // instantiating array with fewer characters than the array length
    char a[5] = {'a','b'};
    printf("Defined character index: %c\n", a[1]);
    printf("Undefined character index: %d\n", a[3]);
    // This proves that an array of characters is instantiated with zeroes.o

    // Declaring strings
    char b[10] = {'j','o', 'h', 'n','\0'};
    char name[] = "JOHN";

    printf("Printing string from a char array: %s\n", b);
    printf("Printing string from a string declaration: %s\n", name);
    // printf will loop and print the entire char array until the \0 is encountered.
}

void lesson_132()
{
    char name[] = "JOHN DOE";
    int name_length = string_length(name);
    printf("Number of characters in the name: %d\n", name_length);
}

int string_length(char* string)
{
    int char_count = 0;
    char current_char;

    while (*(string + char_count) != '\0')
    {
        char_count++;
    }
    return char_count;
}

void lesson_133()
{
    // char name[] = {'j','o','h','n', '\0'};
    char name[] = "john";
    int i = 0;
    while (name[i] != '\0')
    {
        name[i] = toupper(name[i]);
        i++;
    }
    printf("Name in changed case: %s\n", name);

    // If not using any built in libraries, then subtract 32 from ASCII code to get upper case.
    // Add 32 to ASCII code of the letter to get lower case.

    char name2[] = "jane";
    for (int j = 0; name2[j] != '\0'; j++)
    {
        if (name2[j] >= 97 && name2[j] <= 122)
        {
            name2[j] = name2[j] - 32;
        }
    }

    printf("Case change with method 2: %s\n", name2);

    char test[] = "wElCoMe!";
    string_switch_case(test);
    printf("%s\n", test);
}

void string_switch_case(char* string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isupper(string[i]))
        {
            string[i] = tolower(string[i]);
        }
        else
        {
            string[i] = toupper(string[i]);
        }
    }
}

void lesson_134()
{
    char phrase[] = "Hello, how are you?";

    int vowels, consonants, words;
    vowels = consonants = words = 0;

    for (int i = 0; phrase[i] != '\0'; i++)
    {
        char temp = tolower(phrase[i]);
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
        {
            vowels++;
        }
        else if (temp >= 97 && temp <= 122)
        {
            consonants++;
        }
        else if (temp == ' ')
        {
            words++;
        }
    }
    words++;
    printf("The phrase had %d vowels.\n", vowels);
    printf("The phrase had %d consonants.\n", consonants);
    printf("The phrase had %d words.\n", words);
}

int string_is_alphanumeric(char* string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        char temp = tolower(string[i]);
        if (
            !(temp >= 97 && temp <= 122) &&
            !(temp >= 48 && temp <= 57)
        )
        {
            return 0;
        }
    }
    return 1;
}
void lesson_135()
{
    // Validate a string as containing only alphanumeric characters.
    // Do this without using the built-in method

    char username1[] = "john123";
    char username2[] = "jane22!";

    if (string_is_alphanumeric(username1))
    {
        printf("Given username %s is valid.\n", username1);
    }
    if (string_is_alphanumeric(username2))
    {
        printf("Given username %s is valid.\n", username2);
    }
}

void string_reverse(char* string)
{
    int start = 0;
    int end = string_length(string) - 1;

    while (start < end)
    {
        char temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}

void lesson_136()
{
    char name[] = "python";
    string_reverse(name);
    printf("The reversed string is %s\n", name);
}

void string_to_lowercase(char* string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = tolower(string[i]);
    }
}

void lesson_137()
{
    // Check if a given string is a palindromes

    char word1[] = "raceCAR";
    string_to_lowercase(word1);
    int front_letter = 0;
    int back_letter = string_length(word1) - 1;

    while (front_letter < back_letter)
    {
        if (word1[front_letter] != word1[back_letter])
        {
            printf("%s is not a palindrome.\n", word1);
            return;
        }
        front_letter++;
        back_letter--;
    }
    printf("%s is a palindrome.\n", word1);
}

void lesson_138()
{
    // Find duplicate letters in a string. In this case, case insensitive
    // This implementation does not work for special characters.
    char example[] = "findINgs";

    // Method 1: using hash tables
    const int START_ASCII = 97;
    const int END_ASCII = 122;
    const int TOTAL_LETTERS = 26;

    int* letters_map = (int *)calloc(TOTAL_LETTERS, sizeof(int));

    for (int i = 0; example[i] != '\0'; i++)
    {
        char temp = tolower(example[i]);
        if (temp >= START_ASCII && temp <= END_ASCII)
        {
            letters_map[temp - START_ASCII]++;
        }
    }
    for (int j = 0; j < TOTAL_LETTERS; j++)
    {
        if (letters_map[j] > 1)
        {
            printf("%c is present %d times in the given string.\n", START_ASCII + j, letters_map[j]);
        }
    }

    free(letters_map);
}

void lesson_139()
{
    // Find duplicate letters in a string using bit manipulation
    unsigned int test = 1;
    test = test << 2;
    printf("New value of test is %d\n", test);

    unsigned int num1 = 10;
    unsigned int num2 = 6;
    printf("10 AND 6 is: %d\n", num1 & num2);
    printf("10 OR 6 is: %d\n", num1 | num2);

    // Finding duplicates in a string using masking and merging
    char* string = "finding\0";
    const int START_ASCII = 97;
    // Create a bit mask to use, similar to a hash map
    // The bit mask needs to be able to accomodate all 26 letters, so unsigned int should be sufficient.

    unsigned int bit_mask, temp;
    bit_mask = 0;
    temp = 0;
    // printf("%u\n", bit_mask-1);

    // for (int i = 0; i < sizeof(bit_mask) * 8; i++)
    // {
    //     temp = bit_mask << i;
    //     printf("%u\n", temp);
    // }
    for (int i = 0; string[i] != '\0'; i++)
    {
        temp = 1;
        temp = temp << (string[i] - START_ASCII);

        if ((temp & bit_mask) > 0)
        {
            printf("%c is a duplicate letter.\n", string[i]);
        }
        else
        {
            bit_mask = temp | bit_mask;
        }
    }
}