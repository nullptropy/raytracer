workspace "ComputerGraphics"
  configurations { "debug", "release" }
  buildoptions { "-pedantic", "-Wall", "-Wextra" }

  newaction {
    trigger = "clean",
    description = "clean the project",
    execute = function()
      os.rmdir("build")
      os.remove("Makefile")
      os.remove("compile_commands.json")
    end
  }

  newaction {
    trigger = "format",
    description = "chang-format",
    execute = function()
      os.execute("find . -type f -name '*.[ch]' -exec clang-format -i {} +")
    end
  }

  newaction {
    trigger = "make",
    description = "call execute `premake5 gmake; bear -- make;`",
    execute = function()
      os.execute("premake5 gmake")
      os.execute("bear -- make config=debug all;")
    end
  }

  function generate_project(name, type, link, include)
    project(name)
      kind(type)
      language "C"
      location("build/" .. name)

      files({ name .. "/*.h", name .. "/*.c" })
      links(link)

      includedirs(link)
      includedirs(include)

      filter "configurations:debug"
        defines { "DEBUG" }
        symbols "on"

      filter "configurations:release"
        optimize "Speed"
  end

  function generate_test(name, link, include)
    project(name)
      kind "ConsoleApp"
      location "build/tests"

      files({ "tests/" .. name .. ".c" })
      links(link)

      includedirs(link)
      includedirs(include)
  end

  generate_project("linal", "StaticLib", { "libm" }, {})
  generate_project("canvas", "StaticLib", {}, {})

  generate_project("raytracer", "ConsoleApp", { "canvas", "linal" }, { "." })
  -- generate_project("rasterizer", "ConsoleApp", { "canvas", "linal" }, {})

  generate_test("test_canvas", "canvas", {})
  generate_test("test_linal_vec", "linal", {})
