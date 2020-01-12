#ifndef LINE_H_
#define LINE_H_

#include <iostream>
using std::string;

class line{
    private:
        int choice;
        int percentage;
        string chosen_line;
        string finish_line;
    public:
        line();
        void select_line(int choice);
        void increment_percentage(int inc);
        string getLine(bool finish);
        int getPercentage();
        ~line();
};

#endif /* LINE_H_ */