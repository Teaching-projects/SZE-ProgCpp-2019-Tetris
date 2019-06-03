#include "Menu.h"
#include "game.h"

Menu::Menu(float width, float height)
{


	if (!font.loadFromFile("arial.ttf"))
	{
		// ha nincs fájl
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Green);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(20,10));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Best");
	menu[1].setPosition(sf::Vector2f(20, 40));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(20, 70));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}
int Menu::load(){
    std::string score;
    std::ifstream in;

    in.open("best.txt");
    in>>score;

    int num;
    std::stringstream ss(score);
    ss >> num;

    in.close();
    return num;

}

void Menu::save(std::string score,int num){
    if(num>load()){
        std::ofstream out;
        out.open("best.txt");
        out<<score;
        out.close();
    }
}

bool Menu::GetAgain(){
    return Again;
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= minSelectedItemIndex)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}
std::string Menu::intToStr(int num){
    std::string out_string;
    std::stringstream ss;
    ss << num;
    out_string = ss.str();
    return out_string;
}


void Menu::Best(){
     menu[0].setColor(sf::Color::Red);
     selectedItemIndex=1;
     menu[selectedItemIndex].setColor(sf::Color::Green);
     minSelectedItemIndex++;
     Again=true;
     Bestn+=intToStr(load());
     menu[0].setString(Bestn);
     menu[1].setString("Play");
}

void Menu::GameOver(int score){
    if(Again==false){
        menu[0].setColor(sf::Color::Red);
        selectedItemIndex=1;
        menu[selectedItemIndex].setColor(sf::Color::Green);
        minSelectedItemIndex++;
        Again=true;

        save(intToStr(score),score);
        Score+=intToStr(score);
        menu[0].setString(Score);
        menu[1].setString("Play");
    }else{
        Score="Score: ";
        Score+=intToStr(score);
        save(intToStr(score),score);
        menu[0].setString(Score);
    }
}

