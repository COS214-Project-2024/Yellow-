/**
 * @file OpenField.h
 * @author Johan and Stefan Jansen van Rensburg
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CODE_OPENFIELD_H
#define CODE_OPENFIELD_H
#include "Cell.h"

class OpenField : public Cell{
public:
    OpenField();
    void setIcon() override;
    Cell * clone() override;

};


#endif //CODE_OPENFIELD_H
