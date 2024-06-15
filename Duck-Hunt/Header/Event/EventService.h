#pragma once
#include <SFML/Graphics.hpp>

namespace Event {

	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};

	class EventService
	{
		sf::Event game_event;
		sf::RenderWindow* game_window;

		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_arrow_button_state;
		ButtonState right_arrow_button_state;
		ButtonState A_button_state;
		ButtonState D_button_state;
		ButtonState Esc_button;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();
		void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);
		void updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button);
	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();

		//mouse input
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();

		//keyboard input
		bool pressedEscapeKey();
		bool isKeyboardEvent();
		bool pressedLeftKey();
		bool pressedRightKey();
		bool pressedAKey();
		bool pressedDKey();

	};
}