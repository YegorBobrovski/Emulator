#ifndef DENDYDEBUGGER_H
#define DENDYDEBUGGER_H

#include <QDialog>
#include <QFile>
#include "dendymemory.h"
#include "dendycpu.h"

namespace Ui {
class DendyDebugger;
}

class DendyDebugger : public QDialog
{
    Q_OBJECT

public:
    explicit DendyDebugger(QWidget *parent = 0);
    explicit DendyDebugger(DendyCPU* cpu, DendyMemory *memory, QWidget *parent = 0);
    ~DendyDebugger();
    

private slots:
    void on_C_stateChanged(int state);
    
    void on_Z_stateChanged(int state);
    
    void on_I_stateChanged(int state);
    
    void on_D_stateChanged(int state);
    
    void on_B_stateChanged(int state);
    
    void on_V_stateChanged(int state);
    
    void on_N_stateChanged(int state);
    
    void on_resetCPU_clicked();
    
private:
    Ui::DendyDebugger *ui;
    DendyCPU* cpu;
    DendyMemory* memory;
    
    void initMemoryView();
    void initRegisters();
    void toHexString(char* dest, unsigned short num, int size);
    void showMemoryBlock(QByteArray* block, short startAdress = 0x000);
    void updateRegP();
};

#endif // DENDYDEBUGGER_H
