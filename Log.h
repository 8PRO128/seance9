#ifndef LOG_H
#define LOG_H

#include <iostream>
using namespace std;

class Log {
  private:
    string message;

    // La méthode renvoie les dates au format AAAA-MM-JJ HH:MM:SS
    string get_current_datetime();
  
  public:
    Log(string message);

    virtual string get_message();

    void print_message();
};


#endif