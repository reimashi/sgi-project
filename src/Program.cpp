#include "Program.h"
#include "engine/engine.h"
#include "game_scene.h"

using namespace Engine;

Program::Program()
{
}

Program::~Program()
{
}

int Program::Main(int argc, char *argv[]) {
	// Descomentar para hacer debug
	Engine::Utils::Logger::setLevel(Engine::Utils::Logger::L_ALL);

	Core::Engine *engine = &Core::Engine::getInstance();

	GameScene *scene = new GameScene();

	engine->resize(new Types::Dimension2D(800, 600));
	engine->setTitle("Air hockey");
	engine->run(scene);

	return 0;
}

int main(int argc, char *argv[]) {
	Program *program = new Program();
	return program->Main(argc, argv);
}