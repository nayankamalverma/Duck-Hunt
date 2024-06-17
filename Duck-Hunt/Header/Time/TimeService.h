#pragma once
#include <chrono>

namespace Time {
	class TimeService
	{
		std::chrono::time_point<std::chrono::steady_clock> previous_time;

		float delta_time = 0;

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:
		//lifecycle method
		void initialize();
		void update();

		//getter
		float getDeltaTime();
	};
}