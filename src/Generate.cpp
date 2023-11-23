#include <SFML/Graphics.hpp>
#include <iostream>
#include <random> 

#include "Generate.h"
#include "Case.h"

//generate an echiquier

std::vector<std::vector<Case>> generateList(double sizeCase, double windowX, double windowY) {
    std::vector<std::vector<Case>> listCase;

    for (double y = sizeCase; y <= windowY - 2.0 * sizeCase; y += sizeCase) {
        std::vector<Case> ligne;

        for (double x = sizeCase; x <= windowX - 2.0 * sizeCase; x += sizeCase) {
            if ((int)(x / sizeCase) % 3 == (int)(y / sizeCase) % 3) {
                Case newCase(sizeCase);

                newCase.drawCase(x, y);
                ligne.push_back(newCase);
            }

            else {
                Case newCase(sizeCase, true);

                newCase.drawCase(x, y);
                ligne.push_back(newCase);
            }
        }

        listCase.push_back(ligne);
    }

    for (int i = 0; i < listCase.size(); i++) {
        for (int j = 0; j < listCase[i].size(); j++) {
            if (i == 0) {
                listCase[i][j]._firstLine = true;
            }

            if (i == listCase.size() - 1) {
                listCase[i][j]._lastLine = true;
            }

            if (j == 0) {
                listCase[i][j]._firstRow = true;
            }

            if (j == listCase[i].size() - 1) {
                listCase[i][j]._lastRow = true;
            }
        }
    }

    return listCase;
}

//destroy the wall to make a makable labyrinthe
void generateLaby(std::vector<std::vector<Case>> *listCase) {
    for (int i = 0; i < (*listCase).size(); i++) {
        for (int j = 0; j < (*listCase)[i].size(); j++) {
            if (!(*listCase)[i][j]._isWall) {

                int sideWall(0);

                if ((*listCase)[i][j]._firstLine) {
                    if ((*listCase)[i][j]._firstRow) {
                        if ((*listCase)[i][j + 1]._isWall && (*listCase)[i + 1][j]._isWall) {
                            switch (rand() % 2)
                            {
                            case 1:
                                (*listCase)[i][j + 1].destroy();
                                break;

                            default:
                                (*listCase)[i + 1][j].destroy();
                                break;
                            }
                        }
                    }

                    else if ((*listCase)[i][j]._lastRow) {
                        if ((*listCase)[i][j - 1]._isWall && (*listCase)[i + 1][j]._isWall) {
                            switch (rand() % 2)
                            {
                            case 1:
                                (*listCase)[i][j - 1].destroy();
                                break;

                            default:
                                (*listCase)[i + 1][j].destroy();
                                break;
                            }
                        }
                    }

                    else {
                        if ((*listCase)[i][j - 1]._isWall && (*listCase)[i + 1][j]._isWall && (*listCase)[i][j + 1]._isWall) {
                            switch (rand() % 3)
                            {
                            case 1:
                                (*listCase)[i][j + 1].destroy();
                                break;

                            case 2:
                                (*listCase)[i][j - 1].destroy();
                                break;

                            default:
                                (*listCase)[i + 1][j].destroy();
                                break;
                            }
                        }
                    }
                }


                else if ((*listCase)[i][j]._lastLine) {
                    if ((*listCase)[i][j]._firstRow) {
                        if ((*listCase)[i][j + 1]._isWall && (*listCase)[i - 1][j]._isWall) {
                            switch (rand() % 2)
                            {
                            case 1:
                                (*listCase)[i][j + 1].destroy();
                                break;

                            default:
                                (*listCase)[i - 1][j].destroy();
                                break;
                            }
                        }
                    }

                    else if ((*listCase)[i][j]._lastRow) {
                        if ((*listCase)[i][j - 1]._isWall && (*listCase)[i - 1][j]._isWall) {
                            switch (rand() % 2)
                            {
                            case 1:
                                (*listCase)[i][j - 1].destroy();
                                break;

                            default:
                                (*listCase)[i - 1][j].destroy();
                                break;
                            }
                        }
                    }

                    else {
                        if ((*listCase)[i][j + 1]._isWall && (*listCase)[i - 1][j]._isWall && (*listCase)[i][j - 1]._isWall) {
                            switch (rand() % 3)
                            {
                            case 1:
                                (*listCase)[i][j + 1].destroy();
                                break;

                            case 2:
                                (*listCase)[i][j - 1].destroy();
                                break;

                            default:
                                (*listCase)[i - 1][j].destroy();
                                break;
                            }
                        }
                    }
                }


                else if ((*listCase)[i][j]._firstRow) {
                    if ((*listCase)[i+1][j]._isWall && (*listCase)[i - 1][j]._isWall && (*listCase)[i][j + 1]._isWall) {
                        switch (rand() % 3)
                        {
                        case 1:
                            (*listCase)[i][j + 1].destroy();
                            break;

                        case 2:
                            (*listCase)[i+1][j].destroy();
                            break;

                        default:
                            (*listCase)[i - 1][j].destroy();
                            break;
                        }
                    }
                }


                else if ((*listCase)[i][j]._lastRow) {
                    if ((*listCase)[i + 1][j]._isWall && (*listCase)[i - 1][j]._isWall && (*listCase)[i][j - 1]._isWall) {
                        switch (rand() % 3)
                        {
                        case 1:
                            (*listCase)[i][j - 1].destroy();
                            break;

                        case 2:
                            (*listCase)[i + 1][j].destroy();
                            break;

                        default:
                            (*listCase)[i - 1][j].destroy();
                            break;
                        }
                    }
                }


                else {
                    if ((*listCase)[i][j - 1]._isWall) {
                        sideWall++;
                    }

                    if ((*listCase)[i][j + 1]._isWall) {
                        sideWall++;
                    }

                    if ((*listCase)[i - 1][j]._isWall) {
                        sideWall++;
                    }

                    if ((*listCase)[i + 1][j]._isWall) {
                        sideWall++;
                    }

                    if (sideWall == 3) {
                        switch (rand() % 4)
                        {
                        case 1:
                            (*listCase)[i][j - 1].destroy();
                            break;

                        case 2:
                            (*listCase)[i][j + 1].destroy();
                            break;

                        case 3:
                            (*listCase)[i - 1][j].destroy();
                            break;

                        default:
                            (*listCase)[i + 1][j].destroy();
                            break;
                        }
                    }

                    if (sideWall == 4) {
                        switch (rand() % 6)
                        {
                        case 1:
                            (*listCase)[i][j - 1].destroy();
                            (*listCase)[i][j + 1].destroy();
                            break;

                        case 2:
                            (*listCase)[i][j + 1].destroy();
                            (*listCase)[i - 1][j].destroy();
                            break;

                        case 3:
                            (*listCase)[i - 1][j].destroy();
                            (*listCase)[i][j - 1].destroy();
                            break;

                        case 4:
                            (*listCase)[i + 1][j].destroy();
                            (*listCase)[i][j + 1].destroy();
                            break;

                        case 5:
                            (*listCase)[i + 1][j].destroy();
                            (*listCase)[i][j - 1].destroy();
                            break;

                        default:
                            (*listCase)[i + 1][j].destroy();
                            (*listCase)[i - 1][j].destroy();
                            break;
                        }
                    }
                }
            }
        }
    }
}
