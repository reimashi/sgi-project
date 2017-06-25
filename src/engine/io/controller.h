#pragma once

#ifndef ENGINE_IO_CONTROLLER_H
#define ENGINE_IO_CONTROLLER_H

#include <list>
#include <iterator>
#include <stdlib.h>
#include <gl/glut.h>
#include "../types/point2d.h"
#include "../utils/singleton.h"

namespace Engine {
	namespace Core { class Engine; } // Definición postergada para evitar dependencia circular.
	namespace IO {

		/**
		* \brief Mapa de teclas de control
		*/
		enum class ControlKey {
			BACKSPACE = 0x08,
			TAB = 0x09,
			CAPS_LOCK = 0x0F, // Caso especial 0x0E
			ESC = 0x1B,
			SPACE = 0x20,
			DEL = 0x7F,

			NUM_0 = static_cast<int>('0'),
			NUM_1 = static_cast<int>('1'),
			NUM_2 = static_cast<int>('2'),
			NUM_3 = static_cast<int>('3'),
			NUM_4 = static_cast<int>('4'),
			NUM_5 = static_cast<int>('5'),
			NUM_6 = static_cast<int>('6'),
			NUM_7 = static_cast<int>('7'),
			NUM_8 = static_cast<int>('8'),
			NUM_9 = static_cast<int>('9'),

			A = static_cast<int>('a'),
			B = static_cast<int>('b'),
			C = static_cast<int>('c'),
			D = static_cast<int>('d'),
			E = static_cast<int>('e'),
			F = static_cast<int>('f'),
			G = static_cast<int>('g'),
			H = static_cast<int>('h'),
			I = static_cast<int>('i'),
			J = static_cast<int>('j'),
			K = static_cast<int>('k'),
			L = static_cast<int>('l'),
			M = static_cast<int>('m'),
			N = static_cast<int>('n'),
			Ñ = static_cast<int>('ñ'),
			O = static_cast<int>('o'),
			P = static_cast<int>('p'),
			Q = static_cast<int>('q'),
			R = static_cast<int>('r'),
			S = static_cast<int>('s'),
			T = static_cast<int>('t'),
			U = static_cast<int>('u'),
			V = static_cast<int>('v'),
			W = static_cast<int>('w'),
			X = static_cast<int>('x'),
			Y = static_cast<int>('y'),
			Z = static_cast<int>('z'),

			F1 = 0xF000 + GLUT_KEY_F1,
			F2 = 0xF000 + GLUT_KEY_F2,
			F3 = 0xF000 + GLUT_KEY_F3,
			F4 = 0xF000 + GLUT_KEY_F4,
			F5 = 0xF000 + GLUT_KEY_F5,
			F6 = 0xF000 + GLUT_KEY_F6,
			F7 = 0xF000 + GLUT_KEY_F7,
			F8 = 0xF000 + GLUT_KEY_F8,
			F9 = 0xF000 + GLUT_KEY_F9,
			F10 = 0xF000 + GLUT_KEY_F10,
			F11 = 0xF000 + GLUT_KEY_F11,
			F12 = 0xF000 + GLUT_KEY_F12,

			LEFT = 0xF000 + GLUT_KEY_LEFT,
			UP = 0xF000 + GLUT_KEY_UP,
			RIGHT = 0xF000 + GLUT_KEY_RIGHT,
			DOWN = 0xF000 + GLUT_KEY_DOWN,
			PAGE_UP = 0xF000 + GLUT_KEY_PAGE_UP,
			PAGE_DOWN = 0xF000 + GLUT_KEY_PAGE_DOWN,
			HOME = 0xF000 + GLUT_KEY_HOME,
			END = 0xF000 + GLUT_KEY_END,
			INSERT = 0xF000 + GLUT_KEY_INSERT,

			MOUSE_LEFT = 0xF200 + GLUT_LEFT_BUTTON, 
			MOUSE_RIGHT = 0xF200 + GLUT_RIGHT_BUTTON,
			MOUSE_CENTER = 0xF200 + GLUT_MIDDLE_BUTTON,

			SHIFT = 0xF300, 
			CTRL = 0xF301,
			ALT = 0xF302
		};

		/**
		* \brief Clase que maneja todos los controles del game engine.
		*/
		class Controller : public Utils::Singleton<Controller>
		{
			friend class Core::Engine;
			friend class Utils::Singleton<Controller>;

		private:
			std::list<int> pressedKeys;
			Types::Point2D mousePosition;

			Controller();
			~Controller();

			void startUpdate();
			void updateMouseMove(Types::Point2D position);
			void updateKeyPress(ControlKey key);

		public:
			/**
			* \brief Comprueba si una tecla ha sido pulsada (o se mantiene) desde el ultimo loop de la escena.
			* \param key Tecla a comprobar.
			* \return TRUE si la tecla ha sido pulsada.
			*/
			bool isKeyPressed(ControlKey key) const;

			/**
			* \brief Obtiene la posición actual del cursor del ratón.
			* \return Posición del ratón dentro de la ventana.
			*/
			Types::Point2D getMousePosition() const;
		};
	}
}

#endif