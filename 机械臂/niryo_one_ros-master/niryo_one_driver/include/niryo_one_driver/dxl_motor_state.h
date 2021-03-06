/*
    dxl_motor_state.h
    Copyright (C) 2017 Niryo
    All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NIRYO_DXL_MOTOR_STATE_H
#define NIRYO_DXL_MOTOR_STATE_H

#include <string>

#define TOOL_STATE_PING_OK       0x01
#define TOOL_STATE_PING_ERROR    0x02
#define TOOL_STATE_WRONG_ID      0x03
#define TOOL_STATE_TIMEOUT       0x04

#define GRIPPER_STATE_OPEN       0x10 
#define GRIPPER_STATE_CLOSE      0x11

#define VACUUM_PUMP_STATE_PULLED 0x20
#define VACUUM_PUMP_STATE_PUSHED 0x21

class DxlMotorState {

    public:
        DxlMotorState() {}
        DxlMotorState(const std::string name, uint8_t motor_id) {
            this->name = name;
            id = motor_id;

            resetState();
            resetCommand();
        }

        void resetState() {
            state_pos = 0;
            state_vel = 0;
            state_torque = 0;
            state_temperature = 0;
            state_voltage = 0;
            state_hw_error = 0;
        }
        void resetCommand() {
            cmd_pos = 0;
            cmd_vel = 0;
            cmd_torque = 0;
            cmd_led = 0;
        }

        std::string getName()        { return name; }
        void setName(std::string n)  { name = n; } 
        uint8_t getId()              { return id; }
        void setId(uint8_t motor_id) { id = motor_id; } // allows to change tool motor easily
        
        // getters - state
        uint32_t getPositionState()     { return state_pos; }
        uint32_t getVelocityState()     { return state_vel; }
        uint32_t getTorqueState()       { return state_torque; }
        uint8_t getTemperatureState()   { return state_temperature; }
        uint8_t getVoltageState()       { return state_voltage; }
        uint8_t getHardwareErrorState() { return state_hw_error; }

        // setters - state
        void setPositionState(uint32_t pos)     { state_pos = pos; }
        void setVelocityState(uint32_t vel)     { state_vel = vel; }
        void setTorqueState(uint32_t torque)    { state_torque = torque; }
        void setTemperatureState(uint8_t temp)  { state_temperature = temp; }
        void setVoltageState(uint8_t volt)      { state_voltage = volt; }
        void setHardwareError(uint8_t hw_error) { state_hw_error = hw_error; }

        // getters - command
        uint32_t getPositionCommand() { return cmd_pos; }
        uint32_t getVelocityCommand() { return cmd_vel; }
        uint32_t getTorqueCommand()   { return cmd_torque; }
        uint8_t getLedCommand()       { return cmd_led; }

        // setters - command
        void setPositionCommand(uint16_t pos)  { cmd_pos = pos; }
        void setVelocityCommand(uint16_t vel)  { cmd_vel = vel; }
        void setTorqueCommand(uint16_t torque) { cmd_torque = torque; }
        void setLedCommand(uint8_t led)        { cmd_led = led; }

    private:

        std::string name;
        uint8_t id;

        // read variables
        
        uint32_t state_pos; 
        uint32_t state_vel;
        uint32_t state_torque;
        uint8_t state_temperature;
        uint8_t state_voltage;
        uint8_t state_hw_error;

        // write variables 

        uint32_t cmd_pos;
        uint32_t cmd_vel;
        uint32_t cmd_torque; 
        uint8_t cmd_led;
};

#endif
