#include <gtest.h>

#include <Windows.h> 

HANDLE nConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(int argc, char **argv)
{
	SetConsoleTextAttribute(nConsole, 15);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
