#ifndef PROGRAMNAME_H
#define PROGRAMNAME_H

#include <QDialog>

namespace Ui {
class ProgramName;
}

class ProgramName : public QDialog
{
    Q_OBJECT
    
public:
    explicit ProgramName(QWidget *parent = 0);
    ~ProgramName();

signals:
    void sig_sndNewName(QString str);
    void sig_sndClearName();
    void sig_ND(int);
    void sig_CD(QChar);

private slots:
    void on_programName_confirm_clicked();

    void on_programName_cancal_clicked();

    void ProNewisEmpty();
    void ProNewClose();
    void ProNewMulName();
    void ProNewisAZ();
    
    void on_panelButton_1_clicked();

    void on_panelButton_2_clicked();

    void on_panelButton_3_clicked();
    void on_panelButton_4_clicked();

    void on_panelButton_5_clicked();

    void on_panelButton_6_clicked();
    void on_panelButton_7_clicked();

    void on_panelButton_8_clicked();

    void on_panelButton_9_clicked();
    void on_panelButton_0_clicked();

    void on_panelButton_q_clicked();

    void on_panelButton_w_clicked();
    void on_panelButton_e_clicked();

    void on_panelButton_r_clicked();

    void on_panelButton_t_clicked();
    void on_panelButton_y_clicked();

    void on_panelButton_u_clicked();

    void on_panelButton_i_clicked();
    void on_panelButton_o_clicked();

    void on_panelButton_p_clicked();

    void on_panelButton_a_clicked();
    void on_panelButton_s_clicked();

    void on_panelButton_d_clicked();
    void on_panelButton_f_clicked();

    void on_panelButton_g_clicked();

    void on_panelButton_h_clicked();
    void on_panelButton_j_clicked();

    void on_panelButton_k_clicked();

    void on_panelButton_l_clicked();
    void on_panelButton_z_clicked();

    void on_panelButton_x_clicked();

    void on_panelButton_c_clicked();
    void on_panelButton_v_clicked();

    void on_panelButton_b_clicked();
    void on_panelButton_n_clicked();

    void on_panelButton_m_clicked();

    void on_BackButton_clicked();

    void on_panelButton_Plus_clicked();

    void on_panelButton_Dec_clicked();

    void on_panelButton_star_clicked();

private:
    Ui::ProgramName *ui;
};

#endif // PROGRAMNAME_H
