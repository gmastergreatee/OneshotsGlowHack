#pragma once
/*here we have all our includes that we need to include
into OneshotsGlowHack.cpp this is nice to do*/
#include "Hprocess.h"
#include "Glow.h"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

void displayStat(bool&, int&, bool&, bool&);
void loadOffsets();
void setOffset(std::string line);