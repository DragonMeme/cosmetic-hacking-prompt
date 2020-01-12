#include "line.h"

line::line(){
    // Initialise variables.
    percentage = 0;
    choice = 0;
    this->select_line(choice);
}

void line::increment_percentage(int inc){
    // Check that the increment to percentage does not exceed 100.
    // Also check that percentage is not initially at 100.
    if(percentage + inc > 100 && percentage < 100){
        percentage = 100;

    // Reset percentage if 100% is already reached.
    }else if(percentage == 100){
        percentage = 0;

    // Otherwise increment percentage.
    }else{
        percentage = percentage + inc;
    }
}

void line::select_line(int line){
    choice = line;
    switch(choice){
        case 1:
            chosen_line = "Searching for system with DNS Name: NASA.";
            finish_line = "NASA system found, encrypted using process AES-256!";
            break;
        case 2:
            chosen_line = "Attempting to decrypt NASA system.";
            finish_line = "NASA system successfully decrypted!";
            break;
        case 3:
            chosen_line = "Searching for important information.";
            finish_line = "Blob storage of important information found!";
            break;
        case 4:
            chosen_line = "Obtaining blob storage.";
            finish_line = "Blob storage successfully downloaded!";
            break;
        case 5:
            chosen_line = "Attempting to decrypt blob storage.";
            finish_line = "Decryption process completed, password required for access!";
            break;
        case 6:
            chosen_line = "Cracking password to decrypt blob storage.";
            finish_line = "Successfully accessed blob, password is: DOOMSDAY2012";
            break;
        case 7:
            chosen_line = "Copyiing files to local storage.";
            finish_line = "Files successfully copied from blob storage!";
            break;
        case 8:
            chosen_line = "Processing files obtained from blob.";
            finish_line = "Blob successfully processed, NASA current main objective: Send Elon Musk to Mars!";
            break;
        default:
            chosen_line = "Loading Program.";
            finish_line = "Successfully Loaded Program!";
            break;
    }
}

// Return the line depending on if the finished line is wanted or not.
string line::getLine(bool finish){
    return finish ? finish_line : chosen_line;
}

int line::getPercentage(){
    return percentage;
}

line::~line(){
}