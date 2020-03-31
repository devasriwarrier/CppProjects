#include "mainwin.h"
#include "entrydialog.h"
#include "store.h"
#include <iostream> 
#include <sstream>
#include <iomanip>

Mainwin::Mainwin() : store{nullptr} {
    
    // /////////////////
    // G U I   S E T U P

    store = new Store();
    set_default_size(400, 200);
    set_title("ELSA SUPER COMPUTER");
    msg = Gtk::manage(new Gtk::Label());
    data = Gtk::manage(new Gtk::Label());
    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    //Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    //A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

//V I E W
    // Create a view menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

//C U S T O M E R
    // Append customer to the File menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_customer);

//P E R I P H E R A L
    // Append peripheral to the File menu
    Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_peripheral);

//D E S K T O P
    Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
    menuitem_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_desktop);
//O R D E R
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_order);

//I N S E R T
    // Create a insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
//C U S T O M E R
    // Append customer to the File menu
    Gtk::MenuItem *menuitem__insert_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem__insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem__insert_customer);
//P E R I P H E R A L
    // Append peripheral to the File menu
    Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_insert_peripheral);
//D E S K T O P
    Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("Desktop", true));
    menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_insert_desktop);
//O R D E R
    Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_insert_order);

    //     Q U I T
    // Push the quit botton all the way to the right by setting set_expand true
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);

    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit game");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
   // toolbar->append(*quit_button);

    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
     vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

}

Mainwin::~Mainwin() { }


//utilities
std::string Mainwin::get_string(std::string prompt){
EntryDialog dialog{*this, prompt, true};
dialog.set_text(prompt);
dialog.run();
return (dialog.get_text()).c_str();
};

double Mainwin::get_double(std::string prompt){
    EntryDialog dialog(*this, "??");
    dialog.set_text(prompt);
    dialog.run();
    return std::stoi((dialog.get_text()));
};

int Mainwin::get_int(std::string prompt){
    EntryDialog dialog(*this, "Order/Desktop");
    dialog.set_text(prompt);
    dialog.run();
    return std::stoi((dialog.get_text()));
};
void Mainwin::set_data(std::string s){
std::ostringstream oss;
data->set_text(s);
oss.str();
};
void Mainwin::set_msg(std::string s){
msg->set_text(s);
};
// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback

void Mainwin::on_quit_click() { close(); }

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("The ELSA Application");
   // auto logo = Gdk::Pixbuf::create_from_file("128px-Pyramidal_matches.png");
   // dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Devasri Warrier"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "No LOGO in this  sprint..next one"
        "no image yet"};
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_view_customer_click() {
std::ostringstream oss;
Glib::ustring s = R"(
<span size='20000' weight='bold'>Customers:</span>)";
 for(int i=0; i < store->num_customers(); ++i) {
 oss << i << ") " << store->customer(i) << "\n";
 std:: string s = oss.str();
 std::cout << s;
}
 msg->set_markup(s);
};
void Mainwin::on_view_peripheral_click() {
std::ostringstream oss;
Glib::ustring s = R"(
<span size='20000' weight='bold'>Peripherals::</span>)";
for(int i=0; i<store->num_options(); ++i) {
oss << i << ") " << store->option(i) << "\n";
 std:: string s = oss.str();
 std::cout << s;
}
 msg->set_markup(s);

};  
void Mainwin::on_view_desktop_click(){};
void Mainwin::on_view_order_click(){};

void Mainwin::on_insert_customer_click(){
std::string Name = get_string("Customer name?");
std::string Phone = get_string("Customer phone (xxx-xxx-xxxx)? ");
std::string Email = get_string("Customer email (xxx@domain.com)? ");
Customer customer{Name, Phone, Email};
store->add_customer(customer);

};

void Mainwin::on_insert_peripheral_click(){
std::string s = get_string ("Name of new peripheral? ");
std::string _cost = get_string("Cost? ");
double cost = atof(_cost.c_str());
Options option{s, cost};
store->add_option(option);
};
void Mainwin::on_insert_desktop_click(){
 int desktop = store->new_desktop();
while(true) {
int option;
for(int i=0; i<store->num_options(); ++i) 
int option = get_int("Add which peripheral?");
if(option == -1) break;
try {store->add_option(option, desktop);} 
catch(std::exception& e) {std::cerr << "#### INVALID OPTION ####\n\n";}
   }
};
void Mainwin::on_insert_order_click(){
	int customer = get_int("Customer");
	int order = store->new_order(customer);
};




