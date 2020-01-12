#include "prompt.h"
#include <ctime>

int main(){

    // Initialisation.
    prompt *p = new prompt();
    system("clear");
    bool running;
    time_t start_time, current_time;
    start_time = time(nullptr);
    running = true;

    // Start Program.
    while(running){
        // Update time.
        current_time = time(nullptr);

        // Make sure to render every 2 seconds as time_t is in seconds.
        if((int) (current_time - start_time) >= 1) {
            start_time = current_time;
            p->tick();

            // Start render.
            system("clear");
            p->render();

            //When process is complete, set running false to exit program.
            running = p->getProgress() < 9;
        }
    }

    // Exit program.
    p->~prompt();
    return 1;
}



