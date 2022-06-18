#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

class BubbleSort {
private:
    int i, j, p, k;
    int RectSpacing = 11;
    float RectWidth = 8.f;
public:
    void Bubble_Sort(sf::RenderWindow& window, float arr[], int n){
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                    window.clear();
                    for(p=0; p<n; p++) {
                        sf::RectangleShape Rect(sf::Vector2f(RectWidth, arr[p]));
                        Rect.setPosition(10 + p * RectSpacing, window.getSize().y - arr[p] - 10);
                        Rect.setFillColor((p==j+1)? sf::Color::Red : sf::Color::White);
                        window.draw(Rect);
                    }
                    window.display();
                }
            }
        }
    }

    bool showBubble(sf::RenderWindow& window, float arr[], int l, sf::RectangleShape& ResetButton)
    {
        Bubble_Sort(window, arr, l);
        window.clear();

        for(k=0; k<l; k++) {
            sf::RectangleShape Rect(sf::Vector2f(RectWidth, arr[k]));
            Rect.setPosition(10 + k * RectSpacing, window.getSize().y - arr[k] - 10);
            Rect.setFillColor(sf::Color::Green);

            window.draw(Rect);
        }
        window.draw(ResetButton);
        window.display();

        return true;
    }
};

class SelectionSort {
private:
    int i, j, p, k, pos;
    int RectSpacing = 11;
    float RectWidth = 8.f;
public:

    void Selection_Sort(sf::RenderWindow& window, float arr[], int n)
    {
        for (i = 0; i < n - 1; i++)
        {
            pos = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[pos]) pos = j;
                window.clear();
                for(p=0; p<n; p++) {
                    sf::RectangleShape Rect(sf::Vector2f(RectWidth, arr[p]));
                    Rect.setPosition(10 + p * RectSpacing, window.getSize().y - arr[p] - 10);
                    Rect.setFillColor((p==j || (arr[p]==arr[pos] && p < j))? (p==j)? sf::Color::Red : sf::Color::Blue : sf::Color::White);
                    window.draw(Rect);
                }
                window.display();
            }
            std::swap (arr[pos], arr[i]);
        }
    }

    bool showSelection(sf::RenderWindow& window, float arr[], int l, sf::RectangleShape& ResetButton)
    {
        Selection_Sort(window, arr, l);
        window.clear();

        for(k=0; k<l; k++) {
            sf::RectangleShape Rect(sf::Vector2f(RectWidth, arr[k]));
            Rect.setPosition(10 + k * RectSpacing, window.getSize().y - arr[k] - 10);
            Rect.setFillColor(sf::Color::Green);

            window.draw(Rect);
        }
        window.draw(ResetButton);
        window.display();

        return true;
    }
};

class InsertionSort {
private:
    int i, x, j, p, k, currIndex;
    int RectSpacing = 11;
    float RectWidth = 8.f;
public:

    void Insertion_Sort(sf::RenderWindow& window, float arr[], int n) {
            for (i = 1; i < n; i++) {
                x = arr[i];
                j = i - 1;

                while (j>= 0 && arr[j] > x) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                    for(p=0; p<n; p++) {
                        sf::RectangleShape Rect(sf::Vector2f(RectWidth, (p==j+1)? x : arr[p]));
                        Rect.setPosition(10 + p * RectSpacing, (p==j+1)? window.getSize().y - x - 10 : window.getSize().y - arr[p] - 10);
                        Rect.setFillColor((p==j+1)? sf::Color::Red : sf::Color::White);

                        window.draw(Rect);
                        //Sleep(10);
                    }
                        window.display();
                        window.clear();
                }

                arr[j + 1] = x;
            }
    }

    bool showInsertion(sf::RenderWindow& window, float arr[], int l, sf::RectangleShape& ResetButton)
    {
        Insertion_Sort(window, arr, l);
        window.clear();

        for(k=0; k<l; k++) {
            sf::RectangleShape Rect(sf::Vector2f(RectWidth, arr[k]));
            Rect.setPosition(10 + k * RectSpacing, window.getSize().y - arr[k] - 10);
            Rect.setFillColor(sf::Color::Green);

            window.draw(Rect);
        }
        window.draw(ResetButton);
        window.display();

        return true;
    }
};

int main()
{
    BubbleSort bubble;
    SelectionSort selection;
    InsertionSort insertion;
    //Buttons button;
    srand(time(NULL));
    int l = 99;
    float arr[l];
    for(int i=0; i<l; i++) {
        int rndNum = 25 + rand()%450;
        arr[i] = float(rndNum);
    }
    sf::RenderWindow window(sf::VideoMode(1100, 650), "Sorting Algorithm Visualization", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

 //button for bubble sort
    sf::RectangleShape BubbleButton(sf::Vector2f(100.0f,50.0f));
    BubbleButton.setPosition(10,10);
    sf::Texture bubblePNG;
    bubblePNG.loadFromFile("Bubble.png");
    BubbleButton.setTexture(&bubblePNG);
    //button for selection sort
    sf::RectangleShape SelectionButton(sf::Vector2f(100.0f,50.0f));
    SelectionButton.setPosition(120,10);
    sf::Texture selectionPNG;
    selectionPNG.loadFromFile("Selection.png");
    SelectionButton.setTexture(&selectionPNG);
    //button for insertion sort
    sf::RectangleShape InsertionButton(sf::Vector2f(100.0f,50.0f));
    InsertionButton.setPosition(230,10);
    sf::Texture insertionPNG;
    insertionPNG.loadFromFile("Insertion.png");
    InsertionButton.setTexture(&insertionPNG);
    //button for reset
    sf::RectangleShape ResetButton(sf::Vector2f(100.f, 50.f));
    ResetButton.setPosition(window.getSize().x-110, 10);
    sf::Texture ResetPNG;
    ResetPNG.loadFromFile("Reset.png");
    ResetButton.setTexture(&ResetPNG);

    bool buttonIsPressed = false;
    while (window.isOpen())
    {
        sf::Vector2i mousePoz=sf::Mouse::getPosition(window);
        if(buttonIsPressed == false) {
            window.draw(BubbleButton);
            window.draw(InsertionButton);
            window.draw(SelectionButton);
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
                buttonIsPressed = bubble.showBubble(window,arr,l, ResetButton);
            }

            if (SelectionButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y))
            {
                buttonIsPressed = selection.showSelection(window,arr,l, ResetButton);
            }

            if (InsertionButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y))
            {
                buttonIsPressed = insertion.showInsertion(window,arr,l, ResetButton);
            }

            if (ResetButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y))
            {
                window.clear();
                window.draw(BubbleButton);
                window.draw(SelectionButton);
                window.draw(InsertionButton);
                window.display();

                for(int i=0; i<l; i++) {
                    int rndNum = 25 + rand()%400;
                    arr[i] = float(rndNum);
                }
            }

        }

    }

    return 0;
}
