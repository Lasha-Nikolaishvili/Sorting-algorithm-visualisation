#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

float windowWidth=1100.0f, windowHeight=650.0f;

class BubbleSort {
private:
    int i, j, p, k;
public:
    void Bubble_Sort(sf::RenderWindow& window, std::vector<float>& arr, int n){
        float RectSpacing = (windowWidth - 10)/(n);
        float RectWidth = RectSpacing-2.0f;
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

    bool showBubble(sf::RenderWindow& window, std::vector<float>& arr, int l, sf::RectangleShape& ResetButton)
    {
        Bubble_Sort(window, arr, l);
        float RectSpacing = (windowWidth - 10)/(l);
        float RectWidth = RectSpacing-2.0f;
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

    void showExplanation(sf::RenderWindow& window, sf::Font headerFont, sf::Font bodyFont, sf::RectangleShape& ResetButton) {
        //header
        sf::Text headerText;
        headerText.setFont(headerFont);
        headerText.setString("Bubble Sort");
        headerText.setCharacterSize(30);
        headerText.setPosition(10.0f,10.0f);
        headerText.setFillColor(sf::Color::Green);

        //body
        std::string howItWorks = "The basic idea of bubble sorting is that it repeatedly swaps adjacent elements if they are not in the desired order.\n\nIf a given array of elements has to be sorted in ascending order, bubble sorting will start by comparing the first element of the array\nwith the second element and immediately swap them if it turns out to be greater than the second element, and then move on to compare\nthe second and third element, and so on.";
        std::string timeComplexity = "Time Complexity:\n\t* Worst Case: O(n^2)\n\t* Average Case: O(n*logn)\n\t* Best case: O(n*logn)";
        std::string useCases = "Use Cases:\n\t* It is used to introduce the concept of a sorting algorithm to Computer Science students.\n\t* In computer graphics, bubble sorting is quite popular when it comes to detecting a very small error (like swap of just two elements) \nin almost-sorted arrays.";
        sf::Text bodyText;
        bodyText.setFont(bodyFont);
        bodyText.setString(howItWorks + "\n\n" + timeComplexity + "\n\n" + useCases);
        bodyText.setCharacterSize(16);
        bodyText.setPosition(10.0f,60.0f);
        bodyText.setFillColor(sf::Color::White);

        //code img
        sf::RectangleShape BubbleCode(sf::Vector2f(528.0f,220.0f));
        BubbleCode.setPosition(0,windowHeight - 230.0f);
        sf::Texture BubbleCodePNG;
        BubbleCodePNG.loadFromFile("images/BubbleCode.png");
        BubbleCode.setTexture(&BubbleCodePNG);

        window.clear();
        window.draw(headerText);
        window.draw(bodyText);
        window.draw(ResetButton);
        window.draw(BubbleCode);
        window.display();
    }
};

class SelectionSort {
private:
    int i, j, p, k, pos;
public:

    void Selection_Sort(sf::RenderWindow& window, std::vector<float>& arr, int n)
    {
        float RectSpacing = (windowWidth - 10)/(n);
        float RectWidth = RectSpacing-2.0f;
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

    bool showSelection(sf::RenderWindow& window, std::vector<float>& arr, int l, sf::RectangleShape& ResetButton)
    {
        Selection_Sort(window, arr, l);
        window.clear();
        float RectSpacing = (windowWidth - 10)/(l);
        float RectWidth = RectSpacing-2.0f;

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

    void showExplanation(sf::RenderWindow& window, sf::Font headerFont, sf::Font bodyFont, sf::RectangleShape& ResetButton) {
        //header
        sf::Text headerText;
        headerText.setFont(headerFont);
        headerText.setString("Selection Sort");
        headerText.setCharacterSize(30);
        headerText.setPosition(10.0f,10.0f);
        headerText.setFillColor(sf::Color::Green);

        //body
        std::string howItWorks = "Selection sort is a sorting algorithm in which the given array is divided into two subarrays, the sorted left section, \nand the unsorted right section.\n\nInitially, the sorted portion is empty and the unsorted part is the entire list. In each iteration, \nwe fetch the minimum element from the unsorted list and push it to the end of the sorted list\nthus building our sorted array.";
        std::string timeComplexity = "Time Complexity:\n\t* Worst Case: O(n*n)\n\t* Average Case: O(n*logn)\n\t* Best case: O(n*logn)";
        std::string useCases = "Use Cases:\n\t* It is used when the size of a list is small. (Time complexity of selection sort is O(N^2) which makes it inefficient for a large list.)\n\t* It is also used when memory space is limited because it makes the minimum possible number of swaps during sorting.";
        sf::Text bodyText;
        bodyText.setFont(bodyFont);
        bodyText.setString(howItWorks + "\n\n" + timeComplexity + "\n\n" + useCases);
        bodyText.setCharacterSize(16);
        bodyText.setPosition(10.0f,60.0f);
        bodyText.setFillColor(sf::Color::White);

        //code img
        sf::RectangleShape SelectionCode(sf::Vector2f(453.0f,301.0f));
        SelectionCode.setPosition(0,windowHeight - 301.0f);
        sf::Texture SelectionCodePNG;
        SelectionCodePNG.loadFromFile("images/SelectionCode.png");
        SelectionCode.setTexture(&SelectionCodePNG);

        window.clear();
        window.draw(headerText);
        window.draw(bodyText);
        window.draw(ResetButton);
        window.draw(SelectionCode);
        window.display();
    }
};

class InsertionSort {
private:
    int i, x, j, p, k;

public:

    void Insertion_Sort(sf::RenderWindow& window, std::vector<float>& arr, int n) {
        float RectSpacing = (windowWidth - 10)/(n);
        float RectWidth = RectSpacing-2.0f;
        window.clear();
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

    bool showInsertion(sf::RenderWindow& window, std::vector<float>& arr, int l, sf::RectangleShape& ResetButton)
    {
        Insertion_Sort(window, arr, l);
        window.clear();
        float RectSpacing = (windowWidth - 10)/(l);
        float RectWidth = RectSpacing-2.0f;

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

    void showExplanation(sf::RenderWindow& window, sf::Font headerFont, sf::Font bodyFont, sf::RectangleShape& ResetButton) {
        //header
        sf::Text headerText;
        headerText.setFont(headerFont);
        headerText.setString("Insertion Sort");
        headerText.setCharacterSize(30);
        headerText.setPosition(10.0f,10.0f);
        headerText.setFillColor(sf::Color::Green);

        //body
        std::string howItWorks = "Insertion sort is a sorting algorithm in which the given array is divided into a sorted and an unsorted section. In each iteration, \nthe element to be inserted has to find its optimal position in the sorted subsequence and is then inserted while shifting the \nremaining elements to the right.";
        std::string timeComplexity = "Time Complexity:\n\t* Worst Case: O(n*n)\n\t* Average Case: O(n*logn)\n\t* Best case: O(n*logn)";
        std::string useCases = "Use Cases:\n\t* This algorithm is stable and is quite fast when the list is nearly sorted.\n\t* It is very efficient when it comes to sorting very small lists (example say 30 elements.)";
        sf::Text bodyText;
        bodyText.setFont(bodyFont);
        bodyText.setString(howItWorks + "\n\n" + timeComplexity + "\n\n" + useCases);
        bodyText.setCharacterSize(16);
        bodyText.setPosition(10.0f,60.0f);
        bodyText.setFillColor(sf::Color::White);


        //code image
        sf::RectangleShape InsertionCode(sf::Vector2f(452.0f,276.0f));
        InsertionCode.setPosition(0,windowHeight - 306.0f);
        sf::Texture InsertionCodePNG;
        InsertionCodePNG.loadFromFile("images/InsertionCode.png");
        InsertionCode.setTexture(&InsertionCodePNG);


        window.clear();
        window.draw(headerText);
        window.draw(bodyText);
        window.draw(ResetButton);
        window.draw(InsertionCode);
        window.display();
    }
};

int main()
{
    BubbleSort bubble;
    SelectionSort selection;
    InsertionSort insertion;

    int l=25;
    srand(time(NULL));
    std::vector<float> arr;
    //float arr[l];
    for(int i=0; i<l; i++) {
        int rndNum = 25 + rand()%450;
        arr.push_back(float(rndNum));
    }
    sf::RenderWindow window(sf::VideoMode(windowWidth + 10.0f, windowHeight), "Sorting Algorithm Visualization", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    //button for bubble sort
    sf::RectangleShape BubbleButton(sf::Vector2f(100.0f,50.0f));
    BubbleButton.setPosition(10,10);
    sf::Texture bubblePNG;
    bubblePNG.loadFromFile("images/Bubble.png");
    BubbleButton.setTexture(&bubblePNG);
    //button for selection sort
    sf::RectangleShape SelectionButton(sf::Vector2f(100.0f,50.0f));
    SelectionButton.setPosition(120,10);
    sf::Texture selectionPNG;
    selectionPNG.loadFromFile("images/Selection.png");
    SelectionButton.setTexture(&selectionPNG);
    //button for insertion sort
    sf::RectangleShape InsertionButton(sf::Vector2f(100.0f,50.0f));
    InsertionButton.setPosition(230,10);
    sf::Texture insertionPNG;
    insertionPNG.loadFromFile("images/Insertion.png");
    InsertionButton.setTexture(&insertionPNG);
    //button for reset
    sf::RectangleShape ResetButton(sf::Vector2f(100.f, 50.f));
    ResetButton.setPosition(window.getSize().x-110, 10);
    sf::Texture ResetPNG;
    ResetPNG.loadFromFile("images/Reset.png");
    ResetButton.setTexture(&ResetPNG);
    //BubbleExplanationBtn
    sf::RectangleShape BubbleExplanationBtn(sf::Vector2f(100.0f,50.0f));
    BubbleExplanationBtn.setPosition(10.0f,70.0f);
    sf::Texture BubbleExpPNG;
    BubbleExpPNG.loadFromFile("images/bubble_exp.png");
    BubbleExplanationBtn.setTexture(&BubbleExpPNG);
    //SelectionExplanationBtn
    sf::RectangleShape SelectionExplanationBtn(sf::Vector2f(100.0f,50.0f));
    SelectionExplanationBtn.setPosition(120.0f,70.0f);
    sf::Texture SelectionExpPNG;
    SelectionExpPNG.loadFromFile("images/selection_exp.png");
    SelectionExplanationBtn.setTexture(&SelectionExpPNG);
    //InsertionExplanationBtn
    sf::RectangleShape InsertionExplanationBtn(sf::Vector2f(100.0f,50.0f));
    InsertionExplanationBtn.setPosition(230.0f,70.0f);
    sf::Texture InsertionExpPNG;
    InsertionExpPNG.loadFromFile("images/insertion_exp.png");
    InsertionExplanationBtn.setTexture(&InsertionExpPNG);

    //loading fonts
    sf::Font headerFont, bodyFont;
    if (   !headerFont.loadFromFile("fonts/tilt_neon/TiltNeon-Regular-VariableFont_XROT,YROT.ttf")
        || !bodyFont.loadFromFile("fonts/roboto/roboto-regular.ttf")) {
        std::cout<<"error loading fonts";
    }

    //size buttons
    sf::RectangleShape Size25Btn(sf::Vector2f(100.0f,50.0f));
    Size25Btn.setPosition(10.0f,130.0f);
    sf::Texture Size25BtnPNG;
    Size25BtnPNG.loadFromFile("images/size_25.png");
    Size25Btn.setTexture(&Size25BtnPNG);

    sf::RectangleShape Size50Btn(sf::Vector2f(100.0f,50.0f));
    Size50Btn.setPosition(120.0f,130.0f);
    sf::Texture Size50BtnPNG;
    Size50BtnPNG.loadFromFile("images/size_50.png");
    Size50Btn.setTexture(&Size50BtnPNG);

    sf::RectangleShape Size100Btn(sf::Vector2f(100.0f,50.0f));
    Size100Btn.setPosition(230.0f,130.0f);
    sf::Texture Size100BtnPNG;
    Size100BtnPNG.loadFromFile("images/size_100.png");
    Size100Btn.setTexture(&Size100BtnPNG);

    sf::RectangleShape Size200Btn(sf::Vector2f(100.0f,50.0f));
    Size200Btn.setPosition(340.0f,130.0f);
    sf::Texture Size200BtnPNG;
    Size200BtnPNG.loadFromFile("images/size_200.png");
    Size200Btn.setTexture(&Size200BtnPNG);

    //size text
    sf::Text sizeText;
    sizeText.setFont(bodyFont);
    sizeText.setString("Array size: " + std::to_string(l));
    sizeText.setCharacterSize(25);
    sizeText.setPosition(450.0f,140.0f);
    sizeText.setFillColor(sf::Color::White);

    bool isStarted = false;
    while (window.isOpen()) {
        if(!isStarted) {
            window.clear();
            window.draw(BubbleButton);
            window.draw(SelectionButton);
            window.draw(InsertionButton);
            window.draw(BubbleExplanationBtn);
            window.draw(SelectionExplanationBtn);
            window.draw(InsertionExplanationBtn);
            window.draw(Size25Btn);
            window.draw(Size50Btn);
            window.draw(Size100Btn);
            window.draw(Size200Btn);
            window.draw(sizeText);
            window.display();
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePoz = sf::Mouse::getPosition(window);

            if (Size25Btn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                l = 25;
                arr.clear();
                for(int i=0; i<l; i++) {
                    int rndNum = 25 + rand()%450;
                    arr.push_back(float(rndNum));
                }
                sizeText.setString("Array size: " + std::to_string(l));
                window.clear();
                window.draw(sizeText);
                window.display();
            } else if (Size50Btn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                l = 50;

                arr.clear();
                for(int i=0; i<l; i++) {
                    int rndNum = 25 + rand()%450;
                    arr.push_back(float(rndNum));
                }
                sizeText.setString("Array size: " + std::to_string(l));
                window.clear();
                window.draw(sizeText);
                window.display();
            } else if (Size100Btn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                l = 100;

                arr.clear();
                for(int i=0; i<l; i++) {
                    int rndNum = 25 + rand()%450;
                    arr.push_back(float(rndNum));
                }

                sizeText.setString("Array size: " + std::to_string(l));
                window.clear();
                window.draw(sizeText);
                window.display();
            } else if (Size200Btn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                l = 200;

                arr.clear();
                for(int i=0; i<l; i++) {
                    int rndNum = 25 + rand()%450;
                    arr.push_back(float(rndNum));
                }
                sizeText.setString("Array size: " + std::to_string(l));
                window.clear();
                window.draw(sizeText);
                window.display();
            }

            if (BubbleButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                isStarted = bubble.showBubble(window,arr,l, ResetButton);
            } else if (SelectionButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                isStarted = selection.showSelection(window,arr,l, ResetButton);
            } else if (InsertionButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                isStarted = insertion.showInsertion(window,arr,l, ResetButton);
            } else if (BubbleExplanationBtn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                bubble.showExplanation(window, headerFont, bodyFont, ResetButton);
                isStarted = true;
            } else if (SelectionExplanationBtn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                selection.showExplanation(window, headerFont, bodyFont, ResetButton);
                isStarted = true;
            } else if (InsertionExplanationBtn.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                insertion.showExplanation(window, headerFont, bodyFont, ResetButton);
                isStarted = true;
            }

            if (ResetButton.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
                window.clear();
                window.draw(BubbleButton);
                window.draw(SelectionButton);
                window.draw(InsertionButton);
                window.draw(BubbleExplanationBtn);
                window.draw(SelectionExplanationBtn);
                window.draw(InsertionExplanationBtn);
                window.draw(Size25Btn);
                window.draw(Size50Btn);
                window.draw(Size100Btn);
                window.draw(Size200Btn);
                window.draw(sizeText);
                window.display();
                isStarted = false;
                arr.clear();
                for(int i=0; i<l; i++) {
                    int rndNum = 25 + rand()%450;
                    arr.push_back(float(rndNum));
                }
            }
        }

    }

    return 0;
}
