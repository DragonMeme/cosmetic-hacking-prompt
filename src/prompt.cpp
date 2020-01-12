#include "prompt.h"

prompt::prompt(){
    // Main line class for render.
    l = new line();

    // Alternate class for use to render finished process without affecting main line.
    l2 = new line();

    // Initialise choice.
    choice = 0;
}

void prompt::tick(){
    // Obtain increment percentage, must not be more than 6.
    int increment = (int) rand() % 7;

    // Assure that the percentage is already at 100%. Change to the next choice when this happens.
    if(l->getPercentage() == 100){
        choice++;
        l->select_line(choice);
    }

    // Start incrementing percentage. When already at 100%, reset to 0.
    l->increment_percentage(increment);
}

void prompt::render(){
    int i;

    // Add title for completed processes. This will be colored yellow
    cout << "\u001b[33m" << "[Processes Completed]" << "\n";

    // Add completed process(es). This will be colored green.
    cout << "\u001b[32m";
    for(i = 0; i < choice; i++){
        l2->select_line(i);
        cout << l2->getLine(true) << "\n";
    }

    // Add updating process.
    cout << "\n\u001b[33m" << "[Current Progress]" << "\n";
    cout << "\u001b[37m";

    // Progress only available between choices 0 to 8.
    if(choice < 9){
        int percentage = l->getPercentage();
        
        // Print progress percentage.
        cout << l->getLine(false);
        cout << "\n" << "Progress..." << percentage << "%";
        if(percentage == 100){ 
            cout << "\n" << l->getLine(true); 
            cout << "\n" << "Press [ENTER] to continue!";

            // Wait for enter to be pressed.
            cin.ignore();
        } 

    // When progress reaches 9, make process complete and prompt for enter.
    }else{
        cout << "Process Complete!\n";
        cout << "\nPress [ENTER] to terminate the program!";
                
        // Wait for enter to be pressed and then terminate program.
        cin.ignore();
    }
    cout << endl;
}

// Return current progress.
int prompt::getProgress(){
    return choice;
}

prompt::~prompt(){
}