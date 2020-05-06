- [Betabot Localization and Navigation](#betabot-localization-and-navigation)
  - [Project Description](#project-description)
  - [GUID](#guid)
  - [Project Rubric](#project-rubric)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
  - [Part I: Map (map_server)](#part-i-map-mapserver)
    - [In your own words how maps are represented in ROS?](#in-your-own-words-how-maps-are-represented-in-ros)
    - [State 5 algorithm for SLAM and the ROS implementation](#state-5-algorithm-for-slam-and-the-ros-implementation)
  - [Part II: Localization (amcl)](#part-ii-localization-amcl)
    - [In your own words how amcl works?](#in-your-own-words-how-amcl-works)
    - [Is there other better approaches to localize your robot rather than amcl?](#is-there-other-better-approaches-to-localize-your-robot-rather-than-amcl)
    - [What are the amcl limitations or the fail cases?](#what-are-the-amcl-limitations-or-the-fail-cases)
    - [Is amcl used in domain rather than Robotics?](#is-amcl-used-in-domain-rather-than-robotics)
  - [Part III: Navigation (move_base)](#part-iii-navigation-movebase)
    - [How many official local planner available in ROS?](#how-many-official-local-planner-available-in-ros)
    - [which local planner did you use?](#which-local-planner-did-you-use)
    - [In your own words how the local planner you selected works?](#in-your-own-words-how-the-local-planner-you-selected-works)
    - [How many official global planner available in ROS?](#how-many-official-global-planner-available-in-ros)
    - [which global planner did you use?](#which-global-planner-did-you-use)
    - [In your own words how the global planner you selected works?](#in-your-own-words-how-the-global-planner-you-selected-works)
    - [State your suggestion increase the overall performance?](#state-your-suggestion-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
    - [Demos](#demos)
    - [Screenshots](#screenshots)
      - [NAME:](#name)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom launch files to localize the robot in an environment given the map and also to autonomous navigation. 

*Use the given [map](map/map2d.yaml) for the myoffice world [here](../betabot_gazebo/worlds/myoffice.world)* 

<p float="center">
  <img src="img/myoffice.png" width="589" /> 
  <img src="img/map2d.png" width="500" />
</p>


>NOTE: For the given map and a world the betabot robot should localize it self and move from currant pose to a given goal autonomously

## GUID
Follow where am I project from Udacity Software Robotics Engineer Nanodegree.

---
## Project Rubric

![rubric](img/reviews.jpg) 

---

## After you implement the pkg state your reflection below 

---
## Part I: Map (map_server)

###  In your own words how maps are represented in ROS?


###  State 5 algorithm for SLAM and the ROS implementation

|           SLAM Algorithm           | ROS implementation |
| :--------------------------------: | :----------------: |
|              GMapping              |      gmapping      |
| Bayesian range-only SLAM (RO-SLAM) |    mrpt_ro_slam    |
|          particle filter           |        amcl        |
|       Extended kalman filter       |   robot_pose_ekf   |
|      incremental map building      |  mrpt_icp_slam_2d  |

---

## Part II: Localization (amcl)

### In your own words how amcl works?

- At first the robot doesn’t know its location at all, and here where the all particles distributed all over the map, is equi-probable, or there is some sort of probabilistic belief of the location. Then use laser scan to profound the belief and locate the robot with respect to the map with the assistance of an already made laser-based map.

### Is there other better approaches to localize your robot rather than amcl?

- Although, AMCL is known for very high accuracy and reliability, it is known for its high computational consumption. maybe use hybrid appraches, where multiple algorithms are used to get more accurate and sometimes, higher performance/

### What are the amcl limitations or the fail cases?

- AMCL is very computationally expensive, so with dynamic and big maps this algorithm may not work correctly

### Is amcl used in domain rather than Robotics?

- I found some in Automated vehicles (Which I guess robotics), biut other than that no

---

## Part III: Navigation (move_base)

### How many official local planner available in ROS?

- fake localization
- BaseLocalPlanner
- nav_core local planner
- dwa_local_planner

### which local planner did you use?

- Trajectory Rollout

### In your own words how the local planner you selected works?

- This planner works as follows: to reach the goal state the planner creates trajectories for the ropot and locally estimates the cost of taking that local trajectory using a cost function and then determines the dx, dy, and dthenta velocities to send the ropot

### How many official global planner available in ROS?

- I found those packages:
  1. nav_core
  2. navfn
  3. NF1
  4. carrot_planner
  5. global_planner

### which global planner did you use?

- navfn_global planner

### In your own words how the global planner you selected works?

- The planner uses Dijkstra’s algorithm to find the most optimum between to points with the cost map parameters taken into consideration.

---

### State your suggestion increase the overall performance?

- Depending on the computational power we have we can find the optimum number of particles.
- try to give a good starting guess to the robot while mapping


### List the most time consuming problems you faced

---

### Demos
Add unlisted youtube/drive videos

[Demo](https://www.youtube.com/watch?v=um0YyfveA78)

### Screenshots
1. rviz with all navigation launchers from turtulbot

   ![image-20200506215603810](/home/mostafa-7/.config/Typora/typora-user-images/image-20200506215603810.png)

2. gazebo

![image]()

![image-20200506220425754](/home/mostafa-7/.config/Typora/typora-user-images/image-20200506220425754.png)

---

#### NAME: Moustafa Elsayed
#### ID: 201600848

---
