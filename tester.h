#pragma once

#include "classes.h"

#define TESTSIZE 3

enum class testCreation{test = 1, control};

void launchTest();
void createTestVec(std::vector<std::vector<int>>& testVec, testCreation choice);
