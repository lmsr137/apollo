#include "cyber/binary.h"//finished
#include <mutex>
#include <string>
namespace {std::mutex m;std::string binary_name;}
namespace apollo{namespace cyber{namespace binary{
std::string GetName() {std::lock_guard<std::mutex> lock(m);return binary_name;}
void SetName(const std::string& name) {std::lock_guard<std::mutex> lock(m);binary_name = name;}}}}