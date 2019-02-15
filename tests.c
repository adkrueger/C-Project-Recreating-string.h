/*
 * tests.c
 *
 *  Created on: Jan 24, 2019
 *      Author: Aaron Krueger
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystring.h"

bool tests(void)
{
	bool ok = false;

	bool ok1 = testMystrlen1();
	if (ok1) {
		puts("mystrlen1() passed.");
	}

	bool ok2 = testMystrlen2();
	if (ok2) {
		puts("mystrlen2() passed.");
	}

	bool ok3 = testMystrdup();
	if (ok3) {
		puts("mystrdup() passed.");
	}

	bool ok4 = testMystrncpy();
	if (ok4) {
		puts("mystrncpy() passed.");
	}

	bool ok5 = testMystrcpy();
	if (ok5) {
		puts("mystrcpy() passed.");
	}

	bool ok6 = testMystrncat();
	if (ok6) {
		puts("mystrncat() passed.");
	}

	bool ok7 = testMystrcpyShort();
	if (ok7) {
		puts("mystrcpy() short passed.");
	}

	bool ok8 = testMystrcpyLong();
	if(ok8) {
		puts("mystrcpy() long passed.");
	}

	bool ok9 = testMystrcat();
	if(ok9) {
		puts("mystrcat() passed.");
	}

	bool ok10 = testMystrndup();
	if(ok10) {
		puts("mystrndup() passed.");
	}

	bool ok11 = testMystrndupLarge();
	if(ok11) {
		puts("mystrndup() passed with a large n.");
	}

	bool ok12 = testMystrncpyLarge();
	if (ok12) {
		puts("mystrncpy() passed with a large n.\n");
	}
	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12; // Did all tests pass?
	return ok;
}

/** Tests the mystrlen1() function by comparing it to an incremented int
 * @return true if it passes all tests.
 */
bool testMystrlen1(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	puts("\nTesting mystrlen1...");
	char* s1 = "Some sample string."; // String we will take the length of.
	size_t s1Length = mystrlen1(s1);
	size_t n1Actual = 0; // size of the array, which will be incremented. Starts at 0 because the null terminator isn't counted
	while(*s1) {
		n1Actual++;
		s1++;
	}
	if (s1Length == n1Actual) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t s2Length = mystrlen1(s2); // Get the lengths with the two functions.
	size_t n2Actual = 0; // size of the array, which will be incremented. Starts at 0 because the null terminator isn't counted
	if (s2Length == n2Actual) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}


/** Tests the mystrlen2() function by comparing it to an incremented int
 * @return true if it passes all tests.
 */
bool testMystrlen2(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	puts("\nTesting mystrlen2...");
	char* s1 = "Some sample string."; // String we will take the length of.
	size_t s1Length = mystrlen2(s1);
	size_t n1Actual = 0; // size of the array, which will be incremented. Starts at 0 because of the exclusion of the null terminator
	while(*s1) {
		n1Actual++;
		s1++;
	}
	if (s1Length == n1Actual) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t s2Length = mystrlen2(s2); // Get the lengths with the two functions.
	size_t n2Actual = 0; // size of the array, which will be incremented. Starts at 0 because of the exclusion of the null terminator
	if (s2Length == n2Actual) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}

/** Test mystrdup() function by comparing it to another string and its address
 * @return true if it passes all tests.
 */
bool testMystrdup(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrdup...");
    char s[] = "Some sample string.";
	char* s1 = s; // String we will duplicate.
	char* s2 = mystrdup(s1); // Copy it using my function

	if (strcmp(s1, s2) == 0) { // Same result!
		ok1 = true;
	}

	if(&s1 != &s2) { // if the two strings don't have the same address
		ok2 = true;
	}

	printf("String 1: %s\n", s1);
	printf("String 2: %s\n", s2);
	return ok1 && ok2;
}

/** Test mystrndup() function by comparing it to the standard strndup().
 * @return true if it passes all tests.
 */
bool testMystrndup(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrndup...");
    char sOriginal[] = "Some sample string.";
    char sShortened[] = "Some ";
	char* s1 = sShortened; // String we will duplicate.
	char* s2 = mystrndup(sOriginal, 5); // Copy it using my function

	if (strcmp(s1, s2) == 0) { // Same result!
		ok1 = true;
	}

	if(&s1 != &s2) { // if the two strings don't have the same address
		ok2 = true;
	}

	printf("String 1: %s\n", s1);
	printf("String 2: %s\n", s2);
	return ok1 && ok2;
}

