#include "Program.h"

Program::Program()
{
}


Program::~Program()
{
}

void Program::Main(int argc, char *argv[]) {

}

int main(int argc, char *argv[]) {
	Program *program = new Program();
	program->Main(argc, argv);
}