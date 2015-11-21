#pragma once

#include "State.hpp"

#include <memory>
#include <stack>

namespace falksalt
{
	class StateStack final
	{
	public:
		void push(std::shared_ptr<State> state);
		void pop();

		void update();

	private:
		std::stack<std::shared_ptr<State>> m_stack;
		
	};
}
