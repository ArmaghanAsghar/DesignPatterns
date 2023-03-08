#include <thread>
#include <iostream>

using namespace std;

class Logger {
 private:
  int i = 0;

  Logger() {}

 public:

    static Logger& getInstance() {
      static Logger *instance = new Logger;
      cout << "Address: " << instance << endl;
      return *instance;
    }
  void setValue(int value) {
    i = value;
  }
  int getValue() {
    return i;
  }
};


Logger Logger::*l1 = nullptr;

int main(int argc, char* argv[]) {



  auto &ret = Logger::getInstance();
  auto &ret2 = Logger::getInstance();

  ret.setValue(10);
  cout << ret.getValue() << endl;

  cout << ret2.getValue() << endl;


  return 0;
}
