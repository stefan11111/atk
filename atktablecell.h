#ifndef __ATK_TABLE_CELL_H__
#define __ATK_TABLE_CELL_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>

G_BEGIN_DECLS

#define ATK_TYPE_TABLE_CELL                    (atk_table_cell_get_type ())
#define ATK_IS_TABLE_CELL(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_TABLE_CELL)
#define ATK_TABLE_CELL(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_TABLE_CELL, AtkTableCell)
#define ATK_TABLE_CELL_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_TABLE_CELL, AtkTableCellIface))

#ifndef _TYPEDEF_ATK_TABLE_CELL_
#define _TYPEDEF_ATK_TABLE_CELL_
typedef struct _AtkTableCell AtkTableCell;
#endif
typedef struct _AtkTableCellIface AtkTableCellIface;

struct _AtkTableCellIface
{
  /*< private >*/
  GTypeInterface parent;

  /*< public >*/
  gint          (*get_column_span)         (AtkTableCell *cell);
  GPtrArray *   (*get_column_header_cells) (AtkTableCell *cell);
  gboolean      (*get_position)            (AtkTableCell *cell,
                                            gint         *row,
                                            gint         *column);
  gint          (*get_row_span)            (AtkTableCell *cell);
  GPtrArray *   (*get_row_header_cells)    (AtkTableCell *cell);
  gboolean      (*get_row_column_span)     (AtkTableCell *cell,
                                            gint         *row,
                                            gint         *column,
                                            gint         *row_span,
                                            gint         *column_span);
  AtkObject *   (*get_table)               (AtkTableCell *cell);
};

ATK_AVAILABLE_IN_2_12
GType atk_table_cell_get_type (void);

ATK_AVAILABLE_IN_2_12
gint        atk_table_cell_get_column_span         (AtkTableCell *cell);
ATK_AVAILABLE_IN_2_12
GPtrArray * atk_table_cell_get_column_header_cells (AtkTableCell *cell);
ATK_AVAILABLE_IN_2_12
gboolean    atk_table_cell_get_position            (AtkTableCell *cell,
                                                    gint         *row,
                                                    gint         *column);
ATK_AVAILABLE_IN_2_12
gint        atk_table_cell_get_row_span            (AtkTableCell *cell);
ATK_AVAILABLE_IN_2_12
GPtrArray * atk_table_cell_get_row_header_cells    (AtkTableCell *cell);
ATK_AVAILABLE_IN_2_12
gboolean    atk_table_cell_get_row_column_span     (AtkTableCell *cell,
                                                    gint         *row,
                                                    gint         *column,
                                                    gint         *row_span,
                                                    gint         *column_span);
ATK_AVAILABLE_IN_2_12
AtkObject * atk_table_cell_get_table               (AtkTableCell *cell);

G_END_DECLS

#endif /* __ATK_TABLE_CELL_H__ */