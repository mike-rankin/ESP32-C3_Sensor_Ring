# ESP32-C3_Sensor_Ring
Unfortunately this Arduino based ESP32 Sensor Ring is not an open source project but the customer did give permissions to post images and a description of the hardware.<br/>

The specs are:<br/>
* ESP32-C3 Processor<br/>
* 0.49" 64x32 i2c Oled display<br/>
* LIS2DH12TR accelerometer<br/>
* 3.3V & 1.8V LDO in tiny UDFN-4 footprints<br/>
* MCP73831T-2ACI/OT LiPo charger<br/>
* SGP30 eCO2/TVOC sensor<br/>
* SGP40 Air quality sensor<br/>
* SHT20 Temperature/Humidity sensor<br/>
* 40mAh Battery<br/>
* Four layer mainboard & sensor board 0.8mm thick created in Altium Designer <br/>

The original bluetooth ring is an ZIKR that has limited features and without any sensors. I removed the cap, desoldered the circuit board, pushbutton switch cable and display from the existing board to install the ESP32 sensor board.<br/>  The sensor board is soldered to the processor board with board edge gold pads and programmed with a custom pogo pin CP2104 USB-C board.
Feel free to [email] (geeksworld@outlook.com) who is the owner of this project for any questions


![quarter](https://user-images.githubusercontent.com/4991664/221663001-2fac96d7-cdd7-43dd-9432-7542733127a2.jpg)
![Sensors](https://user-images.githubusercontent.com/4991664/221662958-e2f46356-9d1b-424b-9d84-4c673c9f06ba.jpg)
![Top](https://user-images.githubusercontent.com/4991664/221662973-71cbf2ea-a863-4664-a587-44b4e65210e6.jpg)
![Mating](https://user-images.githubusercontent.com/4991664/221663021-3e8f836b-b37d-4b94-914c-9686603476a2.jpg)
![Bottom](https://user-images.githubusercontent.com/4991664/221663032-07955743-a661-429a-a21b-8a8a61051a17.jpg)
![Box](https://user-images.githubusercontent.com/4991664/221883630-8bd081f1-9824-4627-a08e-17eeb256a8c5.jpg)
* This is the original circuit board that comes with the ring. The battery and oled display are removed and used on the esp32 board. The vibe motor is removed to make room for the sensor board. A small hole is dilled into the ring for the sensors.
![Original](https://user-images.githubusercontent.com/4991664/221883666-a122324d-ea6a-4980-ab1b-1a1c7e7cabbe.jpg)
![Installed_1](https://user-images.githubusercontent.com/4991664/221663038-5e3d3e2c-8c0a-4df0-b6f0-d4dfde024ec7.jpg)
![Finished](https://user-images.githubusercontent.com/4991664/221663045-b58c7a65-43f6-49f9-802e-8f774deaaa4c.jpg)
![Programmer](https://user-images.githubusercontent.com/4991664/221663053-eb7a3136-90b4-415f-bce0-dc80683c4a84.jpg)
* A metal dot is placed over the hole to keep out debris but still allow airflow
![dot](https://user-images.githubusercontent.com/4991664/221876978-88d35399-169c-4034-bf3f-c9f020cdc073.jpg)













