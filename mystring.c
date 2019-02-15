/*
 * mystring.c
 *
 *  Created on: Jan 24, 2019
 *      Author: Aaron Krueger
 */
#include <stdlib.h>
#include <stdio.h>
#include "mystring.h"

/**
 * Calculate the length of the string, excluding the terminating null byte ('\0')
 * @param const char* s the string which we will measure the length of
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}

/**
 * Calculate the length of the string excluding the terminating null byte ('\0')
 * @param const char* s The string we will measure the length of
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s) {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		mystrcpy(newstr, s);
	}
	return newstr;
}

/** Duplicates a character string into a freshly-allocated block of memory,
 * taking up to n bytes from s.
 * If s is longer than n bytes, only n bytes are copied and a null terminator
 * will be added.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrndup(char* s, size_t n) {
	// Allocate a block of memory big enough to hold all n bytes,
	// plus the null terminator.
	char* newstr = (char*) malloc(n + 1);

	if (newstr) { // If allocation succeeded, copy into it
		if(*s && n > 0) {
			mystrncpy(newstr, s, n);
		}

		char* newstr_ptr = (char*) malloc(sizeof(char*));
		newstr_ptr = newstr; // creates a pointer to newstr, which will be used to find location for \0

		while(*s && n > 0) { // while there's still characters in s and n > 0
			newstr_ptr++;
			s++;     // advances the pointer through the string, and decrements n
			n--;     // so we can figure out how to deal with the null terminator
		}

		*newstr_ptr = '\0';

	}

	return newstr;
}

/** Creates another array by copying a string into an empty character array.
 * Null terminates the copied string.
 * *DANGER* If the destination is too short to contain the source array, the
 * program will overwrite the memory following dest.
 * @param dest The destination for the array
 * @param src The array to be copied into dest
 * @return the destination for the array, with the newly copied array
 */
char* mystrcpy(char* dest, char* src) {
	char* original = (char*) malloc(sizeof(char*)); // holds the original starting position of dest
	original = dest;
	while(*src) { // loops through the content of src until we reach \0
		*dest = *src;

		dest++;
		src++;
	}

	*dest = '\0'; // appends a null terminator to the end of dest

	return original;
}

/** Creates another array by copying a string into another string, taking up
 * to n characters of the src array.
 * If n > length of src, pads the rest of the array with null terminators.
 * If n <= length of src, *does not* null terminate the string.
 * *DANGER* If the destination is too short to contain the source array, the
 * program will overwrite the memory following dest.
 * @param dest The destination for the array
 * @param src The array to be copied into dest
 * @return the destination for the array, with the newly copied array
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char* original = (char*) malloc(sizeof(char*));
	original = dest; // holds the original starting position of dest


	while(n > 0 && *src) { // copy n bytes of src into dest
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	while(n > 0) { // need to pad with \0's if n is > src length
		*dest = '\0';
		n--;
	}

	return original;
}

/** Appends one string (src) onto the end of the other (dest).
 * Starts by overwriting null terminator of dest, then appends
 * src onto the end, null-terminating the resulting string.
 * *DANGER* Will overwrite memory following dest if dest does
 * not contain enough space for the newly appended array.
 * @param dest The string that src will be appended to the end of
 * @param src The string being appended to the end of dest
 * @return a pointer to the location of the newly concatenated string
 */
char* mystrcat(char* dest, char* src) {
	char* original = (char*) malloc(sizeof(char*));
	original = dest; // holds the original starting position of dest

	while(*dest) { // loops through the contents of dest until we reach \0
		dest++;
	}

	while(*src) { // loops through the contents of src until we reach \0
		*dest = *src;
		dest++;
		src++;
	}

	*src = '\0';

	return original;
}

/** Appends one string (src) onto the end of the other (dest),
 * up to n characters of the src string.
 * Starts by overwriting null terminator of dest, then appends
 * src onto the end, null-terminating the resulting string (at
 * position n + 1, even if this is out of bounds)
 * *DANGER* Will overwrite memory following dest if dest does
 * not contain enough space for the newly appended array.
 * @param dest The string that src will be appended to the end of
 * @param src The string being appended to the end of dest
 * @return a pointer to the location of the newly concatenated string
 */
char* mystrncat(char* dest, char* src, size_t n) {
	char* original = (char*) malloc(sizeof(char*));
	original = dest; // holds the original starting position of dest

	while(*dest) { // loops through the contents of dest until we reach \0
		dest++;
	}

	while(n > 0 && *src) { // loops through the contents of src until we reach \0
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	*dest = '\0';

	return original;
}
