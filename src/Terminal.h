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
#include <string>
using namespace std;
//Terminal abstraction 
class Terminal{
	private:
		//path to be opened in terminal
		static string path;
		//Command to launch terminal
		static string cmd;

	public:
		//Contructors
		Terminal();
		Terminal(string path,string cmd);
		Terminal(string path);

		//Getters and Setters
		void set_path(string path);
		void set_cmd(string cmd);
		string get_path();
		string get_cmd();

		//launch terminal with a new background thread
		static void handle_open_terminal();
		void open();
};
