/* counter-window.c
 *
 * Copyright 2023 Felipe Kinoshita
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"

#include "counter-window.h"

struct _CounterWindow
{
  AdwApplicationWindow  parent_instance;

  /* Template widgets */
  GtkLabel            *count_label;
  GtkButton           *count_button;

  /* variables */
  gint                 count;
};

G_DEFINE_FINAL_TYPE (CounterWindow, counter_window, ADW_TYPE_APPLICATION_WINDOW)

static void
on_count_button_clicked (GSimpleAction *action,
                         GVariant      *param,
                         gpointer      *user_data)
{
  CounterWindow *window;
  gchar *new_label;

  window = COUNTER_WINDOW (user_data);
  window->count++;

  new_label = g_strdup_printf ("%d", window->count);

  gtk_label_set_label (window->count_label, new_label);
}

static void
counter_window_class_init (CounterWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/github/fkinoshita/Counter/counter-window.ui");
  gtk_widget_class_bind_template_child (widget_class, CounterWindow, count_label);
  gtk_widget_class_bind_template_child (widget_class, CounterWindow, count_button);

  // Callbacks
  gtk_widget_class_bind_template_callback (widget_class, on_count_button_clicked);
}

static void
counter_window_init (CounterWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
