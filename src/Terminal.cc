/**
    Nautilus-Terminal : A nautilus extension to open default x-terminal-emulator in current path
    Copyright (C) 2019  Rishabh Dwivedi <rishabhdwivedi17@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
**/
#include "Terminal.h"
#include <thread>
using namespace std;

Terminal::Terminal(string path,string cmd){
	Terminal::set_path(path);
	Terminal::set_cmd(cmd);
}

Terminal::Terminal(){
	Terminal(".","x-terminal-emulator");
}
Terminal::Terminal(string path){
	Terminal(path,"x-terminal-emulator");
}
void Terminal::set_path(string path){
	Terminal::path = path;
}
void Terminal::set_cmd(string cmd){
	Terminal::cmd = cmd;
}
string Terminal::get_cmd(){
	return Terminal::cmd;
}
string Terminal::get_path(){
	return Terminal::path;
}
void Terminal::handle_open_terminal(){
	string final_cmd = "cd "+Terminal::path+" && "+Terminal::cmd;
	system(final_cmd.c_str());
}
void Terminal::open(){
	thread thr = thread(this->handle_open_terminal);
	thr.detach();
}
