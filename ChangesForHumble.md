# Changes made for ROS2 Humble

This describes the manual changes which ware made to get the main branch of Navigation2 compinling and running.

## Synchroinized commits from Nav2 main branch

|    Date    | Comment | Issue | Commit Hash |
| ---------- | ------- | ----- | ----------- |
| 2024-03-11 | nav2_controller: add loop rate log | #4171 | 47374622dee01a27e5f9b8ae08f3d19a15de9b3a |
| 2024-03-08 | Update default recommendation from Obstacles to Cost critic in MPPI | #4170 | c9d9b5c698d1f5aff060806481d18ba7e9b18cb2 |
| 2024-03-07 | Fix BT.CPP import    | #4165 | 26363716536425ff6479610c18639c853e7537be |
| 2024-03-07 | Stop planner if the goal is cancelled | #4148 | 211273f831108a767a42ccc8bfc5d5de50761cc1 |
| 2024-03-01 | CI green P3 | #4117 | a3cdbbf7d0a9be9ec50f876ab365a45eff2214d9 |

## Disclaimer

Due to limited resources of time and knowledge I can't check every functionality of Nav2.

The first goal is to get the packages build without errors by adapting Rolling functionality to Humble functionality as near as possible.

The second goal is to use these functionality in my ROS2 Humble project.

## Changes made

### CMakelists.txt
- add "humble" as PreProcessor variable where necessary
```
    add_compile_definitions( humble )
```


- There is no gazebo_ros_pkgs package for Raspberry PI (aarch64), so disable the tests if the host system has this architecture:
package "nav2_system_tests" 
```
    if( ${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "arm64" )
```

### Launch files
- "PushROSNamespace" becomes "PushRosNamespace"
                    
- "NotEqualsSubstitution" does not exist in  Humble so it was substituted by "PythonExpression(['"" != "', LaunchConfiguration('map'), '"'])"
E.g.
 ```
    # condition=IfCondition(
    #     NotEqualsSubstitution(LaunchConfiguration('map'), '')
    # ),
    condition=IfCondition(
        PythonExpression(['"" != "', LaunchConfiguration('map'), '"'])
    ),

 ```

### CPP Code

- use "cv_bridge/cv_bridge.h" instead of "cv_bridge/cv_bridge.hpp"
- rewrite some functions in "nav2_util" ("setSoftRealTimePriority()", "copy_all_parameters()")
- use "rclcpp::ServicesQoS().get_rmw_qos_profile()" instead of "rclcpp::SystemDefaultsQoS()"
- use "create_wall_timer" instead of "create_timer"
```
#ifdef humble
#include "cv_bridge/cv_bridge.h"
#else
#include "cv_bridge/cv_bridge.hpp"
#endif
```

## ToDos

- [ ] formatting regarding to Nav2 conventions
- [ ] more tests
- [ ] use environment variable in CMake
- [ ] use if condition in Python

## What was tested so far?

- building of Nav2 with Humble distro on a PC ("x86_64" processor)
- building of Nav2 with Humble distro on a Raspberry PI 4 ("aarch64" processor) - except tests because gazebo_ros_pkgs is not available for "aarch64"
- using CollisionMonitor in simulation with Gazebo Classic

## Motivation

Usage of Nav2 collision monitor for my robot which use Humble.
After trying a backport from main branch to Humble branch which was out of my possibilities, I remembered that software which I used in my early days of computing (Emacs) came with a bundle of compiler options and configuration options at build time. So I decided to try that way ...