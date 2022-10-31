#include "subnode.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SubNode>());
  rclcpp::shutdown();
  return 0;
}
