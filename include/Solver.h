#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Case.h"

//get distance from the last case
void getDist(std::vector<std::vector<Case>> *listCase);

//find the minimal distance between different case
Case minDist(std::vector<Case> neighbor);

//solve the labyrinthe
std::vector<Case> solve(std::vector<std::vector<Case>> listCase);
