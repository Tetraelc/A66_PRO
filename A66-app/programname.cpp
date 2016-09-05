#include "programname.h"
#include "ui_programname.h"
#include <QDebug>

ProgramName::ProgramName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramName)
{
    ui->setupUi(this);

}

ProgramName::~ProgramName()
{
    delete ui;
}

void ProgramName::on_programName_confirm_clicked()
{    
   emit sig_sndNewName(ui->lineEdit_programName->text());

}

void ProgramName::on_programName_cancal_clicked()
{
    emit sig_sndClearName();

}

void ProgramName::ProNewisEmpty()
{
    ui->label_isEmpty->setText(trUtf8("输入不能为空"));
}

void ProgramName::ProNewisAZ()
{
    ui->label_isEmpty->setText(trUtf8("开头输入字母"));
}

void ProgramName::ProNewClose()
{
    this->close();

}

void ProgramName::ProNewMulName()
{
    ui->label_isEmpty->setText(trUtf8("文件已存在，请重新输入"));
}


void ProgramName::on_panelButton_1_clicked()
{
    ui->lineEdit_programName->text().append("1");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("1"));
    qDebug()<<"ui->lineEdit_programName->text().append()"<<ui->lineEdit_programName->text().append("1");
}

void ProgramName::on_panelButton_2_clicked()
{
    ui->lineEdit_programName->text().append("2");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("2"));
}
void ProgramName::on_panelButton_3_clicked()
{
   ui->lineEdit_programName->text().append("3");
   ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("3"));
}

void ProgramName::on_panelButton_4_clicked()
{
   ui->lineEdit_programName->text().append("4");
   ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("4"));
}

void ProgramName::on_panelButton_5_clicked()
{
    ui->lineEdit_programName->text().append("5");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("5"));
}

void ProgramName::on_panelButton_6_clicked()
{
    ui->lineEdit_programName->text().append("6");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("6"));
}
void ProgramName::on_panelButton_7_clicked()
{
     ui->lineEdit_programName->text().append("7");
     ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("7"));
}

void ProgramName::on_panelButton_8_clicked()
{
    ui->lineEdit_programName->text().append("8");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("8"));
}
void ProgramName::on_panelButton_9_clicked()
{
     ui->lineEdit_programName->text().append("9");
     ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("9"));
}

void ProgramName::on_panelButton_0_clicked()
{
    ui->lineEdit_programName->text().append("0");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("0"));
}


void ProgramName::on_panelButton_q_clicked()
{
    ui->lineEdit_programName->text().append("Q");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("Q"));
}

void ProgramName::on_panelButton_w_clicked()
{
    ui->lineEdit_programName->text().append("W");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("W"));
}

void ProgramName::on_panelButton_e_clicked()
{
    ui->lineEdit_programName->text().append("E");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("E"));
}

void ProgramName::on_panelButton_r_clicked()
{
    ui->lineEdit_programName->text().append("R");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("R"));
}

void ProgramName::on_panelButton_t_clicked()
{
    ui->lineEdit_programName->text().append("T");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("T"));
}

void ProgramName::on_panelButton_y_clicked()
{
   ui->lineEdit_programName->text().append("Y");
   ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("Y"));
}

void ProgramName::on_panelButton_u_clicked()
{
    ui->lineEdit_programName->text().append("U");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("U"));
}

void ProgramName::on_panelButton_i_clicked()
{
    ui->lineEdit_programName->text().append("I");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("I"));
}

void ProgramName::on_panelButton_o_clicked()
{
    ui->lineEdit_programName->text().append("O");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("O"));
}

void ProgramName::on_panelButton_p_clicked()
{
    ui->lineEdit_programName->text().append("P");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("P"));
}

void ProgramName::on_panelButton_a_clicked()
{
    ui->lineEdit_programName->text().append("A");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("A"));
}

void ProgramName::on_panelButton_s_clicked()
{
    ui->lineEdit_programName->text().append("S");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("S"));
}

void ProgramName::on_panelButton_d_clicked()
{
    ui->lineEdit_programName->text().append("D");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("D"));
}

void ProgramName::on_panelButton_f_clicked()
{
    ui->lineEdit_programName->text().append("F");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("F"));
}

void ProgramName::on_panelButton_g_clicked()
{
    ui->lineEdit_programName->text().append("G");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("G"));
}

void ProgramName::on_panelButton_h_clicked()
{
    ui->lineEdit_programName->text().append("H");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("H"));
}

void ProgramName::on_panelButton_j_clicked()
{
    ui->lineEdit_programName->text().append("J");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("J"));
}

void ProgramName::on_panelButton_k_clicked()
{
    ui->lineEdit_programName->text().append("K");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("K"));
}

void ProgramName::on_panelButton_l_clicked()
{
    ui->lineEdit_programName->text().append("L");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("L"));
}

void ProgramName::on_panelButton_z_clicked()
{
    ui->lineEdit_programName->text().append("Z");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("Z"));
}

void ProgramName::on_panelButton_x_clicked()
{
    ui->lineEdit_programName->text().append("X");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("X"));
}

void ProgramName::on_panelButton_c_clicked()
{
    ui->lineEdit_programName->text().append("C");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("C"));
}

void ProgramName::on_panelButton_v_clicked()
{
    ui->lineEdit_programName->text().append("V");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("V"));
}

void ProgramName::on_panelButton_b_clicked()
{
    ui->lineEdit_programName->text().append("B");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("B"));
}

void ProgramName::on_panelButton_n_clicked()
{
    ui->lineEdit_programName->text().append("N");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("N"));
}

void ProgramName::on_panelButton_m_clicked()
{
    ui->lineEdit_programName->text().append("M");
    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("M"));
}

void ProgramName::on_BackButton_clicked()
{
   ui->lineEdit_programName->setText( ui->lineEdit_programName->text().left(ui->lineEdit_programName->text().length()-1));
}



void ProgramName::on_panelButton_Plus_clicked()
{
//    ui->lineEdit_programName->text().append("*");
//    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("*"));
}

void ProgramName::on_panelButton_Dec_clicked()
{
//    ui->lineEdit_programName->text().append("#");
//    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("#"));
}

void ProgramName::on_panelButton_star_clicked()
{
//    ui->lineEdit_programName->text().append("-");
//    ui->lineEdit_programName->setText(ui->lineEdit_programName->text().append("-"));
}
