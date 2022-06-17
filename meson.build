project('computer-graphics', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

subdir('linal')
subdir('canvas')
subdir('raytracer')

cc = meson.get_compiler('c')
md = cc.find_library('m', required: true)

lib_canvas = static_library(
  'canvas', canvas_src, include_directories: canvas_inc)

lib_linal = static_library(
  'linal', linal_src, include_directories: linal_inc, dependencies: md)

lib_linal_dep = declare_dependency(
  include_directories: linal_inc, link_with : lib_linal)

lib_canvas_dep = declare_dependency(
  include_directories: canvas_inc, link_with : lib_canvas)

executable(
  'cg-raytracer', raytracer_src,
  include_directories: [raytracer_inc, linal_inc], dependencies: [lib_canvas_dep, lib_linal_dep])
