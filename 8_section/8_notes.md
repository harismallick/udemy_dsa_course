### Strings

In this Chapter, we cover common algorithms when working with strings.

#### 131 Notes

- ASCII: American Standard Code for Information Interchange
- It was one of the first standards established for converting English characters to standard numbers.
- UTF-8 is the modern standard that is used.
- A to Z is 65 to 90.
- a to z is 97 to 122.
- 0 to 9 is 48 to 57.
- Special characters and keyboard operations have specific ASCII codes too:
  - Enter on the keyboard is 10
  - Space is 13
  - Escape is 27
- There are 128 ASCII codes in total, from 0 to 127.
- 7-bits are sufficient for storing all the ASCII characters.
  - But ASCII is stored using 1 byte.
- Unicode is stored in 2-bytes, ie, 16-bits.
  - Unicode is stored in hexadecimal.
- An empty array of characters is instantiated with zeroes.
- All strings in end with the string delimiter - '\0'
- String literals are immutable in C. To mutate elements in the string, it must be declare as a char array.
- Char arrays are stored in writeable memory locations, while string literals are stored in read-only memory locations.

```C
    char name[] = "john"; // This string is mutable!
    char const name[] = "jane"; // This string is immutable!
    char *name = "jane"; // This is a string literal which is immutable.

```