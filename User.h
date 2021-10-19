#include <iostream>
#include "Login.h"


class User : public Login
{
  private:
  std::string username;
  std::string password;

  public:
  User(std::string username, std::string password)
  : Login(username, password), username(username), password(password)
  {}

};