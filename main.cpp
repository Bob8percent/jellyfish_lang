#include "pch.h"
#include "./SystemMain.h"
#include "./SystemDebug.h"

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		// ã≠êßèIóπ
		JF_SYSTEM_ERROR("invalid argc!");
	}
	else if (argc == 2)
	{
		jf::SystemMain sm;
		sm.runFile(argv[1]);
	}
	else
	{
		jf::SystemMain sm;
		sm.runPrompt();
	}
}
