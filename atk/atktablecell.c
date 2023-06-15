

#include "atktablecell.h"

typedef AtkTableCellIface AtkTableCellInterface;

long unsigned int atk_table_cell_get_type(void)
{
    return 0;
}

void atk_table_cell_default_init()
{
}

int
atk_table_cell_get_column_span (AtkTableCell *cell)
{
    return 0;
}

void *
atk_table_cell_get_column_header_cells (AtkTableCell *cell)
{
    return 0;
}

unsigned char
atk_table_cell_get_position (AtkTableCell *cell,
                             int         *row,
                             int         *column)
{
    return 0;
}

int
atk_table_cell_get_row_span (AtkTableCell *cell)
{
    return 0;
}

void *
atk_table_cell_get_row_header_cells (AtkTableCell *cell)
{
    return 0;
}

unsigned char
atk_table_cell_get_row_column_span (AtkTableCell *cell,
                                    int         *row,
                                    int         *column,
                                    int         *row_span,
                                    int         *column_span)
{
    return 0;
}

AtkObject *
atk_table_cell_get_table (AtkTableCell *cell)
{
    return 0;
}
