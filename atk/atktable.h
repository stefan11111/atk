#ifndef __ATK_TABLE_H__
#define __ATK_TABLE_H__

#if defined(ATK_DISABLE_SINGLE_INCLUDES) && !defined (__ATK_H_INSIDE__) && !defined (ATK_COMPILATION)
#error "Only <atk/atk.h> can be included directly."
#endif

#include <atk/atkobject.h>



#define ATK_TYPE_TABLE                    (atk_table_get_type ())
#define ATK_IS_TABLE(obj)                  ((obj), ATK_TYPE_TABLE)
#define ATK_TABLE(obj)                     ((obj), ATK_TYPE_TABLE, AtkTable)
#define ATK_TABLE_GET_IFACE(obj)          ( ((obj), ATK_TYPE_TABLE, AtkTableIface))

#ifndef _TYPEDEF_ATK_TABLE_
#define _TYPEDEF_ATK_TABLE_
typedef struct _AtkTable AtkTable;
#endif
typedef struct _AtkTableIface AtkTableIface;

struct _AtkTableIface
{
  long unsigned int* parent;

  AtkObject*        (* ref_at)                   (AtkTable      *table,
                                                  int          row,
                                                  int          column);
  int              (* get_index_at)             (AtkTable      *table,
                                                  int          row,
                                                  int          column);
  int              (* get_column_at_index)      (AtkTable      *table,
                                                  int          index_);
  int              (* get_row_at_index)         (AtkTable      *table,
                                                  int          index_);
  int              (* get_n_columns)           (AtkTable      *table);
  int              (* get_n_rows)               (AtkTable      *table);
  int              (* get_column_extent_at)     (AtkTable      *table,
                                                  int          row,
                                                  int          column);
  int              (* get_row_extent_at)        (AtkTable      *table,
                                                  int          row,
                                                  int          column);
  AtkObject*
                    (* get_caption)              (AtkTable      *table);
  const char*      (* get_column_description)   (AtkTable      *table,
                                                  int          column);
  AtkObject*        (* get_column_header)        (AtkTable      *table,
						  int		column);
  const char*      (* get_row_description)      (AtkTable      *table,
                                                  int          row);
  AtkObject*        (* get_row_header)           (AtkTable      *table,
						  int		row);
  AtkObject*        (* get_summary)              (AtkTable      *table);
  void              (* set_caption)              (AtkTable      *table,
                                                  AtkObject     *caption);
  void              (* set_column_description)   (AtkTable      *table,
                                                  int          column,
                                                  const char   *description);
  void              (* set_column_header)        (AtkTable      *table,
                                                  int          column,
                                                  AtkObject     *header);
  void              (* set_row_description)      (AtkTable      *table,
                                                  int          row,
                                                  const char   *description);
  void              (* set_row_header)           (AtkTable      *table,
                                                  int          row,
                                                  AtkObject     *header);
  void              (* set_summary)              (AtkTable      *table,
                                                  AtkObject     *accessible);
  int              (* get_selected_columns)     (AtkTable      *table,
                                                  int          **selected);
  int              (* get_selected_rows)        (AtkTable      *table,
                                                  int          **selected);
  unsigned char          (* is_column_selected)       (AtkTable      *table,
                                                  int          column);
  unsigned char          (* is_row_selected)          (AtkTable      *table,
                                                  int          row);
  unsigned char          (* is_selected)              (AtkTable      *table,
                                                  int          row,
                                                  int          column);
  unsigned char          (* add_row_selection)        (AtkTable      *table,
                                                  int          row);
  unsigned char          (* remove_row_selection)     (AtkTable      *table,
                                                  int          row);
  unsigned char          (* add_column_selection)     (AtkTable      *table,
                                                  int          column);
  unsigned char          (* remove_column_selection)  (AtkTable      *table,
                                                  int          column);

  /*
   * signal handlers
   */
  void              (* row_inserted)             (AtkTable      *table,
                                                  int          row,
                                                  int          num_inserted);
  void              (* column_inserted)          (AtkTable      *table,
                                                  int          column,
                                                  int          num_inserted);
  void              (* row_deleted)              (AtkTable      *table,
                                                  int          row,
                                                  int          num_deleted);
  void              (* column_deleted)           (AtkTable      *table,
                                                  int          column,
                                                  int          num_deleted);
  void              (* row_reordered)            (AtkTable      *table);
  void              (* column_reordered)         (AtkTable      *table);
  void              (* model_changed)            (AtkTable      *table);
};

