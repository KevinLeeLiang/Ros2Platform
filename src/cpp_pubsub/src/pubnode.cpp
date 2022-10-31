
#include "pubnode.h"

#include <chrono>
#include <functional>
#include <memory>
#include <string>

using namespace std::chrono_literals;

PubNode::PubNode()
    : Node("pubnode"), count_(0)
{
    //创建话题为say的发布者
    publisher_ = this->create_publisher<std_msgs::msg::String>("say", 10);
    //创建500ms回调一次的定时器
    timer_ = this->create_wall_timer(
        500ms, std::bind(&PubNode::timer_callback, this));
}

PubNode::~PubNode()
{
}

void PubNode::timer_callback()
{
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

    //发布消息
    publisher_->publish(message);
}
