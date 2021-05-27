/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: BackingCommonDecl.h
*/

#pragma warning(disable:4996)

#ifndef __BACKING_COMMON_H__
#define __BACKING_COMMON_H__

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_CUS_NUM = 100;
const int NAME_LEN = 30;

// Menu
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Account type
enum { NORMAL = 1, CREDIT = 2 };

// Credit level
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

#endif // !__BACKING_COMMON_H__