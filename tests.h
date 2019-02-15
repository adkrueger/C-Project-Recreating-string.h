/*
 * tests.h
 *
 *  Created on: Jan 24, 2019
 *      Author: Aaron Krueger
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include "production.h"

// Function prototypes:
bool tests(void);
bool testMystrlen1(void);
bool testMystrlen2(void);
bool testMystrdup(void);
bool testMystrndup(void);
bool testMystrndupLarge(void);
bool testMystrcpy(void);
bool testMystrncpy(void);
bool testMystrncpyLarge(void);
bool testMystrcpy(void);
bool testMystrcpyShort(void);
bool testMystrcpyLong(void);
bool testMystrncat(void);
bool testMystrcat(void);

#endif /* TESTS_H_ */


