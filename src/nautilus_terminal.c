   /* Nautilus Terminal: A terminal program to open default terminal from current path
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.*/


#include <nautilus/nautilus-extension.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct _TerminalExtension TerminalExtension;
typedef struct _TerminalExtensionClass TerminalExtensionClass;
static GType provider_types[1];

static GType terminal_extension_type;
struct _TerminalExtension
{
	GObject parent_slot;
};

struct _TerminalExtensionClass
{
	GObjectClass parent_slot;
};
static void terminal_extension_class_init(TerminalExtensionClass *class)
{
}

static void terminal_extension_instance_init(TerminalExtension *img)
{
}

static void open_terminal(NautilusMenuItem* item,char* path){
	char next[24] = " && x-terminal-emulator";
	char start[4] = "cd ";
	char first[strlen(path+7)+strlen(start)+strlen(next)+1];
	strcpy(first,start);
	strcat(first,path+7);
	strcat(first,next);
	/*	
	g_print("Command: ");
	g_print(first);
	g_print("\n");*/
	system(first);
}
static GList *
terminal_extension_get_file_items (NautilusMenuProvider *provider,
		GtkWidget *window,
		GList *files)
{
	return NULL;
}



static GList *
terminal_extension_get_toolbar_items (NautilusMenuProvider *provider, 
		GtkWidget *window,
		NautilusFileInfo *current_folder)
{
	return NULL;
}
static GList *
terminal_extension_get_background_items (NautilusMenuProvider *provider, 
		GtkWidget *window,
		NautilusFileInfo *current_folder)
{	char* path = nautilus_file_info_get_uri(current_folder);
	NautilusMenuItem* item = nautilus_menu_item_new("TerminalExtension::open_terminal","Open in terminal","Opens Default Terminal",NULL);
	g_signal_connect (item, "activate", G_CALLBACK (open_terminal), path);
	GList* ret =  g_list_append (NULL, item);
	return ret;
}
static void
terminal_extension_menu_provider_iface_init (NautilusMenuProviderIface *iface) {
	iface->get_background_items = terminal_extension_get_background_items;
	iface->get_file_items = terminal_extension_get_file_items;
	return;
}
GType terminal_extension_get_type (void)
{
	return terminal_extension_type;
}

static void
terminal_extension_register_type (GTypeModule *module)
{
	static const GTypeInfo info = {
		sizeof (TerminalExtensionClass),
		(GBaseInitFunc) NULL,
		(GBaseFinalizeFunc) NULL,
		(GClassInitFunc) terminal_extension_class_init,
		NULL,
		NULL,
		sizeof (TerminalExtension),
		0,
		(GInstanceInitFunc) terminal_extension_instance_init,
	};

	terminal_extension_type = g_type_module_register_type (module,
			G_TYPE_OBJECT,
			"TerminalExtension",
			&info, 0);
	static const GInterfaceInfo menu_provider_iface_info = {
		(GInterfaceInitFunc) terminal_extension_menu_provider_iface_init,
		NULL,
		NULL
	};
	 g_type_module_add_interface (module,
                                 terminal_extension_type,
                                 NAUTILUS_TYPE_MENU_PROVIDER,
                                 &menu_provider_iface_info);
}
#define EXPORT __attribute__((__visibility__("default"))) extern

EXPORT void
nautilus_module_initialize (GTypeModule  *module) 
{
	g_print("Starting Nautilus Terminal Extension...\n");
	terminal_extension_register_type (module);

	provider_types[0] = terminal_extension_get_type ();
}
EXPORT void
nautilus_module_shutdown (void)
{
	g_print("Stopping Nautilus Terminal Extension");
	/* Any module-specific shutdown */
}
EXPORT void
nautilus_module_list_types (const GType **types,
		int *num_types)
{
	*types = provider_types;
	*num_types = G_N_ELEMENTS (provider_types);
}



