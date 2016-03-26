#include "procesador.h"

int main()
{

    uint8_t value; //se crea una variable de 8 bits llamada value

    CPUInit(); // esta función inicializa las variables en los rangos establecidos y da un estado.


    CPUWrite(0x2000, 0xFF);

    while(1)
        {
        value = CPURead(0x2002);
        CPUWrite(0x4001, value);
        }
}
