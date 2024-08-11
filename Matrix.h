#pragma once
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include "Cell.h"
#include "FileNames.h"

                class Matrix
                {
                    int dimension;
                    std::vector<std::vector<Cell>> matrix;
                    enum {LOWER_BOUND=2,UPPER_BOUND=3};

                public:
                    Matrix(int=Names::randomDimension);
                    Matrix(std::ifstream&);

                    void calculateNextGen() noexcept;
                    void putMatrixInFile(std::ofstream&) const noexcept;
                    friend std::ostream& operator<<(std::ostream&,const Matrix&) noexcept;

                private:
                    int calculateNeighbours(int,int) const noexcept;
                    STATES calculateDeadCell(int,int) noexcept;
                    STATES calculateAliveCell(int,int) noexcept;
                };
