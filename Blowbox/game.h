#pragma once

#include <chrono>
#include <iostream>
#include <math.h>

#include "../blowbox/memory/shared_ptr.h"
#include "../blowbox/win32/window.h"
#include "../blowbox/input/keyboard.h"

namespace blowbox
{
	/**
	* @class blowbox::Game
	* @brief Manages the Game
	* @author Riko Ophorst
	*/
	class Game
	{
	public:
		/**
		* @brief Default constructor
		*/
		Game();
		/**
		* @brief Default destructor
		*/
		~Game();

		/**
		* @brief Retrieves a pointer to the Game instance
		* @return A pointer to the Game's instance
		*/
		static Game* Instance();

		/**
		* @brief Runs the game
		*/
		void Run();

		/**
		* @brief Updates the game
		*/
		void Update();

		/**
		* @brief Draws the game
		*/
		void Draw();
	private:
		SharedPtr<Window> window_;
		Mouse* mouse_;
		Keyboard* keyboard_;
	};
}