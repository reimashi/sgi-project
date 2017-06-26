#include "game_scene.h"
#include "engine/core/camera.h"

GameScene::GameScene() : Core::Scene()
{
}

GameScene::~GameScene()
{
}

void GameScene::init()
{
	// Se carga el tablero de juego. Se trata de un rectangulo
	// sobre el plano XZ con una textura cargada desde un archivo TGA
	this->table = new TableObject();
	this->addObject(this->table);

	// Se carga la ficha de juego. Se trata de un modelo 3D cargado
	// desde un archivo OBJ con una superficie de un unico color.
	this->puck = new PuckObject();
	this->addObject(this->puck);

	// Se carga el mazo de juego. Se trata de un modelo 3D cargado
	// desde un archivo OBJ con una superficie de un unico color.
	this->mallet = new MalletObject();
	this->addObject(this->mallet);

	// Se configura la camara por defecto de la escena para una vista desde arriba
	this->camera->setTarget(Types::Point3D(0, 0, 0));
	this->camera->setPosition(Types::Point3D(0, 2.5, 3));
}

void GameScene::loop()
{
	// Se inicializan algunas variables necesarias
	float_t widthLimit = this->table->getSize().getWidth();
	float_t depthLimit = this->table->getSize().getHeight();
	Core::Engine *engine = &Core::Engine::getInstance();

	// Manejo de opciones
	if (this->controls->isKeyPressed(IO::ControlKey::F1)) engine->displayFramerate(true);
	else if (this->controls->isKeyPressed(IO::ControlKey::F2)) engine->displayFramerate(false);

	// Control del mallet con el ratón
	Types::Point2D mousePosition = this->controls->getMousePosition();
	float_t malletXLimit = widthLimit - this->mallet->getCollisionRadius();
	float_t malletZLimit = depthLimit - this->mallet->getCollisionRadius();
	float_t malletX = (mousePosition.getX() / engine->getSize()->getWidth() * malletXLimit * 2) - malletXLimit;
	float_t malletZ = (mousePosition.getY() / engine->getSize()->getHeight() * malletZLimit * 2) - malletZLimit;
	this->mallet->setPosition(Types::Point3D(malletX, this->mallet->getPosition().getY(), malletZ));

	// Se resuelven las colisiones con el mazo
	resolveCollision(this->puck, this->mallet);

	// Se resuelven las colisiones con la mesa
	this->table->resolveCollision(this->puck);
	
	_sleep(30);
}

void GameScene::resolveCollision(PuckObject* puck, MalletObject* mallet)
{
	Types::Vector3D malletPosition = mallet->getPosition();
	Types::Vector3D puckPosition = puck->getPosition();

	float_t collisionDistance = mallet->getCollisionRadius() + puck->getCollisionRadius();

	// Vector de colisión
	Types::Vector3D delta = puckPosition - malletPosition;

	// Distancia entre los objetos
	float_t distance = delta.getMagnitude();

	// Para evitar divisiones por 0
	if (distance == 0.0) {
		delta = Types::Vector3D(collisionDistance, 0.0, 0.0);
		distance = collisionDistance;
	}

	// Si la distancia no es suficiente para la colisión, no se hace nada
	if (distance > collisionDistance)
	{
		return;
	}
	else {
		// Consideramos el mallet inamovible y movemos el puck para evitarlo
		Types::Vector3D mtd = delta * ((collisionDistance - distance) / distance);
		puckPosition = puckPosition + (mtd * 2);
		puck->setPosition(puckPosition.getPoint());

		// Calculamos la nueva velocidad del puck
		puck->setVelocity(delta * 2);
	}
}