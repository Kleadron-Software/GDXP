/*************************************************************************/
/*  room.h                                                               */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef ROOM_BOUNDS_H
#define ROOM_BOUNDS_H

#include "bsp_tree.h"
#include "resource.h"
/**
	@author Juan Linietsky <reduzio@gmail.com>
*/
class Room : public Resource {

	OBJ_TYPE(Room, Resource);
	RES_BASE_EXTENSION("room");

	RID area;
	DVector<Face3> geometry_hint;

	void _regenerate_bsp();
	void _regenerate_bsp_cubic();

protected:
	static void _bind_methods();

public:
	virtual RID get_rid() const;

	void set_bounds(const BSP_Tree &p_bounds);
	BSP_Tree get_bounds() const;

	void set_geometry_hint(const DVector<Face3> &geometry_hint);
	DVector<Face3> get_geometry_hint() const;

	Room();
	~Room();
};

#endif // ROOM_H
