#pragma once

#include <iostream>
#include <string>
#include <map>

const int displayWidth = 80;
const int displayHeight = 50;

class Desctop
{
    std::map <std::string,int> commands = { {"display",0},
                                            {"resize", 1},
                                            {"move",   2},
                                            {"exit",   3} };
    struct coordinates
    {
        int x = 0;
        int y = 0;
    };

    coordinates parameters;
    int width = 0;
    int height = 0;

    bool isCorrectCoordinates()
    {
        int wSize = parameters.x + width;
        int hSize = parameters.y + height;

        return (parameters.x <= displayWidth && parameters.y <= displayHeight &&
            wSize <= displayWidth && hSize <= displayHeight &&
            width > 0 && height > 0);
    }

    char tryAgain()
    {
        int wSize = parameters.x + width;
        int hSize = parameters.y + height;

        return (parameters.x <= displayWidth && parameters.y <= displayHeight &&
            wSize <= displayWidth && hSize <= displayHeight &&
            width > 0 && height > 0);
    }

public:
    Desctop()
    {
        bool correct = false;
        while (!correct)
        {
            std::cout << "Enter coordinate of top-left angle window (0.." << displayHeight <<
                ", 0.." << displayWidth << "):";
            std::cin >> parameters.y >> parameters.x;
            std::cout << "Enter width window: ";
            std::cin >> width;
            std::cout << "Enter height window: ";
            std::cin >> height;
            correct = isCorrectCoordinates();
            if (!correct)
            {
                system ("cls");
                std::cout << "Incorrect window coordinates. Try again" << std::endl;
            }
        }
        system("cls");
    }

    void display()
    {
        system("cls");
        for (int i = 0; i < displayHeight; ++i)
        {
            for (int j = 0; j < displayWidth; ++j)
            {
                if ((j >= parameters.x) && (j <= parameters.x + (width -1)) &&
                    (i >= parameters.y) && (i <= parameters.y + (height - 1)))
                {
                    std::cout << "1";
                }    
                else
                {
                    std::cout << "0";
                }       
            }
            std::cout << std::endl;
        }
    }

    void move()
    {
        int xTmp = parameters.x;
        int yTmp = parameters.y;
        bool correct = false;
        while (!correct)
        {
            system("cls");
            int wMax = displayWidth - width;
            int hMax = displayHeight - height;
            int tmpCoord;
            std::cout << "Enter new width coordinate (" << -xTmp << ".." << wMax << "): ";
            std::cin >> tmpCoord;
            parameters.x += tmpCoord;
            std::cout << "Enter new height coordinate (" << -yTmp << ".." << hMax << "): ";
            std::cin >> tmpCoord;
            parameters.y += tmpCoord;

            correct = isCorrectCoordinates();
            if (!correct)
            {
                parameters.x = xTmp;
                parameters.y = yTmp;
                std::cout << "Incorrect window coordinates" << std::endl;
                char answer = tryAgain();
                if (answer == 'n')
                {
                    correct = true;
                }       
            }
        }
        system("cls");
        if (xTmp == parameters.x && yTmp == parameters.y)
        {
            std::cout << "Window didn't move" << std::endl;
        }   
        else
        {
            std::cout << "Window moved on (" << parameters.y << ", " << parameters.x << ") " << std::endl;
        }
            
        std::cout << std::endl;
    }

    void resize()
    {
        int wTmp = width;
        int hTmp = height;
        bool correct = false;
        while (!correct)
        {
            system("cls");
            int wMax = displayWidth - parameters.x;
            int hMax = displayHeight - parameters.y;
            std::cout << "Current width = " << wTmp << std::endl;
            std::cout << "Current height = " << hTmp << std::endl;
            std::cout << "Enter new width (1.." << wMax << "): ";
            std::cin >> width;
            std::cout << "Enter new height (1.." << hMax << "): ";
            std::cin >> height;
            correct = isCorrectCoordinates();
            if (!correct)
            {
                width = wTmp;
                height = hTmp;
                std::cout << "Incorrect window size" << std::endl;
                char answer = tryAgain();
                if (answer == 'n')
                    correct = true;
            }
        }
        system("cls");
        if (wTmp == width && hTmp == height)
            std::cout << "Window size didn't change" << std::endl;
        else
        {
            std::cout << "Windows change size" << std::endl;
            std::cout << " width = " << width << std::endl;
            std::cout << " height = " << height << std::endl;
        }
        std::cout << std::endl;
    }

    int chosenCommand()
    {
        std::cout << "Available commands:" << std::endl;
        for (const auto& c : commands)
        {
            std::cout << "  " << c.first << ";" << std::endl;
        }   
        std::map <std::string, int>::iterator itf = commands.end();
        while (itf == commands.end())
        {
            std::cout << std::endl << "Enter a command: ";
            std::string enteredCommand;
            std::cin >> enteredCommand;

            itf = commands.find(enteredCommand);
            if (itf != commands.end())
            {
                return (itf->second);
            }   
            else
            {
                std::cout << "Incorrect command. Try again" << std::endl << std::endl;
            }        
        }
    }
private:
    
};
