#include "cyber/cyber.h"
#include <memory>
#include <string>
#include <utility>
#include "cyber/proto/run_mode_conf.pb.h"
#include "cyber/common/global_data.h"
namespace apollo {namespace cyber {
using apollo::cyber::common::GlobalData;
using apollo::cyber::proto::RunMode;
std::unique_ptr<Node> CreateNode(const std::string& node_name,
                                 const std::string& name_space) {
  bool is_reality_mode = GlobalData::Instance()->IsRealityMode();
  if (is_reality_mode && !OK()) {
    AERROR << "please initialize cyber firstly.";
    return nullptr;
  }
  return std::unique_ptr<Node>(new Node(node_name, name_space));
}}}