#include <experimental/filesystem>
#include <iostream>  

class DirReader{
	public:
		DirReader();
		static void readDir(std::string path);
};
