#include "procesador.h"
#include "ports.h"

void secuencias(uint8_t sel);

int main(){

    uint8_t sel;

    CPUInit();

    CPUWrite(DDR_A, 0);
    CPUWrite(DDR_B, 0xFF);

    while(1){
        sel = CPURead(PIN_A);
        secuencias(sel);
        _delay_ms(5);
    }
}

void secuencias(uint8_t sel)
{
    uint8_t value;

    switch(sel)
    {
        case 1:
            value = CPURead(PORT_B);
            if(value != 1)
                value = 1;
            else
                value <<= 1;
            CPUWrite(PORT_B, value);
            break;

        case 2:
            value = CPURead(PORT_B);
            if(value != 0x80)
                value = 0x80;
            else
                value >>= 1;
            CPUWrite(PORT_B, value);
            break;

        case 4:
            value = CPURead(PORT_B);
            value++;
            CPUWrite(PORT_B, value);
            break;

        case 8:
            value = CPURead(PORT_B);
            value--;
            CPUWrite(PORT_B, value);
            break;

        default:
            value = CPURead(PORT_B);
            value ^= 0xFF;
            CPUWrite(PORT_B, value);
            break;
    }
}
