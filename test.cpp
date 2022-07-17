#include <cstdlib>
#include <iostream>
#include <string>

#define NDEBUG
#include <cassert>

void	test	(void)
{
	std::cout	<< "test "
	#ifdef ABC
				<< "lol "
	#endif
				<< "\n";
}

int	main	(int argc,
			 char * argv[])
{
	assert(argc != 1);

	test();

	for (size_t i = 1;
		 i < argc;
		 i++)
	{
		std::cout	<< std::endl
					<< "cmd "
					<< argv[i]
					<< " :\n";
		system(argv[i]);
	}


	for (int c = 0; c < 256; c++)
	{
		std::cout	<< "char \'"
					<< static_cast<char>(c)
					<< "\'("
					<< c
					<< ") :\nisalnum("
					<< std::boolalpha
					<< static_cast<bool>(isalnum(c))
					<< ") | isalpha("
					<< static_cast<bool>(isalpha(c))
					<< ") | isblank("
					<< static_cast<bool>(isblank(c))
					<< ") | iscntrl("
					<< static_cast<bool>(iscntrl(c))
					<< ") | isdigit("
					<< static_cast<bool>(isdigit(c))
					<< ") \nisgraph("
					<< static_cast<bool>(isgraph(c))
					<< ") | islower("
					<< static_cast<bool>(islower(c))
					<< ") | isprint("
					<< static_cast<bool>(isprint(c))
					<< ") | ispunct("
					<< static_cast<bool>(ispunct(c))
					<< ") \nisspace("
					<< static_cast<bool>(isspace(c))
					<< ") | isupper("
					<< static_cast<bool>(isupper(c))
					<< ") | isxdigit("
					<< static_cast<bool>(isxdigit(c))
					<< std::endl
					<< std::endl;

	}
}