ATK_AVAILABLE_IN_ALL
long unsigned int atk_table_get_type (void);

ATK_AVAILABLE_IN_ALL
AtkObject*        atk_table_ref_at               (AtkTable         *table,
                                                  int             row,
                                                  int             column);
ATK_DEPRECATED_IN_2_12_FOR(atk_table_ref_at)
int              atk_table_get_index_at         (AtkTable         *table,
                                                  int             row,
                                                  int             column);
ATK_DEPRECATED_IN_2_12
int              atk_table_get_column_at_index  (AtkTable         *table,
                                                  int             index_);
ATK_DEPRECATED_IN_2_12
int              atk_table_get_row_at_index     (AtkTable         *table,
                                                  int             index_);
ATK_AVAILABLE_IN_ALL
int              atk_table_get_n_columns        (AtkTable         *table);
ATK_AVAILABLE_IN_ALL
int              atk_table_get_n_rows           (AtkTable         *table);
ATK_AVAILABLE_IN_ALL
int              atk_table_get_column_extent_at (AtkTable         *table,
                                                  int             row,
                                                  int             column);
ATK_AVAILABLE_IN_ALL
int              atk_table_get_row_extent_at    (AtkTable         *table,
                                                  int             row,
                                                  int             column);
ATK_AVAILABLE_IN_ALL
AtkObject*
                  atk_table_get_caption          (AtkTable         *table);
ATK_AVAILABLE_IN_ALL
const char*      atk_table_get_column_description
                                                 (AtkTable         *table,
                                                  int             column);
ATK_AVAILABLE_IN_ALL
AtkObject*        atk_table_get_column_header    (AtkTable         *table,
						  int		   column);
ATK_AVAILABLE_IN_ALL
const char*      atk_table_get_row_description  (AtkTable         *table,
                                                  int             row);
ATK_AVAILABLE_IN_ALL
AtkObject*        atk_table_get_row_header       (AtkTable         *table,
						  int		   row);
ATK_AVAILABLE_IN_ALL
AtkObject*        atk_table_get_summary          (AtkTable         *table);
ATK_AVAILABLE_IN_ALL
void              atk_table_set_caption          (AtkTable         *table,
                                                  AtkObject        *caption);
ATK_AVAILABLE_IN_ALL
void              atk_table_set_column_description 
                                                 (AtkTable         *table,
                                                  int             column,
                                                  const char      *description);
ATK_AVAILABLE_IN_ALL
void              atk_table_set_column_header    (AtkTable         *table,
                                                  int             column,
                                                  AtkObject        *header);
ATK_AVAILABLE_IN_ALL
void              atk_table_set_row_description  (AtkTable         *table,
                                                  int             row,
                                                  const char      *description);
ATK_AVAILABLE_IN_ALL
void              atk_table_set_row_header       (AtkTable         *table,
                                                  int             row,
                                                  AtkObject        *header);
ATK_AVAILABLE_IN_ALL
void              atk_table_set_summary          (AtkTable         *table,
                                                  AtkObject        *accessible);
ATK_AVAILABLE_IN_ALL
int              atk_table_get_selected_columns (AtkTable         *table,
                                                  int             **selected);
ATK_AVAILABLE_IN_ALL
int              atk_table_get_selected_rows    (AtkTable         *table,
                                                  int             **selected);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_is_column_selected   (AtkTable         *table,
                                                  int             column);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_is_row_selected      (AtkTable         *table,
                                                  int             row);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_is_selected          (AtkTable         *table,
                                                  int             row,
                                                  int             column);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_add_row_selection    (AtkTable         *table,
                                                  int             row);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_remove_row_selection (AtkTable         *table,
                                                  int             row);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_add_column_selection (AtkTable         *table,
                                                  int             column);
ATK_AVAILABLE_IN_ALL
unsigned char          atk_table_remove_column_selection  
                                                 (AtkTable         *table,
                                                  int             column);



#endif /* __ATK_TABLE_H__ */
