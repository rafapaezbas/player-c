#include "dirReader.h"

namespace fs = std::experimental::filesystem;

void DirReader::readDir(std::string path){
	for (auto entry : fs::recursive_directory_iterator("/media/rafa")){
		std::cout << entry.path() << std::endl;
	}
}
