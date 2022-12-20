#include <gtk/gtk.h>
#include "functelections.h"
#include "claimsfunctions.h"
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

void
on_button_adminmanagment_clicked       (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_claimsmanagment_clicked      (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_listmanagment_clicked        (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_clmactor_clicked             (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_listactor_clicked            (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_VOTE_clicked                 (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_backsigninadmin_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_backto_clicked               (GtkWidget       *button,
                                        gpointer         user_data);
///////////////////////////////////////////////////////////////////////////////////////////

void
on_stuff_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_system_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_other_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_verifymodifclaim_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_stuffmod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_systemmod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_modifyclaim_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_othermod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_submitclaim_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_button_find_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_deletebutton_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_viewbuttondisplay_clicked           (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_displaystats_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_nerstats_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_identrydisplay_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mundisplay_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
