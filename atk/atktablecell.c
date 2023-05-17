#include "config.h"

#include "atktablecell.h"

typedef AtkTableCellIface AtkTableCellInterface;
G_DEFINE_INTERFACE (AtkTableCell, atk_table_cell, ATK_TYPE_OBJECT)

void atk_table_cell_default_init()
{
}

gint
atk_table_cell_get_column_span (AtkTableCell *cell)
{
    return 0;
}

GPtrArray *
atk_table_cell_get_column_header_cells (AtkTableCell *cell)
{
    return 0;
}

gboolean
atk_table_cell_get_position (AtkTableCell *cell,
                             gint         *row,
                             gint         *column)
{
    return 0;
}

gint
atk_table_cell_get_row_span (AtkTableCell *cell)
{
    return 0;
}

GPtrArray *
atk_table_cell_get_row_header_cells (AtkTableCell *cell)
{
    return 0;
}

gboolean
atk_table_cell_get_row_column_span (AtkTableCell *cell,
                                    gint         *row,
                                    gint         *column,
                                    gint         *row_span,
                                    gint         *column_span)
{
    return 0;
}

AtkObject *
atk_table_cell_get_table (AtkTableCell *cell)
{
    return 0;
}
