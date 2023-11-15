#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

class Log {
  private:
    string message;

    // La méthode renvoie les dates au format AAAA-MM-JJ HH:MM:SS
    string get_current_datetime() {
      auto now = chrono::system_clock::now();
      time_t now_time = chrono::system_clock::to_time_t(now);

      std::stringstream ss;
      ss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
      return ss.str();
    }
  
  public:
    Log(string message) : message(message) {}

    virtual string get_message() {
      return get_current_datetime() + " " + message;
    }

    void print_message() {
      cout << get_message() << endl;
    }
};

class DebugLog : public Log {
  public:
    DebugLog(string message) : Log(message) {}
    
    string get_message() override {
      string message = Log::get_message();
      return "[DEBUG] " + message;
    }
};


int main() {
  Log *statement = new Log("Une message generique");
  statement->print_message();

  DebugLog *debug_statement = new DebugLog("La valeur de x est 10");
  debug_statement->print_message();

  vector<Log*> logs;
  logs.push_back(statement);
  logs.push_back(debug_statement);

  for (int i = 0; i < logs.size(); i++) {
    logs[i]->print_message();
  }

  return 0;
}