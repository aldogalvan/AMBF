//==============================================================================
/*
    Software License Agreement (BSD License)
    Copyright (c) 2019-2021, AMBF
    (https://github.com/WPI-AIM/ambf)

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided
    with the distribution.

    * Neither the name of authors nor the names of its contributors may
    be used to endorse or promote products derived from this software
    without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    \author    <amunawar@wpi.edu>
    \author    Adnan Munawar
*/
//==============================================================================

#ifndef AFVEHICLECOMM_H
#define AFVEHICLECOMM_H

#include <string>
#include "ambf_server/VehicleRosCom.h"

namespace ambf_comm{
class Vehicle: public VehicleRosCom{
public:
    Vehicle(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out);
    void cur_position(double px, double py, double pz);
    void cur_orientation(double roll, double pitch, double yaw);
    void cur_orientation(double qx, double qy, double qz, double qw);
    inline void set_wheel_count(int count){m_State.wheel_count = count;}
    inline void set_mass(double mass){m_State.mass = mass;}
    inline void set_principal_inertia(double ix, double iy, double iz){
        m_State.pInertia.x = ix;
        m_State.pInertia.y = iy;
        m_State.pInertia.z = iz;
    }

    void set_type(std::string type);
};
}

#endif
