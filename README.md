# Nautilus-Terminal
This is a nautilus extension used to open terminal from the current path.

# Then how it is different from what nautilus provides.
This extension does not only opens gnome-terminal but it will open your default terminal.

So, for example you use urxvt or st or something else, You can continue your same experience from nautilus without any dependency problem. 
(Some people recommends to uninstall gnome-terminal and make a soft link to that, but removing gnome-terminal many times creates dependencies problem).

# Installtion Steps:

You need ```g++``` and ```libnautilus-extension-dev``` packages for installation.

(Uninstall ```nautilus-open-terminal``` or ```nautilus-extension-gnome-terminal``` if installed so, there would be no name-conflicts)

In source folder, execute ```sudo bash install.sh```


COPYRIGHT 2019 Rishabh Dwivedi <rishabhdwivedi17@gmail.com>
