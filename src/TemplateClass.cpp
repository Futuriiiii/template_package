#include <TemplateClass.h>
#include <pluginlib/class_list_macros.h>

namespace template_package
{
    void TemplateClass::onInit()
    {
        ros::NodeHandle nh("~");
        
        ros::Time::waitForValid();

        mrs_lib::ParamLoader param_loader(nh, "TemplateClass");

        param_loader.loadParam("uav_name", _uav_name_);

        if (!param_loader.loadedSuccessfully())
        {
            ROS_ERROR("[WaypointFlier]: failed to load non-optional parameters!");
            ros::shutdown();
        }

        ROS_INFO_ONCE("[TemplateClass]: initialized");
        ROS_INFO_ONCE("[TemplateClass]: service is available");

        is_initialized_ = true;

        ros::spin();
    }
}
PLUGINLIB_EXPORT_CLASS(template_package::TemplateClass, nodelet::Nodelet);