sudo apt-get install xorg
sudo apt-get install xfce4
sudo apt-get install xrdp
# config port
sudo sed -i 's/port=3389/port=3390/g' /etc/xrdp/xrdp.ini
sudo echo xfce4-session > ~/.xession
sudo service xrdp restart
