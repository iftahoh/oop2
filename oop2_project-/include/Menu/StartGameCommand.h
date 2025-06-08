#include <Menu/ICommand.h>

class StartGameCommand : public ICommand {
public:
	StartGameCommand() = default;
	~StartGameCommand() override = default;
	void execute() override {
		// Logic to start the game
		// This could involve changing the game state, loading resources, etc.
		// For example:
		std::cout << "Starting the game..." << std::endl;
	}
};