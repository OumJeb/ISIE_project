#include <gtk/gtk.h>
#include "functelections.h"

void
on_button_elecadd_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton_electype1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_electype2_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_button_stats_clicked                (GtkWidget       *button,
                                        gpointer         user_data);



void
on_button_modify_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_comfirm_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton_modiftype1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modiftype2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_confirm_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button_displaydelete_clicked        (GtkWidget       *button,
                                        gpointer         user_data);




void
on_treeview_displayelecdelete_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_button_deleteelec_clicked           (GtkWidget      *button,
                                        gpointer         user_data);




void
on_checkbutton_conelecdelete_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_SIGNIN_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_backelec_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_searchelec_clicked           (GtkWidget      *button,
                                        gpointer         user_data);

void
on_checkbutton_idsearch_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_datesearch_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_munsearch_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
