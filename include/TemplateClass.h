#pragma once

#include <string>
#include <map>
#include <ros/ros.h>
#include <ros/package.h>
#include <nodelet/nodelet.h>
#include <mrs_lib/param_loader.h>

namespace template_package
{

    class TemplateClass : public nodelet::Nodelet {
        public:
            virtual void onInit();
        private:
            /* flags */
            std::atomic<bool> is_initialized_ = {false};
            /*ros parameters */
            std::string _uav_name_;

    };
    
}
