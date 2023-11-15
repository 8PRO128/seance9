#include "Log.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

string Log::get_current_datetime() {
  auto now = chrono::system_clock::now();
  time_t now_time = chrono::system_clock::to_time_t(now);

  std::stringstream ss;
  ss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
  return ss.str();
}
  
Log::Log(string message) : message(message) {}

string Log::get_message() {
  return get_current_datetime() + " " + message;
}

void Log::print_message() {
  cout << get_message() << endl;
}