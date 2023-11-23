#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Solver.h"
#include "Case.h"

//get the distance from the last case
void getDist(std::vector<std::vector<Case>>* listCase) {
	for (int i = 0; i < (*listCase).size(); i++) {
		for (int j = 0; j < (*listCase)[i].size(); j++) {
			if (!(*listCase)[i][j]._isWall) {
				double X((*listCase)[i][j]._x - (*listCase).back().back()._x);
				double Y((*listCase)[i][j]._y - (*listCase).back().back()._y);

				(*listCase)[i][j]._distance = X * X + Y * Y;
			}
		}
	}
}

//find the minimal distance between different case
Case minDist(std::vector<Case> neighbor) {
	Case nextCase(neighbor[0]);

	for (int i = 0 ; i < neighbor.size(); i++) {
		if (nextCase._distance > neighbor[i]._distance) {
			nextCase = neighbor[i];
		}
	}

	return nextCase;
}

//solve the labyrinthe
std::vector<Case> solve(std::vector<std::vector<Case>> listCase) {
	std::vector<Case> solveList;

	Case nextCase;

	int s(0);
	int i(0);
	int j(0);

	solveList.push_back(listCase[0][0]);

	while (solveList.back()._x != listCase.back().back()._x && solveList.back()._y != listCase.back().back()._y) {
		std::vector<Case> neighbor;
		
		if (solveList[s]._firstLine) {
			if(solveList[s]._firstRow) {
				if (!listCase[i][j + 1]._isWall) {
					neighbor.push_back(listCase[i][j + 1]);
				}

				if (!listCase[i + 1][j]._isWall) {
					neighbor.push_back(listCase[i + 1][j]);
				}
			}

			else if (solveList[s]._lastRow) {
				if (!listCase[i][j - 1]._isWall) {
					neighbor.push_back(listCase[i][j - 1]);
				}

				if (!listCase[i + 1][j]._isWall) {
					neighbor.push_back(listCase[i + 1][j]);
				}
			}

			else {
				if (!listCase[i][j + 1]._isWall) {
					neighbor.push_back(listCase[i][j + 1]);
				}

				if (!listCase[i][j - 1]._isWall) {
					neighbor.push_back(listCase[i][j - 1]);
				}

				if (!listCase[i + 1][j]._isWall) {
					neighbor.push_back(listCase[i + 1][j]);
				}
			}
		}

		else if (solveList[s]._lastLine) {
			if (solveList[s]._firstRow) {
				if (!listCase[i][j + 1]._isWall) {
					neighbor.push_back(listCase[i][j + 1]);
				}
				
				if (!listCase[i - 1][j]._isWall) {
					neighbor.push_back(listCase[i - 1][j]);
				}
			}

			else if (solveList[s]._lastRow) {
				if (!listCase[i][j - 1]._isWall) {
					neighbor.push_back(listCase[i][j - 1]);
				}

				if (!listCase[i - 1][j]._isWall) {
					neighbor.push_back(listCase[i - 1][j]);
				}
			}

			else {
				if (!listCase[i][j + 1]._isWall) {
					neighbor.push_back(listCase[i][j + 1]);
				}

				if (!listCase[i][j - 1]._isWall) {
					neighbor.push_back(listCase[i][j - 1]);
				}

				if (!listCase[i - 1][j]._isWall) {
					neighbor.push_back(listCase[i - 1][j]);
				}
			}
		}

		else if (solveList[s]._firstRow) {
			if (!listCase[i][j + 1]._isWall) {
				neighbor.push_back(listCase[i][j + 1]);
			}

			if (!listCase[i + 1][j]._isWall) {
				neighbor.push_back(listCase[i + 1][j]);
			}

			if (!listCase[i - 1][j]._isWall) {
				neighbor.push_back(listCase[i - 1][j]);
			}
		}

		else if (solveList[s]._lastRow) {
			if (!listCase[i][j - 1]._isWall) {
				neighbor.push_back(listCase[i][j - 1]);
			}

			if (!listCase[i + 1][j]._isWall) {
				neighbor.push_back(listCase[i + 1][j]);
			}

			if (!listCase[i - 1][j]._isWall) {
				neighbor.push_back(listCase[i - 1][j]);
			}
		}

		else {
			if (!listCase[i][j + 1]._isWall) {
				neighbor.push_back(listCase[i][j + 1]);
			}

			if (!listCase[i][j - 1]._isWall) {
				neighbor.push_back(listCase[i][j - 1]);
			}

			if (!listCase[i + 1][j]._isWall) {
				neighbor.push_back(listCase[i + 1][j]);
			}

			if (!listCase[i - 1][j]._isWall) {
				neighbor.push_back(listCase[i - 1][j]);
			}
		}

		if ((neighbor.size() == 1 && neighbor[0]._isPassed) && solveList.size() != 1) {
			listCase[i][j]._isWall = true;

			if (solveList[s]._x - solveList[s-1]._x < 0.0) {
				j++;
			}

			if (solveList[s]._x - solveList[s-1]._x > 0.0) {
				j--;
			}

			if (solveList[s]._y - solveList[s-1]._y < 0.0) {
				i++;
			}

			if (solveList[s]._y - solveList[s-1]._y > 0.0) {
				i--;
			}

			solveList.pop_back();
			s--;
		}

		else {
			for (int i = 0; i < neighbor.size(); i++) {
				if (neighbor[i]._isPassed) {
					neighbor.erase(neighbor.begin() + i);
				}
			}

			nextCase = minDist(neighbor);

			solveList.push_back(nextCase);

			listCase[i][j]._isPassed = true;

			if (nextCase._x - solveList[s]._x < 0.0) {
				j--;
			}

			if (nextCase._x - solveList[s]._x > 0.0) {
				j++;
			}

			if (nextCase._y - solveList[s]._y < 0.0) {
				i--;
			}

			if (nextCase._y - solveList[s]._y > 0.0) {
				i++;
			}

			s++;
		}
	}

	solveList.push_back(listCase.back().back());

	return solveList;
}