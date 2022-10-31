#include "pubnode.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PubNode>());
  rclcpp::shutdown();
  return 0;
}
