#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SubNode : public rclcpp::Node
{
  public:
    SubNode();
    ~SubNode();

  private:
    //订阅话题的回调函数
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};
