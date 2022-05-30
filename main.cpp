#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void Bubble_Sort(sf::RenderWindow& window, float arr[], int n){
	int i, j, p;
	for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
               // Sleep(100);
                window.clear();
                for(p=0; p<n; p++) {
                    sf::RectangleShape Rect(sf::Vector2f(25.f, arr[p]));
                    Rect.setPosition(10 + p * 30, window.getSize().y - arr[p] - 10);
                    Rect.setFillColor(sf::Color::White);
                    window.draw(Rect);
                }
                window.display();
            }
        }
	}
}

int main()
{
    srand(time(NULL));
    int l = 30;
    float arr[l];
    for(int i=0; i<l; i++) {
        int rndNum = 25 + rand()%400;
        arr[i] = float(rndNum);
    }
    sf::RenderWindow window(sf::VideoMode(1100, 650), "Sorting Algorithm Visualisation", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    window.setFramerateLimit(60);

    //button for bubble sort
    sf::RectangleShape BubbleButton(sf::Vector2f(100.0f,50.0f));
    BubbleButton.setPosition(10,10);
    sf::Texture bubblePNG;
    bubblePNG.loadFromFile("Bubble.png");
    BubbleButton.setTexture(&bubblePNG);
    bool buttonIsPressed = false;

    while (window.isOpen())
    {
        sf::Vector2i mousePoz=sf::Mouse::getPosition(window);
        if(buttonIsPressed == false) {
            window.draw(BubbleButton);
            window.display();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (BubbleButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y))
            {
                buttonIsPressed = true;
                Bubble_Sort(window, arr, l);
                window.clear();

                for(int p=0; p<l; p++) {
                    sf::RectangleShape Rect(sf::Vector2f(25.f, arr[p]));
                    Rect.setPosition(10 + p * 30, window.getSize().y - arr[p] - 10);
                    Rect.setFillColor(sf::Color::Green);

                    window.draw(Rect);
                }

                window.display();
            }
        }

    }

    return 0;
}
