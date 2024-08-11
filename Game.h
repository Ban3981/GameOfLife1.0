#pragma once
#include "Matrix.h"
#include <string>

            class Game
            {
            public:
                Game()=default;
                void executeGame() const noexcept(false);
            private:
                void putGenerationInFile(int,Matrix&) const noexcept(false);
                void putGenerationInConsole(int,Matrix&) const noexcept(false);
                int readFromUser(const std::string&,const std::vector<std::string>&) const noexcept;
            };



