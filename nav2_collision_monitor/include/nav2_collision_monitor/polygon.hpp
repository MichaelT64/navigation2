// Copyright (c) 2022 Samsung R&D Institute Russia
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef NAV2_COLLISION_MONITOR__POLYGON_HPP_
#define NAV2_COLLISION_MONITOR__POLYGON_HPP_

#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/polygon_stamped.hpp"
#include "geometry_msgs/msg/polygon.hpp"

#include "tf2/time.h"
#include "tf2_ros/buffer.h"

#include "nav2_util/lifecycle_node.hpp"
#include "nav2_costmap_2d/footprint_subscriber.hpp"

#include "nav2_collision_monitor/types.hpp"

namespace nav2_collision_monitor
{

/**
 * @brief Basic polygon shape class.
 * For STOP/SLOWDOWN model it represents zone around the robot
 * while for APPROACH model it represents robot footprint.
 */
class Polygon
{
public:
  /**
   * @brief Polygon constructor
   * @param node Collision Monitor node pointer
   * @param polygon_name Name of polygon
   * @param tf_buffer Shared pointer to a TF buffer
   * @param base_frame_id Robot base frame ID
   * @param transform_tolerance Transform tolerance
   */
  Polygon(
    const nav2_util::LifecycleNode::WeakPtr & node,
    const std::string & polygon_name,
    const std::shared_ptr<tf2_ros::Buffer> tf_buffer,
    const std::string & base_frame_id,
    const tf2::Duration & transform_tolerance);
  /**
   * @brief Polygon destructor
   */
  virtual ~Polygon();

  /**
   * @brief Shape configuration routine. Obtains ROS-parameters related to shape object
   * and creates polygon lifecycle publisher.
   * @return True in case of everything is configured correctly, or false otherwise
   */
  bool configure();
  /**
   * @brief Activates polygon lifecycle publisher
   */
  void activate();
  /**
   * @brief Deactivates polygon lifecycle publisher
   */
  void deactivate();

  /**
   * @brief Returns the name of polygon
   * @return Polygon name
   */
  std::string getName() const;
  /**
   * @brief Obtains polygon action type
   * @return Action type for current polygon
   */
  ActionType getActionType() const;
  /**
   * @brief Obtains polygon maximum points to enter inside polygon causing no action
   * @return Maximum points to enter to current polygon and take no action
   */
  int getMaxPoints() const;
  /**
   * @brief Obtains speed slowdown ratio for current polygon.
   * Applicable for SLOWDOWN model.
   * @return Speed slowdown ratio
   */
  double getSlowdownRatio() const;
  /**
   * @brief Obtains required time before collision for current polygon.
   * Applicable for APPROACH model.
   * @return Time before collision in seconds
   */
  double getTimeBeforeCollision() const;

  /**
   * @brief Gets polygon points
   * @param poly Output polygon points (vertices)
   */
  virtual void getPolygon(std::vector<Point> & poly) const;

  /**
   * @brief Updates polygon from footprint subscriber (if any)
   */
  virtual void updatePolygon(const Velocity & /*cmd_vel_in*/);

  /**
   * @brief Gets number of points inside given polygon
   * @param points Input array of points to be checked
   * @return Number of points inside polygon. If there are no points,
   * returns zero value.
   */
  virtual int getPointsInside(const std::vector<Point> & points) const;

  /**
   * @brief Obtains estimated (simulated) time before a collision.
   * Applicable for APPROACH model.
   * @param collision_points Array of 2D obstacle points
   * @param velocity Simulated robot velocity
   * @return Estimated time before a collision. If there is no collision,
   * return value will be negative.
   */
  double getCollisionTime(
    const std::vector<Point> & collision_points,
    const Velocity & velocity) const;

  /**
   * @brief Publishes polygon message into a its own topic
   */
  void publish() const;

protected:
  /**
   * @brief Supporting routine obtaining ROS-parameters common for all shapes
   * @param polygon_pub_topic Output name of polygon publishing topic
   * @return True if all parameters were obtained or false in failure case
   */
  bool getCommonParameters(std::string & polygon_pub_topic);

  /**
   * @brief Supporting routine obtaining polygon-specific ROS-parameters
   * @param polygon_pub_topic Output name of polygon publishing topic
   * @param footprint_topic Output name of footprint topic. Empty, if no footprint subscription
   * @return True if all parameters were obtained or false in failure case
   */
  virtual bool getParameters(std::string & polygon_pub_topic, std::string & footprint_topic);

  /**
   * @brief Checks if point is inside polygon
   * @param point Given point to check
   * @return True if given point is inside polygon, otherwise false
   */
  bool isPointInside(const Point & point) const;

  // ----- Variables -----

  /// @brief Collision Monitor node
  nav2_util::LifecycleNode::WeakPtr node_;
  /// @brief Collision monitor node logger stored for further usage
  rclcpp::Logger logger_{rclcpp::get_logger("collision_monitor")};

  // Basic parameters
  /// @brief Name of polygon
  std::string polygon_name_;
  /// @brief Action type for the polygon
  ActionType action_type_;
  /// @brief Maximum number of data readings within a zone to not trigger the action
  int max_points_;
  /// @brief Robot slowdown (share of its actual speed)
  double slowdown_ratio_;
  /// @brief Time before collision in seconds
  double time_before_collision_;
  /// @brief Time step for robot movement simulation
  double simulation_time_step_;
  /// @brief Footprint subscriber
  std::unique_ptr<nav2_costmap_2d::FootprintSubscriber> footprint_sub_;

  // Global variables
  /// @brief TF buffer
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  /// @brief Base frame ID
  std::string base_frame_id_;
  /// @brief Transform tolerance
  tf2::Duration transform_tolerance_;

  // Visualization
  /// @brief Whether to publish the polygon
  bool visualize_;
  /// @brief Polygon points stored for later publishing
  geometry_msgs::msg::Polygon polygon_;
  /// @brief Polygon publisher for visualization purposes
  rclcpp_lifecycle::LifecyclePublisher<geometry_msgs::msg::PolygonStamped>::SharedPtr polygon_pub_;

  /// @brief Polygon points (vertices)
  std::vector<Point> poly_;
};  // class Polygon

}  // namespace nav2_collision_monitor

#endif  // NAV2_COLLISION_MONITOR__POLYGON_HPP_
