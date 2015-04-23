#ifndef DENDYCPU_H
#define DENDYCPU_H

#include "dendymemory.h"

class DendyCPU
{
private:
    struct REG_6502
    {
        unsigned char a;     /* ����������� */
        unsigned char p;     /* ������� ������ */
        unsigned char x, y;  /* ��������� �������� */
        unsigned char s;     /* ��������� ����� */
        union
        {
            struct {unsigned char l, h;} B;  /* �������, ������� ����� ����� */
            unsigned short W; /* ����� */
        } pc;
    } cpuReg;       /* 16-��������� ������� ������ */

    int iPeriod;    /* ���������� ������ �� ������������ ����. ����� */
    int iTact;      /* ����� ������, ����������� �� ���������� ������� */
    
    DendyMemory *memory = NULL;

public:
    DendyCPU(DendyMemory* memory);
    ~DendyCPU();
    void ResetCPU();
    char stepCPU();
    
    // �������
    void comADC(unsigned char operand);
    void comAND(unsigned char operand);
    unsigned char comASL(unsigned char operand);
    void comBIT(unsigned char operand);
    
    // ������ ���������
    unsigned short adrZP();
    unsigned short adrZPX();
    unsigned short adrZPY();
    unsigned short adrABS();
    unsigned short adrINDX();
    unsigned short adrINDY();
    unsigned short adrREL();
    
    // ������� �������� ���������
    unsigned char getRegA();
    unsigned char getRegP();
    unsigned char getRegX();
    unsigned char getRegY();
    unsigned char getRegS();
    short getRegPC();
    unsigned char getRegPCl();
    unsigned char getRegPCh();
    
    // ������� �������� ������
    bool getFlagN();
    bool getFlagV();
    bool getFlagB();
    bool getFlagD();
    bool getFlagI();
    bool getFlagZ();
    bool getFlagC();
    
    // ������� �������� ������
    void setFlagN(bool state);
    void setFlagV(bool state);
    void setFlagB(bool state);
    void setFlagD(bool state);
    void setFlagI(bool state);
    void setFlagZ(bool state);
    void setFlagC(bool state);
    
    // ������ �� ������
    void pushStack(unsigned char value);
    unsigned char popStack();
    
};

#endif // DENDYCPU_H
