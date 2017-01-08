#pragma once

#ifndef ENGINE_IO_CONTROLLER_H
#define ENGINE_IO_CONTROLLER_H

#include <list>
#include <iterator>
#include <gl/glut.h>
#include "../types/point2d.h"
#include "../utils/singleton.h"

namespace Engine {
	namespace Core { class Engine; } // Definición postergada para evitar dependencia circular.
	namespace IO {
		enum class ControlKey {
			BACKSPACE = 0x08,
			TAB = 0x09,
			CAPS_LOCK = 0x0F, // Caso especial 0x0E
			ESC = 0x1B,
			SPACE = 0x20,
			DEL = 0x7F,

			NUM_0 = (int)'0',
			NUM_1 = (int)'1',
			NUM_2 = (int)'2',
			NUM_3 = (int)'3',
			NUM_4 = (int)'4',
			NUM_5 = (int)'5',
			NUM_6 = (int)'6',
			NUM_7 = (int)'7',
			NUM_8 = (int)'8',
			NUM_9 = (int)'9',

			A = (int)'a',
			B = (int)'b',
			C = (int)'c',
			D = (int)'d',
			E = (int)'e',
			F = (int)'f',
			G = (int)'g',
			H = (int)'h',
			I = (int)'i',
			J = (int)'j',
			K = (int)'k',
			L = (int)'l',
			M = (int)'m',
			N = (int)'n',
			Ñ = (int)'ñ',
			O = (int)'o',
			P = (int)'p',
			Q = (int)'q',
			R = (int)'r',
			S = (int)'s',
			T = (int)'t',
			U = (int)'u',
			V = (int)'v',
			W = (int)'w',
			X = (int)'x',
			Y = (int)'y',
			Z = (int)'z',

			F1 = 0xF000 & GLUT_KEY_F1,
			F2 = 0xF000 & GLUT_KEY_F2,
			F3 = 0xF000 & GLUT_KEY_F3,
			F4 = 0xF000 & GLUT_KEY_F4,
			F5 = 0xF000 & GLUT_KEY_F5,
			F6 = 0xF000 & GLUT_KEY_F6,
			F7 = 0xF000 & GLUT_KEY_F7,
			F8 = 0xF000 & GLUT_KEY_F8,
			F9 = 0xF000 & GLUT_KEY_F9,
			F10 = 0xF000 & GLUT_KEY_F10,
			F11 = 0xF000 & GLUT_KEY_F11,
			F12 = 0xF000 & GLUT_KEY_F12,

			LEFT = 0xF000 & GLUT_KEY_LEFT,
			UP = 0xF000 & GLUT_KEY_UP,
			RIGHT = 0xF000 & GLUT_KEY_RIGHT,
			DOWN = 0xF000 & GLUT_KEY_DOWN,
			PAGE_UP = 0xF000 & GLUT_KEY_PAGE_UP,
			PAGE_DOWN = 0xF000 & GLUT_KEY_PAGE_DOWN,
			HOME = 0xF000 & GLUT_KEY_HOME,
			END = 0xF000 & GLUT_KEY_END,
			INSERT = 0xF000 & GLUT_KEY_INSERT,

			MOUSE_LEFT = 0xF200 & GLUT_LEFT_BUTTON, 
			MOUSE_RIGHT = 0xF200 & GLUT_RIGHT_BUTTON,
			MOUSE_CENTER = 0xF200 & GLUT_MIDDLE_BUTTON,

			SHIFT = 0xF300, 
			CTRL = 0xF301,
			ALT = 0xF302
		};

		class Controller : public Utils::Singleton<Controller>
		{
			friend class Core::Engine;
			friend class Utils::Singleton<Controller>;

		private:
			std::list<ControlKey> pressedKeys;
			Types::Point2D mousePosition;

			Controller();
			~Controller();

			void startUpdate();
			void updateMouseMove(Types::Point2D* position);
			void updateKeyPress(ControlKey key);

		public:
			bool isKeyPressed(ControlKey key) const;
			std::list<ControlKey> getPressedKeys();
			Types::Point2D getMousePosition() const;
		};
	}
}

#endif