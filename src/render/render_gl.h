/*
 *  This file is part of Permafrost Engine. 
 *  Copyright (C) 2017-2018 Eduard Permyakov 
 *
 *  Permafrost Engine is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Permafrost Engine is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *  Linking this software statically or dynamically with other modules is making 
 *  a combined work based on this software. Thus, the terms and conditions of 
 *  the GNU General Public License cover the whole combination. 
 *  
 *  As a special exception, the copyright holders of Permafrost Engine give 
 *  you permission to link Permafrost Engine with independent modules to produce 
 *  an executable, regardless of the license terms of these independent 
 *  modules, and to copy and distribute the resulting executable under 
 *  terms of your choice, provided that you also meet, for each linked 
 *  independent module, the terms and conditions of the license of that 
 *  module. An independent module is a module which is not derived from 
 *  or based on Permafrost Engine. If you modify Permafrost Engine, you may 
 *  extend this exception to your version of Permafrost Engine, but you are not 
 *  obliged to do so. If you do not wish to do so, delete this exception 
 *  statement from your version.
 *
 */

#ifndef RENDER_GL_H
#define RENDER_GL_H

#include "../pf_math.h"

#include <GL/glew.h>

#include <stddef.h>
#include <stdbool.h>


#define SHADOW_MAP_TUNIT (GL_TEXTURE16)

struct render_private;
struct vertex;
struct tile;

/* General */

void   R_GL_Init(struct render_private *priv, const char *shader, const struct vertex *vbuff);

/* Shadows */

void   R_GL_InitShadows(void);
vec3_t R_GL_GetLightPos(void);
void   R_GL_SetLightSpaceTrans(const mat4x4_t *trans);
void   R_GL_SetShadowMap(const GLuint shadow_map_tex_id);

/* Tiles */

void   R_GL_TileGetVertices(const struct tile *tile, struct vertex *out, size_t r, size_t c);

/* ---------------------------------------------------------------------------
 * Patch the vertices for a particular tile to have adjacency information
 * about the neighboring tiles, to be used for smooth blending.
 * Tiles which border tiles with different materials will get blending
 * 'turned on' by setting a vertex attribute.
 * ---------------------------------------------------------------------------
 */
void   R_GL_TilePatchVertsBlend(GLuint VBO, const struct tile *tiles, 
                                int width, int height, int r, int c);

#endif
