/*
 * GStreamer
 * Copyright (C) 2008 Filippo Argiolas <filippo.argiolas@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef _GST_GL_DIFFERENCEMATTE_H_
#define _GST_GL_DIFFERENCEMATTE_H_

#include <gstglfilter.h>

#define GST_TYPE_GL_DIFFERENCEMATTE            (gst_gl_differencematte_get_type())
#define GST_GL_DIFFERENCEMATTE(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_GL_DIFFERENCEMATTE,GstGLDifferenceMatte))
#define GST_IS_GL_DIFFERENCEMATTE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_GL_DIFFERENCEMATTE))
#define GST_GL_DIFFERENCEMATTE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass) , GST_TYPE_GL_DIFFERENCEMATTE,GstGLDifferenceMatteClass))
#define GST_IS_GL_DIFFERENCEMATTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass) , GST_TYPE_GL_DIFFERENCEMATTE))
#define GST_GL_DIFFERENCEMATTE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj) , GST_TYPE_GL_DIFFERENCEMATTE,GstGLDifferenceMatteClass))

typedef struct _GstGLDifferenceMatte GstGLDifferenceMatte;
typedef struct _GstGLDifferenceMatteClass GstGLDifferenceMatteClass;

struct _GstGLDifferenceMatte
{
  GstGLFilter filter;

  GstGLShader *shader[4];

  gchar *location;
  gboolean bg_has_changed;

  guchar *pixbuf;
  GLuint savedbgtexture;
  GLuint newbgtexture;
  GLuint midtexture[4];
  GLuint intexture;
};

struct _GstGLDifferenceMatteClass
{
  GstGLFilterClass filter_class;
};

#endif /* _GST_GL_DIFFERENCEMATTE_H_ */
