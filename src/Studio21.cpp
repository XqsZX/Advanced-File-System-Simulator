#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/CommandPrompt.h"
#include <iostream>

int main() {
    // Set up the file system, file factory, and command
    AbstractFileSystem* fileSystem = new SimpleFileSystem();
    AbstractFileFactory* fileFactory = new SimpleFileFactory();
    TouchCommand* touch = new TouchCommand(fileSystem, fileFactory);

    // Set up the command prompt and add the touch command
    CommandPrompt prompt;
    prompt.setFileSystem(fileSystem);
    prompt.setFileFactory(fileFactory);
    prompt.addCommand("touch", touch);

    // Run the command prompt
    prompt.run();

    // Tests to perform:
    // 1. Quit the command prompt (enter 'q')
    // 2. Ask for general help (enter 'help')
    // 3. Ask for help on the touch command (enter 'help touch')
    // 4. Execute the touch command (enter 'touch test.txt')

    // After quitting, you can verify if "touch" worked by trying to open the file
    AbstractFile* openedFile = fileSystem->openFile("test.txt");
    if (openedFile != nullptr) {
        std::cout << "File created successfully." << std::endl;
        fileSystem->closeFile(openedFile);
    }
    else {
        std::cout << "File creation failed." << std::endl;
    }

    // Clean up
    delete fileSystem;
    delete fileFactory;
    delete touch;

    return 0;
}
