#ifndef STARBLITZGAMEDISPLAY_H
#define STARBLITZGAMEDISPLAY_H

class Display {
private:
    static int DIMW;
    static int DIMH;

public:
    Display();
    ~Display();
    static int getDIMW();
    static int getDIMH();
    static void setDIMW(int DIMW);
    static void setDIMH(int DIMH);
};

#endif