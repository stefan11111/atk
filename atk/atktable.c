#include "config.h"

#include "atktable.h"
#include "atkmarshal.h"

enum {
  ROW_INSERTED,
  ROW_DELETED,
  COLUMN_INSERTED,
  COLUMN_DELETED,
  ROW_REORDERED,
  COLUMN_REORDERED,
  MODEL_CHANGED,
  LAST_SIGNAL
};

long unsigned int
atk_table_get_type (void)
{
    return 0;
}

AtkObject*
atk_table_ref_at (AtkTable *table,
                  int     row,
                  int     column)
{
    return 0;
}

int
atk_table_get_index_at (AtkTable *table,
                        int     row,
                        int     column)
{
    return -1;
}

int
atk_table_get_row_at_index (AtkTable *table,
                            int     index)
{
    return -1;
}

int
atk_table_get_column_at_index (AtkTable *table,
                               int     index)
{
    return -1;
}

AtkObject*
atk_table_get_caption (AtkTable *table)
{
    return 0;
}

int
atk_table_get_n_columns (AtkTable *table)
{
    return 0;
}

const char*
atk_table_get_column_description (AtkTable *table,
                                  int     column)
{
    return 0;
}

int
atk_table_get_column_extent_at (AtkTable *table,
                                int     row,
                                int     column)
{
    return 0;
}

AtkObject*
atk_table_get_column_header (AtkTable *table, int column)
{
    return 0;
}

int
atk_table_get_n_rows (AtkTable *table)
{
    return 0;
}

const char*
atk_table_get_row_description (AtkTable *table,
                               int      row)
{
    return 0;
}

int
atk_table_get_row_extent_at (AtkTable *table,
                             int     row,
                             int     column)
{
    return 0;
}

AtkObject*
atk_table_get_row_header (AtkTable *table, int row)
{
    return 0;
}

AtkObject*
atk_table_get_summary (AtkTable *table)
{
    return 0;
}

int
atk_table_get_selected_rows (AtkTable *table, int **selected)
{
    return 0;
}

int 
atk_table_get_selected_columns (AtkTable *table, int **selected)
{
    return 0;
}

gboolean
atk_table_is_column_selected (AtkTable *table,
                              int     column)
{
    return 0;
}

gboolean
atk_table_is_row_selected (AtkTable *table,
                           int     row)
{
    return 0;
}

gboolean
atk_table_is_selected (AtkTable *table,
                       int     row,
                       int     column)
{
    return 0;
}

gboolean
atk_table_add_row_selection (AtkTable *table,
                       		 int     row)
{
    return 0;
}

gboolean
atk_table_remove_row_selection (AtkTable *table,
                       		    int     row)
{
    return 0;
}

gboolean
atk_table_add_column_selection (AtkTable *table,
                       		    int     column)
{
    return 0;
}
gboolean
atk_table_remove_column_selection (AtkTable *table,
                       			   int     column)
{
    return 0;
}

void
atk_table_set_caption (AtkTable       *table,
                       AtkObject      *caption)
{
}

void
atk_table_set_column_description (AtkTable       *table,
                                  int           column,
                                  const char    *description)
{

}

void
atk_table_set_column_header (AtkTable  *table,
                             int      column,
                             AtkObject *header)
{
}

void
atk_table_set_row_description (AtkTable       *table,
                               int           row,
                               const char    *description)
{
}

void
atk_table_set_row_header (AtkTable  *table,
                          int      row,
                          AtkObject *header)
{
}

void
atk_table_set_summary (AtkTable       *table,
                       AtkObject      *accessible)
{
}
