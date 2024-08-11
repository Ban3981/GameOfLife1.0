#include "FileNames.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


            void Game::executeGame() const noexcept(false)
            {
                std::cout<<"<<<<<<<<<<<<<<<<<<<< - Welcome to Game Of Life!!! - >>>>>>>>>>>>>>>>>>>>\n\n";

                int numberOfGenerations;
                std::cout<<"How much generations you want to calculate?";
                std::cin>>numberOfGenerations;

                int source=readFromUser("Do you want to read configuration from file(enter 1) or you want to generate some random configuration(enter 2)?",{"1","2"});
                int destination=readFromUser("Do you want to print generations in file(enter 1) or you want to print them on console(enter 2)",{"1","2"});

                if(source==2)
                {
                    int dimension;
                    std::cout<<"Enter dimension of your matrix:";
                    std::cin>>dimension;
                    Matrix matrix(dimension);

                    if(destination==1)
                        putGenerationInFile(numberOfGenerations,matrix);
                    else
                        putGenerationInConsole(numberOfGenerations,matrix);
                }

                else
                {
                    std::ifstream sourceFile(Names::inputFile);
                    if(!sourceFile)
                        throw std::runtime_error("Source file cannot be open!");

                    Matrix matrix(sourceFile);
                    sourceFile.close();

                    if(destination==1)
                        putGenerationInFile(numberOfGenerations,matrix);
                    else
                        putGenerationInConsole(numberOfGenerations,matrix);
                }

            }


            void Game::putGenerationInFile(int numberOfGenerations,Matrix& matrix) const noexcept(false)
            {
                std::ofstream destinationFile(Names::outputFile);
                if(!destinationFile)
                    throw std::runtime_error("Output file cannnot be open!");

                for(int i=1;i<=numberOfGenerations;++i)
                {
                    matrix.putMatrixInFile(destinationFile);
                    destinationFile<<"\n\n\n\n";;
                    matrix.calculateNextGen();
                }

                destinationFile.close();
                std::cout<<"Generations have been succesfully written in destination file!";
                std::getchar();
            }


            int Game::readFromUser(const std::string& message,const std::vector<std::string>& validValues) const noexcept
            {
                auto check=[](const std::string input,const std::vector<std::string>& validValues)->bool
                            {
                                for(auto x:validValues)
                                    if(input==x)
                                        return true;
                                return false;
                            };

                std::string input;
                std::cout<<message;
                do
                {
                    std::cin>>input;
                }while(!check(input,validValues));

                int result;
                std::istringstream stream(input);
                stream>>result;
                return result;
            }


            void Game::putGenerationInConsole(int numberOfGenerations,Matrix& matrix) const noexcept(false)
            {
                for(int i=1;i<=numberOfGenerations;++i)
                {
                    std::cout<<matrix<<"\n\n\n\n";;
                    matrix.calculateNextGen();
                }

                std::getchar();
                std::getchar();
            }
