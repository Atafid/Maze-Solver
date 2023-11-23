#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Case.h"

//generate an echiquier
std::vector<std::vector<Case>> generateList(double sizeCase, double windowX, double windowY);

void generateLaby(std::vector<std::vector<Case>> *listCase);