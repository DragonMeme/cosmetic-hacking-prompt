#ifndef PROMPT_H_
#define PROMPT_H_

#include "line.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class prompt{
    private:
        line *l, *l2;
        int choice;
    public:
        prompt();
        void tick();
        void render();
        int getProgress();
        ~prompt();
};

#endif /* PROMPT_H_ */