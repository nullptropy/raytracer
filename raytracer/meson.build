srcs = ['camera.c', 'light.c', 'main.c', 'scene.c', 'sphere.c']
sources = []

foreach i: range(0, srcs.length())
  sources += 'src' / srcs[i]
endforeach

raytracer_src = files(sources)
raytracer_inc = include_directories('include')
