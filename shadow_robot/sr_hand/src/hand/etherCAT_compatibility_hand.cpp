/**
 * @file   virtual_shadowhand.cpp
 * @author Ugo Cupcic <ugo@shadowrobot.com>, Contact <contact@shadowrobot.com>
 * @date   Tue May 25 17:50:42 2010
 *
*
* Copyright 2011 Shadow Robot Company Ltd.
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 2 of the License, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program.  If not, see <http://www.gnu.org/licenses/>.
*
 * @brief
 *
 *
 */

#include "sr_hand/hand/etherCAT_compatibility_hand.hpp"
#include <sr_utilities/sr_math_utils.hpp>

#include <time.h>
#include <ros/ros.h>
#include <std_msgs/Float64.h>

namespace shadowrobot
{
  ROS_DEPRECATED EtherCATCompatibilityHand::EtherCATCompatibilityHand() :
    SRArticulatedRobot(), n_tilde("~")
  {
    ROS_WARN("This interface is deprecated, you should probably use the interface provided by the etherCAT driver directly.");

    initializeMap();
  }

  EtherCATCompatibilityHand::~EtherCATCompatibilityHand()
  {
  }

  void EtherCATCompatibilityHand::initializeMap()
  {
    joints_map_mutex.lock();
    JointData tmpData;
    JointData tmpDataZero;
    tmpDataZero.isJointZero = 1;
    tmpDataZero.max = 180.0;

    std::string controller_suffix;
    std::string searched_param;
    n_tilde.searchParam("controller_suffix", searched_param);
    n_tilde.param(searched_param, controller_suffix, std::string("mixed_position_velocity_controller"));
    std::string topic_prefix = "/sh_";
    std::string topic_suffix = "_"+controller_suffix+"/command";
    std::string full_topic = "";

    joints_map["FFJ0"] = tmpDataZero;
    full_topic = topic_prefix + "ffj0" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    int tmp_index = 0;
    tmpData.publisher_index = tmp_index;

    joints_map["FFJ1"] = tmpData;
    joints_map["FFJ2"] = tmpData;

    joints_map["FFJ3"] = tmpData;
    full_topic = topic_prefix + "ffj3" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -25.0;
    tmpData.max = 25.0;
    joints_map["FFJ4"] = tmpData;
    full_topic = topic_prefix + "ffj4" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    joints_map["MFJ0"] = tmpDataZero;
    full_topic = topic_prefix + "mfj0" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = 0.0;
    tmpData.max = 90.0;
    joints_map["MFJ1"] = tmpData;
    joints_map["MFJ2"] = tmpData;

    joints_map["MFJ3"] = tmpData;
    full_topic = topic_prefix + "mfj3" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -25.0;
    tmpData.max = 25.0;
    joints_map["MFJ4"] = tmpData;
    full_topic = topic_prefix + "mfj4" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    joints_map["RFJ0"] = tmpDataZero;
    full_topic = topic_prefix + "mfj4" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = 0.0;
    tmpData.max = 90.0;
    joints_map["RFJ1"] = tmpData;
    joints_map["RFJ2"] = tmpData;
    joints_map["RFJ3"] = tmpData;
    full_topic = topic_prefix + "rfj3" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -25.0;
    tmpData.max = 25.0;
    joints_map["RFJ4"] = tmpData;
    full_topic = topic_prefix + "rfj4" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    joints_map["LFJ0"] = tmpDataZero;
    full_topic = topic_prefix + "lfj0" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = 0.0;
    tmpData.max = 90.0;
    joints_map["LFJ1"] = tmpData;
    joints_map["LFJ2"] = tmpData;

    joints_map["LFJ3"] = tmpData;
    full_topic = topic_prefix + "lfj3" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -25.0;
    tmpData.max = 25.0;
    joints_map["LFJ4"] = tmpData;
    full_topic = topic_prefix + "lfj4" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = 0.0;
    tmpData.max = 45.0;
    joints_map["LFJ5"] = tmpData;
    full_topic = topic_prefix + "lfj5" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = 0.0;
    tmpData.max = 90.0;
    joints_map["THJ1"] = tmpData;
    full_topic = topic_prefix + "thj1" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -30.0;
    tmpData.max = 30.0;
    joints_map["THJ2"] = tmpData;
    full_topic = topic_prefix + "thj2" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -15.0;
    tmpData.max = 15.0;
    joints_map["THJ3"] = tmpData;
    full_topic = topic_prefix + "thj3" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = 0.0;
    tmpData.max = 75.0;
    joints_map["THJ4"] = tmpData;
    full_topic = topic_prefix + "thj4" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -60.0;
    tmpData.max = 60.0;
    joints_map["THJ5"] = tmpData;
    full_topic = topic_prefix + "thj5" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -30.0;
    tmpData.max = 40.0;
    joints_map["WRJ1"] = tmpData;
    full_topic = topic_prefix + "wrj1" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    tmpData.min = -30.0;
    tmpData.max = 10.0;
    joints_map["WRJ2"] = tmpData;
    full_topic = topic_prefix + "wrj2" + topic_suffix;
    etherCAT_publishers.push_back(node.advertise<std_msgs::Float64>(full_topic, 2));
    tmp_index ++;
    tmpData.publisher_index = tmp_index;

    joints_map_mutex.unlock();
  }

