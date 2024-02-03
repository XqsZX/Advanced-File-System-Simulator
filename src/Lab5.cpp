#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/LSCommand.h"
#include "../include/mockos/RemoveCommand.h"
#include "../include/mockos/CatCommand.h"
#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/MacroCommand.h"
#include "../include/mockos/TouchCatParsingStrategy.h"
#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/RenameParsingStrategy.h"

int main() {
    // File system and factory
    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();

    // Commands
    TouchCommand* touch = new TouchCommand(fs, ff);
    LSCommand* ls = new LSCommand(fs);
    RemoveCommand* rm = new RemoveCommand(fs);
    CatCommand* cat = new CatCommand(fs);
    CopyCommand* cp = new CopyCommand(fs);
    DisplayCommand* ds = new DisplayCommand(fs);

    // Macro commands
    MacroCommand* touchCat = new MacroCommand();
    touchCat->setParseStrategy(new TouchCatParsingStrategy());
    touchCat->addCommand(touch);
    touchCat->addCommand(cat);

    // Create and configure the macro command
    MacroCommand* rn = new MacroCommand();
    rn->setParseStrategy(new RenameParsingStrategy());
    rn->addCommand(cp);
    rn->addCommand(rm);

    // Command prompt setup
    CommandPrompt cmd;
    cmd.setFileSystem(fs);
    cmd.setFileFactory(ff);
    cmd.addCommand("touch", touch);
    cmd.addCommand("ls", ls);
    cmd.addCommand("rm", rm);
    cmd.addCommand("cat", cat);
    cmd.addCommand("cp", cp);
    cmd.addCommand("ds", ds);
    cmd.addCommand("touchcat", touchCat);
    cmd.addCommand("rn", rn);

    // Run command prompt
    cmd.run();

    // Cleanup
    delete rn;
    delete touchCat;
    delete touch;
    delete ls;
    delete rm;
    delete cat;
    delete cp;
    delete ds;
    delete fs;
    delete ff;

    return 0;
}

