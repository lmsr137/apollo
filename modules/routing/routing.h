#include <memory>
#include <string>
#include <vector>

#include "modules/common/monitor_log/monitor_log_buffer.h"
#include "modules/common/status/status.h"
#include "modules/map/hdmap/hdmap_util.h"
#include "modules/routing/core/navigator.h"
#include "modules/routing/proto/routing_config.pb.h"

namespace apollo {
namespace routing {

class Routing {
  // friend class RoutingTestBase;
 public:
  Routing();
  std::string Name() const;

    apollo::common::Status Init();

    apollo::common::Status Start();

  virtual ~Routing() = default;

  bool Process(const std::shared_ptr<RoutingRequest> &routing_request,
               RoutingResponse *const routing_response);

 private:
  std::vector<RoutingRequest> FillLaneInfoIfMissing(
      const RoutingRequest &routing_request);

  bool GetParkingID(const apollo::common::PointENU &parking_point,
                    std::string *parking_space_id);

  bool FillParkingID(RoutingResponse *routing_response);

 private:
  std::unique_ptr<Navigator> navigator_ptr_;
  common::monitor::MonitorLogBuffer monitor_logger_buffer_;

  const hdmap::HDMap *hdmap_ = nullptr;
};
}}