/** Test mystrndup() function by giving it an n larger than the length
 * of the string.
 * @return true if it passes all tests.
 */
bool testMystrndupLarge(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrndup with a large string...");
    char sOriginal[] = "Some sample string.";
    char* sShortened = mystrndup(sOriginal, 5);
	char* s1 = mystrndup(sShortened, 30); // Copy it using my function

	if (strcmp(s1, sShortened) == 0) { // Same result!
		ok1 = true;
	}

	if(&s1 != &sShortened) { // if the two strings don't have the same address
		ok2 = true;
	}

	printf("String 1: %s\n", sShortened);
	printf("String 2: %s\n", s1);
	return ok1 && ok2;
}

/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrcpy...");
	char s1[] = "Some sample string."; // String we will copy.
	char s2[30]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	printf("String 1: %s\n", s1);
	printf("String 2: %s\n", s3);
	bool ok = ok1 && ok2;
	return ok;
}

/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpyShort(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrcpy with a short string...");
	char s1[] = "Some sample string."; // String we will copy.
	char s2[3]; // Empty string we will copy into (too short for s1)

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) > 0) { // Is original greater than to copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	printf("String 1: %s\n", s1);
	printf("String 2: %s\n", s3);
	printf("Data overwritten -- s2 is too short\n");

	return ok1 && ok2;
}

/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpyLong(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrcpy with a long string...");
	char s1[] = "Some sample string."; // String we will copy.
	char s2[40] = "Hi hello what's up hows it going"; // Empty string we will copy into (too long)

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Is original equal to copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	printf("String 1: %s\n", s2);
	printf("String 2: %s\n", s3);
	return ok1 && ok2;
}

/*
 * Test mystrncpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrncpy(void) {
	bool ok1 = false;

	puts("\nTesting mystrncpy...");
	char s1a[] = "      "; // An empty destination string
	char s2a[] = "012345"; // A short string we will copy into it.
	char* s3a = mystrcpy(s1a, s2a); //Copying the string

	char s1b[] = "012345678901234567890123456789"; // A long destination string
	char s2b[] = "      "; // A short string we will copy into it.
	char* s3b = mystrncpy(s2b, s1b, 6); // The result

	printf("String 1: %s\n", s3a);
	printf("String 2: %s\n", s3b);
	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	return ok1;
}

/*
 * Test mystrncpy() function with a large n.
 * @return true if pass, false if fail.
 */
bool testMystrncpyLarge(void) {
	bool ok1 = false;

	puts("\nTesting mystrncpy with a large string...");
	char s1a[] = "      \0\0\0\0"; // A destination string with multiple null terminators
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = mystrcpy(s1a, s2a); // The result with added null terminators

	char s1b[] = "012345678901234567890123456789"; // A long destination string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 10); // The result, with added null terminators

	printf("String 1: %s\n", s3a);
	printf("String 2: %s\n", s3b);
	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	return ok1;
}

/*
 * Test mystrncat() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrncat...");
	char s1a[] = "ABCDEF\0\0\0\0\0\0\0"; // A string with multiple \0's
	char s2a[] = "ABCDEF"; // A short string we will concatenate onto s1a
	strcpy(s1a, s2a);
	char* s4a =	mystrcat(s1a, s2a); // The result

	printf("In testMystrncat(): s1a after mystrcopy = /%s/\n", s1a); // these results should be the
	printf("In testMystrncat(): s4a after mystrcopy = /%s/\n", s4a); // same output as mystrncat

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 6); // The result

	printf("In testMystrncat(): s1b after mystrncopy = /%s/\n", s1b);
	printf("In testMystrncat(): s4b after mystrncopy = /%s/\n", s4b);

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	return ok1 && ok2;
}

/**
 * Test the mystrcat function with a fitting string
 */
bool testMystrcat(void) {
	bool ok1 = false;
	bool ok2 = false;

	puts("\nTesting mystrcat...");
	char s1[7] = "world!"; // String we will concatenate.
	char s2[14] = "Hello, "; // String we will append to
	char correct[14] = "Hello, world!"; // What the final string should look like
    printf("The first string: %s\n", s2);
    printf("The second string (that will be put on the end of the first): %s\n", s1);

	char* s3 = mystrcat(s2, s1); // Append the string
    printf("The string after concatenation: %s\n", s3);
    printf("The correct string: %s\n", correct);

	if (strcmp(correct, s3) == 0) { // Does correct equal s3?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	return ok1 && ok2;
}
