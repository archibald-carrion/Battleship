#ifndef COMMON_HPP
#define COMMON_HPP

typedef struct {
    int row;
    int column;
    int size;
    int dir;
    int symbol; 

    void initShipData() {
        this->row = -1;
        this->column = -1;
        this->size = 0;
        this->dir = 0;
        this->symbol = 6;
    }
} ShipData;

#endif  // COMMON_HPP