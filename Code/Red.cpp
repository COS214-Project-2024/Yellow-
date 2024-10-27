
#include "Red.h"

string Red::getSeverity() {
    return "Red";
}

Severity *Red::handle(bool increment) {
    if(increment){
        cout << "\033[38;5;226m Well done, things seem to be improving. State changing to yellow \033[0m" << endl;
        return new Yellow();
    }
    else{
        cout << "\033[38;5;9m Things are at their lowest. Pay attention to your city! State staying red \033[0m" << endl;
        return new Red();
    }

}

