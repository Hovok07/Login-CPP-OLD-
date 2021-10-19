#include <iostream>
#include "User.h"

int main()
{
  bool running = true;

  while(running)
  {
    std::string username;
    std::string password;
    int choice;

    std::cout << "Login Project" << std::endl;

    std::cout << "Press Enter" << std::endl;

    std::cout << std::endl;


    std::cin.ignore();

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);


    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    std::cout << std::endl;
    
    std::cout << "1.Do you make an account" << std::endl;
    std::cout << "2.Do you want to login" << std::endl;
    std::cin >> choice;

    User LocalUser(username, password);

    switch(choice)
    {
      case 1:
      {
        if(LocalUser.ReadFile() == true)
        {
          std::cout << "You already have an account go and login" << std::endl;

          std::cout << std::endl;
        }
        else
        {
          LocalUser.WriteFile();

          std::cout << "You have an account" << std::endl;

          std::cout << std::endl;
        }
        break;
      }

      case 2:
      {
        if(LocalUser.ReadFile() == false)
        {
          std::cout << "You don't have an account" << std::endl;
          
          std::cout << std::endl;
        }
        else
        {
          std::cout << "You have an account welldone for finishing my project" << std::endl;

          exit(0);
        }
        break;
      }

      default:
      std::cout << "ERROR" << std::endl;
      std::cout << "Enter 1 or 2 next time" << std::endl;
      std::cout << std::endl;
      break;
    }

    int secondchoice;

    std::cout << "1 = Yes" << std::endl;
    std::cout << "2 = No" << std::endl;

    std::cout << std::endl;

    std::cout << "Do you want to contine: ";
    std::cin >> secondchoice;

    bool result = (secondchoice == 1) ? true : false;

    running = result;
    system("clear");
  }

  return 0;
}