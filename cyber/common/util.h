#include <string>//finished
#include <type_traits>
namespace apollo {namespace cyber {namespace common {
inline std::size_t Hash(const std::string& key) {return std::hash<std::string>{}(key);}
template <typename Enum>
auto ToInt(Enum const value) -> typename std::underlying_type<Enum>::type {return static_cast<typename std::underlying_type<Enum>::type>(value);}
}}}