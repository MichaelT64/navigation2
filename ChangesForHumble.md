# Changes made for ROS2 Humble

This describes the manual changes which ware made to get the main branch of Navigation2 compinling and running.

## Synchroinized commits from Nav2 main branch

|    Date    | Comment | Issue | Commit Hash |
| ---------- | ------- | ----- | ----------- |
| 2024-06-03 | Add configure and cleanup transitions to lifecycle manager and client | (#4371)
| 2024-06-03 | adding final pose in analytic expansion to check | (#4353)
| 2024-06-03 | Move projectState after getPointsInside | (#4356)
| 2024-06-03 | Remove flaky spin test that needs to be rewritten | (#4348)
| 2024-06-03 | [LifecycleManagerClient] clean set_initial_pose and navigate_to_pose | (#4346)
| 2024-06-03 | Update path_longer_on_approach.cpp | (#4344)
| 2024-06-03 | [LifecycleNode] add bond_heartbeat_period | (#4342)
| 2024-06-03 | Update README.md
| 2024-06-03 | Update CircleCI badge on readme table
| 2024-06-03 | Update docker workflow readme badge URL
| 2024-06-03 | 4320: Changed precision of calculations of the HybridNode MotionTable::getClosestAngularBin. | (#4324)
| 2024-06-03 | msg validation check for /initialpose in nav2_amcl | (#4301)
| 2024-06-03 | Fix undefined symbols in libpf_lib.so | (#4312)
| 2024-06-03 | complete navigation.ros.org -> docs.nav2.org migration | (#4313)
| 2024-06-03 | updating readme links to the new domain | (#4311)
| 2024-06-03 | Continuation of #4284 | (#4295)
| 2024-06-03 | fixes the issue when the decorator goes to idle state | (#4300)
| 2024-06-03 | Fix #4268 | (#4296)
| 2024-06-03 | Add footprint clearing for static layer | (#4282)
| 2024-06-03 | ruff rule F601 - Dictionary key literal 'use_composition' repeated | (#4293)
| 2024-06-03 | [RotationShimController] rotate also on short paths | (#4290)
| 2024-06-03 | nav2_waypoint_follower: Fix opencv includes | (#4287)
| 2024-06-03 | provide message validation check API | (#4276)
| 2024-06-03 | Ignore warnings in included xtensor library | (#4285)
| 2024-06-03 | Collision monitor: Add polygon source | (#4275)
| 2024-06-03 | removing clearable layer param (unused) | (#4280)
| 2024-06-03 | Make rviz use sim time with TB3 demo | (#4274)
| 2024-06-03 | Fix some warnings on GCC13/Ubuntu 24.04 | (#4265)
| 2024-06-03 | [Collision monitor] Dynamic radius for circle polygon | (#4226)
| 2024-06-03 | Revert "Revert "adding base footprint publisher to nav2_util (#3860) (#3994) | (#3995)
| 2024-04-23 | Completing #4259 | #4273 | 677e6accb3aea9380678da7d623b3387578d3549 |
| 2024-04-23 | Implement Critic for Velocity Deadband Hardware Constraints | #4256 | 12c786f8b8c533b0c4adc1a38c08021c90bfcba3 |
| 2024-04-23 | Set start and goal as float | #4255 | cc2b696e5b512ca3b1e0e175bdd1cbccb265ff91 |
| 2024-04-23 | Smac Planner Optimizations; 9.1% improvement in speed | #4257 | c09708845e2327dfee1dac7d0a874fd9bf7f2598 |
| 2024-04-23 | Add expanding the ~/ to the full home dir of user in the path to the map yaml. | #4258 | 61a774be41fc236738ed7c103ba806be07b0914e |
| 2024-04-23 | Fix compiler warning ‘error_level’ may be used uninitialized | #4253 | 8af70abb35e6f93a0e6e6827c7bc3ad364b33d4b |
| 2024-04-23 | Scale cost critic's weight when dynamically updated | #4246 | f815e8bd8e3826603e97749bb31a3145268de023 |
| 2024-04-02 | Adding config file for DWB to exercise in system tests from MPPI default migration | #4236 | 0be2f25782413677fedc58ea090c6ecfa8b9a6b8 |
| 2024-04-02 | Increasing test count from timeout handling changes | #4234 | d030ea463b40276277f53803b587cd3934f30075 | 
| 2024-04-02 | Nacho/cleanup get transform util | #4181 | 911555a5ad7f6b7e90c1b25b5f9f0ce5cddc3c2e |
| 2024-04-02 | Refactor plugins to use double colons for consistency | #4220 | b0e6d3d2d7e34a6feba00d8c77d847de9c131b6c |
| 2024-04-02 | Add API to gracefully cancel a controller | #4136 | 2ecc91e47bb09485289531144ab9b038f4cfc432 |
| 2024-04-02 | Attempt to fix Rolling 22.04 CI Until 24.04 Comes of Age | #4229 | 80bb5bff1488c0677efcc4254b7a89908c853ba0 |
| 2024-04-02 | nav2_controller: add loop rate log | #4228 | 19e3f46a614cfbed5ee431f3b08d38c720660dda |
| 2024-03-28 | Improving stability of action feedback | #4225 | 63b6d908456e8b421f82b8790c9b55cb82515ec3 |
| 2024-03-28 | allowing costmap to change with new costmap resolutions | #4223 | 6f5bb6bc14a63a8d53286725f39570f6a5180678 |
| 2024-03-28 | add polygon_subscribe_transient_local parameter in collision monitor | #4207 | 0b22bb48b3265feca2d460b2095729f9149f18f6 |
| 2024-03-28 | removed RPP dependency | #4222 | f9828c21e8e9a241ad2d8c3557a21eafa4d55420 |
| 2024-03-28 | 45% performance improvement in MPPI |#4174 | 5a8cbd3fc9373b1d37f51d8226eaabe16f50af5c |
| 2024-03-28 | bt_service_node and bt_action_node: Don't block BT loop | #4214 | fe83956444cdf47610790de92264669dcd5d0ad3 |
| 2024-03-28 | Enable reloading BT xml file with same name | #4209 | a1997db142bef4aff898ab72fc250adba09825e6 |
| 2024-03-28 | Add uint suffix | #4213 | 46ff0ecc4cc7d42cc92477e6159b29d69fd23050 |
| 2024-03-28 | Revert "nav2_controller: add loop rate log (#4171)" | #4210 | 5bf14fc81ad81b815eecf4f153a3ba3cc60e5675 |
| 2024-03-28 | fix missing param declare |#4203 | 1ef462e71d12fd3e4ffb45e332a7d9883e921921 |
| 2024-03-21 | Update footprint iif changed | #4193 | 12292d17c5db73b1fb387d30c0c426415ff2defe |
| 2024-03-20 | Fix typo | #4196 | 2eb99e31ab747662932033b5d29950b6cdc7f690 |
| 2024-03-19 | Move lines for pre-computation to outside a loop | #4191 | 914d881f6e154d8d7bb1975892d4642eaf4c7366 |
| 2024-03-19 | AMCL: Set an initial guess by service call | #4182 | f484b0970327906d54b0e049326d645c8810e126 |
| 2024-03-19 | fix typos in description messages | #4188 | aa849aede4fd9d230220d196a277b171b4f7c557 |
| 2024-03-17 | RPP Dexory tweaks | #4140 | db974ea91b1eb01d7abf094aad511c0f2306d55f |
| 2024-03-17 | Fixing a typo in Smac Heuristic | #4184 | 53f1f4289fb8f5630c4e22ba5b57ceb9c0c25ff6 |
| 2024-03-15 | replace throw-error with error-log to avoid UAF mentioned in | #4175 (#4180) | 9f13cb1b29ca14c11bcbe11ab02d35c71f35de9d |
| 2024-03-15 | chore(nav2_behavior_tree): log actual wait period in bt_action_node | #4178 | 09ba08b7f45004df92f77fa683ea33d8afa2acce |
| 2024-03-15 | completely shutdown inital_pose_sub_ | #4176 | 0897da9252b4cb537b1110e88831a1e63ac157d3 |
| 2024-03-11 | nav2_controller: add loop rate log | #4171 | 47374622dee01a27e5f9b8ae08f3d19a15de9b3a |
| 2024-03-08 | Update default recommendation from Obstacles to Cost critic in MPPI | #4170 | c9d9b5c698d1f5aff060806481d18ba7e9b18cb2 |
| 2024-03-07 | Fix BT.CPP import | #4165 | 26363716536425ff6479610c18639c853e7537be |
| 2024-03-07 | Stop planner if the goal is cancelled | #4148 | 211273f831108a767a42ccc8bfc5d5de50761cc1 |
| 2024-03-01 | CI green P3 | #4117 | a3cdbbf7d0a9be9ec50f876ab365a45eff2214d9 |

## Disclaimer

Due to limited resources of time and knowledge I can't check every functionality of Nav2.

The first goal is to get the packages build without errors by adapting Rolling functionality to Humble functionality as near as possible.

The second goal is to use these functionality in my ROS2 Humble project.

## Changes made

### CMakelists.txt
- add "$ENV{ROS_DISTRO}" as PreProcessor variable where necessary
```
    add_compile_definitions( $ENV{ROS_DISTRO} )
```


- There is no gazebo_ros_pkgs package for Raspberry PI (aarch64), so disable the tests if the host system has this architecture:
package "nav2_system_tests" 
```
    if( ${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "arm64" )
```

### Launch files
- "PushROSNamespace" becomes "PushRosNamespace"

 ```
    if os.getenv('ROS_DISTRO') == 'humble':
        from launch_ros.actions import PushRosNamespace
    else:
        from launch_ros.actions import PushROSNamespace
 ```
 ```
    if os.getenv('ROS_DISTRO') == 'humble':
        namespaceAction = PushRosNamespace(
            condition=IfCondition(use_namespace), namespace=namespace
        )
    else:
        namespaceAction = PushROSNamespace(
            condition=IfCondition(use_namespace), namespace=namespace
        )
 ```

- "NotEqualsSubstitution" does not exist in  Humble so it was substituted by "PythonExpression(['"" != "', LaunchConfiguration('map'), '"'])"
E.g.
 ```
    if os.getenv('ROS_DISTRO') == 'humble':
        condition=IfCondition(
            PythonExpression(['"" != "', LaunchConfiguration('map'), '"'])
        ),
    else:
        condition=IfCondition(
            NotEqualsSubstitution(LaunchConfiguration('map'), '')
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

 - add PolygonInstance Message in nav2_msgs
 - add PolygonInstanceStamped Message in nav2_msgs

## Restrictions

- BaseFootprintPublisherListener does not work (files are deleted)

## ToDos

- [ ] formatting regarding to Nav2 conventions
- [ ] more tests
- [X] use environment variable in CMake
- [X] use if condition in Python

## What was tested so far?

- building of Nav2 with Humble distro on a PC ("x86_64" processor)
- building of Nav2 with Humble distro on a Raspberry PI 4 ("aarch64" processor) - except tests because gazebo_ros_pkgs is not available for "aarch64"
- using CollisionMonitor in simulation with Gazebo Classic

## Motivation

Usage of Nav2 collision monitor for my robot which use Humble.
After trying a backport from main branch to Humble branch which was out of my possibilities, I remembered that software which I used in my early days of computing (Emacs) came with a bundle of compiler options and configuration options at build time. So I decided to try that way ...

## Technic

### once 

$ git clone https://github.com/[username]/[repository_name]

$ git remote add upstream https://github.com/[original_username]/[original_repository_name]

upstream is the name of the remote the original repository

### repeatly

$ git fetch upstream

$ git rebase upstream/main

$ git push -f origin rolling-humble