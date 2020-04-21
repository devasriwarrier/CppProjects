#ifndef __MAINWIN_H
#define __MAINWIN_H
#include <gtkmm.h>
#include "store.h" 


class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();

    protected:
        void on_view_peripheral_click();   // Create a new game
	void on_view_desktop_click();
	void on_view_order_click();
	void on_view_customer_click();

	void on_insert_peripheral_click();
	void on_insert_desktop_click();
	void on_insert_order_click();
	void on_insert_customer_click();

        void on_about_click();             // Display About dialog

	std::string get_string(std::string prompt);
	double get_double(std::string prompt);
	int get_int(std::string prompt);
	void set_data(std::string s);
	void set_msg(std::string s);

        void on_new_store_click();         // Create a new store
        void on_save_click();              // Save the game to default file
        void on_save_as_click();           // Save the game to selected file
        void on_open_click();              // Load the game from selected file
        void on_quit_click();              // Exit the game

        void on_scale_value_changed();
    private:
        Store *store;                      
        Gtk::Label *data;                        
        Gtk::Label *msg; 
	std::string filename; 

};
#endif 
