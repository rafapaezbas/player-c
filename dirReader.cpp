#include "dirReader.h"

namespace fs = std::experimental::filesystem;

std::vector<std::string> dir::readDir(std::string path){
	std::vector<std::string> paths;
	for (auto entry : fs::recursive_directory_iterator("/media/rafa")){
		paths.push_back(entry.path());
	}
	return paths;
}
