#include "modules/prediction/prediction_component.h"
#include "cyber/init.h"
#include "gtest/gtest.h"
namespace apollo {
namespace prediction {

TEST(PredictionComponentTest, Simple) {
  cyber::Init("prediction_component_test");
  PredictionComponent prediction_component;
  EXPECT_EQ(prediction_component.Name(), "prediction");
}
}}
