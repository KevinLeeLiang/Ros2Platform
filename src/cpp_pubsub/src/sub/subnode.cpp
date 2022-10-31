#include "subnode.h"

using std::placeholders::_1;

SubNode::SubNode()
    : Node("subnode")
{
    //创建话题为say的订阅者
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "say", 10, std::bind(&SubNode::topic_callback, this, _1));
}

SubNode::~SubNode()
{
    
}

void SubNode::topic_callback(const std_msgs::msg::String::SharedPtr msg) const
{
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}
