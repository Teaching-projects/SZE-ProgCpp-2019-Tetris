#include <SFML/Graphics.hpp>
#include "cell.h"
#include "figure.h"
#include "game.h"
#include <iostream>
#include "menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 120), "Tetris");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
				    if(menu.GetPressedItem()==0 && menu.GetAgain()==false){
                        std::cout << "Play" << std::endl;

                        window.setVisible(false);
                        Game game;
                        window.setVisible(true);

                        menu.GameOver(game.getScore());
                        game.~Game();


				    }else if(menu.GetPressedItem()==1){
				        if(menu.GetAgain()==true){
                            std::cout << "Again" << std::endl;
                            window.setVisible(false);
                            Game game;
                            window.setVisible(true);
                            menu.GameOver(game.getScore());
                            game.~Game();
				        }else{
                        std::cout << menu.load() << std::endl;
                        menu.Best();
                        std::cout << "Best" << std::endl;
				        }
				    }else if(menu.GetPressedItem()==2){
                        std::cout << "Exit" << std::endl;
                        window.close();
				    }

				}
				break;

			case sf::Event::Closed:
				window.close();

				break;

			}
		}
		window.clear();

		menu.draw(window);

		window.display();
	}
}
