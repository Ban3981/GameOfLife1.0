#pragma once

            enum STATES {DEAD,ALIVE};

            class Cell
            {
            public:
                Cell();
                Cell(const Cell& )=default;

                inline bool isAlive() const noexcept {return state==ALIVE;}
                inline bool isDead() const noexcept {return state==DEAD;}
                inline STATES currentState() const noexcept {return state;}
                void changeState() noexcept;

                Cell& operator=(STATES) noexcept;
                bool operator==(STATES) const noexcept;

                static STATES convertCharToState(char) noexcept;
                static char convertStateToChar(STATES) noexcept;
            private:
                STATES state;
            };


