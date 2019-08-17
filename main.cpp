#include <iostream>
#include <gtk/gtk.h>
#include <libappindicator/app-indicator.h>

// based on: https://www.codeguru.com/cpp/cpp/creating-a-cc-gui-with-gtk.html
// read: https://wiki.ubuntu.com/DesktopExperienceTeam/ApplicationIndicators

AppIndicator *appIndicator = nullptr;

/**
 * Brief: A GTK callback function when the "Say Hello" menu is clicked. 
 * It outputs "Hello there!" to the console to show that it ran.
 */
void sayHello(GtkWidget *widget, gpointer data) {
   std::cout << "Hello there!\n";
}

/**
 * Brief: A GTK callback function that changes the appIndicator icon to the 
 * "security-high" icon of the installed theme.
 * Icons are shown with this tool: gtk3-icon-browser
 */
void highSecurity(GtkWidget *widget, gpointer data) {
   app_indicator_set_icon(appIndicator, "security-high");
}

void mediumSecurity(GtkWidget *widget, gpointer data) {
   app_indicator_set_icon(appIndicator, "security-medium");
}

void lowSecurity(GtkWidget *widget, gpointer data) {
   app_indicator_set_icon(appIndicator, "security-low");
}

void destroy(GtkWidget *widget, gpointer data) {
   gtk_main_quit();
}


int main(int argc, char *argv[]) {
   gtk_init(&argc, &argv);

   // Creates the AppIndicator instance that is referred to right at the top of the program
   // see https://lazka.github.io/pgi-docs/AppIndicator3-0.1/enums.html#AppIndicator3.IndicatorCategory for the 
   // types of IndicatorCategory 
   appIndicator = app_indicator_new("appIndicatorId",
      "applications-development", APP_INDICATOR_CATEGORY_APPLICATION_STATUS);

   // See https://lazka.github* .io/pgi-docs/AppIndicator3-0.1/enums.html#AppIndicator3.IndicatorStatus for the
   // types of status. Here we want it ACTIVE meaning "The indicator should be shown in it’s default state."
   app_indicator_set_status(appIndicator, APP_INDICATOR_STATUS_ACTIVE);

   // Creates the systray menu so that we have something that opens up when we right-click the systray icon
   GtkWidget *menu = gtk_menu_new();

   // Create a menu entry "Say Hello"
   GtkWidget *helloMenuItem = gtk_menu_item_new_with_label("Say Hello");
   gtk_widget_show(helloMenuItem);
   // Connect the entry with the menu
   gtk_menu_shell_append(GTK_MENU_SHELL(menu), helloMenuItem);
   // connect the menu item with the sayHello Gtk callback function
   g_signal_connect(helloMenuItem, "activate", G_CALLBACK(sayHello), NULL);

   GtkWidget *hiSecurityMenuItem = gtk_menu_item_new_with_label("High Security");
   gtk_widget_show(hiSecurityMenuItem);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu), hiSecurityMenuItem);
   g_signal_connect(hiSecurityMenuItem, "activate", G_CALLBACK(highSecurity), NULL);

   GtkWidget *mediumSecurityMenuItem = gtk_menu_item_new_with_label("Medium Security");
   gtk_widget_show(mediumSecurityMenuItem);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu), mediumSecurityMenuItem);
   g_signal_connect(mediumSecurityMenuItem, "activate", G_CALLBACK(mediumSecurity), NULL);

   GtkWidget *lowSecurityMenuItem = gtk_menu_item_new_with_label("Low Security");
   gtk_widget_show(lowSecurityMenuItem);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu), lowSecurityMenuItem);
   g_signal_connect(lowSecurityMenuItem, "activate", G_CALLBACK(lowSecurity), NULL);

   GtkWidget *closeMenuItem = gtk_menu_item_new_with_label("Close this systray menu and exit the GTK app");
   gtk_widget_show(closeMenuItem);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu), closeMenuItem);
   g_signal_connect(closeMenuItem, "activate", G_CALLBACK(destroy), NULL);

   // Connect the menu to the appIndicator
   app_indicator_set_menu(appIndicator, GTK_MENU(menu));

   gtk_main();
   return 0;
}
