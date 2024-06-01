#include <string>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

int main() {
    DSBN dsbn;
    InitBN(dsbn);
    DSDV dsdv = NULL;
    DSThuoc S = NULL;
    DSBS dsbs = NULL;
    Dapung(dsbn,S,dsdv,dsbs);
    return 0;
}