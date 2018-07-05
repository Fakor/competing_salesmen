#include <iostream>
#include <string>

int main(int argc, char **argv){
  std::string command_file;
  if(argc==2){
    command_file = argv[1];
  } else{
    return 1;
  }
  std::cout << "Command file: " << command_file << std::endl;

  return 0;
}
