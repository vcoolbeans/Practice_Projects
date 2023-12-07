#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Practice Movement");

	sf::Texture texture;

	if (!texture.loadFromFile("Character.png")) {
		std::cerr << "failed to load file" << std::endl;
	}

	int frame = 0;

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 220, 47, 74));
	sprite.setPosition(sf::Vector2f(400, 228)); //somewhat centered

	while (window.isOpen()) {
		
		sf::Event event;
		window.setFramerateLimit(60);
	
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			frame++;
			std::cout << frame << std::endl;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				//move right 0 1 2 3 4 5 
				sprite.setTextureRect(sf::IntRect((frame / 2 % 6) * 47, 220, 47, 74)); 
				sprite.move(5, 0);

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				//move left 12 13 14 15 16 17
				sprite.setTextureRect(sf::IntRect((frame / 2 % 6 + 12) * 48, 220, 47, 68));
				sprite.move(-5, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				//move up 6 7 8 9 10 11
				sprite.setTextureRect(sf::IntRect((frame / 2 % 6 + 6) * 48, 220, 48, 68)); 
				sprite.move(0, -5);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				//move down 18 19 20 21 22 23
				sprite.setTextureRect(sf::IntRect((frame / 2 % 6 + 18) * 48, 220, 48, 68));
				sprite.move(0, 5);
			}

			window.clear(sf::Color(255, 255, 255));
			window.draw(sprite);
			window.display();
		}
	}
	return 0;
}