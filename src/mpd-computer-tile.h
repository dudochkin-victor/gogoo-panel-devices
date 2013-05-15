
/*
 * Copyright © 2010 Intel Corp.
 *
 * Authors: Rob Staudinger <robert.staudinger@intel.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_COMPUTER_TILE_H
#define MPD_COMPUTER_TILE_H

#include <glib-object.h>
#include <mx/mx.h>

G_BEGIN_DECLS

#define MPD_TYPE_COMPUTER_TILE mpd_computer_tile_get_type()

#define MPD_COMPUTER_TILE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), MPD_TYPE_COMPUTER_TILE, MpdComputerPane))

#define MPD_COMPUTER_TILE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), MPD_TYPE_COMPUTER_TILE, MpdComputerPaneClass))

#define MPD_IS_COMPUTER_TILE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MPD_TYPE_COMPUTER_TILE))

#define MPD_IS_COMPUTER_TILE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), MPD_TYPE_COMPUTER_TILE))

#define MPD_COMPUTER_TILE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), MPD_TYPE_COMPUTER_TILE, MpdComputerTileClass))

typedef struct
{
  MxBoxLayout parent;
} MpdComputerTile;

typedef struct
{
  MxBoxLayoutClass parent;
} MpdComputerTileClass;

GType
mpd_computer_tile_get_type (void);

ClutterActor *
mpd_computer_tile_new (void);

G_END_DECLS

#endif /* MPD_COMPUTER_TILE_H */

