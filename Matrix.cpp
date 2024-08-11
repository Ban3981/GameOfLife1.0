#include "Matrix.h"
#include "FileNames.h"
#include "Cell.h"


                Matrix::Matrix(int dimension):dimension(dimension),matrix(dimension,std::vector<Cell>(dimension))
                {
                    unsigned seed=std::chrono::steady_clock::now().time_since_epoch().count();
                    std::default_random_engine myRandomEngine(seed);
                    std::uniform_int_distribution<int> myUnifDist(0,1);
                    for(int i=0;i<dimension;++i)
                        for(int j=0;j<dimension;++j)
                            matrix[i][j]=static_cast<STATES>(myUnifDist(myRandomEngine));
                }


                Matrix::Matrix(std::ifstream& file)
                {
                    file>>dimension;
                    matrix.resize(dimension,std::vector<Cell>(dimension));
                    for(unsigned int i=0;i<matrix.size();++i)
                        for(unsigned int j=0;j<matrix.size();++j)
                        {
                            char c;
                            file>>c;
                            if(file && c!=' ' && c!='\n')
                            matrix[i][j]=Cell::convertCharToState(c);
                        }
                }


                void Matrix::calculateNextGen() noexcept
                {
                    std::vector<std::vector<Cell>> temp(dimension,std::vector<Cell>(dimension));
                    for(int i=0;i<dimension;++i)
                        for(int j=0;j<dimension;++j)
                        {
                            STATES state;
                            if(matrix[i][j]==ALIVE)
                                state=calculateAliveCell(i,j);
                            else
                                state=calculateDeadCell(i,j);
                            temp[i][j]=state;
                        }

                    for(int i=0;i<dimension;++i)
                        for(int j=0;j<dimension;++j)
                            matrix[i][j]=temp[i][j];
                }


                void Matrix::putMatrixInFile(std::ofstream& file) const noexcept
                {
                    for(unsigned int i=0;i<matrix.size();++i)
                    {
                        for(unsigned int j=0;j<matrix.size();++j)
                            file<<Cell::convertStateToChar(matrix[i][j].currentState())<<' ';
                        file<<'\n';
                    }
                }


                int Matrix::calculateNeighbours(int x,int y) const noexcept
                {
                    int counter=0;
                    for(int i=x-1;i<=x+1;++i)
                        for(int j=y-1;j<=y+1;++j)       //torus topology
                        {
                            int temp1=i,temp2=j;

                            if(i==-1)
                                i=dimension-1;
                            if(i==dimension)
                                i=0;
                            if(j==-1)
                                j=dimension-1;
                            if(j==dimension)
                                j=0;
                            if(matrix[i][j].isAlive())
                                ++counter;

                            i=temp1,j=temp2;
                        }

                    if(matrix[x][y]==ALIVE)         //avoid cell for which calculation was done
                        --counter;

                    return counter;
                }


                STATES Matrix::calculateDeadCell(int x, int y) noexcept
                {
                    int number=calculateNeighbours(x,y);
                    if(number==UPPER_BOUND)
                        return ALIVE;
                    else
                        return DEAD;
                }


                STATES Matrix::calculateAliveCell(int x,int y) noexcept
                {
                    int number=calculateNeighbours(x,y);
                    if(number<LOWER_BOUND || number>UPPER_BOUND)
                        return DEAD;
                    else
                        return ALIVE;
                }


                std::ostream& operator<<(std::ostream& output,const Matrix& other) noexcept
                {
                    for(unsigned int i=0;i<other.matrix.size();++i)
                    {
                        for(unsigned int j=0;j<other.matrix.size();++j)
                            output<<Cell::convertStateToChar(other.matrix[i][j].currentState())<<' ';
                        output<<'\n';
                    }

                    return output;
                }
