#pragma once
#include <string>

namespace quiz {

	class Response
	{
	public:
		Response(std::string message, int value);
		~Response();
	private:
		const std::string MESSAGE;
		const int VALUE;
	};

}

