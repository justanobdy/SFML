////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#include <SFML/Main.hpp>
#include <vector>
#include <iostream>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "filedrop");

    window.setFileDroppingEnabled(true);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* filedrop = event->getIf<sf::Event::FilesDropped>())
            {
                std::string files;
                for (const auto& file : filedrop->filenames)
                {
                    files.append(file.toAnsiString() + " ");
                }
                std::cout << files << std::endl;
                std::cout << filedrop->position.x << " " << filedrop->position.y << std::endl;
            }
        }

        // Clear screen
        window.clear();

        // Update the window
        window.display();
    }


    return 0;
}
