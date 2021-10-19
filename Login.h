#include <iostream>
#include <fstream>

class Login
{
  private:
  std::string username;
  std::string password;

  public:
  Login(std::string username, std::string password)
  : username(username), password(password) {}

  inline void WriteFile();
  bool ReadFile();
};

void Login::WriteFile()
{
  std::ofstream file;
  file.open("data.txt");

  file << "[USERNAME] " << this->username << " [PASSWORD] " << this->password << std::endl;
  file.close();
}

bool Login::ReadFile()
{
  std::ifstream file;

  file.open("data.txt", std::ios::app);
  std::string text;


  while(std::getline(file, text))
  {
    if(text.find(this->username) != std::string::npos && text.find(this->password) != std::string::npos)
    {
      return true; //we found their account
    }
  }
  file.close();

  return false; // we didn't find their account 
}