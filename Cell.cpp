#include "Cell.h"


                Cell::Cell():state(DEAD) {}


                void Cell::changeState() noexcept
                {
                    if(state==ALIVE)
                        state=DEAD;
                    else
                        state=ALIVE;
                }


                STATES Cell::convertCharToState(char c) noexcept
                {
                    if(c=='*')
                        return DEAD;
                    else
                        return ALIVE;
                }


                char Cell::convertStateToChar(STATES state) noexcept
                {
                    if(state==DEAD)
                        return '*';
                    else return 'A';
                }


                Cell& Cell::operator=(STATES other) noexcept
                {
                    state=other;
                    return *this;
                }


                bool Cell::operator==(STATES other) const noexcept
                {
                    return other==state;
                }
