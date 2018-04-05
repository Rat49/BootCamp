#include <experimental/filesystem>
#include <unordered_set>
#include <sstream>

int main(int argc, char ** argv)
{
  if(argc != 2)
    return 1;

  namespace fs = std::experimental::filesystem::v1;

  const std::string                     root_source = argv[1];
  const std::unordered_set<std::string> source_extensions{".hpp", ".cpp", ".h"};

  const char * clang_format_cmd_static_part = "clang-format.exe -style=file -fallback-style=none -i ";
  for(fs::recursive_directory_iterator it{root_source}, end; it != end; ++it)
  {
    if(!fs::is_directory(it->path()) && source_extensions.count(it->path().filename().extension().string()))
    {
      std::ostringstream clang_format_cmd;
      clang_format_cmd << clang_format_cmd_static_part;
      clang_format_cmd << '"' << fs::absolute(it->path()) << '"';
      system(clang_format_cmd.str().c_str());
    }
  }
  return 0;
}
