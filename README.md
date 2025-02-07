# Gas Detector - Advanced IoT Final Project 🚀🔥🛠️

This repository contains the source code and setup guide for my final project in the **Advanced IoT Course** at **University of Kashan**. The project is a **Gas Detector** system built using **Arduino Wemos D1**, various **sensor modules**, an **LED indicator**, and an **active buzzer** for alert notifications. 🔧📡⚡

## Features 🎯🛠️📡
- **MQTT Communication**: Connects to **HiveMQ** broker for real-time data exchange.
- **Node-RED Dashboard**: Provides a graphical interface for monitoring and controlling the system.
- **Alarm System**: Activates **LED** and **Buzzer** when gas levels exceed a threshold.
- **Email Alerts**: When the gas level exceeds a bound, it sends an email to warn you. 📩⚠️📊
- **Customizable Topics**: MQTT topics can be changed in the code to suit different configurations.

## How It Works 🏭🔍📶
1. The gas sensor detects gas concentration in the environment.
2. If the gas level exceeds a predefined threshold, the **LED** turns on and the **buzzer** sounds an alarm. 🔊⚠️💡
3. The Wemos D1 board publishes gas level readings to the **HiveMQ MQTT broker**.
4. **Node-RED** subscribes to the MQTT topics, processes the data, and displays it on a dashboard.
5. If the gas level exceeds a bound, the system sends an **email alert**. 📧🚨📊
6. The system can be monitored and controlled through the **Node-RED dashboard**. 📊🔄🖥️

## Getting Started 🚀🔌🛠️

### Hardware Requirements 🖥️🔩🔋
- **Wemos D1 (ESP8266)**
- **MQ-2 or MQ-135 Gas Sensor**
- **Active Buzzer**
- **LED**
- **Resistors and Jumper Wires**
- **Breadboard**

### Software Requirements 💻📲⚙️
- **Arduino IDE** with ESP8266 board support
- **MQTT Library** (PubSubClient)
- **HiveMQ Broker** (Cloud-based MQTT service)
- **Node-RED** for data visualization and control

## Setup Instructions 🛠️📝📡
### 1. Arduino Code ⚡🔢🔄
- Install **Arduino IDE** and add **ESP8266 board support**.
- Install **PubSubClient library** for MQTT communication.
- Update the **WiFi credentials** and **MQTT broker details** in the code.
- Upload the code to the **Wemos D1** board. 🔄🚀⚙️

### 2. Node-RED Dashboard 📊🔍🖥️
- Import the provided **JSON flow file** into Node-RED.
- Update MQTT topics if necessary.
- Deploy the flow and monitor sensor data in real time. 📡📈💡

## Customization 🛠️🖥️📌
- You can modify **MQTT topics** in the Arduino code to match your requirements.
- Import the provided **Node-RED JSON file** to visualize data effectively.
- Adjust the **threshold values** in the code to set alarm conditions. 🔄⚠️📊

## Future Improvements 🌍📈💡
- Integrating a **mobile notification system** using **Telegram** or **WhatsApp**. 📲💬🚀


## Author 👨‍💻🏫📜
Mehrdad Chaharbaghi - Advanced IoT Course, **University of Kashan**

Feel free to contribute and improve the project! 🚀✨🤝

