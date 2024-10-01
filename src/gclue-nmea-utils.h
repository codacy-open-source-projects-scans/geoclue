/* vim: set et ts=8 sw=8: */
/*
 * Geoclue is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * Geoclue is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along
 * with Geoclue; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef GCLUE_NMEA_UTILS_H
#define GCLUE_NMEA_UTILS_H

#include <glib.h>

G_BEGIN_DECLS

gboolean         gclue_nmea_type_is              (const char *msg, const char *nmeatype);
GTimeSpan        gclue_nmea_timestamp_to_timespan (const gchar *timestamp);

G_END_DECLS

#endif /* GCLUE_NMEA_UTILS_H */
