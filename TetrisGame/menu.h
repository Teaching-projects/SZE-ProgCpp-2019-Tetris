#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void GameOver(int score);
	int GetPressedItem() { return selectedItemIndex; }
	bool GetAgain();
	int load();
	void Best();

private:
    void save(std::string score,int num);
    bool Again=false;
    std::string intToStr(int num);
    std::string Score="Score: ";
    std::string Bestn="Best: ";
    int minSelectedItemIndex=0;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
