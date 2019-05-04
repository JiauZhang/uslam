# 1. setup sources.list
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
# 2. set up keys
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt update
# 3. install
sudo apt install ros-melodic-desktop
# to find availavel packages, use:
# apt search ros-melodic
# 4. initialize rosdep
sudo rosdep init
rosdep update
# environment setup
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc
# dependencies for building packages
sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