  short EtherCATCompatibilityHand::sendupdate( std::string joint_name, double target )
  {
    joints_map_mutex.lock();

    JointsMap::iterator iter = joints_map.find(joint_name);
    std_msgs::Float64 target_msg;

    //not found
    if( iter == joints_map.end() )
    {
      ROS_DEBUG("Joint %s not found", joint_name.c_str());

      joints_map_mutex.unlock();
      return -1;
    }

    //joint found
    JointData tmpData(iter->second);

    if( target < tmpData.min )
      target = tmpData.min;
    if( target > tmpData.max )
      target = tmpData.max;

    tmpData.position = target;
    tmpData.target = target;

    joints_map[joint_name] = tmpData;
    //the targets are in radians
    target_msg.data = sr_math_utils::to_rad( target );
    etherCAT_publishers[tmpData.publisher_index].publish(target_msg);
    ros::spinOnce();

    joints_map_mutex.unlock();
    return 0;
  }

  JointData EtherCATCompatibilityHand::getJointData( std::string joint_name )
  {
    joints_map_mutex.lock();

    JointsMap::iterator iter = joints_map.find(joint_name);

    //joint found
    if( iter != joints_map.end() )
    {
      //return the position
      iter->second.temperature = ((double)(rand() % 100) / 100.0);
      iter->second.current = ((double)(rand() % 100) / 100.0);
      iter->second.force = ((double)(rand() % 100) / 100.0);

      JointData tmp = JointData(iter->second);

      joints_map_mutex.unlock();
      return tmp;
    }

    ROS_ERROR("Joint %s not found.", joint_name.c_str());
    JointData noData;
    joints_map_mutex.unlock();
    return noData;
  }

  SRArticulatedRobot::JointsMap EtherCATCompatibilityHand::getAllJointsData()
  {
    joints_map_mutex.lock();

    for( JointsMap::const_iterator it = joints_map.begin(); it != joints_map.end(); ++it )
    {
      JointData tmpData = it->second;
      tmpData.temperature = ((double)(rand() % 100) / 100.0);
      tmpData.current = ((double)(rand() % 100) / 100.0);
      tmpData.force = ((double)(rand() % 100) / 100.0);
      tmpData.jointIndex = 0;
      tmpData.flags = "";

      joints_map[it->first] = tmpData;
    }

    JointsMap tmp_map = JointsMap(joints_map);
    joints_map_mutex.unlock();
    return tmp_map;
  }

  short EtherCATCompatibilityHand::setContrl( std::string contrlr_name, JointControllerData ctrlr_data )
  {
    ROS_WARN("The set Controller function is not implemented in the EtherCAT compatibility wrapper, please use the provided services directly.");
    return 0;
  }

  JointControllerData EtherCATCompatibilityHand::getContrl( std::string contrlr_name )
  {
    JointControllerData no_result;
    ROS_WARN("The get Controller function is not implemented in the EtherCAT compatibility wrapper, please use the provided services directly.");
    return no_result;
  }

  short EtherCATCompatibilityHand::setConfig( std::vector<std::string> myConfig )
  {
    ROS_WARN("The set config function is not implemented.");
    return 0;
  }

  void EtherCATCompatibilityHand::getConfig( std::string joint_name )
  {
    ROS_WARN("The get config function is not implemented.");
  }

  std::vector<DiagnosticData> EtherCATCompatibilityHand::getDiagnostics()
  {
    std::vector<DiagnosticData> returnVect;
    return returnVect;
  }

  void EtherCATCompatibilityHand::joint_states_callback(const sensor_msgs::JointStateConstPtr& msg)
  {
    joints_map_mutex.lock();

    //loop on all the names in the joint_states message
    for(unsigned int index = 0; index < msg->name.size(); ++index)
    {
      std::string joint_name = msg->name[index];
      JointsMap::iterator iter = joints_map.find(joint_name);
      //not found => can be a joint from the arm / hand
      if(iter == joints_map.end())
        continue;

      //joint found
      JointData tmpData(iter->second);

      tmpData.position = sr_math_utils::to_degrees(msg->position[index]);
      tmpData.force = msg->effort[index];
      tmpData.velocity = msg->velocity[index];

      joints_map[joint_name] = tmpData;
    }

    /*
    //push the sum of J1+J2 to the J0s
    for(JointsMap::const_iterator it = joints_map.begin(); it != joints_map.end(); ++it)
    {
      JointData tmpData = it->second;
      if( tmpData.isJointZero == 1 )
      {
        std::string joint_name = it->first;
        double position = 0.0;

        //get the position from joint 1
        ++it;
        JointData tmpData1 = JointData(it->second);
        position += tmpData1.position;

        //get the position from joint 2
        ++it;
        JointData tmpData2 = JointData(it->second);
        position += tmpData2.position;

        tmpData.position = position;

        joints_map[joint_name] = tmpData;
      }
    }
    */

    joints_map_mutex.unlock();
  }

} //end namespace


/* For the emacs weenies in the crowd.
Local Variables:
   c-basic-offset: 2
End:
*/
