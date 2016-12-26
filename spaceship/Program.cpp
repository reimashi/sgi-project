#include "Program.h"
#include "engine/engine.h"
#include "SpaceshipScene.h"

using namespace Engine;

Program::Program()
{
}

Program::~Program()
{
}

int Program::Main(int argc, char *argv[]) {
	Core::Engine *engine = &Core::Engine::getInstance();

	SpaceshipScene *scene = new SpaceshipScene();

	engine->resize(new Types::Dimension2D(800, 600));
	engine->setTitle("Spaceship");
	engine->run(scene);

	return 0;
}

int main(int argc, char *argv[]) {
	Program *program = new Program();
	return program->Main(argc, argv);
}